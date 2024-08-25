#ifndef SIM_TOOL_H
#define SIM_TOOL_H

#include <stdio.h>

#include "VTop.h"
#include "VTop___024root.h"
// #include "sim_tool.h"
#include <ncurses.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "verilated.h"
#include "verilated_vcd_c.h"

#include "utils.h"
#include "debug.h"
// #define COLOR_GREEN "\033[32m"
// #define COLOR_END "\033[0m"

extern VerilatedContext* contextp;
extern VerilatedVcdC* tfpL;

extern VTop* Top;

extern volatile int ebreak_flag;

void step_and_dump_wave();

void single_cycle();

void sim_init();

void sim_exit();

void sim_reset_one_cycle();

void check_ebreak();

// static void ebreak() {
//   ebreak_flag = 1;
//   // printf(COLOR_GREEN);
//   // printf("excute the ebreak inst\r\n");
//   // printf(COLOR_END);

//   // printf(COLOR_END);
//   // hit_exit(cpu_gpr[10]);
// }

// extern "C" {

// void ebreak() {
//   ebreak_flag = 1;
//   // printf(COLOR_GREEN);
//   // printf("excute the ebreak inst\r\n");
//   // printf(COLOR_END);

//   // printf(COLOR_END);
//   // hit_exit(cpu_gpr[10]);
// }

// }

void load_memory_from_file(const std::string& filename) ;

extern CPU_state cpu;


// void get_pc();

void get_reg();
uint32_t get_inst();

#endif