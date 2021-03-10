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
    size_t address;
    char type;
    char *name;
} symbol_t;

bool my_nms(int ac, char const *filepaths[]);
bool my_nm(bool print_filepath, const char *filepath);

bool nm_64(void *header);
bool nm_32(void *header);

char get_symbol_char_64(Elf64_Sym sym, Elf64_Shdr *shdr);
char get_symbol_char_32(Elf32_Sym sym, Elf32_Shdr *shdr);

void sort_symbols_by_name(symbol_t *symbols, size_t nb_symbols);

void print_symbols(symbol_t *symbols, size_t symbol_nb);
void print_symbol(symbol_t to_print);

#endif /* !NM_H_ */
