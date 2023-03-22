/*
** EPITECH PROJECT, 2022
** strdup
** File description:
** strdup
*/
#include "../my.h"
#include <stdlib.h>

char *my_strdup(char *str)
{
    int size = my_strlen(str);
    char *nstr = malloc(sizeof(char) * (size + 1));
    int i = 0;
    for (; i < size; i++) {
        nstr[i] = str[i];
    }
    nstr[i] = '\0';
    return (nstr);
}
