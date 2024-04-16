/*
** EPITECH PROJECT, 2023
** my_getnbr.c
** File description:
** This function returns a number given as parameter.
*/

#include "../includes/lib.h"
#include <stddef.h>

static int get_nb_pos(const char *str)
{
    int pos = 0;

    if (str == NULL)
        return -1;
    while (!my_char_isnum(str[pos]) && str[pos] != '\0' &&
    str[pos] != '-')
        pos++;
    if (str[pos] == '\0')
        return -1;
    return pos;
}

static int get_nbrlen(const char *str, int nb_pos)
{
    int len = 0;

    if (str[nb_pos] == '-')
        nb_pos++;
    while (str[nb_pos] != '\0' && my_char_isnum(str[nb_pos])) {
        nb_pos++;
        len++;
    }
    return len;
}

int my_getnbr(const char *str)
{
    int pos = get_nb_pos(str);
    int nbrlen;
    int index = 1;
    int isneg = 0;
    int nb = 0;

    if (pos < 0)
        return 0;
    if (str[pos] == '-') {
        isneg = 1;
        pos++;
    }
    nbrlen = get_nbrlen(str, pos);
    for (int i = 0; i < nbrlen; i++) {
        nb += index * (int)(str[pos + nbrlen - i - 1] - '0');
        index *= 10;
    }
    if (isneg == 1)
        nb -= nb + nb;
    return nb;
}
