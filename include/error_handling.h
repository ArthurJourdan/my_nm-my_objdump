/*
** EPITECH PROJECT, 2021
** error_handling.h
** File description:
** header for error handling
*/

#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H

#include <errno.h>

typedef enum error_identifier
{
    FILE_NOT_FOUND,
    WRONG_FILE_FORMAT,
    FILE_IS_DIR,
    FILE_TRUNCATED
} errorId;

struct err_id_msg
{
    errorId id;
    const char *msg;
};

const char *get_error(errorId id);
void print_error(const char *prog_name, const char *message, const char *arg);

#endif /* !ERROR_HANDLING_H */
