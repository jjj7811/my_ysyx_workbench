#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vtop.h"

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vtop* top;

void step_and_dump_wave(){
  top->eval();
  contextp->timeInc(1);
  tfp->dump(contextp->time());
}

static void single_cycle() {
  top->clk = 0; step_and_dump_wave();
  top->clk = 1; step_and_dump_wave();
}

void sim_init(){
  contextp = new VerilatedContext;
  tfp = new VerilatedVcdC;
  top = new Vtop;
  contextp->traceEverOn(true);
  top->trace(tfp, 0);
  tfp->open("waveform.vcd");
}

void sim_exit(){
  step_and_dump_wave();
  tfp->close();
}

int main() {
  sim_init();
  top->a = 0b001; top->b = 0b0101;  top->op = 0b0;
  single_cycle();
  // step_and_dump_wave();
  // top->A = 0b0100; top->B = 0b0010; top->Ci = 0b0;
  // step_and_dump_wave();
  // top->A = 0b0011; top->B = 0b0101; top->Ci = 0b0;
  // step_and_dump_wave();
  // top->A = 0b1110; top->B = 0b0010; top->Ci = 0b1;
  // step_and_dump_wave();
  // top->A = 0b1010; top->B = 0b0000; top->Ci = 0b1;
  // step_and_dump_wave();

                  
  sim_exit();
}