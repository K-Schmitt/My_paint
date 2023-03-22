/*
** EPITECH PROJECT, 2022
** geph1.0
** File description:
** mouse.c
*/

#include "../lib/my/my.h"
#include "../lib/my/csfmLib/csfmlib.h"

int move_mg(struct alll *all)
{
    int zoneclick = 0;
    if (sfTrue == sfMouse_isButtonPressed(sfMouseLeft))
        zoneclick = 5;
    if (sfTrue == sfMouse_isButtonPressed(sfMouseLeft) &&
    all->mouse.x >= all->cadre.gauche.size.width  - 5 * zoneclick &&
    all->mouse.x <= all->cadre.gauche.size.width + 15 * zoneclick &&
    all->mouse.y >= all->cadre.gauche.size.left &&
    all->mouse.y <= all->cadre.gauche.size.height) {
        all->cadre.gauche.xsize = 0.2 - (all->mouse.x /
        sfRenderWindow_getSize(aw).x);
    }
    return (0);
}

int move_mm(struct alll *all)
{
    int zoneclick = 0;
    if (sfTrue == sfMouse_isButtonPressed(sfMouseLeft))
        zoneclick = 5;
    if (sfTrue == sfMouse_isButtonPressed(sfMouseLeft) &&
    all->mouse.x >= all->cadre.midle.size.width + all->cadre.gauche.size.width
    - 5 * zoneclick && all->mouse.x <= all->cadre.midle.size.width +
    all->cadre.gauche.size.width + 15 * zoneclick && all->mouse.y >=
    all->cadre.midle.size.top && all->mouse.y <= all->cadre.midle.size.height)
        all->cadre.midle.xsize = 0.8 -
        (all->mouse.x / sfRenderWindow_getSize(aw).x);
    return (0);
}
