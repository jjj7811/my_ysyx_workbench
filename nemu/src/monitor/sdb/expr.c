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

#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <memory/paddr.h>
#include <regex.h>

enum {
  TK_NOTYPE = 256,
  TK_EQ = 1,
  TK_NEQ = 2,
  TK_AND = 3,
  TK_OR = 4,
  // L_par = 2,
  // R_par = 3,
  NUM = 5,
  REG = 6,
  POINTER = 7,
  MINUS = 8,
  HEX_NUM = 9,

  /* TODO: Add more token types */

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

    /* TODO: Add more rules.
     * Pay attention to the precedence level of different rules.
     */

    {" +", TK_NOTYPE}, // spaces

    {"\\+", '+'}, // plus
    {"\\-", '-'}, // sub
    {"\\*", '*'}, // mux
    {"\\/", '/'}, // div

    {"\\(", '('}, // left parenthesis
    {"\\)", ')'}, // right parenthesis

    {"==", TK_EQ},  // equal
    {"!=", TK_NEQ}, // no equal
    {"&&", TK_AND}, //&&
    {"\\|\\|", TK_OR},
    {"\\$[a-zA-Z]*[0-9]", REG}, // reg

    {"[0-9]*", NUM},                // number
    {"0[xX][0-9a-fA-F]+", HEX_NUM}, // HEX

};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[32] __attribute__((used)) = {};
static int nr_token __attribute__((used)) = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 &&
          pmatch.rm_so == 0) {
        // char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        // Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s", i,
        //     rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;
        // printf("switch:%d\r\n",rules[i].token_type);

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        switch (rules[i].token_type) {
        case '+':
          tokens[nr_token].type = '+';
          strncpy(tokens[nr_token++].str, e + position - substr_len,
                  substr_len);
          break;
        case '-':
          tokens[nr_token].type = '-';
          strncpy(tokens[nr_token++].str, e + position - substr_len,
                  substr_len);
          break;
        case '*':
          tokens[nr_token].type = '*';
          strncpy(tokens[nr_token++].str, e + position - substr_len,
                  substr_len);
          break;
        case '/':
          tokens[nr_token].type = '/';
          strncpy(tokens[nr_token++].str, e + position - substr_len,
                  substr_len);
          break;
        case '(':
          tokens[nr_token].type = '(';
          strncpy(tokens[nr_token++].str, e + position - substr_len,
                  substr_len);
          break;
        case ')':
          tokens[nr_token].type = ')';
          strncpy(tokens[nr_token++].str, e + position - substr_len,
                  substr_len);
          break;
        case NUM:
          tokens[nr_token].type = NUM;
          strncpy(tokens[nr_token++].str, e + position - substr_len,
                  substr_len);
          break;
        case HEX_NUM:
          tokens[nr_token].type = HEX_NUM;
          strncpy(tokens[nr_token++].str, e + position - substr_len,
                  substr_len);
          break;
        case TK_EQ:
          tokens[nr_token].type = TK_EQ;
          strncpy(tokens[nr_token++].str, e + position - substr_len,
                  substr_len);
          break;
        case TK_NEQ:
          tokens[nr_token].type = TK_NEQ;
          strncpy(tokens[nr_token++].str, e + position - substr_len,
                  substr_len);
          break;
        case TK_AND:
          tokens[nr_token].type = TK_AND;
          strncpy(tokens[nr_token++].str, e + position - substr_len,
                  substr_len);
          break;
        case TK_OR:
          // printf("OR:\r\n");
          tokens[nr_token].type = TK_OR;
          strncpy(tokens[nr_token++].str, e + position - substr_len,
                  substr_len);
          break;
        case REG:
          // printf("REG:\r\n");
          tokens[nr_token].type = REG;
          strncpy(tokens[nr_token++].str, e + position - substr_len,
                  substr_len);
          break;
        default:
          // TODO();
        }

        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}

int op_pri(int op_type) {
  switch (op_type) {
  case '+':
    return 4;
  case '-':
    return 4;
  case '*':
    return 3;
  case '/':
    return 3;
  case TK_EQ:
    return 7;
  case TK_NEQ:
    return 7;
  case TK_AND:
    return 11;
  case TK_OR:
    return 12;
  case MINUS:
    return 2;
  case POINTER:
    return 2;
  default:
    printf("Undefine oprator\n");
    printf("type:%d\r\n", op_type);
    return 0;
    // assert(0);
  }
}

int find_main_op(int p, int q) {
  int op_arry[256] = {0};
  int pp = p;
  int arry_ptr = 0;
  int main_op;
  int op_tep_pri = 0;
  int cnts = 0;
  while (pp <= q) {
    if (tokens[pp].type == '(') {
      cnts++;
    } else if (tokens[pp].type == ')') {
      cnts--;
    } else if (cnts == 0 && tokens[pp].type != NUM) {
      op_arry[arry_ptr] = pp;
      arry_ptr++;
    }
    pp++;
  }
  main_op = op_arry[0];
  for (int i = 0; i < arry_ptr; i++) {
    op_tep_pri = op_pri(tokens[op_arry[i]].type);
    if (op_pri(tokens[main_op].type) <= op_tep_pri) {
      main_op = op_arry[i];
    }
  }
  // for (int i = 0; i < 10; i++) {
  //   printf("op_arry:%d\t", op_arry[i]);
  // }
  // printf("\r\nmain_op:%d\r\n", main_op);
  return main_op;
}

