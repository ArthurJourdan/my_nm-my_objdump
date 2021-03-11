/*
** EPITECH PROJECT, 2021
** print_line.c
** File description:
** print each line of objdump
*/

#include <stdio.h>
#include "objdump.h"
#include "objdump.h"

static void print_16_bytes(Elf32_Ehdr *header, Elf32_Shdr *act_section,
    size_t act_offset, void (*print)(size_t, size_t, uint8_t *, size_t))
{
    uint8_t *my_line = (uint8_t *) ((size_t) header + act_offset);
    size_t my_section_end = act_section->sh_offset + act_section->sh_size;

    for (size_t i = 0; i < 16; i++) {
        print(act_offset, my_section_end, my_line, i);
    }
}

static void print_line(
    Elf32_Ehdr *header, Elf32_Shdr *act_section, size_t act_offset)
{
    printf(" %04x", (unsigned int) act_offset);
    print_16_bytes(header, act_section, act_offset, print_hexa);
    printf(" ");
    print_16_bytes(header, act_section, act_offset, print_ascii);
    printf("\n");
}

void print_section_body_32(Elf32_Ehdr *header, Elf32_Shdr *act_section)
{
    size_t my_offset = (size_t)(act_section->sh_offset);
    size_t my_section_end = (size_t)(my_offset + act_section->sh_size);

    while (my_offset < my_section_end) {
        print_line(header, act_section, my_offset);
        my_offset += 16;
    }
}
