/*
** EPITECH PROJECT, 2021
** get_file_architecture.c
** File description:
** check and get the file architecture, aka number of bits
*/

#include "file_memory.h"

int get_file_architecture(void *address)
{
    Elf32_Ehdr *header = address;

    if (!header)
        return -1;
    return header->e_ident[EI_CLASS];
}