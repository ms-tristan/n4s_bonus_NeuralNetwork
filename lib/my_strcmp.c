/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** This function returns 1 if two strings are de same.
*/

#include <stdio.h>
#include <stdbool.h>

bool my_strcmp(char const *str1, char const *str2)
{
    if (!str1 || !str2)
        return false;
    while ((*str1 == *str2) && (*str1 && *str2)) {
        str1++;
        str2++;
    }
    return *str1 == *str2;
}
