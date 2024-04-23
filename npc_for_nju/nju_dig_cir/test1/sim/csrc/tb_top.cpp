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

  top->s=0b00;  top->a=0b11100011;  step_and_dump_wave();
                top->a=0b00010101;  step_and_dump_wave();
  top->s=0b01;  top->a=0b11101001;  step_and_dump_wave();
                top->a=0b00101110;  step_and_dump_wave();
  top->s=0b10;  top->a=0b10100001;  step_and_dump_wave();
                top->a=0b01001010;  step_and_dump_wave();
  top->s=0b11;  top->a=0b01110101;  step_and_dump_wave();
                top->a=0b10011011;  step_and_dump_wave();

  sim_exit();
}