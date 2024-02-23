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

  top->en = 0b0;  top->x = 0b00;  step_and_dump_wave();
                  top->x = 0b01;  step_and_dump_wave();
                  top->x = 0b10;  step_and_dump_wave();
                  top->x = 0b11;  step_and_dump_wave();
  top->en = 0b1;  top->x = 0b000;  step_and_dump_wave();
                  top->x = 0b001;  step_and_dump_wave();
                  top->x = 0b010;  step_and_dump_wave();
                  top->x = 0b011;  step_and_dump_wave();
                  top->x = 0b100;  step_and_dump_wave();
                  top->x = 0b101;  step_and_dump_wave();
                  top->x = 0b110;  step_and_dump_wave();
                  top->x = 0b111;  step_and_dump_wave();
                  
  sim_exit();
}