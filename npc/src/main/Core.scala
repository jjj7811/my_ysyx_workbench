package lw

import chisel3._
import chisel3.util._
import common.Consts._
import common.Instructions._ // 追加
import chisel3.util.HasBlackBoxInline

class Core extends Module {
  val io = IO(new Bundle {
    val imem = Flipped(new ImemPortIo())
    val dmem = Flipped(new DmemPortIo())
    val exit = Output(Bool())
  })

  val regfile = Mem(32, UInt(WORD_LEN.W))


  //**********************************
  // Instruction Fetch (IF) Stage
  
  val pc_reg = RegInit(START_ADDR)
  io.imem.addr := pc_reg
  val inst = io.imem.inst
  val pc_plus4 = pc_reg + 4.U(WORD_LEN.W)
  val br_target = Wire(UInt(WORD_LEN.W))
  val br_flg = Wire(Bool())
  val jmp_flg = (inst === JAL || inst === JALR)
  val alu_out = Wire(UInt(WORD_LEN.W))

  val pc_next = MuxCase(pc_plus4, Seq(
    br_flg  -> br_target,
    jmp_flg -> alu_out,
  ))
  pc_reg := pc_next


  //**********************************
  // Instruction Decode (ID) Stage
  
  val rs1_addr = inst(19, 15)
  val rs2_addr = inst(24, 20)
  val wb_addr  = inst(11, 7)
  val rs1_data = Mux((rs1_addr =/= 0.U(WORD_LEN.U)), regfile(rs1_addr), 0.U(WORD_LEN.W))
  val rs2_data = Mux((rs2_addr =/= 0.U(WORD_LEN.U)), regfile(rs2_addr), 0.U(WORD_LEN.W))

  val imm_i = inst(31, 20)
  val imm_i_sext = Cat(Fill(20, imm_i(11)), imm_i)
  val imm_s = Cat(inst(31, 25), inst(11, 7))
  val imm_s_sext = Cat(Fill(20, imm_s(11)), imm_s)
  val imm_b = Cat(inst(31), inst(7), inst(30, 25), inst(11, 8))
  val imm_b_sext = Cat(Fill(19, imm_b(11)), imm_b, 0.U(1.U))
  val imm_j = Cat(inst(31), inst(19, 12), inst(20), inst(30, 21))
  val imm_j_sext = Cat(Fill(11, imm_j(19)), imm_j, 0.U(1.U))
  val imm_u = inst(31,12)
  val imm_u_shifted = Cat(imm_u, Fill(12, 0.U))

