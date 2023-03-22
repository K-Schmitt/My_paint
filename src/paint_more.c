/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** paint more
*/

#include "../lib/my/my.h"
#include "../lib/my/csfmLib/csfmlib.h"
#include <stdio.h>
#include <stdlib.h>

void add_node(struct circle **node, struct alll *all)
{
    struct circle* new = (struct circle*)malloc(sizeof(struct circle));
    new->circle = sfCircleShape_create();
    new->radius = 10 * all->button.size_shape;
    new->pos.x = mp.x - 10 * all->button.size_shape;
    new->pos.y = mp.y - 10 * all->button.size_shape;
    new->color = all->button.cur_color;
    new->next = NULL;
    if (*node == NULL)
        *node = new;
    else {
        struct circle* temp = *node;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new;
    }
}

void pencil(struct alll *all)
{
    if (all->mouse_mod != 1 && all->mouse_mod2 != 1)
        return;
    sfUint8 color[all->button.size_pencil * all->button.size_pencil * 4];
    for (int i = 0; i < all->button.size_pencil *
    all->button.size_pencil; i++) {
        color[i * 4] = all->button.cur_color.r;
        color[i * 4 + 1] = all->button.cur_color.g;
        color[i * 4 + 2] = all->button.cur_color.b;
        color[i * 4 + 3] = all->button.cur_color.a;
    }
    if (mp.x > posi.x + ps && mp.x < (posi.x - ps + sizze.x * scal.x) &&
    mp.y > posi.y + ps && mp.y < posi.y - ps + (sizze.y * scal.y))
        if ((sfTrue == left_click && all->mouse_mod2 == 1) ||
        (sfTrue == right_click && all->mouse_mod == 1)) {
            sfTexture_updateFromPixels(all->image.img_texture, color,
            ps, ps, all->brush_pos.x, all->brush_pos.y);
            sfSprite_setTexture(all->image.img_sprite,
            all->image.img_texture, sfTrue);
        }
}

void circle(struct alll *all)
{
    if ((mp.x > posi.x + 5 * all->button.size_shape && mp.x < posi.x -
    5 * all->button.size_shape + (sizze.x * scal.x) &&
    mp.y > posi.y + 5 * all->button.size_shape && mp.y < posi.y -
    5 * all->button.size_shape + (sizze.y * scal.y)))
        if ((sfTrue == left_click && all->mouse_mod2 == 6) ||
        (sfTrue == right_click && all->mouse_mod == 6))
            add_node(&all->node, all);
}

static void get_size(struct alll *all)
{
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyR) &&
    sfTime_asSeconds(sfClock_getElapsedTime(all->c_select)) > 0.15000f) {
        all->button.rotate++;
        sfClock_restart(all->c_select);
    }
    if (all->button.rotate % 2 == 1) {
        all->button.size_x = 70;
        all->button.size_y = 40;
    } else {
        all->button.size_x = 40;
        all->button.size_y = 70;
    }
    all->button.size_x *= (int)all->button.size_shape;
    all->button.size_y *= (int)all->button.size_shape;
}

void rectangle(struct alll *all)
{
    get_size(all);
    sfUint8 color[all->button.size_x * all->button.size_y * 4];
    for (int i = 0; i < all->button.size_x *
    all->button.size_y; i++) {
        color[i * 4] = all->button.cur_color.r;
        color[i * 4 + 1] = all->button.cur_color.g;
        color[i * 4 + 2] = all->button.cur_color.b;
        color[i * 4 + 3] = all->button.cur_color.a;
    }
    if ((mp.x > posi.x && mp.x < posi.x - all->button.size_x + (sizze.x *
    scal.x) && mp.y > posi.y && mp.y < posi.y - all->button.size_y +
    (sizze.y * scal.y)))
        if ((sfTrue == left_click && all->mouse_mod2 == 5) ||
        (sfTrue == right_click && all->mouse_mod == 5)) {
            sfTexture_updateFromPixels(all->image.img_texture, color,
            all->button.size_x, all->button.size_y, all->brush_pos.x,
            all->brush_pos.y);
            sfSprite_setTexture(all->image.img_sprite,
            all->image.img_texture, sfTrue);
        }
}
