/*
** EPITECH PROJECT, 2022
** my_paint
** File description:
** init second
*/

#include "../lib/my/csfmLib/csfmlib.h"
#include <stdlib.h>
#include <stdbool.h>

void init_struct_all_next(struct alll *all)
{
    all->button.color = 0;
    all->button.cur_color.r = 0;
    all->button.cur_color.g = 0;
    all->button.cur_color.b = 0;
    all->button.cur_color.a = 255;
    all->mouse_mod = 0;
    all->mouse_mod2 = 0;
    all->random.fichier = 0;
    all->random.edit = 0;
    all->cadre.toolbar = 0.4;
    all->button.size_x = 70;
    all->button.size_y = 40;
    all->button.rotate = 1;
    all->node = NULL;
    im.clicd_s = "NULL";
    im.clicg_s = "NULL";
}

void init_struct_all(struct alll *all)
{
    all->gfps.Clockfp = sfClock_create();
    all->zoom = 1;
    all->random.click = 0;
    all->random.infobarV = 0;
    all->random.infobarV2 = 0;
    all->random.infobarC = 0;
    all->random.saveR = 0;
    all->random.saveR2 = 0;
    all->random.saveC = 0;
    all->button.size_pencil = 5;
    all->button.size_brush = 15;
    all->button.size_eraser = 10;
    all->button.size_shape = 1.0;
    init_struct_all_next(all);
}

void init_sprite(struct alll *all)
{
    create_sprite(&all->back, "./assets/back.png", vecf(1, 1));
    all->back.pos = vecf(0, 0);
    sfSprite_setPosition(all->back.img_sprite, all->back.pos);
    create_perso(&all->about, "./assets/about.png", vecf(0.5, 0.5),
    veci(512, 512));
    im.stylo.pos = vecf(500, 500);
    sfSprite_setPosition(all->about.img_sprite, vecf(302, 29));
    create_perso(&all->help, "./assets/help.png", vecf(0.5, 0.5),
    veci(512, 512));
    sfSprite_setPosition(all->help.img_sprite, vecf(302, 29));
    create_perso(&all->shortcut, "./assets/short.png", vecf(0.5, 0.5),
    veci(512, 512));
    sfSprite_setPosition(all->help.img_sprite, vecf(302, 29));
    create_perso(&all->shortcut, "./assets/help.png", vecf(0.5, 0.5),
    veci(512, 512));
    sfSprite_setPosition(all->shortcut.img_sprite, vecf(302, 29));
    create_perso(&all->shortcut, "./assets/short.png", vecf(0.5, 0.5),
    veci(512, 512));
    sfSprite_setPosition(all->shortcut.img_sprite, vecf(302, 29));
}
