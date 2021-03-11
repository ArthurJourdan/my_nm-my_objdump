/*
** EPITECH PROJECT, 2021
** main_nm.c
** File description:
** main functions of nm program
*/

#include <locale.h>
#include "my.h"
#include "nm.h"
#include "file_memory.h"

bool my_nm(bool print_filepath, const char *filepath)
{
    struct stat my_stats;
    void *my_file_address = load_file(filepath, &my_stats);

    if (!file_is_object("nm", filepath, my_file_address))
        return false;
    if (print_filepath)
        printf("\n%s:\n", filepath);
    launch_architecture_nm(my_file_address);
    release_file(my_file_address, my_stats);
    return true;
}

bool my_nms(int ac, char const *filepaths[])
{
    bool exit_value = true;
    bool print_filepath = false;

    if (ac > 2)
        print_filepath = true;
    else if (ac == 1) {
        filepaths[ac++] = "a.out";
    }
    setlocale(LC_ALL, "en_US");
    for (int my_ac = 1; my_ac < ac; my_ac++) {
        if (!my_nm(print_filepath, filepaths[my_ac])) {
            exit_value = false;
        }
    }
    return exit_value;
}
