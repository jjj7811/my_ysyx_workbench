// #include "common.h"

// #include "sim_tool.h"
#include "cpu-exec.h"

uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0;

static void statistic() {
  setlocale(LC_NUMERIC, "");
#define NUMBERIC_FMT "%" PRIu64
  Log("Simple message");

  Log("host time spent = " NUMBERIC_FMT " us", g_timer);
  Log("total guest instructions = " NUMBERIC_FMT, g_nr_guest_inst);
  if (g_timer > 0)
    Log("simulation frequency = " NUMBERIC_FMT " inst/s",
        g_nr_guest_inst * 1000000 / g_timer);
  else
    Log("Finish running in less than 1 us and can not calculate the simulation "
        "frequency");
}

void assert_fail_msg() {
  isa_reg_display();
  // IFDEF(CONFIG_ITRACE,print_iringbuf());//CONFIG_ITRACE
  statistic();
}

// void excute(uint32_t n) {

// }
CPU_state cpu = {};
void execute(uint64_t n) {
  // Decode s;
  // uint64_t timer_start = get_time();
  for (; n > 0; n--) {
    uint64_t timer_start = get_time();
    excute_once();
    if (nemu_state.state != NEMU_RUNNING) return;
    // exec_once(&s, cpu.pc);
    g_nr_guest_inst++;
    // trace_and_difftest(&s, cpu.pc);
    // if (nemu_state.state != NEMU_RUNNING) break;
    // IFDEF(CONFIG_DEVICE, device_update());
    uint64_t timer_end = get_time();
    g_timer += timer_end - timer_start;
  }
  // uint64_t timer_end = get_time();
  // g_timer += timer_end - timer_start;
  // printf("g_timer:%d\r\n", g_timer);
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

  // void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int
  // nbyte);
  // disassemble(logbuf, 128,
  //             cpu.pc,
  //             (uint8_t *)&cpu.inst, 4);

  // printf("logbuf:%s\r\n",logbuf);

  single_cycle();

  // cpu.pc =

  switch (nemu_state.state) {
    case NEMU_RUNNING:
      // nemu_state.state = NEMU_STOP;
      break;

    case NEMU_END:
    case NEMU_ABORT:
      Log("nemu: %s at pc = " FMT_WORD,
          (nemu_state.state == NEMU_ABORT
               ? ANSI_FMT("ABORT", ANSI_FG_RED)
               : (nemu_state.halt_ret == 0
                      ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN)
                      : ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
          cpu.pc);
      // fall through
    case NEMU_QUIT:
      // return;
      // break;
      // ;
      statistic();
  }
}