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
#include <sys/stat.h>
#include <sys/mman.h>
#include <elf.h>
#include <fcntl.h>

typedef struct symbol_printing_infos
{
    size_t address;
    char type;
    char *name;
} symbol_t;

bool my_nms(int ac, char const *filepaths[]);
bool my_nm(const char *filepath);

void release_file(void *address, struct stat stats);
void *load_file(const char *filepath, struct stat *stats);

bool check_file(const char *filepath, int fd, struct stat *stats);
int open_file(const char *filepath);

bool file_is_object(const char *filepath, void *file_address);
bool check_object_type(void *header);

bool nm_64(void *header);
bool nm_32(void *header);
void *get_function_of_archi(void *header);
int get_file_architecture(void *header);

char get_symbol_char(Elf64_Sym sym, Elf64_Shdr *shdr);

void print_symbols(symbol_t *symbols, size_t symbol_nb);
void print_symbol(symbol_t to_print);

#endif /* !NM_H_ */
