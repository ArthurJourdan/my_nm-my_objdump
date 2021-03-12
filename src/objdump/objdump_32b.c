/*
** EPITECH PROJECT, 2021
** objdump_32b.c
** File description:
** parsing of 32 bits files
*/

#include "my.h"
#include "objdump.h"

static bool section_to_print(Elf32_Shdr act_section)
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
        if (!section_to_print(my_sections[i]))
            continue;
        print_section(header, my_sections, &my_sections[i]);
    }
    return NULL;
}

bool objdump_32(void *header)
{
    Elf32_Ehdr *my_header = header;

    print_infos_32(header);
    print_sections(my_header);

    return true;
}
