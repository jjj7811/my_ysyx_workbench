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
  top->rst_n = 0b1; top->load = 0b1; top->seed = 0b00000001;
  single_cycle();
  top->load = 0b0;
  single_cycle();
  single_cycle();
  single_cycle();
                  
  sim_exit();
}