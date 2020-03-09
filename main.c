/*
** EPITECH PROJECT, 2020
** 107transfert
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
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

int init_transfert(int argc, char **argv)
{
    data_t data = {0};

    for (int i = 1; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
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
