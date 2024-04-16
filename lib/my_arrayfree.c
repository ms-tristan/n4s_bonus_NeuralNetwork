/*
** EPITECH PROJECT, 2024
** my_array_free.c
** File description:
** This function frees an array and all of its elements.
*/

#include <stdlib.h>

void my_arrayfree(void **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; i++) {
        if (array[i] != NULL)
            free(array[i]);
    }
    free(array);
    array = NULL;
}