  val csignals = ListLookup(inst,
               List(ALU_X    , OP1_RS1, OP2_RS2, MEN_X, REN_X, WB_X  ),
    Array(
      LW    -> List(ALU_ADD  , OP1_RS1, OP2_IMI, MEN_X, REN_S, WB_MEM),
      SW    -> List(ALU_ADD  , OP1_RS1, OP2_IMS, MEN_S, REN_X, WB_X  ),
      ADD   -> List(ALU_ADD  , OP1_RS1, OP2_RS2, MEN_X, REN_S, WB_ALU),
      ADDI  -> List(ALU_ADD  , OP1_RS1, OP2_IMI, MEN_X, REN_S, WB_ALU),
      SUB   -> List(ALU_SUB  , OP1_RS1, OP2_RS2, MEN_X, REN_S, WB_ALU),
      AND   -> List(ALU_AND  , OP1_RS1, OP2_RS2, MEN_X, REN_S, WB_ALU),
      OR    -> List(ALU_OR   , OP1_RS1, OP2_RS2, MEN_X, REN_S, WB_ALU),
      XOR   -> List(ALU_XOR  , OP1_RS1, OP2_RS2, MEN_X, REN_S, WB_ALU),
      ANDI  -> List(ALU_AND  , OP1_RS1, OP2_IMI, MEN_X, REN_S, WB_ALU),
      ORI   -> List(ALU_OR   , OP1_RS1, OP2_IMI, MEN_X, REN_S, WB_ALU),
      XORI  -> List(ALU_XOR  , OP1_RS1, OP2_IMI, MEN_X, REN_S, WB_ALU),
      SLL   -> List(ALU_SLL  , OP1_RS1, OP2_RS2, MEN_X, REN_S, WB_ALU),
      SRL   -> List(ALU_SRL  , OP1_RS1, OP2_RS2, MEN_X, REN_S, WB_ALU),
      SRA   -> List(ALU_SRA  , OP1_RS1, OP2_RS2, MEN_X, REN_S, WB_ALU),
      SLLI  -> List(ALU_SLL  , OP1_RS1, OP2_IMI, MEN_X, REN_S, WB_ALU),
      SRLI  -> List(ALU_SRL  , OP1_RS1, OP2_IMI, MEN_X, REN_S, WB_ALU),
      SRAI  -> List(ALU_SRA  , OP1_RS1, OP2_IMI, MEN_X, REN_S, WB_ALU),
      SLT   -> List(ALU_SLT  , OP1_RS1, OP2_RS2, MEN_X, REN_S, WB_ALU),
      SLTU  -> List(ALU_SLTU , OP1_RS1, OP2_RS2, MEN_X, REN_S, WB_ALU),
      SLTI  -> List(ALU_SLT  , OP1_RS1, OP2_IMI, MEN_X, REN_S, WB_ALU),
      SLTIU -> List(ALU_SLTU , OP1_RS1, OP2_IMI, MEN_X, REN_S, WB_ALU),
      BEQ   -> List(BR_BEQ   , OP1_RS1, OP2_RS2, MEN_X, REN_X, WB_X  ),
      BNE   -> List(BR_BNE   , OP1_RS1, OP2_RS2, MEN_X, REN_X, WB_X  ),
      BGE   -> List(BR_BGE   , OP1_RS1, OP2_RS2, MEN_X, REN_X, WB_X  ),
      BGEU  -> List(BR_BGEU  , OP1_RS1, OP2_RS2, MEN_X, REN_X, WB_X  ),
      BLT   -> List(BR_BLT   , OP1_RS1, OP2_RS2, MEN_X, REN_X, WB_X  ),
      BLTU  -> List(BR_BLTU  , OP1_RS1, OP2_RS2, MEN_X, REN_X, WB_X  ),
      JAL   -> List(ALU_ADD  , OP1_PC , OP2_IMJ, MEN_X, REN_S, WB_PC ),
      JALR  -> List(ALU_JALR , OP1_RS1, OP2_IMI, MEN_X, REN_S, WB_PC ),
      LUI   -> List(ALU_ADD  , OP1_X  , OP2_IMU, MEN_X, REN_S, WB_ALU),
      AUIPC -> List(ALU_ADD  , OP1_PC , OP2_IMU, MEN_X, REN_S, WB_ALU),
    )
  )
  val exe_fun :: op1_sel :: op2_sel :: mem_wen :: rf_wen :: wb_sel :: Nil = csignals

  val op1_data = MuxCase(0.U(WORD_LEN.W), Seq(
    (op1_sel === OP1_RS1) -> rs1_data,
    (op1_sel === OP1_PC)  -> pc_reg
  ))

  val op2_data = MuxCase(0.U(WORD_LEN.W), Seq(
    (op2_sel === OP2_RS2) -> rs2_data,
    (op2_sel === OP2_IMI) -> imm_i_sext,
    (op2_sel === OP2_IMS) -> imm_s_sext,
    (op2_sel === OP2_IMJ) -> imm_j_sext,
    (op2_sel === OP2_IMU) -> imm_u_shifted, // 追加
  ))


  //**********************************
  // Execute (EX) Stage
  
