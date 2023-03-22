/*
** EPITECH PROJECT, 2022
** gestion sprite
** File description:
** gestion tout
*/

#include "csfmlib.h"
#include "./../my.h"

sfVector2f nscale_reverse(struct alll *all, float x, float y)
{
    sfVector2f b;

    float xx = x / (sfRenderWindow_getSize(aw).x / (float)1920);
    float yy = y / (sfRenderWindow_getSize(aw).y / (float)1080);
    if (xx > yy)
        b = vecf(xx, xx);
    else
        b = vecf(yy, yy);
    return (b);
}

int create_text(struct stocktext *x, char *str, int charasize, sfVector2f pos)
{
    x->font = sfFont_createFromFile("./assets/arial.ttf");
    x->text = sfText_create();
    sfText_setFont(x->text, x->font);
    sfText_setCharacterSize(x->text, charasize);
    sfText_setFillColor(x->text, sfBlack);
    sfText_setString(x->text, str);
    sfText_setPosition(x->text, pos);
    return (0);
}

void create_rect_next(struct stockrect *x, sfVector2f size, int opt)
{
    if (opt >= 3) {
        sfColor bob = sfColor_fromRGB(170, 170, 170);
        bob.a = 135;
        sfRectangleShape_setFillColor(x->name, bob);
        sfRectangleShape_setOutlineColor(x->name, sfBlack);
        if (opt == 4)
            sfRectangleShape_setOutlineColor(x->name, sfRed);
        if (opt == 5)
            sfRectangleShape_setOutlineColor(x->name, sfBlue);
    }
    sfRectangleShape_setOutlineThickness(x->name, 3);
    sfRectangleShape_setSize(x->name, size);
}

void create_rect(struct stockrect *x, sfVector2f size, sfVector2f pos, int opt)
{
    x->name = sfRectangleShape_create();
    sfRectangleShape_setPosition(x->name, pos);
    if (opt == 0) {
        sfRectangleShape_setFillColor(x->name, sfTransparent);
        sfRectangleShape_setOutlineColor(x->name, sfBlack);
    }
    if (opt == 1) {
        sfRectangleShape_setFillColor(x->name, sfColor_fromRGB(80, 80, 80));
        sfRectangleShape_setOutlineColor(x->name, sfBlack);
    }
    create_rect_next(x, size, opt);
}

void create_bouton(struct alll *all, int x_pos, int y_pos, int mode)
{
    if (all->mouse.x >= x_pos && all->mouse.x <= x_pos + 200 &&
    all->mouse.y >= y_pos && all->mouse.y <= y_pos + 30) {
        if (sfTrue == sfMouse_isButtonPressed(sfMouseLeft) &&
        all->random.click == 0)
            all->random.click = 1;
        if (sfFalse == sfMouse_isButtonPressed(sfMouseLeft) &&
        all->random.click == 1) {
            all->mouse_mod2 = mode;
            all->random.click = 0;
            all->random.infobarC = 0;
        }
    }
}
