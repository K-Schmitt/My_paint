/*
** EPITECH PROJECT, 2022
** flag1
** File description:
** flag1
*/
#include "../my.h"
#include "pmy.h"

int positive_sign_suite(char *str, int *fus, char *flag, const char *format)
{
    int nb = fus[0];
    int taille_totale = my_strlen(str) + 1;
    char *taille = malloc(sizeof(char) * (taille_totale));
    taille[taille_totale - 1] = '\0';
    if (str[0] == '0' && str[nb] >= 48 && str[nb] <= 57)
        str[0] = '+';
    if (str[0] >= 48 && str[0] <= 57) {
        taille[0] = '+';
        taille[1] = '\0';
        my_strcat(taille, str);
        char size[my_strlen(flag) - 1];
        char *nflag = reduc_positive(flag, size);
        return (gestionflag(taille, fus, nflag, format));
    }
    return (0);
}

int positive_sign(char *str, int *fus, char *flag, const char *format)
{
    int i = 0;
    while (str [i] != '-' && str[i] != '\0')
        i++;
    if (str[i] == '-') {
        char size[my_strlen(flag) - 1];
        char *nflag = reduc_positive(flag, size);
        return (gestionflag(str, fus, nflag, format));
        }
    positive_sign_suite(str, fus, flag, format);
    return (1);
}

int zero(char *str, int *fus, char *flag, const char *format)
{
    for (int y = 0; str[y] >= 48 && str[y] <= 57; y++) {
        if (str[y] == '\0') {
            char size[my_strlen(flag) - 1];
            char *nflag = reduc_zero(flag, size);
            return (gestionflag(str, fus, nflag, format));
        }
    }
    for (int i = 0; str[i] == ' '; i++)
        str[i] = '0';
    char size[my_strlen(flag) - 1];
    char *nflag = reduc_zero(flag, size);
    return (gestionflag(str, fus, nflag, format));
}

int space_suite(char *str, int *fus, char *flag, const char *format)
{
    int nb = fus[0];
    int taille_totale = my_strlen(str) + 1;
    char *taille_deux = malloc(sizeof(char) * (taille_totale));
    taille_deux[taille_totale - 1] = '\0';
    if (str[0] == '0' && str[nb] >= 48 && str[nb] <= 57) {
        taille_deux[0] = ' ';
        char size[my_strlen(flag) - 1];
        char *nflag = reduc_space(flag, size);
        return (gestionflag(taille_deux, fus, nflag, format));
    } else {
        char size[my_strlen(flag) - 1];
        char *nflag = reduc_space(flag, size);
        return (gestionflag(str, fus, nflag, format));
    }
}

int space(char *str, int *fus, char *flag, const char *format)
{
    int taille_totale = my_strlen(str) + 1;
    char *taille = malloc(sizeof(char) * (taille_totale));
    taille[taille_totale - 1] = '\0';
    if (str[0] >= 48 && str[0] <= 57) {
        taille[0] = ' ';
        taille[1] = '\0';
        my_strcat(taille, str);
    } else  {
        space_suite(str, fus, flag, format);
        }
    char size[my_strlen(flag) - 1];
    char *nflag = reduc_space(flag, size);
    return (gestionflag(taille, fus, nflag, format));
}
