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

#include "sdb.h"
#include <common.h>
#include <cpu/cpu.h>
#include <isa.h>
#include <memory/paddr.h>
#include <readline/history.h>
#include <readline/readline.h>

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();
void disp_info_w();

/* We use the `readline' library to provide more flexibility to read from stdin.
 */
static char *rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}

static int cmd_q(char *args) {
  // cpu_exec(4);
<<<<<<< HEAD
  //在这里将状态切换即可，之前把默认值改了，是不对的。
  nemu_state.state = NEMU_QUIT;
=======
>>>>>>> main
  return -1;
}

static int cmd_si(char *args) {
  char *arg = strtok(NULL, " ");
  if (arg != NULL) {
    int i = atoi(arg);
    cpu_exec(i);
    printf("exec:%d times\r\n", i);
  } else {
    cpu_exec(1);
    printf("exec:%d times\r\n", 1);
  }
  return 0;
}

static int cmd_info(char *args) {
  // cpu_exec(4);
  char *arg = strtok(NULL, " ");
  if (arg == NULL) {
    printf("wrong args\r\n");
  } else if (strcmp(arg, "r") == 0) {
    printf("print args\r\n");
    isa_reg_display();
  } else if (strcmp(arg, "w") == 0) {
<<<<<<< HEAD
    disp_info_w();
=======
    printf("Not yet implemented\r\n");
>>>>>>> main
  }
  return 0;
}

static int cmd_x(char *args) {
  char *N = strtok(NULL, " ");
  char *addr = strtok(NULL, " ");
  int n = 0;
  paddr_t paddr = 0;
  if (N == NULL || addr == NULL) {
    printf("Wrong args\r\n");
  } else {
    sscanf(N, "%u", &n);
    sscanf(addr, "%x", &paddr);
    for (int i = 0; i < n; i++) {
      word_t t = paddr_read(paddr + i * 4, 4);
      printf("%u 0x%x : 0x%x\r\n", n, paddr + i * 4, t);
    }
  }
<<<<<<< HEAD
  return 0;
}

static int cmd_p(char *args) {
  char *cmd = strtok(NULL, " ");
  // printf("test:%s\r\n",cmd);
  bool success = 1;
  uint32_t value;
  value = expr(cmd, &success);
  if (success == false)
    printf("something is wrong,check your expression:\r\n");
  else
    printf("Value:%x\r\n", value);
  return 0;
}

static int cmd_pp(char *args) {
  FILE *fp;
  char str[50];
  fp = fopen("input", "r");
  if (fp == NULL) {
    printf("Unable to open file.\n");
    return 1;
  }
  bool succ = 0;
  char value[50];
  uint32_t nemu_value = 0;
  char cmd[50];
  bool b = 1;
  int right_cnt = 0;
  // printf("%d",succ);
  for (int i = 0; i < 100; i++) {
    // succ = fscanf(fp, "%[^\n]", str);
    succ = fgets(str, 50, fp);
    str[strcspn(str, "\n")] = 0;
    if (succ != 0) {
      // b = 1;
      strcpy(value, strtok(str, " "));
      strcpy(cmd, strtok(NULL, " "));
      nemu_value = expr(cmd, &b);

      if (atoi(value) == nemu_value) {
        right_cnt++;
      } else {
        Log("here is a error,maybe because 中间结果是负数，而要求NEMU使用unsigned\r\n");
      }

      printf("exp : %20s\t", cmd);
      printf("golden value : %5s\t", value);
      printf("nemu value: %5d\r\n", nemu_value);
    }
  }
  printf("right cnt:%d\r\n", right_cnt);
  fclose(fp);
  return 0;
}

static int cmd_w(char *args) {
  uint32_t NO = 0;
  NO = set_watchpoint(args);
  printf("NO:%d\r\n", NO);
  return 0;
}

static int cmd_d(char *args) {
  char *char_no = strtok(NULL, " ");
  uint32_t NO = atoi(char_no);
  printf("NO:%d\r\n", NO);
  ;
  bool success = del_watchpoint(NO);
  if (success) {
    printf("Success del watchpoint NO: %d\r\n", NO);
  } else {
    printf("your watchpoint is not exist\r\n");
  }
=======

>>>>>>> main
  return 0;
}

static int cmd_help(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler)(char *);
} cmd_table[] = {
    {"help", "Display information about all supported commands", cmd_help},
    {"c", "Continue the execution of the program", cmd_c},
    {"q", "Exit NEMU", cmd_q},
    {"si", "exec once", cmd_si},
    {"info", "print the state of program", cmd_info},
    {"x", "print N values on the addr", cmd_x},
<<<<<<< HEAD
    {"p", "Expression evaluation", cmd_p},
    {"pp", "test for exp", cmd_pp},
    {"w", "set watchpoint", cmd_w},
    {"d", "set watchpoint", cmd_d},
=======
>>>>>>> main

    /* TODO: Add more commands */

};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  } else {
    for (i = 0; i < NR_CMD; i++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode() { is_batch_mode = true; }

void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL;) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) {
      continue;
    }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) {
          return;
        }
        break;
      }
    }

    if (i == NR_CMD) {
      printf("Unknown command '%s'\n", cmd);
    }
  }
}

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
