/*
** EPITECH PROJECT, 2021
** check_file.c
** File description:
** error handling of arguments
*/

#include <stdbool.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "error_handling.h"

bool check_file(const char *filepath, int fd, struct stat *stats)
{
    if (fstat(fd, stats) == -1) {
        return false;
    }
    if ((stats->st_mode & S_IFMT) == S_IFDIR) {
        print_error("nm", get_error(FILE_IS_DIR), filepath);
        return false;
    }
    return true;
}

int open_file(const char *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1) {
        if (errno == ENOENT)
            print_error("nm", get_error(FILE_NOT_FOUND), filepath);
        return -1;
    }
    return fd;
}