  alu_out := MuxCase(0.U(WORD_LEN.W), Seq(
    (exe_fun === ALU_ADD)  -> (op1_data + op2_data),
    (exe_fun === ALU_SUB)  -> (op1_data - op2_data),
    (exe_fun === ALU_AND)  -> (op1_data & op2_data),
    (exe_fun === ALU_OR)   -> (op1_data | op2_data),
    (exe_fun === ALU_XOR)  -> (op1_data ^ op2_data),
    (exe_fun === ALU_SLL)  -> (op1_data << op2_data(4, 0))(31, 0),
    (exe_fun === ALU_SRL)  -> (op1_data >> op2_data(4, 0)),
    (exe_fun === ALU_SRA)  -> (op1_data.asSInt >> op2_data(4, 0)).asUInt,
    (exe_fun === ALU_SLT)  -> (op1_data.asSInt < op2_data.asSInt),
    (exe_fun === ALU_SLTU) -> (op1_data < op2_data),
    (exe_fun === ALU_JALR) -> ((op1_data + op2_data) & ~(1.U(WORD_LEN.W))) // 追加
  ))

  // branch
  br_target := pc_reg + imm_b_sext
  br_flg := MuxCase(false.B, Seq(
    (exe_fun === BR_BEQ)  -> (op1_data === op2_data),
    (exe_fun === BR_BNE)  -> (op1_data =/= op2_data),
    (exe_fun === BR_BLT)  -> (op1_data.asSInt < op2_data.asSInt),
    (exe_fun === BR_BGE)  -> (op1_data.asSInt >= op2_data.asSInt),
    (exe_fun === BR_BLTU) -> (op1_data < op2_data),
    (exe_fun === BR_BGEU) -> (op1_data >= op2_data)
  ))

  //**********************************
  // Memory Access Stage  

  io.dmem.addr  := alu_out
  io.dmem.wen   := Mux(mem_wen === MEN_S, 1.U(MEN_LEN.W), 0.U(MEN_LEN.W))
  io.dmem.wdata := rs2_data


  //**********************************
  // Writeback (WB) Stage

  val wb_data = MuxCase(alu_out, Seq(
    (wb_sel === WB_MEM) -> io.dmem.rdata,
    (wb_sel === WB_PC) -> pc_plus4
  ))

  //对应ret情况，省略了rd，但是不能往x0写，要写到ra
  // when(exe_fun === ALU_JALR && wb_addr === 0.U(WORD_LEN.W)) {
  //   wb_addr := 1.U(WORD_LEN.W)
  // }

  // val real_wb_addr = Wire(UInt(WORD_LEN.W))


  // real_wb_addr := MuxCase(wb_addr, Seq(
  //   (exe_fun === ALU_JALR && wb_addr === 0.U(WORD_LEN.W))  -> (op1_data + op2_data)
  // ))

  when(rf_wen === REN_S && wb_addr =/= 0.U(WORD_LEN.W)) {
    regfile(wb_addr) := wb_data
  }

  val ebreakModule = Module(new EBREAK)
  ebreakModule.io.inst_i := inst
  val exitEbreakReg = RegNext(ebreakModule.io.exit_ebreak, init = false.B)
  io.exit := exitEbreakReg


  //**********************************
  // Debug
  // io.exit := (inst === 0xc0001073L.U(WORD_LEN.W))
  val regNames = Array(
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2", 
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5", 
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7", 
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
  )
  // for (i <- 0 until 32) {
  //   if (i % 8 == 0) {
  //     printf("\n")
  //   }
  //   printf(p"${regNames(i)}:0x${Hexadecimal(regfile(i).asUInt)}\t")
  // }
  // printf("\n---------\n")
  // printf(p"pc_reg     : 0x${Hexadecimal(pc_reg)}\n")
  // printf(p"inst       : 0x${Hexadecimal(inst)}\n")
  // printf(p"wb_addr    : $wb_addr\n")
  // printf(p"rs1_addr   : $rs1_addr\n")
  // printf(p"rs2_addr   : $rs2_addr\n")
  // printf(p"rs1_data   : 0x${Hexadecimal(rs1_data)} = ${rs1_data}\n")
  // printf(p"rs2_data   : 0x${Hexadecimal(rs2_data)} = ${rs2_data}\n")
  // printf(p"wb_data    : 0x${Hexadecimal(wb_data)} = ${wb_data}\n")
  // printf(p"dmem.addr  : ${io.dmem.addr}\n")
  // printf(p"dmem.rdata : ${io.dmem.rdata}\n")

  

