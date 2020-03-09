/*
** EPITECH PROJECT, 2020
** 107transfert
** File description:
** 107transfert
*/

#include <stdio.h>
#include "transfert.h"

int transfert(nb_list_t *lists)
{
    for (int i = 0; lists[i].list != 0; i++) {
        for (int y = 0; y < lists[i].len; y++)
            printf("%.2f, ", lists[i].list[y]);
        printf("\n");
    }
	return 0;
}
