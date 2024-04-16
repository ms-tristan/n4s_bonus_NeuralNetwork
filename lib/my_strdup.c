/*
** EPITECH PROJECT, 2024
** my_strdup.c
** File description:
** This function duplicates the given string
** (and free it if do_free equals to 1).
*/

#include <stdlib.h>
#include <stdbool.h>

#include "../includes/lib.h"

// if do_free == 1, the orignal str will be freed
char *my_strdup(char *str, bool do_free)
{
    char *dup = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;

    if (str == NULL) {
        free(dup);
        return NULL;
    }
    while (str[i] != '\0') {
        dup[i] = str[i];
        i++;
    }
    dup[i] = '\0';
    if (do_free == true)
        free(str);
    return dup;
}