  // for (i <- 0 until 32) {
  //   printf(p"a$i : ${Hexadecimal(regfile(i).asUInt)}\t")
  // }
  // printf(p"a1         : ${Hexadecimal(regfile(1).asUInt)}\n")
  // printf("\n---------\n")
}

// package lw

// import chisel3._
// import chisel3.util._
// import common.Consts._
// import common.Instructions._ // 追加
// import chisel3.util.HasBlackBoxInline

// class Core extends Module {
//   val io = IO(new Bundle {
//     val imem = Flipped(new ImemPortIo())
//     val dmem = Flipped(new DmemPortIo()) // 追加
//     val exit = Output(Bool())
//   })

//   val regfile = Mem(32, UInt(WORD_LEN.W))

//   //**********************************
//   // Instruction Fetch (IF) Stage
  
//   val pc_reg = RegInit(START_ADDR)
//   // pc_reg := 1.U(WORD_LEN.W)
//   io.imem.addr := pc_reg
//   val inst = io.imem.inst
//   pc_reg := pc_reg + 4.U(WORD_LEN.W)


//   //**********************************
//   // Instruction Decode (ID) Stage
  
//   val rs1_addr = inst(19, 15)
//   val rs2_addr = inst(24, 20)
//   val wb_addr  = inst(11, 7)
//   val rs1_data = Mux((rs1_addr =/= 0.U(WORD_LEN.U)), regfile(rs1_addr), 0.U(WORD_LEN.W))
//   val rs2_data = Mux((rs2_addr =/= 0.U(WORD_LEN.U)), regfile(rs2_addr), 0.U(WORD_LEN.W))

//   val imm_i = inst(31, 20) // offset[11:0]の抽出
//   val imm_i_sext = Cat(Fill(20, imm_i(11)), imm_i) // offsetの符号拡張


//   //**********************************
//   // Execute (EX) Stage

//   val alu_out = MuxCase(0.U(WORD_LEN.W), Seq(
//     (inst === LW) -> (rs1_data + imm_i_sext),
//     (inst === ADDI) -> (rs1_data + imm_i_sext) 
//   ))


//   //**********************************
//   // Memory Access Stage
  
//   io.dmem.addr := alu_out


//   //**********************************
//   // Writeback (WB) Stage

//   val wb_data = MuxCase(alu_out, Seq(
//     (inst === LW) -> io.dmem.rdata
//   ))
  
//   when(inst === LW || inst === ADDI) {
//     regfile(wb_addr) := wb_data
//   }

//   val ebreakModule = Module(new EBREAK)
//   ebreakModule.io.inst_i := inst
//   val exitEbreakReg = RegNext(ebreakModule.io.exit_ebreak, init = false.B)
//   io.exit := exitEbreakReg


//   //**********************************
//   // Debug
//   // io.exit := (inst === 0x14131211.U(WORD_LEN.W))
//   printf(p"pc_reg    : 0x${Hexadecimal(pc_reg)}\n")
//   printf(p"inst      : 0x${Hexadecimal(inst)}\n")
//   printf(p"rs1_addr  : $rs1_addr\n")
//   printf(p"rs2_addr  : $rs2_addr\n")
//   printf(p"wb_addr   : $wb_addr\n")
//   printf(p"alu_out   : 0x${Hexadecimal(alu_out)}\n")
//   printf(p"rs1_data  : 0x${Hexadecimal(rs1_data)}\n")
//   printf(p"rs2_data  : 0x${Hexadecimal(rs2_data)}\n")
//   printf(p"wb_data   : 0x${Hexadecimal(wb_data)}\n") // 追加
//   printf(p"dmem.addr : ${io.dmem.addr}\n")              // 追加
//   printf("---------\n")
// }