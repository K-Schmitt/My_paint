/*
** EPITECH PROJECT, 2022
** my paint
** File description:
** wanna save
*/

#include "../lib/my/my.h"
#include "../lib/my/csfmLib/csfmlib.h"
#include <stdio.h>
#include <stdlib.h>

static void init_wanna_save2(files *file)
{
    sfVector2u windowSize = sfRenderWindow_getSize(file->window2);
    float rectWidth = 800;
    float rectHeight = 150;
    float rectPosX = (windowSize.x - rectWidth) / 2.0f;
    float rectPosY = (windowSize.y - rectHeight) / 2.0f;
    file->yes_texture = sfTexture_createFromFile("./assets/yes.png", NULL);
    file->yes_sprite = sfSprite_create();
    sfSprite_setTexture(file->yes_sprite, file->yes_texture, sfTrue);
    sfSprite_setScale(file->yes_sprite, (sfVector2f){0.5, 0.5});
    sfSprite_setPosition(file->yes_sprite,
    (sfVector2f){rectPosX + 500, rectPosY + 170});
    file->no_texture = sfTexture_createFromFile("./assets/no.png", NULL);
    file->no_sprite = sfSprite_create();
    sfSprite_setTexture(file->no_sprite, file->no_texture, sfTrue);
    sfSprite_setScale(file->no_sprite, (sfVector2f){0.5, 0.5});
    sfSprite_setPosition(file->no_sprite,
    (sfVector2f){rectPosX + 130, rectPosY + 170});
}

void init_wanna_save(files *file)
{
    sfVideoMode mode = {1000, 600, 64};
    file->window2 = sfRenderWindow_create(mode, "Wanna Save", sfClose, NULL);
    file->font = sfFont_createFromFile("./assets/arial.ttf");
    file->help = sfText_create();
    sfText_setFont(file->help, file->font);
    sfText_setCharacterSize(file->help, 40);
    sfText_setFillColor(file->help, sfWhite);
    sfText_setString(file->help, "Do you wan't to save your file ?");
    sfVector2u windowSize = sfRenderWindow_getSize(file->window2);
    float rectPoX = (windowSize.x - 800) / 2.0f;
    float rectPoY = (windowSize.y - 150) / 2.0f;
    sfText_setPosition(file->help, (sfVector2f){rectPoX + 110, rectPoY + 30});
    file->rectangle = sfRectangleShape_create();
    sfRectangleShape_setPosition(file->rectangle,
    (sfVector2f){rectPoX, rectPoY - 20});
    sfRectangleShape_setSize(file->rectangle,
    (sfVector2f){800, 150});
    sfRectangleShape_setFillColor(file->rectangle, sfBlack);
    sfRectangleShape_setOutlineColor(file->rectangle, sfGreen);
    init_wanna_save2(file);
}

static void event_next(files* file, struct alll *all)
{
    if (all->event.type == sfEvtMouseButtonReleased ||
    sfTrue == sfKeyP(sfKeyEnter)) {
        sfRenderWindow_close(file->window2);
        file->save = 1;
    }
}

static void event(files* file, struct alll *all)
{
    sfVector2i cur = sfMouse_getPositionRenderWindow(file->window2);
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(file->window2, cur, NULL);
    while (sfRenderWindow_pollEvent(file->window2, &all->event)) {
        if (all->event.type == sfEvtClosed)
            sfRenderWindow_close(file->window2);
        if (pos.x > 230 && pos.x < 400 && pos.y > 400 && pos.y < 560)
            save_bip(file, all);
        if (pos.x > 600 && pos.x < 770 && pos.y > 400 && pos.y < 560)
            event_next(file, all);
    }
}

void wanna_save(files *file, struct alll *all)
{
    init_wanna_save(file);
    while (sfRenderWindow_isOpen(file->window2)) {
        event(file, all);
        sfRenderWindow_clear(file->window2, sfWhite);
        sfRenderWindow_drawRectangleShape(file->window2, file->rectangle,
        NULL);
        sfRenderWindow_drawText(file->window2, file->help, NULL);
        sfRenderWindow_drawSprite(file->window2, file->yes_sprite, NULL);
        sfRenderWindow_drawSprite(file->window2, file->no_sprite, NULL);
        sfRenderWindow_display(file->window2);
    }
    sfRenderWindow_destroy(file->window2);
    sfFont_destroy(file->font);
    sfText_destroy(file->help);
    sfSprite_destroy(file->yes_sprite);
    sfSprite_destroy(file->no_sprite);
    sfRectangleShape_destroy(file->rectangle);
}
