/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** print_args
*/
#include <stdlib.h>
#include "corewar.h"
#include "op.h"
#include "my.h"

void what_to_print(int nb, asm_t *asm_s, unsigned int i,
    enum e_where_index where)
{
    char *temp = NULL;

    if ((where == FIRST_ONE && i == 1) || (where == FIRST_TWO && i <= 1) ||
        (where == LAST_TWO && i >= 1)) {
        nb = CONVERT_ENDIAN(nb);
        temp = int_copy_in_char((char *)&nb, IND_SIZE);
        fwrite(temp, IND_SIZE, 1, asm_s->output);
        free(temp);
        return;
    }
    nb = CONVERT_ENDIAN(nb);
    temp = int_copy_in_char((char *)&nb, DIR_SIZE);
    fwrite(temp, DIR_SIZE, 1, asm_s->output);
    free(temp);
}

char *create_delim_direct_label(void)
{
    char *delim = malloc(sizeof(char) * 3);

    delim[0] = DIRECT_CHAR;
    delim[1] = LABEL_CHAR;
    delim[2] = '\0';
    return (delim);
}

static void print_direct_char(char *arg, asm_t *asm_s, unsigned int i,
    enum e_where_index where)
{
    char **arr = NULL;
    char *delim = NULL;
    char direct_arg = DIRECT_CHAR;
    int nb = 0;

    if (arg[1] == LABEL_CHAR && check_label_chars(arg, 1) == 0) {
        delim = create_delim_direct_label();
        arr = my_str_to_word_arr(arg, delim);
        asm_s->temp_where_bytes = asm_s->temp_where_bytes + 2;
        print_labels(asm_s, arr[0]);
        return;
    }
    if (my_is_num(arg, 1) == 0) {
        arr = my_str_to_word_arr(arg, &direct_arg);
        nb = my_getnbr(arr[0], 0);
        asm_s->temp_where_bytes = asm_s->temp_where_bytes +
            get_param_size(where, i);
        what_to_print(nb, asm_s, i, where);
    }
}

static void print_register(char *arg, asm_t *asm_s)
{
    int nb = 0;

    nb = my_getnbr(arg, 1);
    if (nb > 0 && nb <= REG_NUMBER) {
        my_fputchar(nb, asm_s->output);
        asm_s->temp_where_bytes++;
    }
}

void print_args(char *arg, asm_t *asm_s, unsigned int i,
    enum e_where_index where)
{
    char *temp = NULL;
    int nb = 0;

    if (arg[0] == DIRECT_CHAR)
        return (print_direct_char(arg, asm_s, i, where));
    if (arg[0] == 'r')
        return (print_register(arg, asm_s));
    if (my_is_num(arg, 0) == 0) {
        nb = my_getnbr(arg, 0);
        nb = CONVERT_ENDIAN(nb);
        temp = int_copy_in_char((char *)&nb, IND_SIZE);
        fwrite(temp, IND_SIZE, 1, asm_s->output);
        asm_s->temp_where_bytes = asm_s->temp_where_bytes + IND_SIZE;
        free(temp);
    } else if (arg[0] == LABEL_CHAR && check_label_chars(arg, 1) == 0)
        do_if_indirect_label(arg, asm_s);
}
