/*
** EPITECH PROJECT, 2021
** error_handling.c
** File description:
** print error message for nm
*/

#include <stdio.h>
#include "my.h"
#include "error_handling.h"

static const struct err_id_msg errors[] = {{FILE_NOT_FOUND, "No such file"},
    {WRONG_FILE_FORMAT, "file format not recognized"}};

const char *get_error(errorId id)
{
    for (size_t i = 0; i < ARRAY_SIZE(errors); i++) {
        if (errors[i].id == id) {
            return errors[i].msg;
        }
    }
    return NULL;
}

void print_nm_error(const char *message, const char *arg)
{
    if (!message)
        return;
    if (arg)
        fprintf(stderr, "nm: %s: %s\n", arg, message);
    else
        fprintf(stderr, "nm: %s\n", message);
}