/*
** EPITECH PROJECT, 2021
** main_objdump.c
** File description:
** main functions of objdump program
*/

#include "my.h"
#include "objdump.h"
#include "file_memory.h"

static const char *prog_name = "objdump";

bool my_objdump(const char *filepath)
{
    struct stat my_stats;
    void *my_file_address = load_file(prog_name, filepath, &my_stats);

    if (!file_is_object(prog_name, filepath, my_file_address))
        return false;
    printf("\n%s:\t", filepath);
    launch_architecture_objdump(my_file_address);
    release_file(my_file_address, my_stats);
    return true;
}

bool my_objdumps(int ac, char const *filepaths[])
{
    bool exit_value = true;

    if (ac == 1) {
        filepaths[ac++] = "a.out";
    }
    for (int my_ac = 1; my_ac < ac; my_ac++) {
        if (!my_objdump(filepaths[my_ac])) {
            exit_value = false;
        }
    }
    return exit_value;
}
