/*
** EPITECH PROJECT, 2022
** convert_octa
** File description:
** convertie binaire en octa
*/

#include "pmy.h"
#include "../my.h"
int xlet2(const char *format, int p, char *bob, int dec)
{
    int i = 0;
    while (dec > 15) {
        if ((dec % 16) < 10)
            bob[i] = (char) ((dec % 16) + 48);
        if ((dec % 16) >= 10)
            bob[i] = (char) ((dec % 16) + 87);
        dec /= 16;
        i++;
    }
    if ((dec % 16) < 10)
        bob[i] = (char) ((dec % 16) + 48);
    if ((dec % 16) >= 10)
        bob[i] = (char) ((dec % 16) + 87);
    bob[i + 1] = '\0';
    return (dlm(my_revstr(bob), format, p));
}

int xlet(void * decl, const char *format, int p)
{
    int dec = *(int*)decl;
    int decc = dec;
    int i = 0;
    while (dec > 15) {
        dec /= 16;
        i++;
    }
    i++;
    char bob[i];
    dec = decc;
    return (xlet2(format, p, bob, dec));
}
