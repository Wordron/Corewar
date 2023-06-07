/*
** EPITECH PROJECT, 2023
** display.c
** File description:
** display
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "corewar.h"
#include "op.h"
#include "my.h"

void display_alive(champ_t *champion)
{
    my_putstr("The player ");
    my_put_nbr(champion->id);
    my_putchar('(');
    my_putstr(champion->name_champ);
    my_putstr(")is alive.\n");
}

void display_winner(champ_t *champion)
{
    my_putstr("The player ");
    my_put_nbr(champion->id);
    my_putchar('(');
    my_putstr(champion->name_champ);
    my_putstr(")has won.\n");
}
