/*
** EPITECH PROJECT, 2021
** print_symbols.c
** File description:
** nm print any symbol in the good format
*/

#include <unistd.h>
#include <stdio.h>

inline void print_symbol(
    const void *address, const char type, const char *value)
{
    printf("%016li %c %s\n", (size_t) address, type, value);
}