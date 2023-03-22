/*
** EPITECH PROJECT, 2022
** my paint
** File description:
** print map
*/

#include "../lib/my/my.h"
#include "../lib/my/csfmLib/csfmlib.h"
#include <stdio.h>
#include <stdlib.h>

void destroy_sim(struct alll *all)
{
    sfRectangleShape_destroy(all->cadre.haut.fond.name);
    sfRectangleShape_destroy(all->cadre.gauche.fond.name);
    sfRectangleShape_destroy(all->cadre.midle.fond.name);
    sfRectangleShape_destroy(all->cadre.droite.fond.name);
    sfRectangleShape_destroy(all->cadre.bas.fond.name);
    sfSprite_destroy(all->image.img_sprite);
    sfView_destroy(all->area);
    sfRenderWindow_destroy(aw);
}

void draw_menu(struct alll *all)
{
    sfRenderWindow_drawSprite(aw, im.feutre.img_sprite, NULL);
    sfRenderWindow_drawSprite(aw, im.stylo.img_sprite, NULL);
    sfRenderWindow_drawSprite(aw, im.gomme.img_sprite, NULL);
    sfRenderWindow_drawSprite(aw, im.picker.img_sprite, NULL);
    sfRenderWindow_drawSprite(aw, im.zoom.img_sprite, NULL);
    sfRenderWindow_drawSprite(aw, im.carré.img_sprite, NULL);
    sfRenderWindow_drawRectangleShape(aw, im.color_rect.name, NULL);
    sfRenderWindow_drawSprite(aw, im.color.img_sprite, NULL);
    if (all->mouse_mod != 0)
        sfRenderWindow_drawRectangleShape(aw, im.clicg_rect.name, NULL);
    if (all->mouse_mod2 != 0)
        sfRenderWindow_drawRectangleShape(aw, im.clicd_rect.name, NULL);
    if ((all->mouse_mod2 != 0 && all->mouse_mod2 != 3) ||
    (all->mouse_mod != 0 && all->mouse_mod != 3)) {
    sfRenderWindow_drawRectangleShape(aw, all->bouton_im.rect_size.name, NULL);
    sfRenderWindow_drawSprite(aw, im.size_moins.img_sprite, NULL);
    sfRenderWindow_drawSprite(aw, im.size_plus.img_sprite, NULL);
    sfRenderWindow_drawText(aw, all->bouton_im.cligg_text.text, NULL);
    sfRenderWindow_drawText(aw, all->bouton_im.cligd_text.text, NULL);
    }
}

void draw_sprite(struct alll *all)
{
    sfRenderWindow_drawSprite(aw, all->back.img_sprite, NULL);
    sfRenderWindow_drawSprite(aw, all->image.img_sprite, NULL);
}

void simulation(struct alll *all, files *file)
{
    init_all(all, file);
    sfRenderWindow_setFramerateLimit(aw, 100);
    while (sfRenderWindow_isOpen(aw)) {
        actu_all(all, file);
        brush(all);
        eraser(all);
        pencil(all);
        circle(all);
        rectangle(all);
        select_color(all);
        draw_sprite(all);
        draw_cadre(all);
        draw_menu(all);
        draw_shape(all);
        gestion_bouton(all);
        sfRenderWindow_display(aw);
    }
    destroy_sim(all);
    free(file);
}
