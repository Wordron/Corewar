/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** get_bin_from_hexa
*/
#include <stdlib.h>
#include "my.h"

static char *get_bin_from_hexa_3(char c, char *bin)
{
    if (c == 'e')
        my_strcat(bin, "1110");
    if (c == 'f')
        my_strcat(bin, "1111");
    return (bin);
}

static char *get_bin_from_hexa_2(char c, char *bin)
{
    if (c == '6')
        my_strcat(bin, "0110");
    if (c == '7')
        my_strcat(bin, "0111");
    if (c == '8')
        my_strcat(bin, "1000");
    if (c == '9')
        my_strcat(bin, "1001");
    if (c == 'a')
        my_strcat(bin, "1010");
    if (c == 'b')
        my_strcat(bin, "1011");
    if (c == 'c')
        my_strcat(bin, "1100");
    if (c == 'd')
        my_strcat(bin, "1101");
    bin = get_bin_from_hexa_3(c, bin);
    return (bin);
}

char *get_bin_from_hexa(char *hexa)
{
    char *bin = malloc(sizeof(char) * 200);

    for (int i = 0; i != my_strlen(hexa); i++) {
        if (hexa[i] == '0')
            my_strcat(bin, "0000");
        if (hexa[i] == '1')
            my_strcat(bin, "0001");
        if (hexa[i] == '2')
            my_strcat(bin, "0010");
        if (hexa[i] == '3')
            my_strcat(bin, "0011");
        if (hexa[i] == '4')
            my_strcat(bin, "0100");
        if (hexa[i] == '5')
            my_strcat(bin, "0101");
        bin = get_bin_from_hexa_2(hexa[i], bin);
    }
    return (bin);
}
