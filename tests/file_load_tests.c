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

Test(load_file, basic_load, .timeout = timeout, .disabled = MY_DISABLEMENT,
    .init = redirect_stderr)
{
    char *my_file = "./unit_tests";
    struct stat my_stats;
    void *my_address = load_file(my_file, &my_stats);

    cr_assert_not_null(my_address);
    cr_assert_neq(my_address, MAP_FAILED);
    cr_assert_neq(check_object_type(my_address), false);
}

Test(load_file, directory, .timeout = timeout, .disabled = MY_DISABLEMENT,
    .init = redirect_stderr)
{
    char *my_file = "./include";
    char *my_format = "nm: Warning: '%s' is a directory\n";
    char *my_expected;
    struct stat my_stats;

    cr_assert_null(load_file(my_file, &my_stats));
    asprintf(&my_expected, my_format, my_file);
    cr_assert_stderr_eq_str(my_expected);
}

Test(load_file, file_unknown, .timeout = timeout, .disabled = MY_DISABLEMENT,
    .init = redirect_stderr)
{
    char *my_file = "weoifjoewijfeowijfi";
    char *my_format = "nm: '%s': No such file\n";
    char *my_expected;
    struct stat my_stats;

    cr_assert_null(load_file(my_file, &my_stats));
    asprintf(&my_expected, my_format, my_file);
    cr_assert_stderr_eq_str(my_expected);
}

Test(load_file, file_format_unknown, .timeout = timeout,
    .disabled = MY_DISABLEMENT, .init = redirect_stderr)
{
    char *my_file = "./include/my.h";
    char *my_format = "nm: %s: file format not recognized\n";
    char *my_expected;

    cr_assert_eq(my_nm(false, my_file), false);
    asprintf(&my_expected, my_format, my_file);
    cr_assert_stderr_eq_str(my_expected);
}
