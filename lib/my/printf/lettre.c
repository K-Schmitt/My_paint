/*
** EPITECH PROJECT, 2022
** lettre
** File description:
** combo lettre
*/

#include "pmy.h"
#include "../my.h"
int ulet(void * nbr, const char *format, int p)
{
    int nb = *(int*)nbr;
    char str[my_intlenght(nb)];
    int i = 0;
    for (; nb >= 1; i++) {
        str[i] = (nb % 10) + 48;
        nb /= 10;
    }
    str[i] = '\0';
    return (dlm(my_revstr(str), format, p));
}

int clet(void * charaa, const char *format, int p)
{
    char chara = *(char*)charaa;
    char str[2];
    str[0] = chara;
    str[1] = '\0';
    return (dlm(str, format, p));
}

int dlet(void * nbr, const char *format, int p)
{
    int nb = *(int*)nbr;
    char str[my_intlenght(nb)];
    int i = 0;
    int neg = 0;
    if (nb < 0) {
        nb *= -1;
        str[my_intlenght(nb)] = '-';
        neg = 1;
    }
    for (; nb >= 1; i++) {
        str[i] = (nb % 10) + 48;
        nb /= 10;
    }
    if (neg == 1)
        str[i + 1] = '\0';
    if (neg == 0)
        str[i] = '\0';
    return (dlm(my_revstr(str), format, p));
}

int ilet(void * nbr, const char *format, int p)
{
    int nb = *(int*)nbr;
    char str[my_intlenght(nb)];
    int i = 0;
    int neg = 0;
    if (nb < 0) {
        nb *= -1;
        str[my_intlenght(nb)] = '-';
        neg = 1;
    }
    for (; nb >= 1; i++) {
        str[i] = (nb % 10) + 48;
        nb /= 10;
    }
    if (neg == 1)
        str[i + 1] = '\0';
    if (neg == 0)
        str[i] = '\0';
    return (dlm(my_revstr(str), format, p));
}

int olet(void * decl, const char *format, int p)
{
    int dec = *(int*)decl;
    int decc = dec;
    int i = 0;
    while (dec > 7) {
        dec /= 8;
        i++;
    }
    i++;
    char bob[i + 1];
    dec = decc;
    i = 0;
    while (dec > 7) {
        bob[i] = (char) ((dec % 8) + 48);
        dec /= 8;
        i++;
    }
    bob[i] = (char) ((dec % 8) + 48);
    bob[i + 1] = '\0';
    return (dlm(my_revstr(bob), format, p));
}
