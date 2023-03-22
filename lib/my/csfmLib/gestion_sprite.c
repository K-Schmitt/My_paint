/*
** EPITECH PROJECT, 2022
** gestion sprite
** File description:
** gestion sprite
*/

#include "csfmlib.h"
#include "./../my.h"

sfVector2f nscale(struct alll *all, float x, float y)
{
    sfVector2f b;
    float xx = x / ((float)1920 / sfRenderWindow_getSize(aw).x);
    float yy = y / ((float)1080 / sfRenderWindow_getSize(aw).y);
    if (xx > yy)
        b = vecf(yy, yy);
    else
        b = vecf(xx, xx);
    return (b);
}

sfVector2f centre(struct stocksprite bob, struct alll *all, sfVector2i pos)
{
    sfVector2f b = sfRenderWindow_mapPixelToCoords(aw,
    veci(((sfRenderWindow_getSize(aw).x - pos.x) / 2)
    - ((bob.scale.x * bob.size.x) / 2),
    ((sfRenderWindow_getSize(aw).y - pos.y) / 2)
    - ((bob.scale.y * bob.size.y) / 2)), all->area);
    return (b);
}

void animate(struct stocksprite *bob, float x)
{
    if (bob->r <= 0 && bob->r > bob->frame)
        bob->r = 1;
    bob->frame = x;
    if ((sfClock_getElapsedTime(bob->Clock).ms) > (sfSeconds(1 / bob->frame).ms
    * bob->r)) {
        bob->z.left += 32;
        bob->r++;
    }
    if (bob->r > bob->frame) {
        bob->z.left = 0;
        bob->r = 1;
        sfClock_restart	(bob->Clock);
    }
}

sfSprite *create_sprite(ssbp, char *path, sfVector2f scale)
{
    bob->img_texture = sfTexture_createFromFile(path, NULL);
    bob->img_sprite = sfSprite_create();
    bob->scale.x = scale.x;
    bob->scale.y = scale.y;
    bob->size = sfTexture_getSize(bob->img_texture);
    sfSprite_setTexture(bob->img_sprite, bob->img_texture , sfTrue);
    sfSprite_setScale(bob->img_sprite, bob->scale);
    return (0);
}

sfSprite *create_perso(ssbp, char *path, sfVector2f z, sfVector2i t)
{
    bob->img_texture = sfTexture_createFromFile(path, NULL);
    bob->img_sprite = sfSprite_create();
    bob->scale.x = z.x;
    bob->scale.y = z.y;
    bob->z = recti(0, 0, t.x, t.y);
    bob->Clock = sfClock_create();
    sfSprite_setTexture(bob->img_sprite, bob->img_texture, sfTrue);
    sfSprite_setScale(bob->img_sprite, bob->scale);
    return (0);
}
