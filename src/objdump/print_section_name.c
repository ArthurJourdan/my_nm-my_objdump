/*
** EPITECH PROJECT, 2021
** print_section_namw.c
** File description:
** print name of section
*/

#include <stdio.h>
#include "objdump.h"

char *get_section_name(
    Elf64_Ehdr *header, Elf64_Shdr *sections, Elf64_Shdr *act_section)
{
    char *my_section_name =
        (char *) ((size_t) header + sections[header->e_shstrndx].sh_offset);

    my_section_name += act_section->sh_name;
    return my_section_name;
}

void print_section_name(
    Elf64_Ehdr *header, Elf64_Shdr *sections, Elf64_Shdr *act_section)
{
    char *my_section_name = get_section_name(header, sections, act_section);

    printf("Contents of section %s:\n", my_section_name);
}
