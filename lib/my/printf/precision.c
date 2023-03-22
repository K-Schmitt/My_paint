/*
** EPITECH PROJECT, 2022
** precision
** File description:
** precision
*/
#include "pmy.h"
#include "../my.h"
int precision_string(char *str, int nb, const char *format, int i)
{
    int taille_fonction = my_strlen(str);
    if (nb >= taille_fonction) {
        dlargeur(str, format, i);
        return (0);
    }
    char *taille_finale = malloc(sizeof(char) * (nb + 1));
    taille_finale[nb - 1] = '\0';
    my_strcat(taille_finale, str);
    dlargeur(taille_finale, format, i);
    return (1);
}

int precision_zero(char *str, int nb, const char *format, int i)
{
    int taille_fonction = my_strlen(str);
    int inc = nb - my_strlen(str);
    char *taille_zero = malloc(sizeof(char) * (nb + 1));
    taille_zero[nb - 1] = '\0';
    if (nb <= taille_fonction)
        dlargeur(str, format, i);
    for (int y = 0; inc > y; y++)
        taille_zero[y] = '0';
    my_strcat(taille_zero, str);
    dlargeur(taille_zero, format, i);
    return (1);
}

int precision_int(char *str, int nb, const char *format, int i)
{
    if (str[0] != '-') {
        precision_zero(str, nb, format, i);
        return (0);
    }
    int taille_fonction = my_strlen(str);
    int inc = nb - my_strlen(str);
    char *taille_zero = malloc(sizeof(char) * (nb + 1));
    taille_zero[nb - 1] = '\0';
    if (nb <= taille_fonction)
        dlargeur(str, format, i);
    taille_zero[0] = '-';
    for (int y = 1; inc >= y; y++)
        taille_zero[y] = '0';
    my_strcat(taille_zero, str);
    dlargeur(taille_zero, format, i);
    return (1);
}

int precision(char *str, int nb, const char *format, int y)
{
    if (nb <= my_strlen(str)) {
        dlargeur(str, format, y);
        return (0);
    }
    int i = detection(format, y);
    if (i >= 2 && i <= 5)
        return (precision_zero(str, nb, format, y));
    if (i >= 0 && i <= 1)
        return (precision_int(str, nb, format, y));
    if (i == 15)
        return (precision_string(str, nb, format, y));
    else {
        return (0);
    }
}
