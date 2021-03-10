/*
** EPITECH PROJECT, 2021
** check_file_format.c
** File description:
** check if file is object file and has no errors
*/

#include "my.h"
#include "nm.h"
#include "error_handling.h"

static const int accepted_types[3] = {ET_REL, ET_EXEC, ET_DYN};

bool file_is_object(const char *filepath, void *file_address)
{
    if (!file_address) {
        return false;
    }
    if (file_address == MAP_FAILED) {
        perror("mmap");
        return false;
    }
    if (!check_object_type(file_address)) {
        print_error("nm", get_error(WRONG_FILE_FORMAT), filepath);
        return false;
    }
    return true;
}

bool check_object_type(void *header)
{
    Elf32_Ehdr *my_header = header;

    if (strncmp((const char *) my_header->e_ident, ELFMAG, SELFMAG)) {
        return false;
    }
    for (size_t my_type = 0; my_type < ARRAY_SIZE(accepted_types); my_type++) {
        if (my_header->e_type == accepted_types[my_type]) {
            return true;
        }
    }
    return false;
}
