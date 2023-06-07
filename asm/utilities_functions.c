/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** utilities_functions
*/
#include <stdlib.h>
#include "my.h"

char *get_label_without_two_points(char *str)
{
    int size = my_strlen(str) - 1;
    char *result = malloc(sizeof(char) * size + 1);
    int i = 0;

    for (i = 0; i != size; i++)
        result[i] = str[i];
    result[i] = 0;
    free(str);
    return (result);
}

static int strlen_before_two(char *str)
{
    int i = 0;

    while (i < 8 && str[i] != '2')
        i++;
    return (i);
}

void parameters_cat(char *parameters, char *src)
{
    int when = 0;

    when = strlen_before_two(parameters);
    parameters[when] = src[0];
    parameters[when + 1] = src[1];
}

void free_double_array(char **arr)
{
    if (arr == NULL)
        return;
    for (int i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(arr);
}

int arr_len(char **arr)
{
    int size = 0;

    while (arr[size] != NULL)
        size++;
    return (size);
}
