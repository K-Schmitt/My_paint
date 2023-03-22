/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** init open
*/

#include "../lib/my/my.h"
#include "../lib/my/csfmLib/csfmlib.h"
#include <stdlib.h>

static void init_open_menu4(files *file)
{
    sfVector2u windowSize = sfRenderWindow_getSize(file->window);
    float rectWidth = 800;
    float rectHeight = 150;
    float rectPosX = (windowSize.x - rectWidth) / 2.0f;
    float rectPosY = (windowSize.y - rectHeight) / 2.0f;
    file->save_texture2 = sfTexture_createFromFile("./assets/save.png", NULL);
    file->save_sprite2 = sfSprite_create();
    sfSprite_setTexture(file->save_sprite2, file->save_texture2, sfTrue);
    sfSprite_setScale(file->save_sprite2, (sfVector2f){0.7, 0.7});
    sfSprite_setPosition(file->save_sprite2,
    (sfVector2f){rectPosX + 315, rectPosY + 135});
    file->cancel_texture2 =
    sfTexture_createFromFile("./assets/cancel.png", NULL);
    file->cancel_sprite2 = sfSprite_create();
    sfSprite_setTexture(file->cancel_sprite2, file->cancel_texture2, sfTrue);
    sfSprite_setScale(file->cancel_sprite2, (sfVector2f){0.4, 0.4});
    sfSprite_setPosition(file->cancel_sprite2,
    (sfVector2f){rectPosX + 210, rectPosY + 200});
}

static void init_open_menu3(files *file)
{
    sfVector2u windowSize = sfRenderWindow_getSize(file->window);
    float rectWidth = 800;
    float rectHeight = 150;
    float rectPosX = (windowSize.x - rectWidth) / 2.0f;
    float rectPosY = (windowSize.y - rectHeight) / 2.0f;
    file->open = sfText_create();
    sfText_setFont(file->open, file->font);
    sfText_setCharacterSize(file->open, 32);
    sfText_setFillColor(file->open, sfWhite);
    sfText_setPosition(file->open,
    (sfVector2f){rectPosX + 10, rectPosY + 20});
    sfText_setString(file->open, "Path to the image");
    init_open_menu4(file);
}

static void init_open_menu2(files *file)
{
    sfVector2u windowSize = sfRenderWindow_getSize(file->window);
    float rectWidth = 800;
    float rectHeight = 150;
    float rectPosX = (windowSize.x - rectWidth) / 2.0f;
    float rectPosY = (windowSize.y - rectHeight) / 2.0f;
    sfText_setPosition(file->open_text,
    (sfVector2f){rectPosX + 210, rectPosY + 90});
    sfText_setPosition(file->help, (sfVector2f){rectPosX + 10, rectPosY + 90});
    file->rectangle = sfRectangleShape_create();
    sfRectangleShape_setPosition(file->rectangle,
    (sfVector2f){rectPosX, rectPosY});
    sfRectangleShape_setSize(file->rectangle,
    (sfVector2f){rectWidth, rectHeight});
    sfRectangleShape_setFillColor(file->rectangle, sfBlack);
    sfRectangleShape_setOutlineColor(file->rectangle, sfGreen);
    file->timer = sfClock_create();
    init_open_menu3(file);
}

void init_open_menu(files *file)
{
    sfVideoMode mode = {1200, 600, 64};
    file->window = sfRenderWindow_create(mode, "Open Menu", sfClose, NULL);
    file->font = sfFont_createFromFile("./assets/arial.ttf");
    file->open_text = sfText_create();
    sfText_setFont(file->open_text, file->font);
    sfText_setCharacterSize(file->open_text, 32);
    sfText_setFillColor(file->open_text, sfWhite);
    file->help = sfText_create();
    sfText_setFont(file->help, file->font);
    sfText_setCharacterSize(file->help, 32);
    sfText_setFillColor(file->help, sfWhite);
    sfText_setString(file->help, "Image path: ");
    file->open_input = malloc(sizeof(char) * 100);
    file->open_inputLength = 0;
    init_open_menu2(file);
}
