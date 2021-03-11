/*
** EPITECH PROJECT, 2021
** get_symbol_char_64b.c
** File description:
** get character associated with symbol type
*/

#include "nm.h"

static char get_symbol_char_from_sym(Elf64_Sym sym)
{
    if (ELF64_ST_BIND(sym.st_info) == STB_GNU_UNIQUE)
        return 'u';
    if (ELF64_ST_BIND(sym.st_info) == STB_WEAK) {
        if (sym.st_shndx == SHN_UNDEF)
            return 'w';
        return 'W';
    }
    if (ELF64_ST_BIND(sym.st_info) == STB_WEAK
        && ELF64_ST_TYPE(sym.st_info) == STT_OBJECT) {
        if (sym.st_shndx == SHN_UNDEF)
            return 'v';
        return 'V';
    }
    if (sym.st_shndx == SHN_UNDEF)
        return 'U';
    if (sym.st_shndx == SHN_ABS)
        return 'A';
    if (sym.st_shndx == SHN_COMMON)
        return 'C';
    return '\0';
}

static char get_symbol_char_from_shdr(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    if (shdr[sym.st_shndx].sh_type == SHT_NOBITS
        && shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
        return 'B';
    if (shdr[sym.st_shndx].sh_type == SHT_PROGBITS
        && shdr[sym.st_shndx].sh_flags == SHF_ALLOC)
        return 'R';
    if (shdr[sym.st_shndx].sh_type == SHT_PROGBITS
        && shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
        return 'D';
    if (shdr[sym.st_shndx].sh_type == SHT_PROGBITS
        && shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_EXECINSTR))
        return 'T';
    if (shdr[sym.st_shndx].sh_type == SHT_DYNAMIC)
        return 'D';
    return '\0';
}

char get_symbol_char_64(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    char c;

    if ((c = get_symbol_char_from_sym(sym))) {
    } else if ((c = get_symbol_char_from_shdr(sym, shdr))) {
    } else {
        c = '?';
    }
    if (ELF64_ST_BIND(sym.st_info) == STB_LOCAL && c != '?')
        c += 32;
    return c;
}