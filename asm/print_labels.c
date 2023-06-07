/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** print_labels
*/
#include <stdlib.h>
#include "corewar.h"
#include "my.h"

int find_which_label(label_t **labels, char *label)
{
    for (int i = 0; labels[i] != NULL; i++) {
        if (my_strcmp(label, labels[i]->label_name) == 0)
            return (i);
    }
    exit(84);
}

void print_labels(asm_t *asm_s, char *label)
{
    int which_label = find_which_label(asm_s->labels, label);
    int diff = asm_s->labels[which_label]->position - asm_s->where_bytes;
    int what_to_print = 0;

    if (diff < 0) {
        what_to_print = 0xffffffff + diff;
        what_to_print = (CONVERT_ENDIAN(what_to_print)) >> 16;
        fwrite(&what_to_print, 2, 1, asm_s->output);
        return;
    }
    if (diff >= 0) {
        what_to_print = diff - 1;
        what_to_print = (CONVERT_ENDIAN(what_to_print)) >> 16;
        fwrite(&what_to_print, 2, 1, asm_s->output);
        return;
    }
}

void do_if_indirect_label(char *arg, asm_t *asm_s)
{
    char **arr = NULL;
    char *delim = NULL;

    delim = create_delim_direct_label();
    arr = my_str_to_word_arr(arg, delim);
    asm_s->temp_where_bytes = asm_s->temp_where_bytes + 2;
    print_labels(asm_s, arr[0]);
}
