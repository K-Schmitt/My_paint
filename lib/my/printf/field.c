/*
** EPITECH PROJECT, 2022
** field size
** File description:
** determinate and print field size
*/
#include "../my.h"
#include "pmy.h"

char *field_suite(char *str, int nb)
{
    int taille_zero = nb - my_strlen(str);
    int temp = taille_zero;
    char *zero = malloc(sizeof(char) * nb + 1);
    zero[temp - 1] = '\0';
    int gt = 0;
    for (; temp > 0; gt++) {
        zero[gt] = ' ';
        temp--;
    }
    return (zero);
}

int field_size(char *str, int nb, const char *format, int i)
{
    int lenght = my_strlen(str);
    if (lenght == 0)
        return (84);
    if (lenght >= nb) {
        decflag(str, format, i, nb);
        return (0);
    }
    if (nb == 0) {
        decflag(str, format, i, nb);
        return (0);
    }
    char *zero = field_suite(str, nb);
    my_strcat(zero, str);
    i++;
    decflag(zero, format, i, nb);
    return (0);
}
