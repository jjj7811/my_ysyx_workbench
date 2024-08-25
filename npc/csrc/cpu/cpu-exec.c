// #include "common.h"

// #include "sim_tool.h"
#include "cpu-exec.h"
// void excute(uint32_t n) {

// }
CPU_state cpu = {};
void execute(uint64_t n) {
  // Decode s;
  for (; n > 0; n--) {
    excute_once();
		if (nemu_state.state != NEMU_RUNNING) return;
    // exec_once(&s, cpu.pc);
    // g_nr_guest_inst++;
    // trace_and_difftest(&s, cpu.pc);
    // if (nemu_state.state != NEMU_RUNNING) break;
    // IFDEF(CONFIG_DEVICE, device_update());
  }
}

void excute_once() {
	char logbuf[128];
  // check_ebreak();
  switch (nemu_state.state) {
    case NEMU_END:
    case NEMU_ABORT:
      printf(
          "Program execution has ended. To restart the program, exit NEMU and "
          "run again.\n");
      return;
    default:
      nemu_state.state = NEMU_RUNNING;
  }

  // printf("\r\n brk:%d\r\n", nemu_state.state);
	check_ebreak();

	get_reg();
	isa_reg_display();
	check_diff_wp();

	// void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  // disassemble(logbuf, 128,
  //             cpu.pc,
  //             (uint8_t *)&cpu.inst, 4);

	// printf("logbuf:%s\r\n",logbuf);
	
  single_cycle();

	
	// cpu.pc = 

  // switch (nemu_state.state) {
  //   case NEMU_RUNNING:
  //     nemu_state.state = NEMU_STOP;
  //     break;

  //   case NEMU_END:
  //   case NEMU_ABORT:
	// 	// Log("nemu: %s at pc = " FMT_WORD,
  //   //       (nemu_state.state == NEMU_ABORT
  //   //            ? ANSI_FMT("ABORT", ANSI_FG_RED)
  //   //            : (nemu_state.halt_ret == 0
  //   //                   ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN)
  //   //                   : ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
  //   //       nemu_state.halt_pc);
  //     // printf("nemu: %s at pc = 0x%08d" ,"HIT GOOD TRAP",
  //     //     nemu_state.halt_pc);
  //     // fall through
  //   case NEMU_QUIT:
	// 	// return;
	// 	// break;
	// 	;
  //     // statistic();
  // }
}