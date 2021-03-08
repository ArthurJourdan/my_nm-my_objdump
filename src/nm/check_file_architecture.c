/*
** EPITECH PROJECT, 2021
** check_file_architecture.c
** File description:
** check and get the file architecture, aka number of bits
*/

#include "nm.h"

bool nm_64(void *header)
{
    return true;
}

bool nm_32(void *header)
{
    return true;
}

void *get_function_of_archi(void *header)
{
    int my_architecture = get_file_architecture(header);

    if (my_architecture == ELFCLASS64) {
        return &nm_64;
    } else if (my_architecture == ELFCLASS32) {
        return &nm_32;
    }
    return NULL;
}

int get_file_architecture(void *header)
{
    Elf32_Ehdr *address = header;

    return address->e_ident[EI_CLASS];
}