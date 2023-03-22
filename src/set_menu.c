/*
** EPITECH PROJECT, 2022
** my paint
** File description:
** set_menu.c
*/

#include "../lib/my/my.h"
#include "../lib/my/csfmLib/csfmlib.h"

void set_mh(struct alll *all)
{
    all->cadre.haut.size = rectf(0, 0, sfRenderWindow_getSize(AW).x,
    30);
        sfRectangleShape_setPosition(all->cadre.haut.fond.name, vecf(0, 0));
        sfRectangleShape_setFillColor(all->cadre.haut.fond.name, sfWhite);
        sfRectangleShape_setSize(all->cadre.haut.fond.name,
        vecf(all->cadre.haut.size.width, all->cadre.haut.size.height));
}

void set_mg(struct alll *all)
{
    all->cadre.gauche.size = rectf(3, (sfRenderWindow_getSize(AW).y *
    0.125) + 1, (sfRenderWindow_getSize(AW).x *
    (0.2 - all->cadre.gauche.xsize)) - 4,
    (sfRenderWindow_getSize(AW).y * 0.80) - 2);
    sfRectangleShape_setPosition(all->cadre.gauche.fond.name,
    vecf(all->cadre.gauche.size.left, all->cadre.gauche.size.top));
    sfRectangleShape_setFillColor(all->cadre.gauche.fond.name, sfWhite);
    sfRectangleShape_setSize(all->cadre.gauche.fond.name,
    vecf(all->cadre.gauche.size.width, all->cadre.gauche.size.height));
}

void set_mm(struct alll *all)
{
    all->cadre.midle.size = rectf(sfRenderWindow_getSize(AW).x *
    (0.2 - all->cadre.gauche.xsize) + 2,
    (sfRenderWindow_getSize(AW).y * 0.125)
    + 1, (sfRenderWindow_getSize(AW).x *
    (0.6 + all->cadre.gauche.xsize - all->cadre.midle.xsize)) - 4,
    (sfRenderWindow_getSize(AW).y * 0.80) - 2);
    sfRectangleShape_setPosition(all->cadre.midle.fond.name,
    vecf(all->cadre.midle.size.left, all->cadre.midle.size.top));
    sfRectangleShape_setFillColor(all->cadre.midle.fond.name, sfWhite);
    sfRectangleShape_setSize(all->cadre.midle.fond.name,
    vecf(all->cadre.midle.size.width, all->cadre.midle.size.height));
}

void set_md(struct alll *all)
{
    all->cadre.droite.size = rectf((sfRenderWindow_getSize(AW).x *
    (0.8 - all->cadre.midle.xsize) + 1),
    (sfRenderWindow_getSize(AW).y * 0.125) + 1,
    (sfRenderWindow_getSize(AW).x *
    (0.2 + all->cadre.midle.xsize)) - 4,
    (sfRenderWindow_getSize(AW).y * 0.80) - 2);
    sfRectangleShape_setPosition(all->cadre.droite.fond.name,
    vecf(all->cadre.droite.size.left, all->cadre.droite.size.top));
    sfRectangleShape_setFillColor(all->cadre.droite.fond.name, sfWhite);
    sfRectangleShape_setSize(all->cadre.droite.fond.name,
    vecf(all->cadre.droite.size.width, all->cadre.droite.size.height));
}

void set_mb(struct alll *all)
{
    sfFloatRect bob = sfSprite_getGlobalBounds(im.stylo.img_sprite);
    float X = 0;
    if (all->random.infobarV == 0)
        X = 30;
    all->cadre.bas.size = rectf(0, (all->cadre.haut.size.height),
    bob.width * 3, bob.height * 2);
    sfRectangleShape_setPosition(all->cadre.bas.fond.name,
    vecf(sfRenderWindow_getSize(AW).x * all->cadre.toolbar, X));
    sfRectangleShape_setFillColor(all->cadre.bas.fond.name,
    sfColor_fromRGB(150, 150, 150));
    sfRectangleShape_setSize(all->cadre.bas.fond.name,
    vecf(all->cadre.bas.size.width, all->cadre.bas.size.height));
}
