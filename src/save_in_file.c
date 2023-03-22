/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** save in file
*/

#include "../lib/my/my.h"
#include "../lib/my/csfmLib/csfmlib.h"
#include <stdlib.h>
#include <dirent.h>
#include <SFML/Graphics/Texture.h>

void get_image_from_file(files *file, struct alll *all)
{
    sfImage* image;
    image = sfTexture_copyToImage(all->image.img_texture);
    if (file->option == 1) {
        my_strcat(file->input, ".jpg");
        sfImage_saveToFile(image, file->input);
    }
    if (file->option == 2) {
        my_strcat(file->input, ".png");
        sfImage_saveToFile(image, file->input);
    }
    if (file->option == 3) {
        my_strcat(file->input, ".bmp");
        sfImage_saveToFile(image, file->input);
    }
    sfRenderWindow_close(file->window);
}

char *get_only_folder(const char* input)
{
    int length = my_strlen(input);
    int lastSlashIndex = -1;
    int count = 0;
    if (input == NULL)
        return (NULL);
    for (int i = 0; i < length; i++)
        if (input[i] == '/') {
            lastSlashIndex = i;
            count++;
        }
    if (count == 0)
        return (NULL);
    length = (lastSlashIndex == -1) ? my_strlen(input) : lastSlashIndex;
    char* output = (char*) malloc(length + 1);
    if (output == NULL)
        return NULL;
    for (int i = 0; i < length; i++)
        output[i] = input[i];
    output[length] = '\0';
    return (output);
}

int is_valid_folder(files *file)
{
    char *file_path = get_only_folder(file->input);
    if (file_path == NULL)
        return (2);
    DIR* directory = opendir(file_path);
    if (directory == NULL) {
        free(file_path);
        return (-1);
    }
    closedir(directory);
    free(file_path);
    return (0);
}

int init_save_image(files *file, struct alll *all, sfVector2f pos)
{
    int i = 0;
    int j = 0;
    if (pos.x > 290 && pos.x < 466 && pos.y > 31 && pos.y < 223)
        if (all->event.type == sfEvtMouseButtonReleased)
            file->option = 1;
    if (pos.x > 515 && pos.x < 693 && pos.y > 31 && pos.y < 223)
        if (all->event.type == sfEvtMouseButtonReleased)
            file->option = 2;
    if (pos.x > 737 && pos.x < 918 && pos.y > 31 && pos.y < 223)
        if (all->event.type == sfEvtMouseButtonReleased)
            file->option = 3;
    if (pos.x > 590 && pos.x < 802 && pos.y > 472 && pos.y < 554)
        if (all->event.type == sfEvtMouseButtonReleased &&
        file->inputLength > 0) {
            (is_valid_folder(file) == -1) ? i++ : 0;
            j++;
        }
    if (i == 0 && j != 0)
        get_image_from_file(file, all);
    return (0);
}

void simple_save(struct alll *all, files *file)
{
    if (file->path_open != NULL) {
        sfImage* image;
        image = sfTexture_copyToImage(all->image.img_texture);
        sfImage_saveToFile(image, file->path_open);
    } else if (file->path != NULL) {
        sfImage* image;
        image = sfTexture_copyToImage(all->image.img_texture);
        sfImage_saveToFile(image, file->path);
    } else
        print_save_menu(file, all);
}
