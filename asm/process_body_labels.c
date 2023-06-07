/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** process_body
*/
#include <stdlib.h>
#include "corewar.h"
#include "op.h"
#include "my.h"

static int get_labels_size(label_t **labels)
{
    int size = 0;

    while (labels[size] != NULL)
        size++;
    return (size);
}

static void check_label_def(char *label_name, label_t **labels)
{
    for (int i = 0; labels[i] != NULL; i++) {
        if (my_strcmp(labels[i]->label_name, label_name) == 0)
            exit(84);
    }
}

void process_command_labels(char **arr, asm_t *asm_s)
{
    int labels_size = get_labels_size(asm_s->labels) + 1;
    int arr_size = arr_len(arr);
    int start = 0;
    if (arr[0][my_strlen(arr[0]) - 1] == LABEL_CHAR) {
        check_label_def(arr[0], asm_s->labels);
        check_label_chars(arr[0], 0);
        asm_s->labels = realloc(asm_s->labels, sizeof(label_t *)
            * (labels_size + 1));
        asm_s->labels[labels_size - 1] = malloc(sizeof(label_t));
        asm_s->labels[labels_size - 1]->label_name = malloc(sizeof(char)
            * (my_strlen(arr[0]) + 1));
        asm_s->labels[labels_size - 1]->position = asm_s->header->prog_size + 1;
        my_strcpy(asm_s->labels[labels_size - 1]->label_name, arr[0]);
        asm_s->labels[labels_size] = NULL;
        start = 1;
    }
    if (arr_size == 1 && arr[0][my_strlen(arr[0]) - 1] != LABEL_CHAR)
        exit(84);
    if (arr_size != 1)
        do_if_command_labels(arr, asm_s, start, arr_size);
}
