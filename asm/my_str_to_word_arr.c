/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** main
*/
#include <stdlib.h>
#include <stdio.h>

static int check_if_delim(char c, char *delim)
{
    for (int i = 0; delim[i] != '\0'; i++) {
        if (c == delim[i])
            return (1);
    }
    return (0);
}

static int get_nb_words(char *str, char *delim)
{
    int nb_words = 0;

    for (int i = 0; str[i + 1] != '\0'; i++) {
        if (check_if_delim(str[i], delim) == 1 &&
            check_if_delim(str[i + 1], delim) == 0)
            nb_words++;
    }
    if (check_if_delim(str[0], delim) == 0)
        nb_words++;
    return (nb_words);
}

static char **allocate_arr(char *str, char *delim)
{
    int nb_words = get_nb_words(str, delim);
    char **arr = malloc(sizeof(char *) * (nb_words + 2));
    int size_of_word = 0;
    int j_arr = 0;

    for (int i_str = 0; str[i_str] != '\0'; i_str++) {
        if (check_if_delim(str[i_str], delim) == 0)
            size_of_word++;
        if (((i_str != 0 && check_if_delim(str[i_str - 1], delim) == 0) &&
            check_if_delim(str[i_str], delim) == 1) ||
            str[i_str + 1] == '\0') {
            arr[j_arr] = malloc(sizeof(char) * (size_of_word + 1));
            size_of_word = 0;
            j_arr++;
        }
    }
    return (arr);
}

char **my_str_to_word_arr(char *str, char *delim)
{
    char **arr = allocate_arr(str, delim);
    int i_arr = 0;
    int j_arr = 0;
    for (int i_str = 0; str[i_str] != '\0'; i_str++) {
        if (check_if_delim(str[i_str], delim) == 0) {
            arr[j_arr][i_arr] = str[i_str];
            i_arr++;
        }
        if (((i_str != 0 && check_if_delim(str[i_str - 1], delim) == 0) &&
            check_if_delim(str[i_str], delim) == 1) ||
            str[i_str + 1] == '\0') {
            arr[j_arr][i_arr] = '\0';
            j_arr++;
            i_arr = 0;
        }
    }
    if (arr[j_arr - 1][0] == '\0')
        arr[j_arr - 1] = NULL;
    arr[j_arr] = NULL;
    return (arr);
}
