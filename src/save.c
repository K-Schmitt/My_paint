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

void save_bip(files* file, struct alll *all)
{
    if (all->event.type == sfEvtMouseButtonReleased) {
        sfRenderWindow_close(file->window2);
        file->save = 0;
    }
}
