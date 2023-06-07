/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** process_args
*/
#include <stdlib.h>
#include "corewar.h"
#include "op.h"
#include "my.h"

int get_param_size(enum e_where_index where, int i)
{
    if ((where == FIRST_ONE && i == 1) || (where == FIRST_TWO && i <= 1) ||
        (where == LAST_TWO && i >= 1))
        return (IND_SIZE);
    return (DIR_SIZE);
}

static void process_direct_char_labels(char *arg, asm_t *asm_s,
    enum e_where_index where, int i)
{
    if (my_strlen(arg) == 1)
        exit(84);
    if (arg[1] == LABEL_CHAR && check_label_chars(arg, 1) == 0) {
        asm_s->header->prog_size = asm_s->header->prog_size + IND_SIZE;
        return;
    }
    if (my_is_num(arg, 1) == 0) {
        asm_s->header->prog_size = asm_s->header->prog_size +
            get_param_size(where, i);
        return;
    }
    exit(84);
}

static void process_register_labels(char *arg, asm_t *asm_s)
{
    int nb = 0;

    if (my_strlen(arg) == 1)
        exit(84);
    nb = my_getnbr(arg, 1);
    if (nb > 0 && nb <= REG_NUMBER) {
        asm_s->header->prog_size++;
        return;
    }
    exit(84);
}

void process_args_labels(char *arg, asm_t *asm_s, int which_command, int i)
{
    enum e_where_index where = where_is_index(which_command);

    if (arg[0] == DIRECT_CHAR)
        return (process_direct_char_labels(arg, asm_s, where, i));
    if (arg[0] == 'r')
        return (process_register_labels(arg, asm_s));
    if (my_is_num(arg, 0) == 0) {
        asm_s->header->prog_size = asm_s->header->prog_size + IND_SIZE;
        return;
    }
    if (arg[0] == LABEL_CHAR && check_label_chars(arg, 1) == 0) {
        asm_s->header->prog_size = asm_s->header->prog_size + IND_SIZE;
        return;
    }
    exit(84);
}
