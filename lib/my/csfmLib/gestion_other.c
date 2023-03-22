/*
** EPITECH PROJECT, 2022
** gestion sprite
** File description:
** gestion other
*/

#include "csfmlib.h"
#include "./../my.h"

void create_bouton_image_next(struct alll *all,
int mode)
{
    if (sfTrue == sfMouse_isButtonPressed(sfMouseLeft) &&
    all->random.click == 0)
        all->random.click = 1;
    if (sfFalse == sfMouse_isButtonPressed(sfMouseLeft) &&
    all->random.click == 1) {
        all->mouse_mod = mode;
        all->random.click = 0;
    }
    if (sfTrue == sfMouse_isButtonPressed(sfMouseRight) &&
    all->random.click == 0)
        all->random.click = 1;
    if (sfFalse == sfMouse_isButtonPressed(sfMouseRight) &&
    all->random.click == 1) {
        all->mouse_mod2 = mode;
        all->random.click = 0;
    }
}

void create_bouton_image(struct alll *all, struct stocksprite *tutu,
sfVector2i z, int mode)
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
        create_bouton_image_next(all, mode);
}
