/*
** EPITECH PROJECT, 2022
** my paint
** File description:
** size adapt
*/

#include "../lib/my/my.h"
#include "../lib/my/csfmLib/csfmlib.h"
#include <stdio.h>
#include <stdlib.h>

void gestion_mouse2_next(struct alll *all, int opt)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(all->c_select)) > 0.15000f &&
    opt == -1) {
        if (all->mouse_mod2 == 1 && all->button.size_pencil - 1 > 1)
            all->button.size_pencil--;
        if (all->mouse_mod2 == 2 && all->button.size_eraser - 2 > 1)
            all->button.size_eraser -= 2;
        if (all->mouse_mod2 == 4 && all->button.size_brush - 2 > 10)
            all->button.size_brush -= 2;
        if ((all->mouse_mod2 == 5 || all->mouse_mod2 == 6)
        && all->button.size_shape - 0.2 > 1)
            all->button.size_shape -= 0.2;
        sfClock_restart(all->c_select);
    }
}

void gestion_mouse2(struct alll *all, int opt)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(all->c_select)) > 0.15000f &&
    opt == 1) {
        if (all->mouse_mod2 == 1 && all->button.size_pencil + 1 < 15)
            all->button.size_pencil++;
        if (all->mouse_mod2 == 2 && all->button.size_eraser + 2 < 50)
            all->button.size_eraser += 2;
        if (all->mouse_mod2 == 4 && all->button.size_brush + 2 < 50)
            all->button.size_brush += 2;
        if ((all->mouse_mod2 == 5 || all->mouse_mod2 == 6) &&
        all->button.size_shape + 0.2 < 8)
            all->button.size_shape += 0.2;
        sfClock_restart(all->c_select);
    }
    gestion_mouse2_next(all, opt);
}

void gestion_mouse_next(struct alll *all, int opt)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(all->c_select)) > 0.15000f &&
    opt == -1) {
        if (all->mouse_mod == 1 && all->button.size_pencil - 1 > 1)
            all->button.size_pencil--;
        if (all->mouse_mod == 2 && all->button.size_eraser - 2 > 1)
            all->button.size_eraser -= 2;
        if (all->mouse_mod == 4 && all->button.size_brush - 2 > 10)
            all->button.size_brush -= 2;
        if ((all->mouse_mod == 5 || all->mouse_mod == 6) &&
        all->button.size_shape - 0.2 > 1)
            all->button.size_shape -= 0.2;
        sfClock_restart(all->c_select);
    }
}

void gestion_mouse(struct alll *all, int opt)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(all->c_select)) > 0.15000f &&
    opt == 1) {
        if (all->mouse_mod == 1 && all->button.size_pencil + 1 < 15)
            all->button.size_pencil++;
        if (all->mouse_mod == 2 && all->button.size_eraser + 2 < 50)
            all->button.size_eraser += 2;
        if (all->mouse_mod == 4 && all->button.size_brush + 2 < 50)
            all->button.size_brush += 2;
        if ((all->mouse_mod == 5 || all->mouse_mod == 6) &&
        all->button.size_shape + 0.2 < 8)
            all->button.size_shape += 0.2;
        sfClock_restart(all->c_select);
    }
    gestion_mouse_next(all, opt);
}
