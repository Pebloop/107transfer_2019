/*
** EPITECH PROJECT, 2020
** 107transfert
** File description:
** 107transfert
*/

#include <stdio.h>
#include "transfert.h"

double get_result(nb_list_t list, double x)
{
    int len = list.len;
    double num = list.list[len - 1];

    for (int y = len - 2; y >= 0; y--) {
        num = num * x + list.list[y];
    }
    return num;
}

int calculate(nb_list_t *lists, double x)
{
    double result = 1;

    for (int i = 0; lists[i].list != 0; i+=2) {
        double numerator = get_result(lists[i], x);
        double denominator = get_result(lists[i + 1], x);
        if (denominator == 0)
            return 84;
        result *= numerator / denominator;
    }
    printf("%.5f\n", result);
    return 0;
}

int transfert(nb_list_t *lists)
{
    for (double i = 0; i <= 1.001; i += 0.001) {
        printf("%.3f -> ", i);
        if (calculate(lists, i))
            return 84;
    }
	return 0;
}
