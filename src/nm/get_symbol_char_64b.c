/*
** EPITECH PROJECT, 2021
** get_symbol_char_64b.c
** File description:
** get character associated with symbol type
*/

#include "nm.h"

static char get_symbol_char_from_sym(Elf64_Sym act_sym)
{
    if (ELF64_ST_BIND(act_sym.st_info) == STB_GNU_UNIQUE)
        return 'u';
    if (ELF64_ST_BIND(act_sym.st_info) == STB_WEAK) {
        if (ELF64_ST_TYPE(act_sym.st_info) == STT_OBJECT)
            return (act_sym.st_shndx == SHN_UNDEF) ? 'v' : 'v';
        return (act_sym.st_shndx == SHN_UNDEF) ? 'w' : 'W';
    }
    if (act_sym.st_shndx == SHN_UNDEF)
        return 'U';
    if (act_sym.st_shndx == SHN_ABS)
        return 'A';
    if (act_sym.st_shndx == SHN_COMMON)
        return 'C';
    return '\0';
}

static char get_symbol_char_from_shdr(Elf64_Sym act_sym, Elf64_Shdr *act_sect)
{
    if (act_sect[act_sym.st_shndx].sh_type == SHT_NOBITS
        && act_sect[act_sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
        return 'B';
    if (act_sect[act_sym.st_shndx].sh_type == SHT_PROGBITS
        && act_sect[act_sym.st_shndx].sh_flags == SHF_ALLOC)
        return 'R';
    if (act_sect[act_sym.st_shndx].sh_type == SHT_PROGBITS
        && act_sect[act_sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
        return 'D';
    if (act_sect[act_sym.st_shndx].sh_type == SHT_PROGBITS
        && act_sect[act_sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_EXECINSTR))
        return 'T';
    if (act_sect[act_sym.st_shndx].sh_type == SHT_DYNAMIC)
        return 'D';
    return '\0';
}

char get_symbol_char_64(Elf64_Sym act_sym, Elf64_Shdr *act_sect)
{
    char my_sym_char = '\0';

    my_sym_char = get_symbol_char_from_sym(act_sym);
    if (!my_sym_char)
        my_sym_char = get_symbol_char_from_shdr(act_sym, act_sect);
    if (!my_sym_char)
        my_sym_char = '?';
    if (ELF64_ST_BIND(act_sym.st_info) == STB_LOCAL && my_sym_char != '?')
        my_sym_char += 32;
    return my_sym_char;
}