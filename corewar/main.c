/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "corewar.h"
#include "op.h"
#include "my.h"

int my_is_num_2(char *str, int start)
{
    for (int i = start; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (1);
    }
    return (0);
}

static void init(vm_t *vm, int ac, char **av)
{
    vm->ac = ac;
    vm->av = av;
    vm->cycle_die = CYCLE_TO_DIE;
    vm->nb_live = 2;
    vm->nb_champions_alive = 10;
    vm->nb_tot_champ = 10;
    vm->nb_cycle_dump = 30;
}

void free_everything(vm_t *vm)
{
    for (int i = 0; i != vm->ac; i++)
        free(vm->av[i]);
    free(vm->av);
}

int main(int ac, char **av)
{
    vm_t *vm = malloc(sizeof(vm_t));

    if (ac < 2) {
        free(vm);
        return (84);
    }
    init(vm, ac, av);
    get_args(vm);
    if ((vm->nb_cycle_dump == 0) | (vm->nb_tot_champ == 0))
        return (84);
    vm->champs = malloc(sizeof(champ_t *) * vm->nb_tot_champ);
    for (int i = 0; i != vm->nb_tot_champ; i++) {
        vm->champs[i] = malloc(sizeof(champ_t));
        vm->champs[i]->registers = REG_NUMBER;
    }
    main_loop(vm);
    return (0);
}
