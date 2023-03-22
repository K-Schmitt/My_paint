/*
** EPITECH PROJECT, 2022
** my paint
** File description:
** draw form
*/

#include "../lib/my/my.h"
#include "../lib/my/csfmLib/csfmlib.h"
#include <stdio.h>
#include <stdlib.h>

void draw_shape(struct alll *all)
{
    struct circle* temp = all->node;
    while (temp != NULL) {
        sfCircleShape_setPosition(temp->circle, temp->pos);
        sfCircleShape_setRadius(temp->circle, temp->radius);
        sfCircleShape_setOutlineColor(temp->circle, temp->color);
        sfCircleShape_setFillColor(temp->circle, temp->color);
        sfRenderWindow_drawCircleShape(aw, temp->circle, NULL);
        temp = temp->next;
    }
}
