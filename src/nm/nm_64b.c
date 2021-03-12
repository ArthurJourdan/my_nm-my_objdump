/*
** EPITECH PROJECT, 2021
** nm_64b.c
** File description:
** parsing of 64 bits files
*/

#include "my.h"
#include "nm.h"

static symbol_t *get_section_symbols(
    Elf64_Ehdr *header, Elf64_Shdr *sections, Elf64_Shdr *symbol_table)
{
    Elf64_Sym *my_symbols =
        (Elf64_Sym *) ((size_t) header + symbol_table->sh_offset);
    size_t my_symbol_nb = get_nb_symbols_section_64(*symbol_table);
    symbol_t *my_syms_print = calloc(sizeof(symbol_t), my_symbol_nb);

    if (!my_symbols || !my_syms_print)
        return NULL;
    for (size_t i = 0; i < my_symbol_nb; i++) {
        my_syms_print[i] =
            get_symbol_64(header, sections, symbol_table, my_symbols[i]);
    }
    return my_syms_print;
}

static symbol_t *get_symbols(Elf64_Ehdr *header, Elf64_Shdr *sections)
{
    symbol_t *my_symbols = NULL;
    size_t my_nb_symbols = 0;
    symbol_t *my_tmp_symbols = NULL;
    size_t my_tmp_nb_symbols = 0;

    for (size_t i = 0; i < header->e_shnum; i++) {
        if (sections[i].sh_type == SHT_SYMTAB) {
            my_tmp_nb_symbols = get_nb_symbols_section_64(sections[i]);
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

bool nm_64(void *header)
{
    Elf64_Ehdr *my_header = header;
    Elf64_Shdr *my_sections =
        (Elf64_Shdr *) ((size_t) header + my_header->e_shoff);
    size_t my_nb_symbols = get_nb_symbols_64(my_header, my_sections);
    symbol_t *my_syms_print = get_symbols(my_header, my_sections);

    if (!my_syms_print)
        return false;
    sort_symbols_by_name(my_syms_print, my_nb_symbols);
    print_symbols(my_syms_print, my_nb_symbols);
    free(my_syms_print);
    return true;
}
