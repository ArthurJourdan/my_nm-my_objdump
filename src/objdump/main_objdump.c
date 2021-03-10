/*
** EPITECH PROJECT, 2021
** main_objdump.c
** File description:
** main functions of objdump program
*/

#include "my.h"
#include "objdump.h"

bool my_objdump_architecture(void *file_address)
{
    bool (*my_function)(void *) = get_function_of_archi(file_address);

    if (!my_function)
        return false;
    my_function(file_address);
    return true;
}

bool my_objdump(bool print_filepath, const char *filepath)
{
    struct stat my_stats;
    void *my_file_address = load_file(filepath, &my_stats);

    if (!file_is_object(filepath, my_file_address))
        return false;
    if (print_filepath)
        printf("\n%s:\n", filepath);
    my_objdump_architecture(my_file_address);
    release_file(my_file_address, my_stats);
    return true;
}

bool my_objdumps(int ac, char const *filepaths[])
{
    bool exit_value = true;
    bool print_filepath = false;

    if (ac > 2)
        print_filepath = true;
    else if (ac == 1) {
        filepaths[ac++] = "a.out";
    }
    for (int my_ac = 1; my_ac < ac; my_ac++) {
        if (!my_objdump(print_filepath, filepaths[my_ac])) {
            exit_value = false;
        }
    }
    return exit_value;
}
