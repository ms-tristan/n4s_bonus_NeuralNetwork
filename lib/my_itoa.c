/*
** EPITECH PROJECT, 2023
** my_itoa.c
** File description:
** This function transforms an int into a string.
*/

#include "../../includes/lib.h"
#include <stdlib.h>

static int get_int_len(int nb)
{
    int len = 0;

    if (nb == 0)
        return 1;
    while (nb != 0) {
        nb /= 10;
        len++;
    }
    return len;
}

static char *my_neg_itoa(int nb)
{
    int len = get_int_len(nb) + 1;
    char *result;

    if (nb == 0) {
        result = malloc(sizeof(char) * 2);
        result[0] = '0';
        result[1] = '\0';
        return result;
    }
    result = malloc(sizeof(char) * (len + 1));
    for (int i = len - 1; i >= 0; i--) {
        result[i] = '0' + ((nb % 10) - ((nb % 10) * 2));
        nb /= 10;
    }
    result[0] = '-';
    result[len] = '\0';
    return result;
}

char *my_itoa(int nb)
{
    int len = get_int_len(nb);
    char *result;

    if (nb < 0)
        return my_neg_itoa(nb);
    if (nb == 0) {
        result = malloc(sizeof(char) * 2);
        result[0] = '0';
        result[1] = '\0';
        return result;
    }
    result = malloc(sizeof(char) * (len + 1));
    for (int i = len - 1; i >= 0; i--) {
        result[i] = '0' + nb % 10;
        nb /= 10;
    }
    result[len] = '\0';
    return result;
}
