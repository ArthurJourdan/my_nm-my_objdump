/*
** EPITECH PROJECT, 2021
** print_section_namw.c
** File description:
** print name of section
*/

void print_names(char *table_address, size_t max_index)
{
    char *my_table = table_address;

    for (size_t i = 0; i < max_index; i++) {
        printf("%s\n", my_table);
        my_table += strlen(my_table) + 1;
    }
}

// itérer à travers les noms de section --> objdump
void print_section_names(Elf64_Ehdr *header)
{
    Elf64_Shdr *my_section_header =
        (Elf64_Shdr *) ((size_t) header + header->e_shoff);

    Elf64_Half my_section_nb = header->e_shnum;

    char *my_string_table = (char *) ((size_t) header
        + my_section_header[header->e_shstrndx].sh_offset);

    size_t my_offset = 0;

    print_names(my_string_table, my_section_nb);
}