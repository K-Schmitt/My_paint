/*
** EPITECH PROJECT, 2022
** plib
** File description:
** lib pour printf
*/

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
int dlet(void* nbr, const char *format, int p);
int ilet(void* nbr, const char *format, int p);
int ulet(void* nbr, const char *format, int p);
int olet(void* decl, const char *format, int p);
int blet(void* decl, const char *format, int p);
int xlet(void* decl, const char *format, int p);
int xmlet(void* decl, const char *format, int p);
int alet(void* decl, const char *format, int p);
int clet(void* charaa, const char *format, int p);
int slet(void* charaa, const char *format, int p);
int smlet(void * charaa, const char *format, int p);
int dlm(char *str, const char *format, int i);
int dlargeur(char *str, const char *format, int i);
int decflag(char *str, const char *format, int i, int bob);
int gestionflag(char *str, int *fus, char *flag, const char *format);
int field_size(char *str, int nb, const char *format, int i);
int positive_sign(char *str, int *fus, char *flag, const char *format);
int space(char *str, int *fus, char *flag, const char *format);
int zero(char *str, int *fus, char *flag, const char *format);
int minus(char *str, int *fus, char *flag, const char *format);
int hashtag(char *str, int *fus, char *flag, const char *format);
int detection(const char *format, int i);
int my_printf(const char* format, ...);
char *reduc_positive(char *flag, char *size);
char *reduc_space(char *flag, char *size);
char *reduc_zero(char *flag, char *size);
char *reduc_hashtag(char *flag, char *size);
char *reduc_minus(char *flag, char *size);
char *my_concatstr(char *dest, ...);
char *concatflag(char *flag, char *nflag);
int dprecis(char *str, const char *format, int i);
char *extra_for(char *flag, char *size);
int precision(char *str, int nb, const char *format, int y);
int mini_printf(const char *format, ...);

struct stockflag {
    int plus;
    int moin;
    int hashtg;
    int space;
    int zero;
};
