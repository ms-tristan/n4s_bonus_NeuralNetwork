/*
** EPITECH PROJECT, 2024
** minishell_2
** File description:
** is_in_list
*/

#include <stdbool.h>

bool is_in_list(char c, const char *list)
{
    while (*list) {
        if (*list == c)
            return true;
        list++;
    }
    return false;
}
