/*
** EPITECH PROJECT, 2019
** libfae
** File description:
** Return a number from a string (int)
*/

#include "fae.h"

int fae_stoi(char const *str, char const **end)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    if (end)
        *end = str;
    if (!(fae_char_is_num(*str) || *str == '+' || *str == '-'))
        return 0;
    for (; str[i] == '+' || str[i] == '-'; i++)
        sign *= (str[i] == '-') ? -1 : 1;
    for (; fae_char_is_num(str[i]); i++) {
        result *= 10;
        result += ((str[i] - '0') * (sign > 0 ? 1 : -1));
        if ((result < 0 && sign > 0) || (result > 0 && sign < 0))
            return 0;
    }
    if (end)
        *end = &(str[i]);
    return result;
}

char *fae_itos(int nb)
{
    char *str = "           ";
    int i = (nb < 0 ? 1 : 0) + fae_nblen(nb);

    for (int y = 0; y < 11; y++)
        str[y] = '\0';
    str[0] = (nb < 0) ? '-' : '\0';
    for (; nb != 0; i--) {
        str[i] = (nb % 10) + '0';
        nb /= 10;
    }
    return str;
}
