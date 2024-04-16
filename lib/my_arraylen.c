/*
** EPITECH PROJECT, 2024
** my_arraylen.c
** File description:
** This functions gives the number of elements from an array.
*/

#include <stdio.h>

int my_arraylen(void **array)
{
    int count = 0;

    if (array == NULL)
        return 0;
    while (array[count] != NULL)
        count++;
    return count;
}
