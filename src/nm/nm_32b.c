/*
** EPITECH PROJECT, 2021
** nm_32b.c
** File description:
** parsing of 32 bits files
*/

#include "my.h"
#include "nm.h"

static symbol_t *get_section_symbols(
    Elf32_Ehdr *header, Elf32_Shdr *sections, Elf32_Shdr *symbol_table)
{
    Elf32_Sym *my_symbols =
        (Elf32_Sym *) ((size_t) header + symbol_table->sh_offset);
    size_t my_symbol_nb = get_nb_symbols_section_32(*symbol_table);
    symbol_t *my_syms_print = calloc(sizeof(symbol_t), my_symbol_nb);

    if (!my_symbols || !my_syms_print)
        return NULL;
    for (size_t i = 0; i < my_symbol_nb; i++) {
        my_syms_print[i] =
            get_symbol_32(header, sections, symbol_table, my_symbols[i]);
    }
    return my_syms_print;
}

static symbol_t *get_symbols(Elf32_Ehdr *header, Elf32_Shdr *sections)
{
    symbol_t *my_symbols = NULL;
    size_t my_nb_symbols = 0;
    symbol_t *my_tmp_symbols = NULL;
    size_t my_tmp_nb_symbols = 0;

    for (size_t i = 0; i < header->e_shnum; i++) {
        if (sections[i].sh_type == SHT_SYMTAB) {
            my_tmp_nb_symbols = get_nb_symbols_section_32(sections[i]);
            my_tmp_symbols =
                get_section_symbols(header, sections, &sections[i]);
            my_symbols = append_symbols(
                my_symbols, my_nb_symbols, my_tmp_symbols, my_tmp_nb_symbols);
            my_nb_symbols += my_tmp_nb_symbols;
            free(my_tmp_symbols);
        }
    }
    return my_symbols;
}

bool nm_32(void *header)
{
    Elf32_Ehdr *my_header = header;
    Elf32_Shdr *my_sections =
        (Elf32_Shdr *) ((size_t) header + my_header->e_shoff);
    size_t my_nb_symbols = get_nb_symbols_32(my_header, my_sections);
    symbol_t *my_syms_print = get_symbols(my_header, my_sections);

    if (!my_syms_print)
        return false;
    sort_symbols_by_name(my_syms_print, my_nb_symbols);
    print_symbols(my_syms_print, my_nb_symbols);
    free(my_syms_print);
    return true;
}
