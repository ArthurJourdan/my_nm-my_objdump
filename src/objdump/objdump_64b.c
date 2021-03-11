/*
** EPITECH PROJECT, 2021
** objdump_64b.c
** File description:
** parsing of 64 bits files
*/

#include "my.h"
#include "objdump.h"

static void print_section(
    Elf64_Ehdr *header, Elf64_Shdr *sections, Elf64_Shdr *act_section)
{
    print_section_name_64(header, sections, act_section);
    print_section_body_64(header, act_section);
}

static Elf64_Shdr *print_sections(Elf64_Ehdr *header)
{
    Elf64_Shdr *my_sections =
        (Elf64_Shdr *) ((size_t) header + header->e_shoff);

    for (size_t i = 1; i < header->e_shnum; i++) {
        if (my_sections[i].sh_type == SHT_SYMTAB
            || my_sections[i].sh_type == SHT_STRTAB)
            continue;
        print_section(header, my_sections, &my_sections[i]);
    }
    return NULL;
}

bool objdump_64(void *header)
{
    Elf64_Ehdr *my_header = header;

    print_sections(my_header);

    return true;
}
