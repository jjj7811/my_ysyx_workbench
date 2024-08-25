/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include "host.h"
#include "paddr.h"
// #include <device/mmio.h>
// #include <isa.h>
#include "sim_tool.h"
#include <debug.h>


#if   defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
// static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#endif



uint8_t* guest_to_host(paddr_t paddr) { return &Top->rootp->Top__DOT__memory__DOT__mem_ext__DOT__Memory[0] + paddr - CONFIG_MBASE; }
// paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

// // 读取mem时进行mtrace
// void mem_trace_read(paddr_t addr, int len , word_t data){
//   // printf("this is mrtrace test\r\n");
//   printf(ANSI_FMT("read_addr:  ", ANSI_FG_BLUE) FMT_PADDR "\tlen: %d\tdata:0x%x\n", addr, len,data);
// }

// // 写入mem时进行mtrace
// void mem_trace_write(paddr_t addr, int len , word_t data){
//   // printf("this is mrtrace test\r\n");
//   printf(ANSI_FMT("write_addr: ", ANSI_FG_YELLOW) FMT_PADDR "\tlen: %d\tdata:%x\n", addr, len,data);
// }

static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
}

static void out_of_bound(paddr_t addr) {
  panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
      addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
}

void init_mem() {
#if   defined(CONFIG_PMEM_MALLOC)
  pmem = malloc(CONFIG_MSIZE);
  assert(pmem);
#endif
  // IFDEF(CONFIG_MEM_RANDOM, memset(pmem, rand(), CONFIG_MSIZE));
  // Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
}
#define likely(cond)   __builtin_expect(cond, 1)
#define unlikely(cond) __builtin_expect(cond, 0)
word_t paddr_read(paddr_t addr, int len) {
  // IFDEF(CONFIG_MTRACE,mem_trace_read(addr,len,pmem_read(addr, len)));
  if (likely(in_pmem(addr))) return pmem_read(addr, len);
  // IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  out_of_bound(addr);
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
  // IFDEF(CONFIG_MTRACE,mem_trace_write(addr,len,pmem_read(addr, len)));
  if (likely(in_pmem(addr))) { pmem_write(addr, len, data); return; }
  // IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  out_of_bound(addr);
}
