/*
** EPITECH PROJECT, 2022
** my paint
** File description:
** actualisation tools bar 2
*/

#include "../lib/my/my.h"
#include "../lib/my/csfmLib/csfmlib.h"
#include <stdio.h>
#include <stdlib.h>

static void pos_clicktool_next(struct alll *all)
{
    if (all->mouse_mod2 == 1)
        sfRectangleShape_setPosition(im.clicd_rect.name,
        sfSprite_getPosition(im.stylo.img_sprite));
    if (all->mouse_mod2 == 2)
        sfRectangleShape_setPosition(im.clicd_rect.name,
        sfSprite_getPosition(im.gomme.img_sprite));
    if (all->mouse_mod2 == 3)
        sfRectangleShape_setPosition(im.clicd_rect.name,
        sfSprite_getPosition(im.picker.img_sprite));
    if (all->mouse_mod2 == 4)
        sfRectangleShape_setPosition(im.clicd_rect.name,
        sfSprite_getPosition(im.feutre.img_sprite));
    if (all->mouse_mod2 == 5)
        sfRectangleShape_setPosition(im.clicd_rect.name,
        sfSprite_getPosition(im.zoom.img_sprite));
    if (all->mouse_mod2 == 6)
        sfRectangleShape_setPosition(im.clicd_rect.name,
        sfSprite_getPosition(im.carré.img_sprite));
}

void pos_clictool(struct alll *all)
{
    if (all->mouse_mod == 1)
        sfRectangleShape_setPosition(im.clicg_rect.name,
        sfSprite_getPosition(im.stylo.img_sprite));
    if (all->mouse_mod == 2)
        sfRectangleShape_setPosition(im.clicg_rect.name,
        sfSprite_getPosition(im.gomme.img_sprite));
    if (all->mouse_mod == 3)
        sfRectangleShape_setPosition(im.clicg_rect.name,
        sfSprite_getPosition(im.picker.img_sprite));
    if (all->mouse_mod == 4)
        sfRectangleShape_setPosition(im.clicg_rect.name,
        sfSprite_getPosition(im.feutre.img_sprite));
    if (all->mouse_mod == 5)
        sfRectangleShape_setPosition(im.clicg_rect.name,
        sfSprite_getPosition(im.zoom.img_sprite));
    if (all->mouse_mod == 6)
        sfRectangleShape_setPosition(im.clicg_rect.name,
        sfSprite_getPosition(im.carré.img_sprite));
    pos_clicktool_next(all);
}

static void bouton_addminus_next(struct alll *all, int option)
{
    if (sfTrue == sfMouse_isButtonPressed(sfMouseLeft) &&
    all->random.click == 0)
        all->random.click = 1;
    if (sfFalse == sfMouse_isButtonPressed(sfMouseLeft) &&
        all->random.click == 1) {
        gestion_mouse(all, option);
        all->random.click = 0;
    }
    if (sfTrue == sfMouse_isButtonPressed(sfMouseRight) &&
    all->random.click == 0)
        all->random.click = 1;
    if (sfFalse == sfMouse_isButtonPressed(sfMouseRight) &&
    all->random.click == 1) {
        gestion_mouse2(all, option);
        all->random.click = 0;
    }
}

void bouton_addminus(struct alll *all, struct stocksprite *tutu, sfVector2i z,
int option)
{
    sfFloatRect bob = sfSprite_getGlobalBounds(tutu->img_sprite);
    sfVector2f jean = sfSprite_getPosition(tutu->img_sprite);
    tutu->scale = nscale(all, 0.22, 0.22);
    sfSprite_setScale(tutu->img_sprite, tutu->scale);
    tutu->z.left = z.x;
    tutu->z.top = z.y;
    sfSprite_setTextureRect(tutu->img_sprite, tutu->z);
    if ((mp.x >= jean.x && mp.x <= (jean.x + bob.width)) &&
    (mp.y >= jean.y && mp.y <= (jean.y + bob.height)))
        bouton_addminus_next(all, option);
}

void actu_addminus(struct alll *all)
{
    sfFloatRect size = sfGB(im.size_moins.img_sprite);
    sfVector2f pos = sfRectangleShape_getPosition(im.rect_size.name);
    sfRectangleShape_setSize(im.rect_size.name,
    vecf(size.width * 3.05, size.height * 1.2));
    sfRectangleShape_setPosition(im.rect_size.name, im.rect_size.pos);
    bouton_addminus(all, &im.size_moins, veci(0, 0), -1);
    sfSprite_setScale(im.size_moins.img_sprite, nscale(all, 0.1, 0.1));
    sfSprite_setPosition(im.size_moins.img_sprite,
    vecf(pos.x, pos.y + size.height * 0.1));
    bouton_addminus(all, &im.size_plus, veci(0, 0), 1);
    sfSprite_setScale(im.size_plus.img_sprite, nscale(all, 0.1, 0.1));
    sfSprite_setPosition(im.size_plus.img_sprite,
    vecf(pos.x + (size.width * 2), pos.y + size.height * 0.1));
    sfText_setScale(im.cligg_text.text, nscale(all, 1, 1));
    sfText_setColor(im.cligg_text.text, sfBlue);
    sfText_setString(im.cligg_text.text, im.clicg_s);
    sfText_setPosition(im.cligg_text.text,
    vecf(pos.x + size.width * 1.2, pos.y + size.height * 0.15));
    sfText_setScale(im.cligd_text.text, nscale(all, 1, 1));
    actu_nbr_size(all);
}
