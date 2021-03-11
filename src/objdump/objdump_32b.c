/*
** EPITECH PROJECT, 2021
** objdump_32b.c
** File description:
** parsing of 32 bits files
*/

#include "my.h"
#include "objdump.h"

static void print_section(
    Elf32_Ehdr *header, Elf32_Shdr *sections, Elf32_Shdr *act_section)
{
    print_section_name_32(header, sections, act_section);
    print_section_body_32(header, act_section);
}

static Elf32_Shdr *print_sections(Elf32_Ehdr *header)
{
    Elf32_Shdr *my_sections =
        (Elf32_Shdr *) ((size_t) header + header->e_shoff);

    for (size_t i = 1; i < header->e_shnum; i++) {
        if (my_sections[i].sh_type == SHT_SYMTAB
            || my_sections[i].sh_type == SHT_STRTAB)
            continue;
        print_section(header, my_sections, &my_sections[i]);
    }
    return NULL;
}

bool objdump_32(void *header)
{
    Elf32_Ehdr *my_header = header;

    print_sections(my_header);

    return true;
}
