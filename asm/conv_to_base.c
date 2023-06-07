/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** conv_to_base
*/
#include <stdlib.h>
#include "my.h"

static int rev_nb(int i, char *nb_base_temp, FILE *output)
{
    int t = 0;
    int z = 0;
    int j = 0;
    int count = 0;
    char temp;

    for (j = i - 1; j > t; j--) {
        temp = nb_base_temp[t];
        nb_base_temp[t] = nb_base_temp[j];
        nb_base_temp[j] = temp;
        t++;
    }
    for (z = 0; z < i; z++) {
        my_fputchar(nb_base_temp[z], output);
        count++;
    }
    return (count);
}

int conv_to_base(unsigned long nb, int base, FILE *output)
{
    int i = 0;
    int rest = 0;
    char nb_base_temp[200];

    if (nb == 0)
        my_fputchar('0', output);
    while (nb > 0) {
        rest = nb % base;
        if (rest < 10)
            nb_base_temp[i] = rest + 48;
        else
            nb_base_temp[i] = rest + 87;
        nb = nb / base;
        i++;
    }
    return (rev_nb(i, nb_base_temp, output));
}

int conv_bin_to_hexa(long int binary)
{
    int decimal_num = 0;
    int base = 1;
    int rem = 0;

    while (binary > 0) {
        rem = binary % 10;
        decimal_num = decimal_num + rem * base;
        binary = binary / 10;
        base = base * 2;
    }
    return (decimal_num);
}
