/*
** EPITECH PROJECT, 2024
** my_strdup.c
** File description:
** This function duplicates the given string
** (and free it if do_free equals to 1).
*/

#include <stdlib.h>

#include "../includes/lib.h"
#include <stdbool.h>

char *my_strdup(char *str)
{
    char *dup = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;

    if (!str)
        return FREE(dup);
    while (str[i] != '\0') {
        dup[i] = str[i];
        i++;
    }
    dup[i] = '\0';
    return dup;
}
