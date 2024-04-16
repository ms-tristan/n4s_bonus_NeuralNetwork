/*
** EPITECH PROJECT, 2023
** is_num.c
** File description:
** This function tells if the str given as parameter only contains
** digits or not.
*/

#include <stdbool.h>

bool my_char_isnum(char c)
{
    if (c < '0' || c > '9')
        return false;
    else
        return true;
}

bool my_str_isnum(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!my_char_isnum(str[i]))
            return false;
    }
    return true;
}

bool my_char_isalpha(char c)
{
    if (c < 'A' || c > 'z')
        return false;
    if (c > 'Z' && c < 'a')
        return false;
    return true;
}

bool my_str_isalphanum(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!my_char_isalpha(str[i]) && !my_char_isnum(str[i]))
            return false;
    }
    return true;
}
