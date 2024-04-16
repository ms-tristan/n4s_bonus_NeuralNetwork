/*
** EPITECH PROJECT, 2023
** my_strcat.c
** File description:
** This function adds the src string to the dest string.
*/

#include <stdlib.h>
#include "../includes/lib.h"

char *my_strcat(char const *src1, char const *src2)
{
    int total_size;
    char *ret;
    int cursor = 0;

    if (src1 == NULL || src2 == NULL)
        return NULL;
    total_size = my_strlen(src1) + my_strlen(src2) + 1;
    ret = malloc(sizeof(char) * total_size);
    for (int i = 0; src1[i] != '\0'; i++) {
        ret[cursor] = src1[i];
        cursor++;
    }
    for (int i = 0; src2[i] != '\0'; i++) {
        ret[cursor] = src2[i];
        cursor++;
    }
    ret[cursor] = '\0';
    return ret;
}
