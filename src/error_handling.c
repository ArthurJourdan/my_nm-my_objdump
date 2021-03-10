/*
** EPITECH PROJECT, 2021
** error_handling.c
** File description:
** print error message for nm
*/

#include <stdio.h>
#include "my.h"
#include "error_handling.h"

static const struct err_id_msg errors[] = {
    {FILE_NOT_FOUND, "'%s': No such file"},
    {WRONG_FILE_FORMAT, "%s: file format not recognized"},
    {FILE_IS_DIR, "Warning: '%s' is a directory"}};

const char *get_error(errorId id)
{
    for (size_t i = 0; i < ARRAY_SIZE(errors); i++) {
        if (errors[i].id == id) {
            return errors[i].msg;
        }
    }
    return NULL;
}

void print_error(const char *prog_name, const char *message, const char *arg)
{
    if (!message)
        return;
    if (prog_name)
        fprintf(stderr, "%s: ", prog_name);
    if (arg)
        fprintf(stderr, message, arg);
    else
        fprintf(stderr, "%s", message);
    fprintf(stderr, "\n");
}