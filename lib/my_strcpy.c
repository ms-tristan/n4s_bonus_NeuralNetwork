/*
** EPITECH PROJECT, 2023
** my_strcpy.c
** File description:
** This function copy a char string into another.
*/

#include <stddef.h>

void my_strcpy(char *dest, char *src)
{
    if (dest == NULL || src == NULL) {
        dest = NULL;
        src = NULL;
        return;
    }
    for (int i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
}
