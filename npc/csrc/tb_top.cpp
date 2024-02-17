#include "Vtop.h"
#include "verilated.h"
#include <verilated_vcd_c.h>
#include <stdlib.h>
#include <iostream>


#define MAX_SIM_TIME 30
vluint64_t sim_time = 0;

int main(int argc, char** argv) {
	// VerilatedContext* contextp = new VerilatedContext;
  // contextp->commandArgs(argc, argv);
  // Vtop* top = new Vtop{contextp};
  Verilated::commandArgs(argc, argv);
  Vtop *top = new Vtop;

  Verilated::traceEverOn(true);
  VerilatedVcdC *m_trace = new VerilatedVcdC;
  top->trace(m_trace, 5);
  m_trace->open("waveform.vcd");

  int i =10;
  while (sim_time<MAX_SIM_TIME) {
		int a = rand() & 1;
    int b = rand() & 1;
    top->a = a;
    top->b = b;
    top->eval();
    printf("a = %d, b = %d, c = %d\n", a, b, top->f);
    assert(top->f == (a ^ b));

    m_trace->dump(sim_time);
    sim_time++;
   }
  top->final();
  m_trace->close();
  delete top;
  return 0;
}

