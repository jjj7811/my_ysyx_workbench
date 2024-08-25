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

#include <elf.h>
#include <isa.h>
#include <memory/paddr.h>

#include "trace.h"

void init_rand();
void init_log(const char *log_file);
void init_mem();
void init_difftest(char *ref_so_file, long img_size, int port);
void init_device();
void init_sdb();
void init_disasm(const char *triple);

static void welcome() {
  Log("Trace: %s", MUXDEF(CONFIG_TRACE, ANSI_FMT("ON", ANSI_FG_GREEN),
                          ANSI_FMT("OFF", ANSI_FG_RED)));
  IFDEF(CONFIG_TRACE,
        Log("If trace is enabled, a log file will be generated "
            "to record the trace. This may lead to a large log file. "
            "If it is not necessary, you can disable it in menuconfig"));
  Log("Build time: %s, %s", __TIME__, __DATE__);
  printf("Welcome to %s-NEMU!\n",
         ANSI_FMT(str(__GUEST_ISA__), ANSI_FG_YELLOW ANSI_BG_RED));
  printf("For help, type \"help\"\n");
  // Log("Exercise: Please remove me in the source code and compile NEMU
  // again."); assert(0);
}

#ifndef CONFIG_TARGET_AM
#include <getopt.h>

void sdb_set_batch_mode();

static char *log_file = NULL;
static char *diff_so_file = NULL;
static char *img_file = NULL;
static int difftest_port = 1234;

// ftrace_elf
static char *elf_file = NULL;

FuncInfo funcInfos[MAX_FUNC_COUNT];
int funcCount = 0;

// Function to read the section headers and find .strtab and .symtab
void read_section_headers(FILE *file, Elf32_Ehdr *ehdr, Elf32_Shdr **shdrs_out,
                          Elf32_Shdr **strtab_out, Elf32_Shdr **symtab_out) {
  // Seek to the section header table
  fseek(file, ehdr->e_shoff, SEEK_SET);

  // Allocate memory for the section headers
  Elf32_Shdr *shdrs = (Elf32_Shdr *)malloc(ehdr->e_shnum * sizeof(Elf32_Shdr));
  if (!shdrs) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }

  // Read the section headers
  if (fread(shdrs, sizeof(Elf32_Shdr), ehdr->e_shnum, file) != ehdr->e_shnum) {
    perror("fread");
    free(shdrs);
    exit(EXIT_FAILURE);
  }

  *shdrs_out = shdrs;

  // Initialize pointers to NULL
  *strtab_out = NULL;
  *symtab_out = NULL;

  // Find the .strtab and .symtab sections
  for (int i = 0; i < ehdr->e_shnum; i++) {
    if (shdrs[i].sh_type == SHT_STRTAB && i != ehdr->e_shstrndx) {
      *strtab_out = &shdrs[i];
    }
    if (shdrs[i].sh_type == SHT_SYMTAB) {
      *symtab_out = &shdrs[i];
    }
  }

  if (*strtab_out == NULL) {
    printf(".strtab section not found\n");
  }
  if (*symtab_out == NULL) {
    printf(".symtab section not found\n");
  }
}

