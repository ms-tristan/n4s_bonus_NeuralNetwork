/*
** EPITECH PROJECT, 2024
** minishell_2
** File description:
** my_extractor
*/

#include "../includes/lib.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compute_new_len(const char *src, const char *delim)
{
    int len = 0;
    bool on_a_delim = false;

    if (!src || !delim)
        return -1;
    while (*src) {
        if (is_in_list(*src, delim) && !on_a_delim) {
            on_a_delim = true;
            len += 2;
        }
        if (!is_in_list(*src, delim))
            on_a_delim = false;
        len++;
        src++;
    }
    return len;
}

static char *extract(const char *src, const char *delim, int len)
{
    int i = 0;
    char *result = malloc(sizeof(char) * (len + 1));
    bool on_a_delim = false;

    while (*src) {
        if (is_in_list(*src, delim) && !on_a_delim) {
            on_a_delim = true;
            result[i] = ' ';
            i++;
        }
        if (!is_in_list(*src, delim) && on_a_delim) {
            on_a_delim = false;
            result[i] = ' ';
            i++;
        }
        result[i] = *src;
        src++;
        i++;
    }
    return result;
}

char *my_extractor(const char *src, const char *delim)
{
    int len = compute_new_len(src, delim);

    if (len < 0) {
        return NULL;
    }
    return extract(src, delim, len);
}
