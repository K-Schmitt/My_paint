/*
** EPITECH PROJECT, 2022
** my paint
** File description:
** gestion bouton
*/

#include "../lib/my/my.h"
#include "../lib/my/csfmLib/csfmlib.h"
#include <stdio.h>
#include <stdlib.h>

static void show_fichier_next(struct alll *all)
{
    if (mp.x >= 2 && mp.x <= 202 && mp.y >= 33 && mp.y <= 63)
        sfRenderWindow_drawRectangleShape(aw,
        ai.nfile.Rect.name, NULL);
    if (mp.x >= 2 && mp.x <= 202 && mp.y >= 63 && mp.y <= 93)
        sfRenderWindow_drawRectangleShape(aw,
        ai.opfile.Rect.name, NULL);
    if (mp.x >= 2 && mp.x <= 202 && mp.y >= 93 && mp.y <= 123)
        sfRenderWindow_drawRectangleShape(aw,
        ai.presave.Rect.name, NULL);
    if (mp.x >= 2 && mp.x <= 202 && mp.y >= 123 && mp.y <= 153)
        sfRenderWindow_drawRectangleShape(aw,
        ai.save.Rect.name, NULL);
}

void show_fichier(struct alll *all)
{
    sfRectangleShape_setFillColor(af.Rect.name, sfBlack);
    sfText_setColor(af.Texte.text, sfWhite);
    sfRenderWindow_drawRectangleShape(aw, af.Rect.name, NULL);
    sfRenderWindow_drawText(aw, af.Texte.text, NULL);
    sfRenderWindow_drawRectangleShape(aw, ai.Rect_fichier.name,
    NULL);
    sfRenderWindow_drawText(aw, ai.nfile.Texte.text, NULL);
    sfRenderWindow_drawText(aw, ai.opfile.Texte.text, NULL);
    sfRenderWindow_drawText(aw, ai.presave.Texte.text, NULL);
    sfRenderWindow_drawText(aw, ai.save.Texte.text, NULL);
    show_fichier_next(all);
}

static void show_edit_next(struct alll *all)
{
    if ((mp.x >= sfST(af.Texte.text).width + 20 && mp.x <=
    sfST(af.Texte.text).width + 220) && mp.y >= 33 && mp.y <= 63)
        sfRenderWindow_drawRectangleShape(aw,
        ai.pencil.Rect.name, NULL);
    if ((mp.x >= sfST(af.Texte.text).width + 20 && mp.x <=
    sfST(af.Texte.text).width + 220) && mp.y >= 63 && mp.y <= 93)
        sfRenderWindow_drawRectangleShape(aw,
        ai.eraser.Rect.name, NULL);
    if ((mp.x >= sfST(af.Texte.text).width + 20 && mp.x <=
    sfST(af.Texte.text).width + 220) && mp.y >= 93 && mp.y <= 123)
        sfRenderWindow_drawRectangleShape(aw,
        ai.picker.Rect.name, NULL);
    if ((mp.x >= sfST(af.Texte.text).width + 20 && mp.x <=
    sfST(af.Texte.text).width + 220) && mp.y >= 123 && mp.y <= 153)
        sfRenderWindow_drawRectangleShape(aw,
        ai.fill.Rect.name, NULL);
}

void show_edit(struct alll *all)
{
    sfRectangleShape_setFillColor(ae.Rect.name, sfBlack);
    sfText_setColor(ae.Texte.text, sfWhite);
    sfRenderWindow_drawRectangleShape(aw, ae.Rect.name, NULL);
    sfRenderWindow_drawText(aw, ae.Texte.text, NULL);
    sfRenderWindow_drawRectangleShape(aw, ai.Rect_edit.name,
    NULL);
    sfRenderWindow_drawText(aw, ai.pencil.Texte.text, NULL);
    sfRenderWindow_drawText(aw, ai.eraser.Texte.text, NULL);
    sfRenderWindow_drawText(aw, ai.picker.Texte.text, NULL);
    sfRenderWindow_drawText(aw, ai.fill.Texte.text, NULL);
    show_edit_next(all);
}

void show_help(struct alll *all)
{
    sfRectangleShape_setFillColor(aa.Rect.name, sfBlack);
    sfText_setColor(aa.Texte.text, sfWhite);
    sfRenderWindow_drawRectangleShape(aw, aa.Rect.name, NULL);
    sfRenderWindow_drawText(aw, aa.Texte.text, NULL);
    sfRenderWindow_drawRectangleShape(aw, ai.Rect_help.name, NULL);
    sfRenderWindow_drawText(aw, ai.about.Texte.text, NULL);
    sfRenderWindow_drawText(aw, ai.help.Texte.text, NULL);
    sfRenderWindow_drawText(aw, ai.racc.Texte.text, NULL);
    show_help2(all);
}
