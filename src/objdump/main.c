/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main for my_objdump
*/

#include "my.h"
#include "objdump.h"

int main(int ac, char const *av[])
{
    if (!my_objdumps(ac, av))
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
