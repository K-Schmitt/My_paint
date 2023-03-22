/*
** EPITECH PROJECT, 2022
** blet
** File description:
** b lettre
*/
#include "../my.h"
#include "pmy.h"
int blet(void * decl, const char *format, int p)
{
    int dec = *(int*)decl;
    int decc = dec;
    int i = 0;
    while (dec > 1) {
        dec /= 2;
        i++;
    }
    i++;
    char bob[i];
    dec = decc;
    i = 0;
    for (;dec > 1; i++) {
        bob[i] = (char) ((dec % 2) + 48);
        dec /= 2;
    }
    bob[i] = (char) ((dec % 2) + 48);
    dlm(my_revstr(bob), format, p);
    return (i);
}
