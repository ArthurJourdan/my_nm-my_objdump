/*
** EPITECH PROJECT, 2021
** check_file_memory.c
** File description:
** check if file is truncated
*/

#include "file_memory.h"
#include "error_handling.h"

static inline bool check_file_end(
    void *address, size_t size, void *other_address)
{
    return (address + size < other_address) ? true : false;
}

static bool check_file_memory_64(Elf64_Ehdr *header, size_t size)
{
    Elf64_Shdr *my_sections = (Elf64_Shdr *) (header + header->e_shoff);

    if (check_file_end(header, size, my_sections)) {
        return false;
    }
    if (check_file_end(header, size, &my_sections[header->e_shnum])) {
        return false;
    }
    return true;
}

static bool check_file_memory_32(Elf32_Ehdr *header, size_t size)
{
    Elf32_Shdr *my_sections = (Elf32_Shdr *) (header + header->e_shoff);

    if (check_file_end(header, size, my_sections)) {
        return false;
    }
    if (check_file_end(header, size, &my_sections[header->e_shnum])) {
        return false;
    }
    return true;
}

bool check_file_memory(void *address, size_t size)
{
    size_t my_archi = get_file_architecture(address);
    bool my_check = false;

    if (my_archi == ELFCLASS64) {
        my_check = check_file_memory_64(address, size);
    } else if (my_archi == ELFCLASS32) {
        my_check = check_file_memory_32(address, size);
    }
    return my_check;
}