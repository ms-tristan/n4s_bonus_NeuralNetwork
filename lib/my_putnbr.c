/*
** EPITECH PROJECT, 2023
** my_put_nbr.c
** File description:
** This function displays any entry using the putchar function.
*/

#include "../includes/lib.h"

static int displaynb(long nb)
{
    long cp = nb;
    long i = 1000000000000000000;
    int count = 0;

    while ((cp / i) == 0)
        i = i / 10;
    while (i > 1) {
        cp = cp / i;
        my_putchar('0' + cp);
        count++;
        cp = cp * i;
        nb = nb - cp;
        i = i / 10;
        if (i > 1){
            cp = nb;
        }
    }
    my_putchar('0' + nb);
    return count + 1;
}

int my_putnbr(int nb)
{
    long nbl = (long)nb;

    if (nbl > 0)
        return displaynb(nbl);
    else if (nbl < 0) {
        my_putchar('-');
        nbl = nbl - nbl - nbl;
        return 1 + displaynb(nbl);
    } else
        return my_putchar('0');
}
