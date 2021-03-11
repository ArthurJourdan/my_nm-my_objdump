/*
** EPITECH PROJECT, 2021
** get_function_architecture.c
** File description:
** check and get the file architecture, aka number of bits
*/

#include "nm.h"
#include "file_memory.h"

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