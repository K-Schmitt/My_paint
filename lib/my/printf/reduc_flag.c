/*
** EPITECH PROJECT, 2022
** flag1
** File description:
** flag1
*/
#include "pmy.h"
#include "../my.h"
char *reduc_positive(char *flag, char *size)
{
    for (int y = 0; flag[y] != '\0'; y++) {
        if (flag[y] == '+') {
            extra_for(flag, size);
        }
    }
    return (size);
}

char *reduc_minus(char *flag, char *size)
{
    for (int y = 0; flag[y] != '\0'; y++) {
        if (flag[y] == '-') {
            extra_for(flag, size);
        }
    }
    return (size);
}

char *reduc_zero(char *flag, char *size)
{
    for (int y = 0; flag[y] != '\0'; y++) {
        if (flag[y] == '0') {
            extra_for(flag, size);
        }
    }
    return (size);
}

char *reduc_space(char *flag, char *size)
{
    for (int y = 0; flag[y] != '\0'; y++) {
        if (flag[y] == ' ') {
            extra_for(flag, size);
        }
    }
    return (size);
}

char *reduc_hashtag(char *flag, char *size)
{
    for (int y = 0; flag[y] != '\0'; y++) {
        if (flag[y] == '#') {
            extra_for(flag, size);
        }
    }
    return (size);
}
