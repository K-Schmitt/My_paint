/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** mini_printf
*/

#include "../my.h"
#include <stdarg.h>
int deftype(const char *format, int i, va_list list)
{
    if (format[i + 1] == 'd')
        return (my_put_nbr(va_arg(list, int)));
    if (format[i + 1] == 'i')
        return (my_put_nbr(va_arg(list, int)));
    if (format[i + 1] == 's')
        return (my_putstr(va_arg(list, char*)));
    if (format[i + 1] == 'c')
        return (my_putchar(va_arg(list, int)));
    if (format[i + 1] == '%')
        return (my_putchar('%'));
    return (0);
}

int mini_printf(const char *format, ...)
{
    va_list list;
    va_start(list, format);
    int nb = 0;
    int i = 0;
    for (; format[i] != '\0'; i++) {
        if (format[i] != '%')
            my_putchar(format[i]);
        if (format[i] == '%') {
            nb += deftype(format, i, list) - 1;
            i++;
        }
    }
    return (nb + i);
}
