/*
** EPITECH PROJECT, 2022
** my_putchar
** File description:
** print one character
*/

#include <unistd.h>
int my_putchar (char c)
{
    return (write(1, &c, 1));
}
