/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** my_strstr
*/

#include <stdbool.h>

bool check_occurence(const char *str, const char *pattern)
{
    for (int i = 0; str[i] && pattern[i]; i++) {
        if (str[i] != pattern[i])
            return false;
    }
    return true;
}

bool my_strstr(const char *str, const char *pattern)
{
    bool result = false;

    for (int i = 0; str[i] && !result; i++) {
        if (str[i] == *pattern) {
            result = check_occurence(&str[i], pattern);
        }
    }
    return result;
}