// Function to find and store FUNC symbols from the .symtab section that are
// within .strtab address range
void find_func_symbols_within_strtab(FILE *file, Elf32_Shdr *symtab,
                                     Elf32_Shdr *strtab) {
  if (!symtab || !strtab) {
    printf("Required sections not found\n");
    return;
  }

  // Seek to the symbol table
  fseek(file, symtab->sh_offset, SEEK_SET);

  // Allocate memory for the symbols
  int num_symbols = symtab->sh_size / symtab->sh_entsize;
  Elf32_Sym *symbols = (Elf32_Sym *)malloc(symtab->sh_size);
  if (!symbols) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }

  // Read the symbols
  if (fread(symbols, symtab->sh_entsize, num_symbols, file) != num_symbols) {
    perror("fread");
    free(symbols);
    exit(EXIT_FAILURE);
  }

  // Seek to the string table
  fseek(file, strtab->sh_offset, SEEK_SET);

  // Allocate memory for the string table
  char *strtab_data = (char *)malloc(strtab->sh_size);
  if (!strtab_data) {
    perror("malloc");
    free(symbols);
    exit(EXIT_FAILURE);
  }

  // Read the string table
  if (fread(strtab_data, 1, strtab->sh_size, file) != strtab->sh_size) {
    perror("fread");
    free(symbols);
    free(strtab_data);
    exit(EXIT_FAILURE);
  }

  // Find and store FUNC symbols that are within the .strtab address range
  for (int i = 0; i < num_symbols; i++) {
    if (ELF32_ST_TYPE(symbols[i].st_info) == STT_FUNC) {
      char *name = &strtab_data[symbols[i].st_name];
      // Ensure the symbol name is within the .strtab address range
      if ((uintptr_t)name >= (uintptr_t)strtab_data &&
          (uintptr_t)name < (uintptr_t)strtab_data + strtab->sh_size) {
        if (funcCount < MAX_FUNC_COUNT) {
          strncpy(funcInfos[funcCount].name, name,
                  sizeof(funcInfos[funcCount].name) - 1);
          funcInfos[funcCount].name[sizeof(funcInfos[funcCount].name) - 1] =
              '\0';
          funcInfos[funcCount].address = symbols[i].st_value;
          funcInfos[funcCount].size = symbols[i].st_size;
          funcCount++;
        } else {
          printf("Function array is full\n");
        }
      }
    }
  }

  free(symbols);
  free(strtab_data);
}

void analyze_lef() {}

static long load_img() {
  if (img_file == NULL) {
    Log("No image is given. Use the default build-in image.");
    return 4096;  // built-in image size
  }

  FILE *fp = fopen(img_file, "rb");
  Assert(fp, "Can not open '%s'", img_file);

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);

  Log("The image is %s, size = %ld", img_file, size);
  FILE *file = fopen("/home/hehe/ysyx-workbench/am-kernels/tests/cpu-tests/build/dummy-riscv32-nemu.bin", "r");
  unsigned char buffer[16]; // 用于存储每次读取的16个字节
  size_t bytesRead;
  int i;
  // 读取并打印文件内容
  while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
    for (i = 0; i < bytesRead; i++) {
      printf("%02X ", buffer[i]);
    }
    printf("\n");
  }
  fseek(fp, 0, SEEK_SET);
  int ret = fread(guest_to_host(RESET_VECTOR), size, 1, fp);
  assert(ret == 1);

  fclose(fp);
  return size;
}

