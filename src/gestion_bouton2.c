/*
** EPITECH PROJECT, 2023
** my paint
** File description:
** gestion bouton
*/

#include "../lib/my/my.h"
#include "../lib/my/csfmLib/csfmlib.h"
#include <stdio.h>
#include <stdlib.h>

void gestion_bouton_edit(struct alll *all)
{
    create_bouton(all, sfST(af.Texte.text).width + 20, 33, 1);
    create_bouton(all, sfST(af.Texte.text).width + 20, 67, 2);
    create_bouton(all, sfST(af.Texte.text).width + 20, 99, 3);
    create_bouton(all, sfST(af.Texte.text).width + 20, 122, 4);
}
