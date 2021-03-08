/*
** EPITECH PROJECT, 2021
** parse_file.c
** File description:
** nm file parsing
*/

#include "my.h"
#include "nm.h"

bool parse_file(void *address)
{
    Elf64_Ehdr *my_header = address;

    // printf("mmap() : %016x\n", address);
    // printf("Section Header Table : addr = %08x, \nnb = %d, \nsize = %d\n",
    // my_header->e_shoff,
    // my_header->e_shnum,
    // my_header->e_shentsize);
    // printf("SSection header string table index = %08x\n",
    // my_header->e_shstrndx);
    return true;
}