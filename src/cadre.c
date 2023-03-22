/*
** EPITECH PROJECT, 2022
** geph1.0
** File description:
** cadre.c
*/

#include "../lib/my/my.h"
#include "../lib/my/csfmLib/csfmlib.h"
#include <stdio.h>
#include <stdlib.h>

int create_cadre(struct alll *all)
{
    all->cadre.haut.fond.name = sfRectangleShape_create();
    all->cadre.gauche.fond.name = sfRectangleShape_create();
    all->cadre.midle.fond.name = sfRectangleShape_create();
    all->cadre.droite.fond.name = sfRectangleShape_create();
    all->cadre.bas.fond.name = sfRectangleShape_create();
    all->cadre.gauche.xsize = 0;
    all->cadre.midle.xsize = 0;
    all->cadre.MGV = 0;
    all->cadre.MDV = 0;
    return (0);
}

int draw_cadre(struct alll *all)
{
    move_mg(all);
    move_mm(all);
    set_mm(all);
    set_mh(all);
    if (all->random.infobarV == 0)
        sfRenderWindow_drawRectangleShape(aw, all->cadre.haut.fond.name, 0);
    set_mg(all);
    if (all->cadre.MGV == 1)
        sfRenderWindow_drawRectangleShape(aw, all->cadre.gauche.fond.name, 0);
    set_md(all);
    if (all->cadre.MDV == 1)
        sfRenderWindow_drawRectangleShape(aw, all->cadre.droite.fond.name, 0);
    set_mb(all);
    sfRenderWindow_drawRectangleShape(aw, all->cadre.bas.fond.name, 0);
    if (all->random.infobarV == 0) {
        sfRenderWindow_drawText(aw, af.Texte.text, NULL);
        sfRenderWindow_drawText(aw, ae.Texte.text, NULL);
        sfRenderWindow_drawText(aw, aa.Texte.text, NULL);
    }
    return (0);
}
