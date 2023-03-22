/*
** EPITECH PROJECT, 2022
** hashtag
** File description:
** hashtag case
*/
#include "pmy.h"
#include "../my.h"
char *extra_for(char *flag, char *size)
{
    int u;
    for (u = 0; flag[u + 1] != '\0'; u++)
        size[u] = flag[u + 1];
    size[u] = '\0';
    return (size);
}

char hashtag_o(char *str, int *fus, char *flag, const char *format)
{
    if (str[0] == '0')
        return (0);
    else {
    int taille_totale = my_strlen(str) + 2;
    char *taille = malloc(sizeof(char) * (taille_totale));
    taille[taille_totale - 1] = '\0';
    taille[0] = '0';
    my_strcat(taille, str);
    char test[my_strlen(flag) - 1];
    char *nflag = reduc_hashtag(flag, test);
    return (gestionflag(taille, fus, nflag, format));
    }
}

char hashtag_x(char *str, int *fus, char *flag, const char *format)
{
    if (str[0] == '0')
        return (0);
    else {
    int taille_totale = my_strlen(str) + 3;
    char *taille = malloc(sizeof(char) * (taille_totale));
    taille[taille_totale - 1] = '\0';
    taille[0] = '0';
    taille[1] = 'x';
    my_strcat(taille, str);
    char test[my_strlen(flag) - 1];
    char *nflag = reduc_hashtag(flag, test);
    return (gestionflag(taille, fus, nflag, format));
    }
}

char hashtag_grand_x(char *str, int *fus, char *flag, const char *format)
{
    if (str[0] == '0')
        return (0);
    else {
    int taille_totale = my_strlen(str) + 3;
    char *taille = malloc(sizeof(char) * (taille_totale));
    taille[taille_totale - 1] = '\0';
    taille[0] = '0';
    taille[1] = 'X';
    my_strcat(taille, str);
    char test[my_strlen(flag) - 1];
    char *nflag = reduc_hashtag(flag, test);
    return (gestionflag(taille, fus, nflag, format));
    }
}

int hashtag(char *str, int *fus, char *flag, const char *format)
{
    int nb = fus[0];
    int y = detection(format, nb);
    if (y == 2) {
        hashtag_o(str, fus, flag, format);
    }
    if (y == 4)
        hashtag_x(str, fus, flag, format);
    if (y == 5)
        hashtag_grand_x(str, fus, flag, format);
    else {
        char test[my_strlen(flag) - 1];
        char *nflag = reduc_hashtag(flag, test);
        return (gestionflag(str, fus, nflag, format));
    }
    return (0);
}
