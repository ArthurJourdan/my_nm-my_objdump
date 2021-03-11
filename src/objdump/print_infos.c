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

static const map_flag_t flag_list[10] = {{BFD_NO_FLAGS, "BFD_NO_FLAGS"},
    {HAS_RELOC, "HAS_RELOC"},
    {EXEC_P, "EXEC_P"},
    {HAS_LINENO, "HAS_LINENO"},
    {HAS_DEBUG, "HAS_DEBUG"},
    {HAS_SYMS, "HAS_SYMS"},
    {HAS_LOCALS, "HAS_LOCALS"},
    {DYNAMIC, "DYNAMIC"},
    {WP_TEXT, "WP_TEXT"},
    {D_PAGED, "D_PAGED"}};

static void print_start_address(Elf64_Ehdr *header)
{
    printf("start address 0x%016x", (unsigned int) header->e_entry);
}

static void print_flags(Elf64_Ehdr *header)
{
    unsigned int my_flags = header->e_flags;
    bool my_print_several = false;

    printf("flags 0x%08x\n", my_flags);
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

static void print_architecture(void)
{
    printf("architecture: ");
    printf("i386:x86-64, ");
}

static void print_file_format(void)
{
    printf("file format elf64-x86-64\n");
}

void print_infos_64(Elf64_Ehdr *header)
{
    print_file_format();
    print_architecture();
    print_flags(header);
    print_start_address(header);
    printf("\n\n");
}
