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

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// this should be enough
static char buf[65536] = {};
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format = "#include <stdio.h>\n"
                           "int main() { "
                           "  unsigned result = %s; "
                           "  printf(\"%%u\", result); "
                           "  return 0; "
                           "}";
static char *code_normal = "#include <stdio.h>\n"
                           "int main() { "
                           "  unsigned result = %s; "
                           "  printf(\"%%u\", result); "
                           "  return 0; "
                           "}";
static char *buf_ptr = buf;

int choose(int n) { return rand() % n; }

void gen(char c) {
  if (strlen(buf) + 1 < sizeof(buf)) {
    *buf_ptr++ = c;
  } else {
    // printf("overflow");
    return;
  }
}

static void gen_num() {
  int num = rand() % 9 + 1;
  char num_str[2];
  snprintf(num_str, sizeof(num_str), "%u", num);
  // num_str = '(num)';
  // printf("%c-%c",num_str[0],num_str[1]);
  gen(num_str[0]);
}

void gen_rand_op() {
  char ops[4] = {'+', '-', '*', '/'};
  int n = rand() % 4;
  gen(ops[n]);
}

static void gen_rand_expr() {
  switch (choose(3)) {
  // switch (0) {
  case 0:
    if (*(buf_ptr - 1) != ')') {
      gen_num();
    } else {
      gen_rand_expr();
    }
    break;
  case 1:
    if (strchr("+-*/", *(buf_ptr - 1))) {
      gen('(');
      gen_rand_expr();
      gen(')');
    } else {
      gen_rand_expr();
    }
    break;
  default:
    gen_rand_expr();
    gen_rand_op();
    gen_rand_expr();
    break;
  }
}

int main(int argc, char *argv[]) {
  int seed = time(0);
  srand(seed);
  int loop = 1;
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);
  }
  int i;
  for (i = 0; i < loop; i++) {
    // memset(buf,0,sizeof(buf));
    gen_rand_expr();
    // printf("\r\n");

    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc /tmp/.code.c -o /tmp/.expr");
    if (ret != 0)
      continue;

    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    int result;
    ret = fscanf(fp, "%d", &result);
    pclose(fp);

    if(result<0){
      i--;
      // printf("error,result less than zero");
    }else if(strlen(buf)<=32){
      printf("%u %s\n", result, buf);
    }else{
      i--;
    }
    // printf("%s\n",  buf);

    // printf("\r\nnums:%ld\r\n", strlen(buf));
    buf_ptr = buf;
    memset(buf, 0, sizeof(buf));
    memset(code_buf, 0, sizeof(code_buf));
    strcpy(code_format,code_normal);
  }
  // printf("\r\nnums:%ld\r\n", strlen(buf));

  return 0;
}
