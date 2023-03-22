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

void actu_nbr_size2(struct alll *all)
{
    (all->mouse_mod2 == 5 || all->mouse_mod2 == 6) ? im.clicg_s =
    my_int_to_str(all->button.size_shape) : 0;
    (all->mouse_mod == 5 || all->mouse_mod == 6) ? im.clicd_s =
    my_int_to_str(all->button.size_shape) : 0;
}

void actu_nbr_size(struct alll *all)
{
    sfFloatRect size = sfGB(im.size_moins.img_sprite);
    sfVector2f pos = sfRectangleShape_getPosition(im.rect_size.name);
    sfText_setColor(im.cligd_text.text, sfRed);
    sfText_setString(im.cligd_text.text, im.clicd_s);
    sfText_setPosition(im.cligd_text.text,
    vecf(pos.x + size.width * 1.2, pos.y + size.height * 0.55));
    (all->mouse_mod2 == 1) ? im.clicg_s =
    my_int_to_str(all->button.size_pencil) : 0;
    (all->mouse_mod == 1) ? im.clicd_s =
    my_int_to_str(all->button.size_pencil) : 0;
    (all->mouse_mod2 == 2) ? im.clicg_s =
    my_int_to_str(all->button.size_eraser) : 0;
    (all->mouse_mod == 2) ? im.clicd_s =
    my_int_to_str(all->button.size_eraser) : 0;
    (all->mouse_mod2 == 3) ? im.clicg_s = my_int_to_str(1) : 0;
    (all->mouse_mod == 3) ? im.clicd_s = my_int_to_str(1) : 0;
    (all->mouse_mod2 == 4) ? im.clicg_s = my_int_to_str(bs) : 0;
    (all->mouse_mod == 4) ? im.clicd_s = my_int_to_str(bs) : 0;
    actu_nbr_size2(all);
}

void show_help2(struct alll *all)
{
    sfVector2f pos = sfRectangleShape_getPosition(ai.aide.Rect.name);
    if (mp.x >= pos.x && mp.x <= (pos.x + 200) && mp.y >= 33 && mp.y <= 63) {
        sfRenderWindow_drawRectangleShape(aw, ai.about.Rect.name, NULL);
        sfRenderWindow_drawSprite(aw, all->about.img_sprite, NULL);
    }
    if (mp.x >= pos.x && mp.x <= (pos.x + 200) && mp.y >= 63 && mp.y <= 93) {
        sfRenderWindow_drawRectangleShape(aw, ai.help.Rect.name, NULL);
        sfRenderWindow_drawSprite(aw, all->help.img_sprite, NULL);
    }
    if (mp.x >= pos.x && mp.x <= (pos.x + 200) && mp.y >= 93 && mp.y <= 123) {
        sfRenderWindow_drawRectangleShape(aw, ai.racc.Rect.name, NULL);
        sfRenderWindow_drawSprite(aw, all->shortcut.img_sprite, NULL);
    }
}
