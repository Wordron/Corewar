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

static void print_in_file(int which_command, asm_t *asm_s, char *parameters)
{
    int binary = 0;

    for (int i = 0; i < 8; i++) {
        if (parameters[i] == '2')
            parameters[i] = '0';
    }
    my_fputchar(op_tab[which_command].code, asm_s->output);
    asm_s->temp_where_bytes++;
    if (my_strcmp(op_tab[which_command].mnemonique, "live") != 0 &&
        my_strcmp(op_tab[which_command].mnemonique, "zjmp") != 0 &&
        my_strcmp(op_tab[which_command].mnemonique, "fork") != 0 &&
        my_strcmp(op_tab[which_command].mnemonique, "lfork") != 0) {
        my_strcat(parameters, "\0");
        binary = my_getnbr(parameters, 0);
        binary = conv_bin_to_hexa(binary);
        my_fputchar(binary, asm_s->output);
        asm_s->temp_where_bytes++;
    }
}

static char *create_char_coding_byte(void)
{
    char *parameters = malloc(sizeof(char) * 9);

    for (int i = 0; i < 8; i++)
        parameters[i] = '2';
    parameters[8] = '\0';
    return (parameters);
}

void do_if_command(char **arr, asm_t *asm_s, int start)
{
    char *parameters = create_char_coding_byte();
    enum e_where_index where = NONE;
    int which_command = 0;

    which_command = check_command(arr[start]);
    for (unsigned int i = start + 1; arr[i] != NULL; i++) {
        check_which_type(arr[i], op_tab[which_command].type[i - (start + 1)]);
        parameters = process_args(arr[i], parameters);
    }
    asm_s->temp_where_bytes = 0;
    print_in_file(which_command, asm_s, parameters);
    where = where_is_index(which_command);
    for (unsigned int i = start + 1; arr[i] != NULL; i++)
        print_args(arr[i], asm_s, i - (start + 1), where);
    asm_s->where_bytes = asm_s->where_bytes + asm_s->temp_where_bytes;
    free(parameters);
}
