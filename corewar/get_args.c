/*
** EPITECH PROJECT, 2023
** get_args.c
** File description:
** get_args
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "corewar.h"
#include "op.h"
#include "my.h"

int check_if_arg_number(char *str)
{
    int nb = 0;

    if (my_is_num_2(str, 0) == 0) {
        nb = atoi(str);
        return (nb);
    } else
        return (-1);
}

int my_is_hexa(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < '0' || str[i] > '9') && (str[i] < 'a' || str[i] > 'f'))
            return (1);
    }
    return (0);
}

void count_tot_champ(int n, int a, int ac, vm_t *vm)
{
    n *= 2;
    a *= 2;
    ac = ac - n - a - 3;
    vm->nb_tot_champ = ac;
    vm->nb_champions_alive = ac;
    return;
}

void get_tot_champ(vm_t *vm)
{
    int n = 0;
    int a = 0;
    int ac = vm->ac;

    for (int i = 3; i != vm->ac; i++) {
        if (my_strcmp(vm->av[i], "-n") == 0 && vm->av[i + 1] != NULL
            && my_is_num_2(vm->av[i + 1], 0) == 0) {
            printf("n\n");
            n++;
        }
        if (my_strcmp(vm->av[i], "-a") == 0 && vm->av[i + 1] != NULL
            && my_is_hexa(vm->av[i + 1]) == 0) {
            printf("a\n");
            a++;
        }
    }
    count_tot_champ(n, a, ac, vm);
    return;
}

void get_args(vm_t *vm)
{
    get_tot_champ(vm);
    for (int k = 0; k != vm->ac; k++) {
        if (my_strcmp(vm->av[k], "-dump") == 0 && vm->av[k + 1] != NULL)
            vm->nb_cycle_dump = check_if_arg_number(vm->av[k + 1]);
    }
}
