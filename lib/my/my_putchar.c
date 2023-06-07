/*
** EPITECH PROJECT, 2022
** my_putchar.c
** File description:
** write the letter
*/
#include <stdio.h>
#include <unistd.h>

void my_fputchar(char c, FILE *where)
{
    fwrite(&c, 1, 1, where);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}
