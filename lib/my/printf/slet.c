/*
** EPITECH PROJECT, 2022
** clet
** File description:
** 1 char in string
*/
#include "pmy.h"
int slet(void * charaa, const char *format, int p)
{
    char *str = *(char**)charaa;
    return (dlm(str, format, p));
}

int smlet(void * charaa, const char *format, int p)
{
    char *str = *(char**)charaa;
    return (dlm(str, format, p));
}
