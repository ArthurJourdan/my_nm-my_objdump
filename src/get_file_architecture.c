/*
** EPITECH PROJECT, 2021
** get_file_architecture.c
** File description:
** check and get the file architecture, aka number of bits
*/

#include "file_memory.h"

bool launch_architecture(void *file_address)
{
    bool (*my_function)(void *) = get_function_of_archi(file_address);

    if (!my_function)
        return false;
    my_function(file_address);
    return true;
}

int get_file_architecture(void *header)
{
    Elf32_Ehdr *address = header;

    return address->e_ident[EI_CLASS];
}