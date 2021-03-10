/*
** EPITECH PROJECT, 2021
** manip_file_memory.h
** File description:
** check file and place it into memory
*/

#ifndef FILE_MEMORY_H
#define FILE_MEMORY_H

#include <stdbool.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <elf.h>
#include <fcntl.h>

void release_file(void *address, struct stat stats);
void *load_file(const char *filepath, struct stat *stats);

bool check_file(const char *filepath, int fd, struct stat *stats);
int open_file(const char *filepath);

bool file_is_object(
    const char *prog_name, const char *filepath, void *file_address);
bool check_object_type(void *header);

int get_file_architecture(void *header);
void *get_function_of_archi(void *header);
bool launch_architecture(void *file_address);

#endif /* FILE_MEMORY_H */
