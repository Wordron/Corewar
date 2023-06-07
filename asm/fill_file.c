/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** fill_file
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "corewar.h"
#include "op.h"
#include "my.h"

void get_labels(asm_t *asm_s)
{
    char *str = NULL;
    size_t len = 0;

    asm_s->line = 0;
    while (getline(&str, &len, asm_s->fd) > 0) {
        asm_s->line++;
        if (str[0] != COMMENT_CHAR && my_strcmp(str, "\n") != 0)
            check_for_commentaries_labels(str, asm_s);
        str = NULL;
        len = 0;
    }
    fclose(asm_s->fd);
    asm_s->fd = fopen(asm_s->file_path_input, "r");
    for (int i = 0; asm_s->labels[i] != NULL; i++)
        asm_s->labels[i]->label_name = get_label_without_two_points(
            asm_s->labels[i]->label_name);
}

void get_file(asm_t *asm_s)
{
    char *str = NULL;
    size_t len = 0;

    asm_s->labels = malloc(sizeof(label_t *) * 1);
    asm_s->labels[0] = NULL;
    get_labels(asm_s);
    asm_s->header->prog_size = CONVERT_ENDIAN(asm_s->header->prog_size);
    asm_s->line = 0;
    while (getline(&str, &len, asm_s->fd) > 0) {
        asm_s->line++;
        if (str[0] != COMMENT_CHAR && my_strcmp(str, "\n") != 0)
            check_for_commentaries(str, asm_s);
        str = NULL;
        len = 0;
    }
}

void get_long_from_string(char *string, FILE *output)
{
    long integer = 0;
    int i = 0;

    while (string[i] != '\0') {
        integer = (int)string[i];
        conv_to_base(integer, 16, output);
        i++;
    }
}
