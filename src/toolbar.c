/*
** EPITECH PROJECT, 2022
** my paint
** File description:
** actualisation tools bar
*/

#include "../lib/my/my.h"
#include "../lib/my/csfmLib/csfmlib.h"
#include <stdio.h>
#include <stdlib.h>

void actu_toolbar3(struct alll *all, sfFloatRect bob, float X)
{
    sfSprite_setPosition(im.carré.img_sprite,
    vecf(sfRenderWindow_getSize(aw).x * all->cadre.toolbar + bob.width * 2, X
    + bob.height));
    sfRectangleShape_setSize(im.clicg_rect.name,
    vecf(sfGB(im.feutre.img_sprite).width, sfGB(im.feutre.img_sprite).height));
    sfRectangleShape_setSize(im.clicd_rect.name,
    vecf(sfGB(im.feutre.img_sprite).width, sfGB(im.feutre.img_sprite).height));
    pos_clictool(all);
    sfRectangleShape_setFillColor(im.color_rect.name, all->button.cur_color);
    actu_addminus(all);
    create_bouton_image(all, &im.zoom, veci(512, 512), 5);
    create_bouton_image(all, &im.carré, veci(512, 1024), 6);
}

void actu_toolbar2(struct alll *all, sfFloatRect bob, float X)
{
    create_bouton_image(all, &im.picker, veci(0, 1024), 3);
    sfSprite_setPosition(im.picker.img_sprite,
    vecf(sfRenderWindow_getSize(aw).x * all->cadre.toolbar + bob.width, X));
    im.zoom.scale = nscale(all, 0.22, 0.22);
    sfSprite_setScale(im.zoom.img_sprite, im.zoom.scale);
    im.zoom.z.left = 512;
    im.zoom.z.top = 1024;
    sfSprite_setTextureRect(im.zoom.img_sprite, im.zoom.z);
    sfSprite_setPosition(im.zoom.img_sprite,
    vecf(sfRenderWindow_getSize(AW).x * all->cadre.toolbar
    + (bob.width * 2), X));
    sfSprite_setScale(im.color.img_sprite, nscale(all, 1, 1));
    sfSprite_setPosition(im.color.img_sprite,
    vecf(0, centre(im.color, all, veci(0, 150)).y));
    sfRectangleShape_setPosition(im.color_rect.name,
    vecf(0, centre(im.color, all, veci(0, 150)).y));
    sfRectangleShape_setSize(im.color_rect.name,
    vecf(sfGB(im.color.img_sprite).width, sfGB(im.color.img_sprite).height));
    actu_toolbar3(all, bob, X);
}

void actu_toolbar(struct alll *all)
{
    sfFloatRect bob = sfSprite_getGlobalBounds(im.stylo.img_sprite);
    float X = 0;
    if (all->random.infobarV == 0)
        X = 30;
    create_bouton_image(all, &im.stylo, veci(0, 0), 1);
    sfSprite_setPosition(im.stylo.img_sprite,
    vecf(sfRenderWindow_getSize(AW).x * all->cadre.toolbar, X));
    create_bouton_image(all, &im.gomme, veci(512, 0), 2);
    sfSprite_setPosition(im.gomme.img_sprite,
    vecf(sfRenderWindow_getSize(AW).x * all->cadre.toolbar
    + bob.width, X  + bob.height));
    im.feutre.scale = nscale(all, 0.22, 0.22);
    sfSprite_setScale(im.feutre.img_sprite, im.feutre.scale);
    im.feutre.z.left = 0;
    im.feutre.z.top = 512;
    create_bouton_image(all, &im.feutre, veci(0, 512), 4);
    sfSprite_setTextureRect(im.feutre.img_sprite, im.feutre.z);
    sfSprite_setPosition(im.feutre.img_sprite,
    vecf(sfRenderWindow_getSize(AW).x * all->cadre.toolbar, X + bob.height));
    actu_toolbar2(all, bob, X);
}

void init_toolbar2(struct alll *all)
{
    cp(&im.color, "./assets/color.png", vecf(1, 1), veci(235, 200));
    im.color.pos = vecf(100, 100);
    sfSprite_setPosition(im.color.img_sprite, im.color.pos);
    create_rect(&im.color_rect, vecf(sfGB(im.color.img_sprite).width,
    sfGB(im.color.img_sprite).height), im.color.pos, 1);
    create_rect(&im.clicg_rect, vecf(sfGB(im.feutre.img_sprite).width,
    sfGB(im.feutre.img_sprite).height), im.feutre.pos, 4);
    create_rect(&im.clicd_rect, vecf(sfGB(im.feutre.img_sprite).width,
    sfGB(im.feutre.img_sprite).height), im.feutre.pos, 5);
    cp(&im.size_moins, "./assets/mark.png", vecf(1, 1), veci(512, 512));
    sfSprite_setPosition(im.size_moins.img_sprite, vecf(100, 100));
    cp(&im.size_plus, "./assets/add.png", vecf(1, 1), veci(512, 512));
    sfSprite_setPosition(im.size_plus.img_sprite, vecf(100, 100));
    im.rect_size.pos = vecf(100, 100);
    create_rect(&im.rect_size, vecf(im.size_moins.size.x * 3,
    im.size_moins.size.y), im.size_moins.pos, 1);
    create_text(&im.cligg_text, "oui", 20, vecf(im.size_moins.size.x + 6,
    im.size_moins.size.y * 0.33));
    create_text(&im.cligd_text, "non", 20, vecf(im.size_moins.size.x + 6,
    im.size_moins.size.y * 0.66));
}

void init_toolbar(struct alll *all)
{
    cp(&im.stylo, "./assets/non.png", vecf(0.2, 0.2), veci(512, 512));
    im.stylo.pos = vecf(500, 500);
    sfSprite_setPosition(im.stylo.img_sprite, im.stylo.pos);
    cp(&im.feutre, "./assets/non.png", vecf(0.2, 0.2), veci(512, 512));
    im.feutre.pos = vecf(500, 500);
    sfSprite_setPosition(im.feutre.img_sprite, im.feutre.pos);
    cp(&im.gomme, "./assets/non.png", vecf(0.2, 0.2), veci(512, 512));
    im.gomme.pos = vecf(500, 500);
    sfSprite_setPosition(im.gomme.img_sprite, im.gomme.pos);
    cp(&im.picker, "./assets/non.png", vecf(0.2, 0.2), veci(512, 512));
    im.picker.pos = vecf(500, 500);
    sfSprite_setPosition(im.picker.img_sprite, im.picker.pos);
    cp(&im.zoom, "./assets/non.png", vecf(0.2, 0.2), veci(512, 512));
    im.zoom.pos = vecf(500, 500);
    sfSprite_setPosition(im.zoom.img_sprite, im.zoom.pos);
    cp(&im.carré, "./assets/non.png", vecf(0.2, 0.2), veci(512, 512));
    im.carré.pos = vecf(500, 500);
    sfSprite_setPosition(im.carré.img_sprite, im.carré.pos);
    init_toolbar2(all);
}
