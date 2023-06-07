/*
** EPITECH PROJECT, 2023
** loop.c
** File description:
** loop
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "corewar.h"
#include "op.h"
#include "my.h"

static int check_cycle_die(vm_t *vm)
{
    if (vm->nb_live >= NBR_LIVE) {
        vm->nb_live = 0;
        vm->cycle_die = vm->cycle_die - CYCLE_DELTA;
    }
    return (0);
}

char *convert_int_to_char(int nb, char nbstr[11], int j)
{
    int temp = 0;

    for (int i = 1; nb != 0; i++) {
        temp = nb % my_compute_power_rec(10, i);
        nb = nb - temp;
        if (i == 1)
            nbstr[j] = temp + '0';
        else
            nbstr[j] = ((temp / my_compute_power_rec(10, i - 1)) + '0');
        j++;
    }
    nbstr[j] = 0;
    return (nbstr);
}

char *get_nbr(int nb)
{
    char nbstr[11] = "\0";
    int j = 0;

    if (nb < 0) {
        nbstr[0] = '-';
        nb = nb * (-1);
        j++;
    }
    if (nb == 0)
        nbstr[j] = '0';
    convert_int_to_char(nb, nbstr, j);
    return (my_revstr(nbstr));
}

static void dump(vm_t *vm)
{
    return;
}

int main_loop(vm_t *vm)
{
    int nb_cycle = 0;

    while (vm->nb_champions_alive > 0) {
        if (nb_cycle == vm->nb_cycle_dump)
            dump(vm);
        check_cycle_die(vm);
        nb_cycle++;
    }
    return (0);
}
