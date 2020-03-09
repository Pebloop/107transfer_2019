/*
** EPITECH PROJECT, 2019
** libfae
** File description:
** Display a character
*/

#include <unistd.h>

void fae_putchar(char c)
{
    write(1, &c, 1);
}
