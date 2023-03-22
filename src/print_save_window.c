/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** save image
*/

#include "../lib/my/my.h"
#include "../lib/my/csfmLib/csfmlib.h"
#include <stdlib.h>

static void get_text(files *file, struct alll *all)
{
    if (all->event.text.unicode >= 32 && all->event.text.unicode < 128) {
        char c = (char)all->event.text.unicode;
        if (sfTime_asSeconds(sfClock_getElapsedTime(file->timer)) > 0.15000f
        && file->inputLength < 99) {
            file->input[file->inputLength] = c;
            file->input[file->inputLength + 1] = '\0';
            file->inputLength++;
            sfText_setString(file->text, file->input);
            sfClock_restart(file->timer);
        }
    }
    if (all->event.text.unicode == '\b' && file->inputLength > 0) {
        if (sfTime_asSeconds(sfClock_getElapsedTime(file->timer)) > 0.09500f) {
            file->inputLength--;
            file->input[file->inputLength] = '\0';
            sfText_setString(file->text, file->input);
            sfClock_restart(file->timer);
        }
    }
}

static void print_save_next(files *file, struct alll *all)
{
    sfVector2i mous = sfMouse_getPositionRenderWindow(file->window);
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(file->window, mous, NULL);
    while (sfRenderWindow_pollEvent(file->window, &all->event)) {
        if (all->event.type == sfEvtClosed)
            sfRenderWindow_close(file->window);
        init_save_image(file, all, pos);
        if (pos.x > 422 && pos.x < 526 && pos.y > 461 && pos.y < 566)
            (all->event.type == sfEvtMouseButtonReleased) ?
            sfRenderWindow_close(file->window) : 0;
        if (all->event.type == sfEvtTextEntered)
            get_text(file, all);
    }
}

void destroy_save(files *file)
{
    sfFont_destroy(file->font);
    sfText_destroy(file->text);
    sfText_destroy(file->ex);
    sfText_destroy(file->help);
    sfSprite_destroy(file->save_sprite);
    sfSprite_destroy(file->cancel_sprite);
    sfSprite_destroy(file->jpg_sprite);
    sfSprite_destroy(file->png_sprite);
    sfSprite_destroy(file->bmp_sprite);
    sfClock_destroy(file->timer);
    sfRectangleShape_destroy(file->rectangle);
    sfRenderWindow_destroy(file->window);
}

static void option(files *file)
{
    if (file->option == 1)
        sfRenderWindow_drawRectangleShape(file->window, file->rect_jpg, NULL);
    if (file->option == 2)
        sfRenderWindow_drawRectangleShape(file->window, file->rect_png, NULL);
    if (file->option == 3)
        sfRenderWindow_drawRectangleShape(file->window, file->rect_bmp, NULL);
}

void print_save_menu(files *file, struct alll *all)
{
    init_save_menu(file);
    while (sfRenderWindow_isOpen(file->window)) {
        print_save_next(file, all);
        sfRenderWindow_clear(file->window, sfWhite);
        option(file);
        sfRenderWindow_drawRectangleShape(file->window, file->rectangle, NULL);
        sfRenderWindow_drawText(file->window, file->help, NULL);
        sfRenderWindow_drawText(file->window, file->text, NULL);
        sfRenderWindow_drawText(file->window, file->ex, NULL);
        sfRenderWindow_drawSprite(file->window, file->save_sprite, NULL);
        sfRenderWindow_drawSprite(file->window, file->cancel_sprite, NULL);
        sfRenderWindow_drawSprite(file->window, file->jpg_sprite, NULL);
        sfRenderWindow_drawSprite(file->window, file->png_sprite, NULL);
        sfRenderWindow_drawSprite(file->window, file->bmp_sprite, NULL);
        sfRenderWindow_display(file->window);
    }
    destroy_save(file);
}
