/*
** EPITECH PROJECT, 2022
** my_paint
** File description:
** init first
*/

#include "../lib/my/csfmLib/csfmlib.h"
#include <stdlib.h>
#include <stdbool.h>

files *init_file(void)
{
    files *file = malloc(sizeof(files));
    if (file == NULL)
        return (NULL);
    file->buffer = NULL;
    file->path = NULL;
    file->path_open = NULL;
    file->option = 1;
    file->open_active = 0;
    file->save = 0;
    return (file);
}

void new_file(struct alll *all, files *file, int option)
{
    if (option == 1) {
        wanna_save(file, all);
        if (file->save == 1)
            print_save_menu(file, all);
    }
    create_sprite(&all->image, "./assets/background.png", vecf(1, 1));
}

static void init_window(struct alll *all, files *file)
{
    sfVideoMode mode = {1920, 1080, 64};
    aw = sfRenderWindow_create(mode, "My Paint", sfResize | sfClose, 0);
    sfImage *icon = sfImage_createFromFile("./assets/icon.png");
    sfRenderWindow_setIcon(aw, sfImage_getSize(icon).x,
    sfImage_getSize(icon).y, sfImage_getPixelsPtr(icon));
    new_file(all, file, 0);
    all->c_select = sfClock_create();
}

static int init_image(struct alll *all, files *file)
{
    if (file->buffer == NULL)
        return (0);
    create_sprite(&all->image, file->path, vecf(0.5, 0.5));
    all->image.pos = vecf(500, 500);
    sfSprite_setPosition(all->image.img_sprite, all->image.pos);
    return (0);
}

void init_all(struct alll *all, files *file)
{
    init_window(all, file);
    init_struct_all(all);
    create_cadre(all);
    init_image(all, file);
    init_toolbar(all);
    init_bouton(all);
    init_sprite(all);
}
