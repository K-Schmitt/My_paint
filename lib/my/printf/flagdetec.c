/*
** EPITECH PROJECT, 2022
** detector flag
** File description:
** detect les flag
*/
#include "pmy.h"
struct stockflag concatflag1(char flag, struct stockflag flaglist)
{
    if (flag == '+')
        flaglist.plus = 1;
    if (flag == '-')
        flaglist.moin = 1;
    if (flag == '#')
        flaglist.hashtg = 1;
    if (flag == ' ')
        flaglist.space = 1;
    if (flag == '0')
        flaglist.zero = 1;
    return (flaglist);
}

char *concatflag4(char *nflag, struct stockflag flaglist, int y)
{
    if (flaglist.hashtg == 1) {
        nflag[y] = '#';
        y++;
    }
    if (flaglist.moin == 1) {
        nflag[y] = '-';
        y++;
    }
    nflag[y] = '\0';
    return (nflag);
}

char *concatflag3(char *nflag, struct stockflag flaglist)
{
    int y = 0;
    if (flaglist.plus == 1) {
        nflag[y] = '+';
        y++;
    }
    if (flaglist.space == 1) {
        nflag[y] = ' ';
        y++;
    }
    if (flaglist.zero == 1) {
        nflag[y] = '0';
        y++;
    }
    return (concatflag4(nflag, flaglist, y));
}

char *concatflag(char *flag, char *nflag)
{
    struct stockflag flaglist = {0, 0, 0, 0, 0};
    for (int y = 0; flag[y] != '\0'; y++) {
        flaglist = concatflag1(flag[y], flaglist);
    }
    if (flaglist.plus + flaglist.space == 2)
        flaglist.space = 0;
    if (flaglist.moin + flaglist.zero == 2)
        flaglist.zero = 0;
    nflag = concatflag3(nflag, flaglist);
    return (nflag);
}
