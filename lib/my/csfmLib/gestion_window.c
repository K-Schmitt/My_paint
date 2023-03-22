/*
** EPITECH PROJECT, 2022
** gestion window
** File description:
** gestion window
*/

#include <stdlib.h>
#include "csfmlib.h"
#include "./../my.h"

void detect_fps(struct alll *all)
{
    all->gfps.fp++;
    if (sfClock_getElapsedTime(all->gfps.Clockfp).ms > sfSeconds(0.5).ms) {
        sfClock_restart(all->gfps.Clockfp);
        all->gfps.fps = (all->gfps.fp * 2);
        all->gfps.fp = 0;
    }
}

void sizemin(struct sfRenderWindow *window)
{
    if (sfRenderWindow_getSize(window).x <= 700) {
        sfRenderWindow_setSize(window, vecu(700,
        sfRenderWindow_getSize(window).y));
    }
    if (sfRenderWindow_getSize(window).y <= 500) {
        sfRenderWindow_setSize(window, vecu(sfRenderWindow_getSize(window).x,
        500));
    }
}

void closew(struct alll *all)
{
    while (sfRenderWindow_pollEvent(aw, &all->event))
        if (all->event.type == sfEvtClosed)
            sfRenderWindow_close(aw);
}

void actuwindow(struct alll *all)
{
    detect_fps(all);
    sizemin(aw);
    sfRenderWindow_clear(aw, sfColor_fromRGB(100, 100, 100));
    all->size = rectf(0, 0, sfRenderWindow_getSize(aw).x,
    sfRenderWindow_getSize(aw).y);
    all->area = sfView_createFromRect(all->size);
    all->mouse = sfRenderWindow_mapPixelToCoords(aw,
    sfMouse_getPositionRenderWindow(aw), all->area);
    sfRenderWindow_setView(aw, all->area);
    closew(all);
}

void actudraw(struct alll *all, struct stocksprite bob)
{
    sfSprite_setScale(bob.img_sprite, bob.scale);
    sfSprite_setPosition(bob.img_sprite, bob.pos);
    sfRenderWindow_drawSprite(aw, bob.img_sprite, 0);
}
