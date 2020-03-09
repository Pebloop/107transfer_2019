/*
** EPITECH PROJECT, 2020
** 107transfert
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "transfert.h"

void display_usage(void)
{
    printf("USAGE\n");
    printf("    ./107transfert [num den]*\n");
    printf("\n");
    printf("DESCRIPTION\n");
    printf("    num    polynomial numerator defined by its coefficients\n");
    printf("    den    polynomial denominator defined by its coefficients\n");
}

int check_integrity(char *chain, nb_list_t *list)
{
    int len = 1;

    for (int i = 0; chain[i]; i++)
        if (chain[i] == '*')
            len++;
    list->len = len;
    list->list = malloc(sizeof(double) * len);
    if (chain[0] < '0' && chain[0] > '9' && chain[0] != '-' && chain[0] != '+')
        return 84;
    for (int t = 0;chain && *chain != '\0'; chain++) {
        list->list[t] = strtof(chain, &chain);
        if (*chain != '*' && *chain != '\0' && (*chain == '*' && chain[1] == '\0')) {
            free(list->list);
            return 0;
        }
        if (*chain == '\0')
            return 1;
        t++;
    }
    return 1;
}

void free_data(nb_list_t *data)
{
    for (int i = 0; data[i].list != 0; i++)
        free(data[i].list);
    free(data);
}

int init_transfert(int argc, char **argv)
{
    nb_list_t *data = malloc(sizeof(nb_list_t) * (argc + 1));
    int tr_value = 0;

    for (int i = 0; i <= argc; i++)
        data[i] = (nb_list_t){0};
    for (int i = 1; i < argc; i++) {
        if (!check_integrity(argv[i], &(data[i - 1]))) {
            free_data(data);
            return 84;
        }
    }
    tr_value = transfert(data);
    free_data(data);
    return tr_value;
}

int main(int argc, char **argv)
{
    if (argc == 2 && !strcmp(argv[1], "-h")) {
        display_usage();
        return 0;
    } else if (argc > 2 && (argc % 2)) {
	   return init_transfert(argc, argv);
    }
    return 84;
}
