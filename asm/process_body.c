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

static void is_in_label_chars(char c)
{
    for (int j = 0; LABEL_CHARS[j] != '\0'; j++) {
        if (c == LABEL_CHARS[j] || c == LABEL_CHAR)
            return;
    }
    exit(84);
}

int check_label_chars(char *label, int start)
{
    for (int i = start; label[i + 1] != '\0'; i++)
        is_in_label_chars(label[i]);
    return (0);
}

void process_command(char **arr, asm_t *asm_s)
{
    int start = 0;
    int arr_size = arr_len(arr);

    if (arr[0][my_strlen(arr[0]) - 1] == LABEL_CHAR) {
        start = 1;
        check_label_chars(arr[0], 0);
    }
    if (arr_size == 1 && arr[0][my_strlen(arr[0]) - 1] != LABEL_CHAR)
        exit(84);
    if (arr_size != 1)
        do_if_command(arr, asm_s, start);
}