// bool check_parentheses(int p, int q, bool *success) {
//   if (tokens[p].type != '(' || tokens[q].type != ')') {
//     // *success = false;
//     return false;
//   }
//   while (p <= q) {
//     // printf("p:%d q:%d\r\n", p, q);
//     if (tokens[p].type == '(') {
//       if (tokens[q].type == ')') {
//         p++;
//         q--;
//       } else if (p == q) {
//         *success = false;
//         return false;
//       } else {
//         p++;
//       }

//     } else if (tokens[p].type == ')') {
//       *success = false;
//       return false;
//     } else
//       p++;
//   }
//   return true;
// }

bool check_parentheses(int p, int q, bool *success) {
  // printf("%d %d\r\n",p,q);
  int cnt = 0;
  if (tokens[p].type != '(' || tokens[q].type != ')') {
    // *success = false;
    return false;
  }
  for (int i = p; i <= q; i++) {
    if (tokens[i].type == '(') {
      cnt++;
    } else if (tokens[i].type == ')') {
      cnt--;
    }
    if (cnt == 0 && i != q) {
      success = 0;
      return false;
    }
  }
  // printf("cnt:%d\r\n",cnt);
  if (cnt == 0) {

    // *success = True;
    return true;
  }

  return true;
}

u_int32_t eval(int p, int q, bool *success) {
  int main_op;
  if (p > q) {
    /* Bad expression */
    assert(0);
  } else if (p == q) {
    if (tokens[p].type == REG) {
      bool t = true;
      u_int32_t num = isa_reg_str2val(tokens[p].str, &t);
      if (!t) {
        *success = false;
        num = 0;
      } else {
        return num;
      }
    } else if (tokens[p].type == NUM) {
      return atoi(tokens[p].str);
    } else if (tokens[p].type == HEX_NUM) {
      uint32_t tmp = 0;
      sscanf(tokens[p].str, "%x", &tmp);
      return tmp;
    }
    /* Single token.
     * For now this token should be a number.
     * Return the value of the number.
     */
    // printf("singal token\r\n");

  } else if (check_parentheses(p, q, success) == true) {
    /* The expression is surrounded by a matched pair of parentheses.
     * If that is the case, just throw away the parentheses.
     */
    // printf("right expression,here we go!\r\n");
    return eval(p + 1, q - 1, success);
  } else {
    /* We should do more things here. */
    // printf("else\r\n");
    main_op = find_main_op(p, q);

    if (tokens[main_op].type == MINUS) {
      // printf("minus\r\n");
      u_int32_t val = eval(main_op + 1, q, success);
      return 0 - val;
    } else if (tokens[main_op].type == POINTER) {
      u_int32_t val = eval(main_op + 1, q, success);
      return paddr_read(val, 4);
    } else {
      // printf("else\r\n");
      u_int32_t val1 = eval(p, main_op - 1, success);
      u_int32_t val2 = eval(main_op + 1, q, success);

      switch (tokens[main_op].type) {
      case '+':
        return val1 + val2;
        break;
      case '-':
        return val1 - val2;
        break;
      case '*':
        return val1 * val2;
        break;
      case '/':
        return val1 / val2;
        break;
      case TK_EQ:
        return val1 == val2;
        break;
      case TK_NEQ:
        return val1 != val2;
        break;
      case TK_AND:
        return val1 && val2;
        break;
      case TK_OR:
        return val1 || val2;
        break;
      case MINUS:
        // printf("minus\r\n");
        return 0 - val2;
        break;
      default:
        printf("wrong op\r\n");
        break;
      }
    }
  }
  return 0;
}

word_t expr(char *e, bool *success) {
  // printf("make_token\r\n");
  if (!make_token(e)) {
    *success = false;
    return 0;
  }
  for (int i = 0; i < nr_token; i++) {
    if (tokens[i].type == '*' &&
        (i == 0 || (tokens[i - 1].type != NUM && tokens[i - 1].type != REG &&
                    tokens[i - 1].type != ')'))) {
      tokens[i].type = POINTER;
    }
    if (tokens[i].type == '-' &&
        (i == 0 || (tokens[i - 1].type != NUM && tokens[i - 1].type != REG &&
                    tokens[i - 1].type != ')'))) {
      tokens[i].type = MINUS;
    }
  }

  // for (int i = 0; i < nr_token; i++) {
  //   int ty = tokens[i].type;
  //   if (ty == 42 || ty == 43 || ty == 45 || ty == 47 || ty == 40 || ty == 41)
  //     printf("tokens[%d]:\ttype:%c str:%s\r\n", i, ty, tokens[i].str);
  //   else
  //     printf("tokens[%d]:\ttype:%d str:%s\r\n", i, tokens[i].type,
  //            tokens[i].str);
  // }
  // printf("nr_token:%d \r\n", nr_token);
  int ev = eval(0, nr_token - 1, success);
  printf("value: %d\r\n", ev);
  /* TODO: Insert codes to evaluate the expression. */
  // TODO();s

  return ev;
}
