#ifndef DISASM_H
#define DISASM_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// 初始化反汇编器
void init_disasm(const char *triple);

// 执行反汇编
void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);

#ifdef __cplusplus
}
#endif

#endif // DISASM_H