static int parse_args(int argc, char *argv[]) {
  const struct option table[] = {
      {"batch", no_argument, NULL, 'b'},
      {"log", required_argument, NULL, 'l'},
      {"diff", required_argument, NULL, 'd'},
      {"port", required_argument, NULL, 'p'},
      {"ftrace", required_argument, NULL, 'f'},
      {"help", no_argument, NULL, 'h'},
      {0, 0, NULL, 0},
  };
  int o;
  while ((o = getopt_long(argc, argv, "-bhl:d:p:f:", table, NULL)) != -1) {
    switch (o) {
      case 'b':
        sdb_set_batch_mode();
        break;
      case 'p':
        sscanf(optarg, "%d", &difftest_port);
        break;
      case 'l':
        log_file = optarg;
        // printf("log enable : %s\r\n",optarg);
        break;
      case 'd':
        diff_so_file = optarg;
        break;
      case 'f':
        elf_file = optarg;
        // printf("ftrace enable : %s\r\n",elf_file);
        break;
      case 1:
        img_file = optarg;
        return 0;
      default:
        printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
        printf("\t-b,--batch              run with batch mode\n");
        printf("\t-l,--log=FILE           output log to FILE\n");
        printf(
            "\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
        printf("\t-p,--port=PORT          run DiffTest with port PORT\n");
        printf("\t-f,--ftrace             enable ftrace\n");
        printf("\n");
        exit(0);
    }
  }
  return 0;
}

void read_elf() {
  // elf_file = "/home/hehe/ysyx-workbench/am-kernels/tests/cpu-tests/build/recursion-riscv32-nemu.elf";
  // 解析elf
  // FILE *file = fopen(
  //     "/home/hehe/ysyx-workbench/am-kernels/tests/cpu-tests/build/"
  //     "recursion-riscv32-nemu.elf",
  //     "rb");
  // printf("\nelf:%s\n",elf_file);
  FILE *file = fopen(elf_file,"rb");
  if (!file) {
    perror("fopen");
  }

  // Read the ELF header
  Elf32_Ehdr ehdr;
  if (fread(&ehdr, 1, sizeof(ehdr), file) != sizeof(ehdr)) {
    perror("fread");
    fclose(file);
  }

  // Check the ELF magic number
  if (memcmp(ehdr.e_ident, ELFMAG, SELFMAG) != 0) {
    fprintf(stderr, "Not an ELF file\n");
    fclose(file);
  }

  // Read the section headers and find .strtab and .symtab
  Elf32_Shdr *shdrs, *strtab, *symtab;
  read_section_headers(file, &ehdr, &shdrs, &strtab, &symtab);

  // Find and store FUNC symbols within .strtab range
  find_func_symbols_within_strtab(file, symtab, strtab);

  // Print the collected function information
  IFDEF(CONFIG_FTRACE,printf("---------Func_list-----------\n");
  for (int i = 0; i < funcCount; i++) {
    printf("FUNC: %s at address 0x%x with size %u\n", funcInfos[i].name,
           funcInfos[i].address, funcInfos[i].size);
  })
  // printf("---Func_list---\n");
  // for (int i = 0; i < funcCount; i++) {
  //   printf("FUNC: %s at address 0x%x with size %u\n", funcInfos[i].name,
  //          funcInfos[i].address, funcInfos[i].size);
  // }

  free(shdrs);
  fclose(file);
}

void init_monitor(int argc, char *argv[]) {
  /* Perform some global initialization. */

  /* Parse arguments. */
  parse_args(argc, argv);
  
  /*解析ELF文件*/
  IFDEF(CONFIG_FTRACE, read_elf());

  /* Set random seed. */
  init_rand();

  /* Open the log file. */
  init_log(log_file);

  /* Initialize memory. */
  init_mem();

  /* Initialize devices. */
  IFDEF(CONFIG_DEVICE, init_device());

  /* Perform ISA dependent initialization. */
  init_isa();

  /* Load the image to memory. This will overwrite the built-in image. */
  long img_size = load_img();

  /* Initialize differential testing. */
  init_difftest(diff_so_file, img_size, difftest_port);

  /* Initialize the simple debugger. */
  init_sdb();

#ifndef CONFIG_ISA_loongarch32r
  IFDEF(CONFIG_ITRACE,
        init_disasm(
            MUXDEF(CONFIG_ISA_x86, "i686",
                   MUXDEF(CONFIG_ISA_mips32, "mipsel",
                          MUXDEF(CONFIG_ISA_riscv,
                                 MUXDEF(CONFIG_RV64, "riscv64", "riscv32"),
                                 "bad"))) "-pc-linux-gnu"));
#endif

  /* Display welcome message. */
  welcome();
}
#else  // CONFIG_TARGET_AM
static long load_img() {
  extern char bin_start, bin_end;
  size_t size = &bin_end - &bin_start;
  Log("img size = %ld", size);
  memcpy(guest_to_host(RESET_VECTOR), &bin_start, size);
  return size;
}

void am_init_monitor() {
  init_rand();
  init_mem();
  init_isa();
  load_img();
  IFDEF(CONFIG_DEVICE, init_device());
  welcome();
}
#endif
