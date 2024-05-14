/*
** EPITECH PROJECT, 2024
** lib
** File description:
** my_mem
*/

#include <stdlib.h>
#include <unistd.h>

#include "../includes/lib.h"

static void *print_error(char *error)
{
    write(2, error, my_strlen(error));
    return NULL;
}

void *my_free(void **ptr)
{
    if (!ptr || !*ptr)
        return print_error("my_free error: invalid ptr\n");
    free(*ptr);
    *ptr = NULL;
    return NULL;
}

void *my_alloc(size_t size)
{
    void *new_ptr;

    if (size < 1)
        return print_error("my_alloc error: invalid size\n");
    new_ptr = malloc(size);
    if (!new_ptr)
        return print_error("my_alloc error: malloc failed\n");
    return new_ptr;
}

void *my_realloc(void **ptr, size_t size)
{
    if (!ptr || !*ptr)
        return print_error("my_realloc error: invalid ptr\n");
    ptr = realloc(*ptr, size);
    if (!*ptr)
        return print_error("my_realloc error: realloc failed\n");
    return *ptr;
}
