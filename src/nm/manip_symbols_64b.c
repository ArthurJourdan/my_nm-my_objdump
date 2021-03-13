/*
** EPITECH PROJECT, 2021
** manip_symbols.c
** File description:
** manipulte symbol_t arrays
*/

#include "my.h"
#include "nm.h"

size_t get_nb_symbols_section_64(Elf64_Shdr symbol_table)
{
    if (symbol_table.sh_entsize)
        return symbol_table.sh_size / symbol_table.sh_entsize;
    else
        return 0;
}

size_t get_nb_symbols_64(Elf64_Ehdr *header, Elf64_Shdr *sections)
{
    size_t my_nb_symbols = 0;
    for (size_t i = 0; i < header->e_shnum; i++) {
        if (sections[i].sh_type == SHT_SYMTAB) {
            my_nb_symbols += get_nb_symbols_section_64(sections[i]);
        }
    }
    return my_nb_symbols;
}

symbol_t get_symbol_64(Elf64_Ehdr *header, Elf64_Shdr *section_header,
    Elf64_Shdr *symbol_table, Elf64_Sym symbol)
{
    symbol_t my_sym_print = {(size_t) -1, '\0', NULL};
    char *my_sym_name = my_sym_name = (char *) ((size_t) header
        + section_header[symbol_table->sh_link].sh_offset);

    my_sym_name = &my_sym_name[symbol.st_name];
    if (symbol.st_value || symbol.st_shndx != SHN_UNDEF)
        my_sym_print.value = symbol.st_value;
    my_sym_print.type = get_symbol_char_64(symbol, section_header);
    my_sym_print.name = my_sym_name;
    return my_sym_print;
}