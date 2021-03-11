/*
** EPITECH PROJECT, 2021
** print_symbols.c
** File description:
** nm print any symbol in the good format
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "nm.h"

void print_symbol(symbol_t to_print)
{
    if (to_print.type == '?' || !to_print.name || !strlen(to_print.name))
        return;
    if (to_print.address)
        printf("%016lx", to_print.address);
    else {
        printf("\t\t");
    }
    printf(" %c %s\n", to_print.type, to_print.name);
}

void print_symbols(symbol_t *symbols, size_t symbol_nb)
{
    size_t i = 0;

    while (i < symbol_nb) {
        print_symbol(symbols[i]);
        i++;
    }
}