/*
** EPITECH PROJECT, 2019
** unit tests with criterion
** File description:
** just triing
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "test.h"
#include "my.h"
#include "nm.h"
#include "file_memory.h"

static const unsigned short timeout = 2;

Test(file_archi, basic, .timeout = timeout, .disabled = MY_DISABLEMENT,
    .init = redirect_stderr)
{
    char *my_file = "./unit_tests";
    struct stat my_stats;
    void *my_address = load_file(my_file, &my_stats);
    bool (*my_function)(void *);

    if (!my_address || !file_is_object("nm", my_file, my_address))
        cr_skip_test();
    my_function = get_function_of_archi(my_address);
    cr_assert_not_null(my_function);
    cr_assert_eq(my_function, &nm_64);
}