#include <common.h>

typedef struct {
  word_t gpr[32];
  vaddr_t pc;
	uint32_t inst;
	char logbuf[128];
} riscv32_CPU_state;

typedef riscv32_CPU_state CPU_state;