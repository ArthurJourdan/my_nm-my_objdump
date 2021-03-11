/*
** EPITECH PROJECT, 2021
** objdump.h
** File description:
** function prototypes for objdump
*/

#ifndef OBJDUMP_H_
#define OBJDUMP_H_

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

bool my_objdumps(int ac, char const *filepaths[]);
bool my_objdump(const char *filepath);

bool objdump_64(void *header);
bool objdump_32(void *header);

char *get_section_name(
    Elf64_Ehdr *header, Elf64_Shdr *sections, Elf64_Shdr *act_section);
void print_section_name(
    Elf64_Ehdr *header, Elf64_Shdr *sections, Elf64_Shdr *act_section);

void print_section_body(Elf64_Ehdr *header, Elf64_Shdr *act_section);

#endif /* !OBJDUMP_H_ */
