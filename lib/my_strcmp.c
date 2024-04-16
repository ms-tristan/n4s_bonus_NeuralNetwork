/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** This function returns 1 if two strings are de same.
*/

#include <stdio.h>

int my_strcmp(char const *str1, char const *str2)
{
    int i = 0;

    if (str1 == NULL || str2 == NULL)
        return -1;
    while (str1[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;
        }
        i++;
    }
    if (str1[i] != str2[i]) {
        return 0;
    }
    return 1;
}
