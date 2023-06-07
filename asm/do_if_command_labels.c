/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** do_if_command
*/
#include <stdlib.h>
#include "corewar.h"
#include "op.h"
#include "my.h"

int check_command(char *command)
{
    for (int i = 0; op_tab[i].code != 0; i++) {
        if (my_strcmp(op_tab[i].mnemonique, command) == 0)
            return (i);
    }
    exit(84);
}

static void check_for_coding_byte(int which_command, asm_t *asm_s)
{
    if (my_strcmp(op_tab[which_command].mnemonique, "live") != 0 &&
        my_strcmp(op_tab[which_command].mnemonique, "zjmp") != 0 &&
        my_strcmp(op_tab[which_command].mnemonique, "fork") != 0 &&
        my_strcmp(op_tab[which_command].mnemonique, "lfork") != 0)
        asm_s->header->prog_size++;
}

enum e_where_index where_is_index(int which_command)
{
    if (my_strcmp(op_tab[which_command].mnemonique, "zjmp") == 0 ||
        my_strcmp(op_tab[which_command].mnemonique, "fork") == 0)
        return (FIRST_ONE);
    if (my_strcmp(op_tab[which_command].mnemonique, "ldi") == 0)
        return (FIRST_TWO);
    if (my_strcmp(op_tab[which_command].mnemonique, "sti") == 0)
        return (LAST_TWO);
    return (NONE);
}

void do_if_command_labels(char **arr, asm_t *asm_s, int start, int arr_size)
{
    int which_command = 0;

    which_command = check_command(arr[start]);
    if ((arr_size - (start + 1)) != (op_tab[which_command].nbr_args))
        exit(84);
    asm_s->header->prog_size++;
    for (unsigned int i = start + 1; arr[i] != NULL; i++)
        check_which_type(arr[i], op_tab[which_command].type[i - (start + 1)]);
    check_for_coding_byte(which_command, asm_s);
    for (unsigned int i = start + 1; arr[i] != NULL; i++)
        process_args_labels(arr[i], asm_s, which_command, i);
}
