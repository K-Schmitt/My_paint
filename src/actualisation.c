/*
** EPITECH PROJECT, 2022
** my paint
** File description:
** actualisation
*/

#include "../lib/my/my.h"
#include "../lib/my/csfmLib/csfmlib.h"
#include <stdio.h>
#include <stdlib.h>

static void actu_image(struct alll *all)
{
    all->image.scale = nscale(all, all->zoom, all->zoom);
    sfSprite_setScale(all->image.img_sprite, all->image.scale);
    all->mouse_pos = sfRenderWindow_mapPixelToCoords(aw,
    sfMouse_getPositionRenderWindow(aw), sfRenderWindow_getView(aw));
    all->brush_pos = vecf((all->mouse_pos.x - posi.x) /
    all->image.scale.x, (all->mouse_pos.y - posi.y) / scal.y);
    im.color.scale_r = nscale_reverse(all, 1, 1);
    all->image.pos = centre(all->image, all, veci(0, 0));
    all->image.size = sfTexture_getSize(all->image.img_texture);
    sfSprite_setPosition(all->image.img_sprite, all->image.pos);
    all->back.scale = nscale(all, 1.5, 1.5);
    sfSprite_setScale(all->back.img_sprite, all->back.scale);
    sfSprite_setPosition(all->back.img_sprite,
    centre(all->back, all, veci(0, 0)));
    sfVector2f scale = {all->image.scale.x / 2, all->image.scale.y / 2};
    sfSprite_setScale(all->about.img_sprite, scale);
    sfSprite_setScale(all->help.img_sprite, scale);
    sfSprite_setScale(all->shortcut.img_sprite, scale);
}

int actu_all(struct alll *all, files *file)
{
    actuwindow(all);
    actu_image(all);
    actu_toolbar(all);
    gestion_raccourci(all, file);
    return (0);
}
