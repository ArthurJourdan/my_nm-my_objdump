/*
** EPITECH PROJECT, 2021
** get_function_architecture.c
** File description:
** check and get the file architecture, aka number of bits
*/

#include "nm.h"
#include "file_memory.h"

static void *get_function_of_archi(void *header)
{
    int my_architecture = get_file_architecture(header);

    if (my_architecture == ELFCLASS64) {
        return &nm_64;
    } else if (my_architecture == ELFCLASS32) {
        return &nm_32;
    }
    return NULL;
}

bool launch_architecture_nm(void *file_address)
{
    bool (*my_function)(void *) = get_function_of_archi(file_address);

    if (!my_function)
        return false;
    return my_function(file_address);
}
