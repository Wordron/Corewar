/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** check_type
*/
#include <stdlib.h>
#include "corewar.h"
#include "op.h"
#include "my.h"

static char check_direct_char(char *arg)
{
    if (my_strlen(arg) == 1)
        exit(84);
    if (arg[1] == LABEL_CHAR && check_label_chars(arg, 1) == 0)
        return (T_DIR);
    if (my_is_num(arg, 1) == 0)
        return (T_DIR);
    return (0);
}

static char process_register(char *arg)
{
    int nb = 0;

    if (my_strlen(arg) == 1)
        exit(84);
    nb = my_getnbr(arg, 1);
    if (nb > 0 && nb <= REG_NUMBER)
        return (T_REG);
    return (0);
}

char check_type(char *arg)
{
    if (arg[0] == DIRECT_CHAR)
        return (check_direct_char(arg));
    if (arg[0] == 'r')
        return (process_register(arg));
    if (my_is_num(arg, 0) == 0)
        return (T_IND);
    if (arg[0] == LABEL_CHAR && check_label_chars(arg, 1) == 0)
        return (T_IND);
    return (0);
}

void check_which_type(char *arg, args_type_t args_type)
{
    char parameters = check_type(arg);
    char tmp = parameters & args_type;

    if (tmp == 0)
        exit(84);
    return;
}
