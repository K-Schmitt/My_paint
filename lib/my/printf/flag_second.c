/*
** EPITECH PROJECT, 2022
** flag
** File description:
** flag2
*/
#include "pmy.h"
#include "../my.h"

int minus(char *str, int *fus, char *flag, const char *format)
{
    int nb = fus[0];
    int taille_fonction = my_strlen(str);
    int size = nb - taille_fonction;
    char *temp = malloc(sizeof (char) * taille_fonction + 1);
    temp[taille_fonction - 1] = '\0';
    if (str[0] == '0') {
        for (int i = 0; str[i] == 0; i++)
            temp[i] = str[i + size];
    }
    if (str[0] == ' ') {
        for (int i = 0; str[i] == 0; i++)
            temp[i] = str[i + size];
    }
    my_strncat(temp, str, size);
    char taille[my_strlen(flag) - 1];
    char *nflag = reduc_minus(flag, taille);
    return (gestionflag(temp, fus, nflag, format));
}
