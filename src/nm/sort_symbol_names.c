/*
** EPITECH PROJECT, 2021
** sort_symbol_names.c
** File description:
** alphabetically sorts name of symbols
*/

#include "nm.h"
#include <string.h>

static int check_sort(const void *sym_1, const void *sym_2)
{
    const char *my_name_1 = ((const symbol_t *) sym_1)->name;
    const char *my_name_2 = ((const symbol_t *) sym_2)->name;
    size_t my_offset_1 = 0;
    size_t my_offset_2 = 0;

    if (!my_name_1 || !my_name_2)
        return 0;
    while (my_name_1[my_offset_1] == '_') {
        my_offset_1++;
    }
    while (my_name_2[my_offset_2] == '_') {
        my_offset_2++;
    }
    return strcoll(my_name_1 + my_offset_1, my_name_2 + my_offset_2);
}

void sort_symbols_by_name(symbol_t *symbols, size_t nb_symbols)
{
    qsort(symbols, nb_symbols, sizeof(symbol_t), &check_sort);
}