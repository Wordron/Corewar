/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** displays the characters of a string
*/
#include <stdio.h>
#include <unistd.h>

void my_fputchar(char c, FILE *where);
void my_putchar(char c);

int my_fputstr(char const *str, FILE *where)
{
    int i = 0;

    while (str[i] != '\0') {
        my_fputchar(str[i], where);
        i = i + 1;
    }
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
}
