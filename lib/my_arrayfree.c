/*
** EPITECH PROJECT, 2024
** my_array_free.c
** File description:
** This function frees an array and all of its elements.
*/

#include <stdlib.h>

#include "../includes/lib.h"

void my_arrayfree(void **array)
{
    if (!array)
        return;
    for (int i = 0; array[i]; i++) {
        if (array[i] != NULL)
            FREE(array[i]);
    }
    FREE(array);
}
