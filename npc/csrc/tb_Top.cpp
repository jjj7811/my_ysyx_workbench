// #include <ncurses.h>

// #include <fstream>
// #include <iostream>
// #include <sstream>
// #include <string>
// #include <vector>

// #include "/home/hehe/ysyx-workbench/npc/csrc/t1.h"
// #include "VTop.h"
// #include "VTop___024root.h"
// #include "verilated.h"
// #include "verilated_vcd_c.h"

#include "sim_tool.h"
#include "cpu/cpu-exec.h"
#include "monitor/sdb/sdb.h"


// #include "common.h"
#define COLOR_GREEN "\033[32m"
#define COLOR_END "\033[0m"

extern void sdb_mainloop();

int main(int argc, char** argv) {

  std::string hexfile =
      "/home/hehe/ysyx-workbench/am-kernels/tests/cpu-tests/build/"
      "dummy-riscv32e-npc16.bin";  // 默认程序
  printf("argc:%d\r\n", argc);
  for (int i = 0; i < argc; i++) {
    std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
  }
  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];
    if (arg.find("+hexfile=") != std::string::npos) {
      hexfile = arg.substr(arg.find("+hexfile=") + 9);
    }
  }
  std::cout << "Hex file: " << hexfile << std::endl;

  sim_init();
  sim_reset_one_cycle();
  // Top__DOT__memory__DOT__mem_ext__DOT__Memory
  Top->io_coreRun = 0;
  load_memory_from_file(hexfile);
  single_cycle();	//更新mem状态
  Top->io_coreRun = 1;

	// excute_once();
	init_wp_pool();
	init_regex();
	init_disasm("riscv32-pc-linux-gnu");
	sdb_mainloop();

	// while (ebreak_flag == 0) {
  //   single_cycle();
  //   // printf("---exit:%d---\n",Top->io_exit);
  // }
  // for debug
  //   int sim_count = 5;
  //   for (int i = 0; i < sim_count; i++) {
  //     single_cycle();
  //   }

  // single_cycle();
  // printf("---exit:%d---\n",Top->io_exit);
  // single_cycle();
  // printf("---exit:%d---\n",Top->io_exit);

  printf(COLOR_GREEN);
  printf("NPC Sim Done\r\n");
  printf(COLOR_END);

  sim_exit();
}