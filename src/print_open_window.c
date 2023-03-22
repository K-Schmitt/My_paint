/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** open image
*/

#include "../lib/my/my.h"
#include "../lib/my/csfmLib/csfmlib.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>

void open_image(files *file, struct alll *all, sfVector2f pos)
{
    int j = 1;
    if ((pos.x > 592 && pos.x < 800 && pos.y > 443 && pos.y < 527
    && (all->event.type == sfEvtMouseButtonReleased))
    || sfTrue == sfKeyP(sfKeyEnter))
        if (file->open_inputLength > 0) {
            (open_file(file->open_input, file, 1) != -1) ? j = 0 : 0;
        }
    if (j == 0) {
        create_sprite(&all->image, file->path_open, vecf(0.5, 0.5));
        all->image.pos = centre(all->image, all, veci(0, 0));
        sfSprite_setPosition(all->image.img_sprite, all->image.pos);
        sfRenderWindow_close(file->window);
    }
}

static void get_text(files *file, struct alll *all)
{
    if (all->event.text.unicode >= 32 && all->event.text.unicode < 128) {
        char c = (char)all->event.text.unicode;
        if (sfTime_asSeconds(sfClock_getElapsedTime(file->timer)) > 0.15000f
        && file->open_inputLength < 99) {
            file->open_input[file->open_inputLength] = c;
            file->open_input[file->open_inputLength + 1] = '\0';
            file->open_inputLength++;
            sfText_setString(file->open_text, file->open_input);
            sfClock_restart(file->timer);
        }
    }
    if (all->event.text.unicode == '\b' && file->open_inputLength > 0) {
        if (sfTime_asSeconds(sfClock_getElapsedTime(file->timer)) > 0.09500f) {
            file->open_inputLength--;
            file->open_input[file->open_inputLength] = '\0';
            sfText_setString(file->open_text, file->open_input);
            sfClock_restart(file->timer);
        }
    }
}

static void print_open_next(files *file, struct alll *all)
{
    sfVector2i mous = sfMouse_getPositionRenderWindow(file->window);
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(file->window, mous, NULL);
    while (sfRenderWindow_pollEvent(file->window, &all->event)) {
        if (all->event.type == sfEvtClosed)
            sfRenderWindow_close(file->window);
        if (pos.x > 416 && pos.x < 526 && pos.y > 432 && pos.y < 541)
            (all->event.type == sfEvtMouseButtonReleased) ?
            sfRenderWindow_close(file->window) : 0;
        open_image(file, all, pos);
        if (all->event.type == sfEvtTextEntered)
            get_text(file, all);
    }
}

void destroy_open(files *file)
{
    sfFont_destroy(file->font);
    sfText_destroy(file->open_text);
    sfText_destroy(file->open);
    sfText_destroy(file->help);
    sfSprite_destroy(file->save_sprite2);
    sfSprite_destroy(file->cancel_sprite2);
    sfRectangleShape_destroy(file->rectangle);
    sfClock_destroy(file->timer);
    sfRenderWindow_destroy(file->window);
}

void print_open_menu(struct alll *all, files *file)
{
    init_open_menu(file);
    while (sfRenderWindow_isOpen(file->window)) {
        print_open_next(file, all);
        sfRenderWindow_clear(file->window, sfWhite);
        sfRenderWindow_drawRectangleShape(file->window, file->rectangle, NULL);
        sfRenderWindow_drawText(file->window, file->help, NULL);
        sfRenderWindow_drawText(file->window, file->open_text, NULL);
        sfRenderWindow_drawText(file->window, file->open, NULL);
        sfRenderWindow_drawSprite(file->window, file->save_sprite2, NULL);
        sfRenderWindow_drawSprite(file->window, file->cancel_sprite2, NULL);
        sfRenderWindow_display(file->window);
    }
    destroy_open(file);
}
