/*
** EPITECH PROJECT, 2023
** mini_printf.c
** File description:
** This is a lite version of the printf function.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "../includes/lib.h"

static int print_flag(const char *str, va_list ap, int debut, int *i)
{
    if (str[debut] == 'd' || str[debut] == 'i')
        return my_putnbr(va_arg(ap, int));
    if (str[debut] == 'c')
        return my_putchar(va_arg(ap, int));
    if (str[debut] == 's')
        return my_putstr(va_arg(ap, char *));
    *i -= 1;
    return my_putchar('%');
}

static int add_arg(const char *str, va_list ap, int *i)
{
    int debut = *i;
    int fixe = debut;

    while (str[debut] == ' ')
        debut++;
    *i += debut - fixe;
    return print_flag(str, ap, debut, i);
}

int mini_printf(const char *format, ...)
{
    va_list ap;
    int letter_count = 0;

    va_start(ap, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] != '%') {
            my_putchar(format[i]);
            letter_count++;
        } else {
            i++;
            letter_count += add_arg(format, ap, &i);
        }
        va_end(ap);
    }
    return letter_count;
}
