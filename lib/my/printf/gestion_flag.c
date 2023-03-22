/*
** EPITECH PROJECT, 2022
** gestion flag
** File description:
** gestion flag
*/

#include "pmy.h"
#include "../my.h"
int (*listeFlag[5])(char *str, int *fus, char *flag, const char *format) =
    {hashtag, zero, minus, positive_sign, space};
int gestionflag(char *str, int *fus, char *flag, const char *format)
{
    int (*bob)(char *str, int *fus, char *flag, const char *format);
    char fflag[6] = {'#', '0', '-', '+', ' ', '\0'};
    int u = 0;
    if (my_strlen(flag) < 1) {
        my_putstr(str);
        return (my_strlen(str));
    }
    for (int y = 0; fflag[y] != '\0'; y++)
        if (flag[u] == fflag[y]) {
            bob = listeFlag[y];
            return ((*bob)(str, fus, flag, format));
        }
    return (0);
}

char *flagy(const char *format, int i, char *flag)
{
    int g = 0;
    for (int y = 0; flag[y] != '\0'; y++)
        if (format[i - 1] == flag[y]) {
            i--;
            y = -1;
            g++;
        }
    i += g;
    char *rflag = malloc(sizeof(char) * g + 1);
    g = 0;
    for (int y = 0; flag[y] != '\0'; y++)
        if (format[i - 1] == flag[y]) {
            rflag[g] = flag[y];
            i--;
            y = -1;
            g++;
            rflag[g + 1] = '\0';
        }
    return (rflag);
}

int decflag(char *str, const char *format, int i, int largeur)
{
    char flag[6] = {'#', '0', '-', '+', ' ', '\0'};
    char *rflag = flagy(format, i, flag);
    char nflag[6];
    int fus[3] = {i, largeur, '\0'};
    return (gestionflag(str, fus, concatflag(rflag, nflag), format));
}

int dlm2(char *LM, const char *format, int i, int y)
{
    if (LM[y] == 'h' || LM[y] == 'l')
        if (format[i - 1] == LM[y]) {
            i--;
        }
    return (i);
}

int dlm(char *str, const char *format, int i)
{
    char LM[9] = {'h', 'l', 'L', 'q', 'j', 'z', 't', 'w', '\0'};
    for (int y = 0; LM[y] != '\0'; y++) {
        if (format[i - 1] == LM[y]) {
            i--;
            dlm2(LM, format, i, y);
        }
    }
    return (dprecis(str, format, i));
}
