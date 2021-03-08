/*
** EPITECH PROJECT, 2021
** main_nm.c
** File description:
** main functions of nm program
*/

#include "my.h"
#include "nm.h"

bool my_nm_architecture(void *address)
{
    return true;
}

bool my_nm(const char *filepath)
{
    struct stat my_stats;
    void *my_file_address = load_file(filepath, &my_stats);

    if (!file_is_object(filepath, my_file_address))
        return false;
    parse_file(my_file_address);
    release_file(my_file_address, my_stats);
    return true;
}

bool my_nms(int ac, char const *filepaths[])
{
    bool exit_value = true;

    for (int my_ac = 1; my_ac < ac; my_ac++) {
        if (!my_nm(filepaths[my_ac])) {
            exit_value = false;
        }
    }
    return exit_value;
}
