/*
** EPITECH PROJECT, 2022
** my_show_word_array
** File description:
** affiche mot d'un tableau de string a la ligne
*/

#include <stdlib.h>
#include "../my.h"

int my_show_word_array(char* const *tab)
{
    int y = 0;
    for (int i = 0; tab[i] != NULL; i++) {
        y += my_putstr(tab[i]);
        my_putchar('\n');
    }
    return (y);
}
