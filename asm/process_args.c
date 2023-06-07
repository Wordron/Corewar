/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** process_args
*/
#include <stdlib.h>
#include "corewar.h"
#include "op.h"
#include "my.h"

int my_is_num(char *str, int start)
{
    for (int i = start; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (1);
    }
    return (0);
}

static char *process_direct_char(char *arg, char *parameters)
{
    if (my_strlen(arg) == 1)
        exit(84);
    if (arg[1] == LABEL_CHAR && check_label_chars(arg, 1) == 0) {
        parameters_cat(parameters, "10");
        return (parameters);
    }
    if (my_is_num(arg, 1) == 0) {
        parameters_cat(parameters, "10");
        return (parameters);
    }
    exit(84);
    return (parameters);
}

static char *process_register(char *arg, char *parameters)
{
    int nb = 0;

    if (my_strlen(arg) == 1)
        exit(84);
    nb = my_getnbr(arg, 1);
    if (nb > 0 && nb <= REG_NUMBER) {
        parameters_cat(parameters, "01");
        return (parameters);
    }
    exit(84);
    return (parameters);
}

char *process_args(char *arg, char *parameters)
{
    if (arg[0] == DIRECT_CHAR)
        return (process_direct_char(arg, parameters));
    if (arg[0] == 'r')
        return (process_register(arg, parameters));
    if (my_is_num(arg, 0) == 0) {
        parameters_cat(parameters, "11");
        return (parameters);
    }
    if (arg[0] == LABEL_CHAR && check_label_chars(arg, 1) == 0) {
        parameters_cat(parameters, "11");
        return (parameters);
    }
    exit(84);
    return (parameters);
}
