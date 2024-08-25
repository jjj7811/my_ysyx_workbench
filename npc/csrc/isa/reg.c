#include "reg.h"


const char *regs[] = {"$0", "ra", "sp",  "gp",  "tp", "t0", "t1", "t2",
                      "s0", "s1", "a0",  "a1",  "a2", "a3", "a4", "a5",
                      "a6", "a7", "s2",  "s3",  "s4", "s5", "s6", "s7",
                      "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"};

void isa_reg_display() {
	printf("pc:%x:\t%08x\t", cpu.pc,cpu.inst);
	disassemble(cpu.logbuf, 128,
              cpu.pc,
              (uint8_t *)&cpu.inst, 4);
	printf("%s\r\n",cpu.logbuf);
	// printf("\r\n");
  for (int i = 0; i < 32; i++) {
    // printf("%s:%d\r", regs[i], cpu.gpr[i]);
    printf("%s:0x%08x\t", regs[i], cpu.gpr[i]);
    if (i % 8 == 7)
      printf("\r\n");
  }
  printf("\r\n");
  // printf("pc:%x\r\n", cpu.pc);
}

word_t isa_reg_str2val(const char *s, bool *success) {
  // printf("%s\r\n", s + 1);
  for (int i = 0; i < 32; ++i) {
    if (strcmp(regs[i], s + 1) == 0) {
      // printf("match success:%s\r\n",regs[i]);
      *success = true;
      return cpu.gpr[i];
    }
  }
  if(strcmp("pc", s + 1) == 0){
    // printf("match pc\r\n");
    *success = true;
    return cpu.pc;
  }
  return 0;
}
