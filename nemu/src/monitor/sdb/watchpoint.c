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

// 监视点个数
#define NR_WP 32

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;

  /* TODO: Add more members if necessary */
  char expr
      [128]; // 表达式是不变的，而值有可能变化，每次重新求表达式的值并进行比较即可。
  uint32_t value; // 上一时刻该监视点的值。

} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;
// static int wp_cnts = 0;
void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
    memset(wp_pool[i].expr, 0, 128);
    wp_pool[i].value = 0;
  }

  head = NULL;
  free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */
// free_链表里面存储NR_WP个监视点池，执行该函数将从池中取出一个监视点并返回。
// 从头取出
WP *new_wp() {
  if (free_ != NULL) {
    WP *p = free_;
    free_ = free_->next;
    return p;
  } else {
    printf("监视点已用完\r\n");
    assert(0);
  }
}

// 前插链表，将free的节点插入开头，并且释放expr表达式和value
void free_wp(WP *p) {
  strcpy(p->expr, "");
  p->value = 0;
  p->next = free_;
  free_ = p;
}

// 调用new_wp取出一个监视点，将监视点插入head链表中
uint32_t set_watchpoint(char *args) {
  bool success;
  WP *p = new_wp();

  // 赋值该监视点相关状态
  strcpy(p->expr, args);
  p->value = expr(args, &success);
  p->next = head;
  head = p; // 加入head链表

  // 打印监视点状态
  printf("p-expr:%s\t", p->expr);
  printf("value:%d\r\n", p->value);
  return p->NO;
}

bool del_watchpoint(int NO) {
  WP *p, *pre;
  p = head;
  pre = NULL;
  // 此时p指向要删除的节点，pre指向前一个节点
  while (p != NULL) {
    if (p->NO == NO) {
      break;
    }
    pre = p;
    p = p->next;
  }
  if (p == NULL) {
    // printf("cant find the watchpoint \r\n");
    return 0;
  } else if (p->NO == NO) {
    // 此时p就是在开头，pre空指针。
    if (pre == NULL) {
      head = p->next;
    } else {
      pre->next = p->next;
    }
    free_wp(p);
    return 1;
  } else {
    return 0;
  }
}

// cpu-exec中检查监视点是否变化
void check_diff_wp() {
  WP *p;
  p = head;
  bool success = 1; // expr若成功不给success置位1，只有失败置0.
  while (p != NULL) {
    // printf("expr:%s\r\n",p->expr);
    uint32_t new_value = expr(p->expr, &success);
    printf("new_value:%d", new_value);
    if (success == false) {
      printf("Watchpoint:%d's expr is valid\r\n", p->NO);
    } else if (new_value != p->value) {
      printf("NO:%d:new_value:%d\told_value:%d\r\n", p->NO, new_value,
             p->value);
      p->value = new_value;
      nemu_state.state = NEMU_STOP;
    }
    p = p->next;
  }
}

// 打印监视点信息
void disp_info_w() {
  WP *p;
  p = head;
  while (p != NULL) {
    printf("NO:%2d\texpr:%20s\t,value_now:%10d\r\n", p->NO, p->expr, p->value);
    p = p->next;
  }
}