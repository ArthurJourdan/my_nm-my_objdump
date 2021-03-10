/*
** EPITECH PROJECT, 2021
** main_nm.c
** File description:
** main functions of nm program
*/

#include "my.h"
#include "nm.h"

bool my_nm_architecture(void *file_address)
{
    bool (*my_function)(void *) = get_function_of_archi(file_address);

    if (!my_function)
        return false;
    my_function(file_address);
    return true;
}

bool my_nm(bool print_filepath, const char *filepath)
{
    struct stat my_stats;
    void *my_file_address = load_file(filepath, &my_stats);

    if (!file_is_object(filepath, my_file_address))
        return false;
    if (print_filepath)
        printf("\n%s:\n", filepath);
    my_nm_architecture(my_file_address);
    release_file(my_file_address, my_stats);
    return true;
}

bool my_nms(int ac, char const *filepaths[])
{
    bool exit_value = true;
    bool print_filepath = false;

    if (ac > 2)
        print_filepath = true;
    for (int my_ac = 1; my_ac < ac; my_ac++) {
        if (!my_nm(print_filepath, filepaths[my_ac])) {
            exit_value = false;
        }
    }
    return exit_value;
}
