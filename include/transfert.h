/*
** EPITECH PROJECT, 2019
** 107transfert
** File description:
** 107transfert functions
*/

#ifndef TRANSFERT_H
#define TRANSFERT_H

typedef struct data {
    int len;
    double **numerator;
    double **denominator;
} data_t;

typedef struct nb_list {
    double *list;
    int len;
} nb_list_t;

int transfert(nb_list_t *lists);

#endif /*TRANSFERT_H*/
