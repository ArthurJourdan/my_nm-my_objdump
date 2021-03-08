/*
** EPITECH PROJECT, 2021
** check_file.c
** File description:
** error handling of arguments
*/

#include <stdbool.h>
#include <stdlib.h>
#include "file.h"
#include "error_handling.h"

bool file_open_check(char const *filepath)
{
    if (!is_file_openable(filepath)) {
        if (errno == ENOENT)
            print_nm_error(get_error(FILE_NOT_FOUND), filepath);
        return false;
    }
    return true;
}

bool file_check(char const *filepath)
{
    if (!file_open_check(filepath))
        return false;
    return true;
}
