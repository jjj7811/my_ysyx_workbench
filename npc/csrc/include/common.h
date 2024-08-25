#ifndef __COMMON_H__
#define __COMMON_H__

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include <macro.h>

#include "generated/autoconf.h"
// #include <debug.h>
// #include <isa/isa-def.h>

// #define COLOR_GREEN "\033[32m"
// #define COLOR_END "\033[0m"

// #include "sim_tool.h"


typedef uint16_t half_word ;
typedef uint32_t word_t ;
typedef int32_t	sword_t;

typedef word_t vaddr_t;
typedef uint32_t paddr_t;
typedef uint16_t ioaddr_t;

#define FMT_WORD MUXDEF(CONFIG_ISA64, "0x%016" PRIx64, "0x%08" PRIx32)

#define FMT_PADDR MUXDEF(PMEM64, "0x%016" PRIx64, "0x%08" PRIx32)


// CPU_state cpu = {};


#endif