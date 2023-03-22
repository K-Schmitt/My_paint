/*
** EPITECH PROJECT, 2022
** lenmodif detector
** File description:
** detect lenmodif
*/

#include "pmy.h"
int lenp(const char *format, int i)
{
    char chiffre[11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\0'};
    for (int y = 0; chiffre[y] != '\0'; y++)
        if (format[i -1] == chiffre[y]) {
            return (1 + lenp(format, i - 1));
        }
    return 0;
}

int makeint(const char *format, int i, int bob)
{
    char chiffre[11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\0'};
    for (int y = 0; chiffre[y] != '\0'; y++)
        if (format[i + 1] == chiffre[y]) {
            bob = bob * 10 + format[i +1] - 48;
            bob = makeint(format, i + 1, bob);
            }
    return (bob);
}

int dlargeur(char *str, const char *format, int i)
{
    int bob = 0;
    if (lenp(format, i) > 0) {
        i = i - lenp(format, i) - 1;
        bob = format[i + 1] - 48;
        bob = makeint(format, i + 1, bob);
        bob += field_size(str, bob, format, i);
        return (bob);
    }
    return (decflag(str, format, i, bob));
}

int dprecis(char *str, const char *format, int i)
{
    if (format[i - lenp(format, i) - 1] == '.') {
        i = i - lenp(format, i) - 1;
        int bob = format[i + 1] - 48;
        bob = makeint(format, i + 1, bob);
        bob += precision(str, bob, format, i);
        return (bob);
    }
    return (dlargeur(str, format, i));

}
