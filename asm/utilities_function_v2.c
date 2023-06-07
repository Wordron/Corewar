/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** utilities_function_v2
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "corewar.h"
#include "op.h"
#include "my.h"

char *int_copy_in_char(char *nb, int new_size)
{
    char *new_char = malloc(sizeof(char) * (new_size + 1));
    int k = sizeof(int);
    int j = 0;

    for (int i = 0; i < new_size; i++)
        new_char[i] = 0;
    for (int i = new_size; j < (int)sizeof(int) && j < new_size; i = i - 1) {
        new_char[i] = nb[k];
        j++;
        k = k - 1;
    }
    return (new_char);
}

static char *do_loop_of_strstr(char *str, char const *to_find)
{
    int ind_str = 0;

    while (to_find[ind_str] != '\0') {
        if (to_find[ind_str] != str[ind_str])
            return (my_strstr(str + 1, to_find));
        ind_str++;
    }
    return (str);
}

char *my_strstr(char *str, char const *to_find)
{
    if (str[0] != '\0') {
        return (do_loop_of_strstr(str, to_find));
    } else
        return (0);
}
