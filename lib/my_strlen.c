/*
** EPITECH PROJECT, 2023
** my_strlen.c
** File description:
** This function count the number of char from a given string.
*/

#include <stddef.h>

static int my_recustr(char const *str, int i)
{
    if (str[i] == '\0')
        return i;
    return my_recustr(str, i + 1);
}

int my_strlen(char const *str)
{
    if (str == NULL)
        return 0;
    return my_recustr(str, 0);
}
