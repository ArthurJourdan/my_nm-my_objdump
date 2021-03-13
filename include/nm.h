/*
** EPITECH PROJECT, 2021
** nm.h
** File description:
** function prototypes for nm
*/

#ifndef NM_H_
#define NM_H_

#include <stdbool.h>
#include <stdlib.h>
#include <elf.h>
#include <fcntl.h>

typedef struct symbol_printing_infos
{
    size_t value;
    char type;
    char *name;
} symbol_t;

bool my_nms(int ac, char const *filepaths[]);
bool my_nm(bool print_filepath, const char *filepath);

bool launch_architecture_nm(void *file_address);

bool nm_64(void *header);
bool nm_32(void *header);

size_t get_nb_symbols_section_64(Elf64_Shdr symbol_table);
size_t get_nb_symbols_64(Elf64_Ehdr *header, Elf64_Shdr *sections);

size_t get_nb_symbols_section_32(Elf32_Shdr symbol_table);
size_t get_nb_symbols_32(Elf32_Ehdr *header, Elf32_Shdr *sections);

symbol_t *append_symbols(symbol_t *act_symbols, size_t my_act_symbol_nb,
    symbol_t *new_symbols, size_t my_new_symbol_nb);

symbol_t get_symbol_32(Elf32_Ehdr *header, Elf32_Shdr *section_header,
    Elf32_Shdr *symbol_table, Elf32_Sym symbol);
symbol_t get_symbol_64(Elf64_Ehdr *header, Elf64_Shdr *section_header,
    Elf64_Shdr *symbol_table, Elf64_Sym symbol);

char get_symbol_char_64(Elf64_Sym sym, Elf64_Shdr *shdr);
char get_symbol_char_32(Elf32_Sym sym, Elf32_Shdr *shdr);

void sort_symbols_by_name(symbol_t *symbols, size_t nb_symbols);

void print_symbols(symbol_t *symbols, size_t symbol_nb);
void print_symbol(symbol_t to_print);

#endif /* !NM_H_ */
