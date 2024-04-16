/*
** EPITECH PROJECT, 2023
** my_nbrlen.c
** File description:
** This function counts the nb of digits of a number.
*/

int my_nbrlen(long long nb)
{
    int count = 0;

    if (nb == 0)
        return 1;
    if (nb < 0)
        count++;
    for (int i = 1; (nb / i) != 0; i *= 10)
        count++;
    return count;
}
