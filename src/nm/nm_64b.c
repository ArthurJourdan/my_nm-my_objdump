/*
** EPITECH PROJECT, 2021
** nm_64b.c
** File description:
** parsing of 64 bits files
*/

#include "my.h"
#include "nm.h"

static size_t get_nb_symbols(Elf64_Shdr *symbol_table)
{
    if (symbol_table->sh_entsize)
        return symbol_table->sh_size / symbol_table->sh_entsize;
    else
        return 0;
}

static symbol_t get_symbol(Elf64_Ehdr *header, Elf64_Shdr *section_header,
    Elf64_Shdr *symbol_table, Elf64_Sym symbol)
{
    symbol_t my_sym_print;
    char *my_sym_name = NULL;

    my_sym_name = (char *) ((size_t) header
        + section_header[symbol_table->sh_link].sh_offset);
    my_sym_name = &my_sym_name[symbol.st_name];
    my_sym_print.address = symbol.st_value;
    my_sym_print.type = get_symbol_char_64(symbol, section_header);
    my_sym_print.name = my_sym_name;
    return my_sym_print;
}

static symbol_t *get_symbols(Elf64_Ehdr *header, Elf64_Shdr *section_header,
    Elf64_Shdr *symbol_table, size_t nb_symbols)
{
    Elf64_Sym *my_symbols =
        (Elf64_Sym *) ((size_t) header + symbol_table->sh_offset);
    symbol_t *my_syms_print = calloc(sizeof(symbol_t), nb_symbols);

    if (!my_syms_print)
        return NULL;
    for (size_t i = 1; i < nb_symbols; i++) {
        my_syms_print[i] =
            get_symbol(header, section_header, symbol_table, my_symbols[i]);
    }
    return my_syms_print;
}

static Elf64_Shdr *get_symbol_table(Elf64_Ehdr *header, Elf64_Shdr *sections)
{
    for (size_t i = 0; i < header->e_shnum; i++) {
        if (sections[i].sh_type == SHT_SYMTAB) {
            return &sections[i];
        }
    }
    return NULL;
}

bool nm_64(void *header)
{
    Elf64_Ehdr *my_header = header;
    Elf64_Shdr *my_sections =
        (Elf64_Shdr *) ((size_t) header + my_header->e_shoff);
    Elf64_Shdr *my_symbol_table = get_symbol_table(my_header, my_sections);
    size_t my_nb_symbols = get_nb_symbols(my_symbol_table);
    symbol_t *my_syms_print = NULL;

    if (!my_symbol_table)
        return false;
    my_syms_print =
        get_symbols(header, my_sections, my_symbol_table, my_nb_symbols);
    sort_symbols_by_name(my_syms_print, my_nb_symbols);
    print_symbols(my_syms_print, my_nb_symbols);
    free(my_syms_print);
    return true;
}
