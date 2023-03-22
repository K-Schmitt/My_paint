/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** init save
*/

#include "../lib/my/my.h"
#include "../lib/my/csfmLib/csfmlib.h"
#include <stdlib.h>

static void init_save_menu5(files *file)
{
    sfVector2u windowSize = sfRenderWindow_getSize(file->window);
    float p_x = (windowSize.x - 160) / 2.0f;
    file->rect_jpg = sfRectangleShape_create();
    sfRectangleShape_setPosition(file->rect_jpg, (sfVector2f){p_x - 223, 40});
    sfRectangleShape_setSize(file->rect_jpg, (sfVector2f){160, 170});
    sfRectangleShape_setOutlineColor(file->rect_jpg, sfBlack);
    sfRectangleShape_setOutlineThickness(file->rect_jpg, 10);
    file->rect_png = sfRectangleShape_create();
    sfRectangleShape_setPosition(file->rect_png, (sfVector2f){p_x + 002, 40});
    sfRectangleShape_setSize(file->rect_png, (sfVector2f){160, 170});
    sfRectangleShape_setOutlineColor(file->rect_png, sfBlack);
    sfRectangleShape_setOutlineThickness(file->rect_png, 10);
    file->rect_bmp = sfRectangleShape_create();
    sfRectangleShape_setPosition(file->rect_bmp, (sfVector2f){p_x + 227, 40});
    sfRectangleShape_setSize(file->rect_bmp, (sfVector2f){160, 170});
    sfRectangleShape_setOutlineColor(file->rect_bmp, sfBlack);
    sfRectangleShape_setOutlineThickness(file->rect_bmp, 10);
}

static void init_save_menu4(files *file)
{
    file->jpg_texture = sfTexture_createFromFile("./assets/jpg.png", NULL);
    file->jpg_sprite = sfSprite_create();
    sfSprite_setTexture(file->jpg_sprite, file->jpg_texture, sfTrue);
    sfSprite_setScale(file->jpg_sprite, (sfVector2f){0.3, 0.3});
    sfSprite_setPosition(file->jpg_sprite, (sfVector2f){300, 50});
    file->png_texture = sfTexture_createFromFile("./assets/png.png", NULL);
    file->png_sprite = sfSprite_create();
    sfSprite_setTexture(file->png_sprite, file->png_texture, sfTrue);
    sfSprite_setScale(file->png_sprite, (sfVector2f){0.3, 0.3});
    sfSprite_setPosition(file->png_sprite, (sfVector2f){525, 50});
    file->bmp_texture = sfTexture_createFromFile("./assets/bmp.png", NULL);
    file->bmp_sprite = sfSprite_create();
    sfSprite_setTexture(file->bmp_sprite, file->bmp_texture, sfTrue);
    sfSprite_setScale(file->bmp_sprite, (sfVector2f){0.3, 0.3});
    sfSprite_setPosition(file->bmp_sprite, (sfVector2f){750, 50});
    init_save_menu5(file);
}

static void init_save_menu3(files *file)
{
    file->save_texture = sfTexture_createFromFile("./assets/save.png", NULL);
    file->save_sprite = sfSprite_create();
    sfSprite_setTexture(file->save_sprite, file->save_texture, sfTrue);
    sfSprite_setScale(file->save_sprite, (sfVector2f){0.7, 0.7});
    sfSprite_setPosition(file->save_sprite,
    (sfVector2f){file->rect_px + 315, file->rect_py + 160});
    file->cancel_texture =
    sfTexture_createFromFile("./assets/cancel.png", NULL);
    file->cancel_sprite = sfSprite_create();
    sfSprite_setTexture(file->cancel_sprite, file->cancel_texture, sfTrue);
    sfSprite_setScale(file->cancel_sprite, (sfVector2f){0.4, 0.4});
    sfSprite_setPosition(file->cancel_sprite,
    (sfVector2f){file->rect_px + 210, file->rect_py + 225});
    file->ex = sfText_create();
    sfText_setPosition(file->ex, (sfVector2f){file->rect_px + 10,
    file->rect_py + 70});
    sfText_setFont(file->ex, file->font);
    sfText_setFillColor(file->ex, sfWhite);
    sfText_setString(file->ex, "Example: valid_file_path/name_of_the_file");
    init_save_menu4(file);
}

static void init_save_menu2(files *file)
{
    sfText_setPosition(file->text,
    (sfVector2f){file->rect_px + 150, file->rect_py + 135});
    sfText_setPosition(file->help,
    (sfVector2f){file->rect_px + 10, file->rect_py + 135});
    file->rectangle = sfRectangleShape_create();
    sfRectangleShape_setPosition(file->rectangle,
    (sfVector2f){file->rect_px, file->rect_py + 50});
    sfRectangleShape_setSize(file->rectangle,
    (sfVector2f){file->rect_x, file->rect_y});
    sfRectangleShape_setFillColor(file->rectangle, sfBlack);
    init_save_menu3(file);
    file->timer = sfClock_create();
}

void init_save_menu(files *file)
{
    sfVideoMode mode = {1200, 600, 64};
    file->window = sfRenderWindow_create(mode, "Save Menu", sfClose, NULL);
    file->window_size = sfRenderWindow_getSize(file->window);
    file->rect_x = 800;
    file->rect_y = 150;
    file->rect_px = (file->window_size.x - file->rect_x) / 2.0f;
    file->rect_py = (file->window_size.y - file->rect_y) / 2.0f;
    file->font = sfFont_createFromFile("./assets/arial.ttf");
    file->text = sfText_create();
    sfText_setFont(file->text, file->font);
    sfText_setCharacterSize(file->text, 32);
    sfText_setFillColor(file->text, sfWhite);
    file->help = sfText_create();
    sfText_setFont(file->help, file->font);
    sfText_setCharacterSize(file->help, 32);
    sfText_setFillColor(file->help, sfWhite);
    sfText_setString(file->help, "File path: ");
    file->input = malloc(sizeof(char) * 100);
    file->inputLength = 0;
    init_save_menu2(file);
}
