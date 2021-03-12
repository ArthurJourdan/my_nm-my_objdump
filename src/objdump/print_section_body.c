/*
** EPITECH PROJECT, 2021
** print_section_body.c
** File description:
** print hexa and ascii representation of 16 bytes in object file
*/

#include <stdio.h>
#include "objdump.h"

void print_ascii(
    size_t act_offset, size_t section_end, uint8_t *line, size_t i)
{
    if (section_end < act_offset + i + 1) {
        printf(" ");
        return;
    }
    if (line[i] >= ' ' && line[i] <= '~')
        printf("%c", line[i]);
    else
        printf(".");
}

void print_hexa(size_t act_offset, size_t section_end, uint8_t *line, size_t i)
{
    if (i % 4 == 0)
        printf(" ");
    if (section_end < act_offset + i + 1) {
        printf("  ");
        return;
    }
    printf("%02x", line[i]);
}