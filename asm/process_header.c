/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** process_header
*/
#include <stdlib.h>
#include "corewar.h"
#include "op.h"
#include "my.h"

static void print_header(asm_t *asm_s, int name)
{
    int zero = 0;
    static int go_in_if = 0;

    if (name != 2)
        exit(84);
    if (go_in_if == 0) {
        go_in_if = 1;
        asm_s->output = fopen(asm_s->output_name, "w");
        if (asm_s->output == NULL)
            exit(84);
        fwrite(&asm_s->header->magic, sizeof(int), 1, asm_s->output);
        fwrite(asm_s->header->prog_name, sizeof(char) * PROG_NAME_LENGTH,
            1, asm_s->output);
        fwrite(&zero, sizeof(int), 1, asm_s->output);
        fwrite(&asm_s->header->prog_size, sizeof(int), 1, asm_s->output);
        fwrite(asm_s->header->comment, sizeof(char) * COMMENT_LENGTH,
            1, asm_s->output);
        fwrite(&zero, sizeof(int), 1, asm_s->output);
    }
}

static int check_if_comment(int name, char *word, asm_t *asm_s)
{
    if (name != 2)
        exit(84);
    check_comment_length(word);
    my_strcpy(asm_s->header->comment, word);
    return (2);
}

void process_word_header(char *word, asm_t *asm_s, int check)
{
    static int name = 0;
    static int comment = 0;

    if (check == 1) {
        print_header(asm_s, name);
        return;
    }
    if (name == 1) {
        name = 2;
        check_name_length(word);
        my_strcpy(asm_s->header->prog_name, word);
    }
    if (comment == 1)
        comment = check_if_comment(name, word, asm_s);
    if (my_strcmp(word, NAME_CMD_STRING) == 0)
        name = update_if_name(name);
    if (my_strcmp(word, COMMENT_CMD_STRING) == 0)
        comment = update_if_comment(comment);
}

void separate_line_header(char *line, asm_t *asm_s)
{
    char **arr = my_str_to_word_arr(line, "\t ");

    for (int i = 0; arr[i] != NULL; i++)
        process_word_header(arr[i], asm_s, 0);
    free_double_array(arr);
    return;
}
