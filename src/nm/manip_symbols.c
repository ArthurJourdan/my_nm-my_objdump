/*
** EPITECH PROJECT, 2021
** manip_symbols.c
** File description:
** manipulte symbol_t arrays
*/

#include "my.h"
#include "nm.h"

symbol_t *append_symbols(symbol_t *act_symbols, size_t my_act_symbol_nb,
    symbol_t *new_symbols, size_t my_new_symbol_nb)
{
    symbol_t *my_symbols = reallocarray(
        act_symbols, sizeof(symbol_t), my_act_symbol_nb + my_new_symbol_nb);

    if (!my_symbols)
        return NULL;
    for (size_t i = 0; i < my_act_symbol_nb + my_new_symbol_nb; i++) {
        my_symbols[my_act_symbol_nb + i].address = new_symbols[i].address;
        my_symbols[my_act_symbol_nb + i].type = new_symbols[i].type;
        my_symbols[my_act_symbol_nb + i].name = new_symbols[i].name;
    }
    return my_symbols;
}
