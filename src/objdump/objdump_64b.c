/*
** EPITECH PROJECT, 2021
** objdump_64b.c
** File description:
** parsing of 64 bits files
*/

#include "my.h"
#include "objdump.h"

static bool section_to_print(Elf64_Shdr act_section)
{
    if (!act_section.sh_size) {
        return false;
    }
    if (act_section.sh_type == SHT_NOBITS) {
        return false;
    }
    if (act_section.sh_type == SHT_PROGBITS
        || act_section.sh_type == SHT_NOTE) {
        return true;
    }
    if ((act_section.sh_flags & SHF_ALLOC) == SHF_ALLOC) {
        return true;
    }
    if ((act_section.sh_flags & SHF_WRITE) == SHF_WRITE) {
        return true;
    }
    return false;
}

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
        if (!section_to_print(my_sections[i]))
            continue;
        print_section(header, my_sections, &my_sections[i]);
    }
    return NULL;
}

bool objdump_64(void *header)
{
    Elf64_Ehdr *my_header = header;

    print_infos_64(header);
    print_sections(my_header);

    return true;
}
