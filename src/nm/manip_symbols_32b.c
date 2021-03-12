/*
** EPITECH PROJECT, 2021
** manip_symbols.c
** File description:
** manipulte symbol_t arrays
*/

#include "my.h"
#include "nm.h"

size_t get_nb_symbols_section_32(Elf32_Shdr symbol_table)
{
    if (symbol_table.sh_entsize)
        return symbol_table.sh_size / symbol_table.sh_entsize;
    else
        return 0;
}

size_t get_nb_symbols_32(Elf32_Ehdr *header, Elf32_Shdr *sections)
{
    size_t my_nb_symbols = 0;
    for (size_t i = 0; i < header->e_shnum; i++) {
        if (sections[i].sh_type == SHT_SYMTAB) {
            my_nb_symbols += get_nb_symbols_section_32(sections[i]);
        }
    }
    return my_nb_symbols;
}

symbol_t get_symbol_32(Elf32_Ehdr *header, Elf32_Shdr *section_header,
    Elf32_Shdr *symbol_table, Elf32_Sym symbol)
{
    symbol_t my_sym_print;
    char *my_sym_name = my_sym_name = (char *) ((size_t) header
        + section_header[symbol_table->sh_link].sh_offset);

    my_sym_name = &my_sym_name[symbol.st_name];
    my_sym_print.address = symbol.st_value;
    my_sym_print.type = get_symbol_char_32(symbol, section_header);
    my_sym_print.name = my_sym_name;
    return my_sym_print;
}