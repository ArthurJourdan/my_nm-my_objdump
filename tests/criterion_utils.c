/*
** EPITECH PROJECT, 2021
** criterion_utils.c
** File description:
** functions to help testing
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirect_stdout(void)
{
    cr_redirect_stdout();
}

void redirect_stderr(void)
{
    cr_redirect_stderr();
}

void redirect_all_std(void)
{
    redirect_stderr();
    redirect_stdout();
}
