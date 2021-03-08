/*
** EPITECH PROJECT, 2021
** load_file.c
** File description:
** put file in memory to be able to naviguate through structures
*/

#include "my.h"
#include "nm.h"

void release_file(void *address, struct stat stats)
{
    munmap(address, stats.st_size);
}

void *load_file(const char *filepath, struct stat *stats)
{
    int my_fd = -1;
    void *my_address = NULL;

    my_fd = open_file(filepath);
    if (my_fd == -1 || !check_file(filepath, my_fd, stats))
        return NULL;
    my_address = mmap(NULL, stats->st_size, PROT_READ, MAP_PRIVATE, my_fd, 0);
    close(my_fd);
    return my_address;
}
