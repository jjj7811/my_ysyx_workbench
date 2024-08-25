package lw

import common.Consts._
import chisel3._

class Top extends Module {
  val io = IO(new Bundle {
    val exit = Output(Bool())
    //to write program from verilator
    // val memWriteEnable = Input(UInt(MEN_LEN.W))
    // val memWriteAddr = Input(UInt(WORD_LEN.W))
    // val memWriteData = Input(UInt(WORD_LEN.W))
    val coreRun = Input(Bool()) // control signal for core clock
  })
  val core = Module(new Core())
  val memory = Module(new Memory())
  core.io.imem <> memory.io.imem
  core.io.dmem <> memory.io.dmem
  io.exit := core.io.exit

//   // Connect the memory write interface
//   memory.io.dmem.wen := io.memWriteEnable
//   memory.io.dmem.addr := io.memWriteAddr
//   memory.io.dmem.wdata := io.memWriteData

  // Control core clock
  core.reset := !io.coreRun
}

// package lw

// import chisel3._

// class Top extends Module {
//   val io = IO(new Bundle {
//     val exit = Output(Bool())
//   })
//   val core = Module(new Core())
//   val memory = Module(new Memory())
//   core.io.imem <> memory.io.imem
//   core.io.dmem <> memory.io.dmem
//   io.exit := core.io.exit
// }