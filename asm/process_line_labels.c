/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** process_line
*/
#include <stdlib.h>
#include "corewar.h"
#include "op.h"
#include "my.h"

int check_line_emptyness(char *line)
{
    char **arr = my_str_to_word_arr(line, " \t\n");

    if (arr[0] == NULL) {
        free_double_array(arr);
        return (1);
    }
    free_double_array(arr);
    return (0);
}

static char *create_delim_labels(void)
{
    char *delim = malloc(sizeof(char) * 5);

    delim[0] = '\t';
    delim[1] = '\n';
    delim[2] = ' ';
    delim[3] = SEPARATOR_CHAR;
    delim[4] = '\0';
    return (delim);
}

static void separate_line_body_labels(char *line, asm_t *asm_s)
{
    char *delim = create_delim_labels();
    char **arr = my_str_to_word_arr(line, delim);

    process_command_labels(arr, asm_s);
    free_double_array(arr);
    return;
}

static void check_for_quotes_labels(char *str, asm_t *asm_s)
{
    char **arr = my_str_to_word_arr(str, "\"");
    int temp = check_line_emptyness(str);

    if (temp == 1)
        return;
    if (arr[1] == NULL)
        separate_line_body_labels(str, asm_s);
    free_double_array(arr);
    return;
}

void check_for_commentaries_labels(char *str, asm_t *asm_s)
{
    char *comment = malloc(sizeof(char) * 2);
    char **arr_commentaries = NULL;

    comment[0] = COMMENT_CHAR;
    comment[1] = '\0';
    arr_commentaries = my_str_to_word_arr(str, comment);
    check_for_quotes_labels(arr_commentaries[0], asm_s);
    free_double_array(arr_commentaries);
    free(comment);
}
