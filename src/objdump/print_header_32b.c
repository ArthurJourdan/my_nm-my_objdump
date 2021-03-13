/*
** EPITECH PROJECT, 2021
** print_infos.c
** File description:
** print heading informations about object file
*/

#include <stdio.h>
#include "objdump.h"
#include "flags.h"
#include "my.h"

static const map_flag_t flag_list[10] = {{0x00, "BFD_NO_FLAGS"},
    {0x01, "HAS_RELOC"},
    {0x02, "EXEC_P"},
    {0x04, "HAS_LINENO"},
    {0x08, "HAS_DEBUG"},
    {0x10, "HAS_SYMS"},
    {0x20, "HAS_LOCALS"},
    {0x40, "DYNAMIC"},
    {0x80, "WP_TEXT"},
    {0x100, "D_PAGED"}};

static unsigned int get_flags(Elf32_Ehdr *header)
{
    switch (header->e_type) {
        case ET_REL: return 0x11;
        case ET_EXEC: return 0x112;
        default: return 0x150;
    }
}

static void print_flags(Elf32_Ehdr *header)
{
    unsigned int my_flags = get_flags(header);
    bool my_print_several = false;

    printf("flags 0x%08x:\n", my_flags);
    for (uint i = 0; i < ARRAY_SIZE(flag_list); i++) {
        if (my_flags & flag_list[i].flag) {
            if (my_print_several)
                printf(", ");
            printf("%s", flag_list[i].name);
            my_print_several = true;
        }
    }
    printf("\n");
}

void print_infos_32(Elf32_Ehdr *header)
{
    printf("file format elf32-i386\n");
    printf("architecture: i386, ");
    print_flags(header);
    printf("start address 0x%016x", (unsigned int) header->e_entry);
    printf("\n\n");
}
