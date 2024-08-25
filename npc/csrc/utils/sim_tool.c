#include "sim_tool.h"

// #define COLOR_GREEN "\033[32m"
// #define COLOR_END "\033[0m"

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

VTop* Top;

volatile int ebreak_flag = 0;

void step_and_dump_wave() {
  Top->eval();
  contextp->timeInc(1);
  tfp->dump(contextp->time());
}

void single_cycle() {
  Top->clock = 0;
  step_and_dump_wave();
  Top->clock = 1;
  step_and_dump_wave();
}

void sim_init() {
  contextp = new VerilatedContext;
  tfp = new VerilatedVcdC;
  Top = new VTop;
  contextp->traceEverOn(true);
  Top->trace(tfp, 0);
  tfp->open("waveform.vcd");
}

void sim_exit() {
  step_and_dump_wave();
  tfp->close();
}

void sim_reset_one_cycle() {
  Top->reset = 0b1;
  single_cycle();
  Top->reset = 0b0;
}

void check_ebreak(){
	if(ebreak_flag == 1){
		nemu_state.state = NEMU_END;
		Log("last ebreak inst , program will done \r\n");
	}else{
		nemu_state.state = NEMU_RUNNING;
	}
}


// static void ebreak() {
//   ebreak_flag = 1;
//   // printf(COLOR_GREEN);
//   // printf("excute the ebreak inst\r\n");
//   // printf(COLOR_END);

//   // printf(COLOR_END);
//   // hit_exit(cpu_gpr[10]);
// }

extern "C" {

void ebreak() {
  ebreak_flag = 1;
  // printf(COLOR_GREEN);
  // printf("excute the ebreak inst\r\n");
  // printf(COLOR_END);

  // printf(COLOR_END);
  // hit_exit(cpu_gpr[10]);
}

}

void load_memory_from_file(const std::string& filename) {
  std::ifstream infile(filename);
  std::string line;
  int address = 0;
  std::string word;

  while (infile >> word) {
    uint32_t data;
    std::stringstream ss;
    ss << std::hex << word;
    ss >> data;

    for (int i = 0; i < 4; ++i) {
      uint8_t byte = (data >> (i * 8)) & 0xFF;
      //   Top->io_memWriteEnable = 1;
      //   Top->io_memWriteAddr = address + i;
      //   Top->io_memWriteData = byte;
      //   single_cycle();
      //   Top->io_memWriteEnable = 0;
      Top->rootp->Top__DOT__memory__DOT__mem_ext__DOT__Memory[address + i] =
          byte;
    }
    address += 1;
  }
}

// void get_pc(){
// 	vaddr_t pc;
// 	pc = Top->rootp->Top__DOT__core__DOT__pc_reg;
// 	cpu.pc = pc;
// 	// return pc;
// 	// printf("------pc : 0x%x",pc);
// }

void get_reg(){
	cpu.pc = Top->rootp->Top__DOT__core__DOT__pc_reg;
	for(int i =0;i<32;i++){
		// printf("%u\t",Top->rootp->Top__DOT__core__DOT__regfile_ext__DOT__Memory[i]);
		cpu.gpr[i] = Top->rootp->Top__DOT__core__DOT__regfile_ext__DOT__Memory[i];
	}
	cpu.inst = Top->rootp->Top__DOT___memory_io_imem_inst;
}

// uint32_t get_inst(){
// 	uint32_t inst;
// 	inst=Top->rootp->Top__DOT___memory_io_imem_inst;
// 	return inst;
// }
