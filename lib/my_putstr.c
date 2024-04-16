/*
** EPITECH PROJECT, 2023
** my_putstr.c
** File description:
** This function displays a char string.
*/

#include <unistd.h>
#include "../includes/lib.h"

int my_putchar(char c)
{
    return write(1, &c, 1);
}

int my_putstr(char const *str)
{
    return write(1, str, my_strlen(str));
}
