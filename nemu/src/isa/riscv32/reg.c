/*
 * @Author: jjj 2356765453@qq.com
 * @Date: 2024-04-14 16:16:39
 * @LastEditors: jjj 2356765453@qq.com
 * @LastEditTime: 2024-04-14 16:17:12
 * @FilePath: /ysyx-workbench/nemu/src/isa/riscv32/reg.c
 * @Description: 
 * 
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved.
 */
/***************************************************************************************
 * Copyright (c) 2014-2022 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan
 *PSL v2. You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 *KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 *NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

#include "local-include/reg.h"
#include <isa.h>

const char *regs[] = {"$0", "ra", "sp",  "gp",  "tp", "t0", "t1", "t2",
                      "s0", "s1", "a0",  "a1",  "a2", "a3", "a4", "a5",
                      "a6", "a7", "s2",  "s3",  "s4", "s5", "s6", "s7",
                      "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"};

void isa_reg_display() {
  for (int i = 0; i < 32; i++) {
    // printf("%s:%d\r", regs[i], cpu.gpr[i]);
    printf("%s:0x%x\t", regs[i], cpu.gpr[i]);
    if (i % 8 == 7)
      printf("\r\n");
  }
  printf("\r\n");
  printf("pc:%x\r\n", cpu.pc);
}

word_t isa_reg_str2val(const char *s, bool *success) {
  // printf("%s\r\n", s + 1);
  for (int i = 0; i < 32; ++i) {
    if (strcmp(regs[i], s + 1) == 0) {
      printf("match success:%s\r\n",regs[i]);
      *success = true;
      return cpu.gpr[i];
    }
  }
  if(strcmp("pc", s + 1) == 0){
    printf("match pc\r\n");
    *success = true;
    return cpu.pc;
  }
  return 0;
}
