/*
** EPITECH PROJECT, 2021
** get_file_architecture.c
** File description:
** check and get the file architecture, aka number of bits
*/

#include "file_memory.h"

int get_file_architecture(void *header)
{
    Elf32_Ehdr *address = header;

    return address->e_ident[EI_CLASS];
}