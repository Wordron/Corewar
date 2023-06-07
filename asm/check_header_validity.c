/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** check_header_validity
*/
#include <stdlib.h>
#include "corewar.h"
#include "op.h"
#include "my.h"

int update_if_comment(int comment)
{
    if (comment != 0)
        exit(84);
    return (1);
}

int update_if_name(int name)
{
    if (name != 0)
        exit(84);
    return (1);
}

void check_name_length(char *word)
{
    if (my_strlen(word) > PROG_NAME_LENGTH)
        exit(84);
}

void check_comment_length(char *word)
{
    if (my_strlen(word) > COMMENT_LENGTH)
        exit(84);
}
