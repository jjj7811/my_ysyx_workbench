#include <stdint.h>
#include <elf.h>

#define MAX_FUNC_COUNT 100

// Define a structure to hold function information
typedef struct {
    char name[256];  // Function name
    uint32_t address;  // Function address
    uint32_t size;  // Function size
} FuncInfo;

// Declare the global array to hold function information
extern FuncInfo funcInfos[MAX_FUNC_COUNT];
extern int funcCount;

// Declare functions to read section headers and find FUNC symbols
void read_section_headers(FILE *file, Elf32_Ehdr *ehdr, Elf32_Shdr **shdrs_out, Elf32_Shdr **strtab_out, Elf32_Shdr **symtab_out);
void find_func_symbols_within_strtab(FILE *file, Elf32_Shdr *symtab, Elf32_Shdr *strtab);

