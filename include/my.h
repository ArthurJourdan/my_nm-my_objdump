/*
** EPITECH PROJECT, 2019
** my
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdbool.h>

#include <errno.h>
#include <string.h>

#include <signal.h>

#include <time.h>

#include <sys/types.h>
#include <sys/wait.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))
#define MAX(a, b)     ((a > b) ? a : b)
#define MIN(a, b)     ((a < b) ? a : b)

#undef EXIT_FAILURE
#define EXIT_FAILURE (84)

// ATTRIBUTES
#define N_U         __attribute__((unused))
#define UNUSED      __attribute__((unused))
#define PURE        __attribute__((pure))
#define CONSTRUCTOR __attribute__((constructor))
#define DESTRUCTOR  __attribute__((destructor))
#define INLINE      __attribute__((always_inline))
#define NO_INLINE   __attribute__((noinline))
#define CONST       __attribute__((const))
#define MALLOC      __attribute__((malloc))
#define NO_RETURN   __attribute__((noreturn))
// !ATTRIBUTES

typedef struct
{
    int x;
    int y;
} vector_t;

#endif /*MY_H_*/