/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** paint basic
*/

#include "../lib/my/my.h"
#include "../lib/my/csfmLib/csfmlib.h"
#include <stdio.h>

void select_color2(struct alll *all)
{
    sfVector2f pos = sfSprite_getPosition(im.color.img_sprite);
    sfVector2u size = sfTexture_getSize(im.color.img_texture);
    sfVector2f scale = sfSprite_getScale(im.color.img_sprite);
    if (all->mouse.x > pos.x && all->mouse.x < pos.x + (size.x * scale.x) &&
    all->mouse.y > pos.y && all->mouse.y < pos.y + (size.y * scale.y)) {
        if (sfTrue == sfMouse_isButtonPressed(sfMouseLeft)) {
            sfImage* image;
            image = sfTexture_copyToImage(im.color.img_texture);
            all->button.cur_color = sfImage_getPixel(image,
            (all->mouse.x - pos.x) * im.color.scale_r.x,
            (all->mouse.y - pos.y) * im.color.scale_r.y);
        }
    }
    if (all->button.cur_color.r == 255 && all->button.cur_color.g == 255 &&
    all->button.cur_color.b == 255 && all->button.cur_color.a == 0) {
        all->button.cur_color.r = 0;
        all->button.cur_color.g = 0;
        all->button.cur_color.b = 0;
        all->button.cur_color.a = 255;
    }
}

void select_color(struct alll *all)
{
    select_color2(all);
    if (all->mouse_mod != 3 && all->mouse_mod2 != 3)
        return;
    if (mp.x > posi.x && mp.x < posi.x + (sizze.x * scal.x) &&
    mp.y > posi.y && mp.y < posi.y + (sizze.y * scal.y))
        if ((sfTrue == left_click && all->mouse_mod2 == 3) ||
        (sfTrue == right_click && all->mouse_mod == 3)) {
            sfImage* image;
            image = sfTexture_copyToImage(all->image.img_texture);
            all->button.cur_color =
            sfImage_getPixel(image, all->brush_pos.x, all->brush_pos.y);
        }
}

void eraser(struct alll *all)
{
    if (all->mouse_mod != 2 && all->mouse_mod2 != 2)
        return;
    sfUint8 color[all->button.size_eraser * all->button.size_eraser * 4];
    for (int i = 0; i < es * es; i++) {
        color[i * 4] = 0;
        color[i * 4 + 1] = 0;
        color[i * 4 + 2] = 0;
        color[i * 4 + 3] = 0;
        color[i * 4 + 3] = 0;
    }
    if (mp.x > posi.x + es && mp.x < posi.x - es + (sizze.x * scal.x) &&
    mp.y > posi.y + es && mp.y < posi.y - es + (sizze.y * scal.y))
        if ((sfTrue == left_click && all->mouse_mod2 == 2) ||
        (sfTrue == right_click && all->mouse_mod == 2)) {
            sfTexture_updateFromPixels(all->image.img_texture, color,
            es, es, all->brush_pos.x, all->brush_pos.y);
            sfSprite_setTexture(all->image.img_sprite,
            all->image.img_texture, sfTrue);
        }
}

void brush(struct alll *all)
{
    if (all->mouse_mod != 4 && all->mouse_mod2 != 4)
        return;
    sfUint8 color[all->button.size_brush * all->button.size_brush * 4];
    for (int i = 0; i < all->button.size_brush * all->button.size_brush; i++) {
        color[i * 4] = all->button.cur_color.r;
        color[i * 4 + 1] = all->button.cur_color.g;
        color[i * 4 + 2] = all->button.cur_color.b;
        color[i * 4 + 3] = all->button.cur_color.a;
    }
    if (mp.x > posi.x + bs && mp.x < (posi.x - bs + sizze.x * scal.x) &&
    mp.y > posi.y + bs && mp.y < posi.y - bs + (sizze.y * scal.y))
        if ((sfTrue == left_click && all->mouse_mod2 == 4) ||
        (sfTrue == right_click && all->mouse_mod == 4)) {
            sfTexture_updateFromPixels(all->image.img_texture, color,
            bs, bs, all->brush_pos.x, all->brush_pos.y);
            sfSprite_setTexture(all->image.img_sprite,
            all->image.img_texture, sfTrue);
        }
}
