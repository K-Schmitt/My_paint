/*
** EPITECH PROJECT, 2022
** printf
** File description:
** reproduit printf
*/

#include "pmy.h"
#include "../my.h"
#include <stdarg.h>
int (*listeFonctions[10])(void *, const char *format, int p) =
{dlet, ilet, olet, ulet, xlet, xmlet, blet, clet, slet,
smlet};

int switchy(va_list list, int* ui, int (*bob)(void* ,
const char *format, int i), const char *format)
{
    int i = ui[0];
    int y = ui[1];
    if (y >= 0 && y <= 6 ) {
        int jen = va_arg(list, int);
        return ((*bob)(&jen, format, i));
    }
    if (y == 7) {
        char jen = va_arg(list, int);
        return ((*bob)(&jen, format, i));
    }
    if (y >= 8 && y <= 9) {
        char *jen = va_arg(list, char*);
        return ((*bob)(&jen, format, i));
    }
    return (0);
}

int size_variable(const char *format, int i, va_list list)
{
    int (*bob)(void *, const char *format, int i);
    char IDC[22] = {'d', 'i', 'o', 'u', 'x', 'X', 'b', 'c', 's',
    'S', 'g', 'G', 'a', 'A', 'e', 'E', 'p', 'n', 'F', 'w', '\0'};
    int size_variable = 0;
    for (int y = 0; IDC[y] != '\0'; y++) {
        if (IDC[y] == 'w') {
            i++;
            size_variable++;
            y = 0;
        }
        if (format[i] == IDC[y]) {
            size_variable++;
            bob = listeFonctions[y];
            int ui[3] = {i, y, '\0'};
            switchy(list, ui, bob, format);
            return (size_variable);
        }
    }
    return 0;
}

int pourcent(const char *format, int i, va_list list)
{
    if (format[i] != '%') {
        my_putchar(format[i]);
        return 0;
    }
    if (format[i] == '%') {
        if (format[i + 1] == '%') {
            my_putchar('%');
            return 1;
        }
        return (size_variable(format, i, list) - 1);
    }
    return (1);
}

int my_printf(const char* format, ...)
{
    va_list list;
    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++) {
        i += pourcent(format, i, list);
    }
    return (0);
}
