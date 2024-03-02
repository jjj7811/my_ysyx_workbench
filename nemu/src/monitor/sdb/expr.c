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
#include <regex.h>

enum {
  TK_NOTYPE = 256,
  TK_EQ = 1,
  // L_par = 2,
  // R_par = 3,
  NUM = 4,

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

    {"==", TK_EQ}, // equal

    {"[0-9]*", NUM}, // number
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
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s", i,
            rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        switch (rules[i].token_type) {
        case '+':
          tokens[nr_token++].type = '+';
          // tokens[nr_token++] =
          break;
        case '-':
          tokens[nr_token++].type = '-';
          break;
        case '*':
          tokens[nr_token++].type = '*';
          break;
        case '/':
          tokens[nr_token++].type = '/';
          break;
        case '(':
          tokens[nr_token++].type = '(';
          break;
        case ')':
          tokens[nr_token++].type = ')';
          break;
        case NUM:
          tokens[nr_token].type = NUM;
          strncpy(tokens[nr_token++].str, e + position - substr_len,
                  substr_len);
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

bool check_parentheses(int p, int q) {
  if (tokens[p].type != '(' || tokens[q].type != ')') {
    return false;
  }
  while (p < q) {
    printf("p:%d q:%d\r\n", p, q);
    if (tokens[p].type == '(' && tokens[q].type == ')') {
      p++;
      q--;
    } else if (tokens[p].type == '(' && tokens[q].type != ')') {
      q--;
    } else if (tokens[p].type == ')') {
      return false;
    } else if (tokens[p].type != '(' && tokens[q].type == ')') {
      p++;
    } else if (tokens[p].type != '(' && tokens[q].type != ')') {
      p++;
    } else {
      p++;
    }
  }
  return true;
}

u_int32_t eval(int p, int q) {
  if (p > q) {
    /* Bad expression */
  } else if (p == q) {
    /* Single token.
     * For now this token should be a number.
     * Return the value of the number.
     */
  } else if (check_parentheses(p, q) == true) {
    /* The expression is surrounded by a matched pair of parentheses.
     * If that is the case, just throw away the parentheses.
     */
    printf("true\r\n");
    return eval(p + 1, q - 1);
  } else {
    /* We should do more things here. */
    printf("else\r\n");
  }
  return 0;
}

word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }
  for (int i = 0; i < nr_token; i++) {
    if (tokens[i].type == 42 || tokens[i].type == 43 || tokens[i].type == 45 ||
        tokens[i].type == 47 || tokens[i].type == 40 || tokens[i].type == 41)
      printf("tokens[%d]:\ttype:%c str:%s\r\n", i, tokens[i].type,
             tokens[i].str);
    else
      printf("tokens[%d]:\ttype:%d str:%s\r\n", i, tokens[i].type,
             tokens[i].str);
  }
  printf("nr_token:%d \r\n", nr_token);
  eval(0, nr_token);

  /* TODO: Insert codes to evaluate the expression. */
  // TODO();

  return 0;
}
