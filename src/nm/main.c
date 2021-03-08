/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main for my_nm
*/

#include "my.h"

bool my_nm(int ac, char const *av[])
{
    bool exit_value = true;

    for (size_t my_ac = 1; my_ac < ac; my_ac++) {
        if (!file_check(av[my_ac])) {
            exit_value = false;
        } else {
        }
    }
}

int main(int ac, char const *av[])
{
    if (!my_nm(ac, av))
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
