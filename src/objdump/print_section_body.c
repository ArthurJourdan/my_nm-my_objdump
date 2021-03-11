/*
** EPITECH PROJECT, 2021
** print_line.c
** File description:
** print each line of objdump
*/

#include "objdump.h"
#include "stdio.h"

#include "objdump.h"

void print_ascii(
    Elf64_Ehdr *header, Elf64_Shdr *act_section, size_t act_offset)
{
    uint8_t *my_line = (uint8_t *) ((size_t) header + act_offset);
    size_t my_section_end = act_section->sh_offset + act_section->sh_size;

    for (size_t i = 0; i < 16; i++) {
        if (my_section_end < act_offset + i) {
            printf(" ");
            continue;
        }
        if (my_line[i] > ' ' && my_line[i] < '~')
            printf("%c", my_line[i]);
        else
            printf(".");
    }
}

void print_hexa(Elf64_Ehdr *header, Elf64_Shdr *act_section, size_t act_offset)
{
    uint8_t *my_line = (uint8_t *) ((size_t) header + act_offset);
    size_t my_section_end = act_section->sh_offset + act_section->sh_size;

    for (size_t i = 0; i < 16; i++) {
        if (i % 4 == 0)
            printf(" ");
        if (my_section_end < act_offset + i) {
            printf("  ");
            continue;
        }
        printf("%02x", my_line[i]);
    }
}

void print_offset(size_t act_offset)
{
    printf(" %04x", (unsigned int) act_offset);
}

void print_line(Elf64_Ehdr *header, Elf64_Shdr *act_section, size_t act_offset)
{
    print_offset(act_offset);
    print_hexa(header, act_section, act_offset);
    printf(" ");
    print_ascii(header, act_section, act_offset);
    printf("\n");
}

void print_section_body(Elf64_Ehdr *header, Elf64_Shdr *act_section)
{
    size_t my_offset = (size_t)(act_section->sh_offset);
    size_t my_section_end = (size_t)(my_offset + act_section->sh_size);

    while (my_offset < my_section_end) {
        print_line(header, act_section, my_offset);
        my_offset += 16;
    }
}
