/*
** EPITECH PROJECT, 2023
** my paint
** File description:
** gestion bouton
*/

#include "../lib/my/my.h"
#include "../lib/my/csfmLib/csfmlib.h"
#include <stdio.h>
#include <stdlib.h>

void gestion_bouton_fichier_next(struct alll *all, files *file)
{
    if (mp.x >= 2 && mp.x <= 202 && mp.y >= 129 && mp.y <= 159) {
        if (sfTrue == left_click && all->random.click == 0)
            all->random.click = 1;
        if (sfFalse == left_click && all->random.click == 1) {
            simple_save(all, file);
            all->random.click = 0;
            all->random.infobarC = 0;
        }
    }
    if (mp.x >= 2 && mp.x <= 202 && mp.y >= 33 && mp.y <= 63) {
        if (sfTrue == left_click && all->random.click == 0)
            all->random.click = 1;
        if (sfFalse == left_click && all->random.click == 1) {
            new_file(all, file, 1);
            all->random.click = 0;
            all->random.infobarC = 0;
        }
    }
}

void gestion_bouton_fichier(struct alll *all, files *file)
{
    if (mp.x >= 2 && mp.x <= 202 && mp.y >= 97 && mp.y <= 127) {
        if (sfTrue == left_click && all->random.click == 0)
            all->random.click = 1;
        if (sfFalse == left_click && all->random.click == 1) {
            print_save_menu(file, all);
            all->random.click = 0;
            all->random.infobarC = 0;
        }
    }
    if (mp.x >= 2 && mp.x <= 202 && mp.y >= 65 && mp.y <= 95) {
        if (sfTrue == left_click && all->random.click == 0)
            all->random.click = 1;
        if (sfFalse == left_click && all->random.click == 1) {
            print_open_menu(all, file);
            all->random.click = 0;
            all->random.infobarC = 0;
        }
    }
    gestion_bouton_fichier_next(all, file);
}

void gestion_bouton2(struct alll *all)
{
    sfRectangleShape_setFillColor(aa.Rect.name, sfTransparent);
    sfText_setColor(aa.Texte.text, sfBlack);
    if ((all->mouse.x >= sfST(ae.Texte.text).width + sfST(af.Texte.text).width
    + 37 && all->mouse.x <= sfST(ae.Texte.text).width +
    sfST(af.Texte.text).width+ sfST(aa.Texte.text).width + 52)
    && all->mouse.y >= 0 && all->mouse.y <= 25 && all->random.infobarV == 0) {
        sfRenderWindow_drawRectangleShape(aw, aa.Rect.name, NULL);
        all->random.fichier = 0;
        all->random.edit = 0;
        all->random.help = 1;
        if (sfTrue == sfMouse_isButtonPressed(sfMouseLeft))
            all->random.infobarC = 1;
    }
    if (all->random.infobarC == 1 && all->random.fichier == 1)
        show_fichier(all);
    if (all->random.infobarC == 1 && all->random.edit == 1)
        show_edit(all);
    if (all->random.infobarC == 1 && all->random.help == 1)
        show_help(all);
}

void gestion_bouton_next(struct alll *all)
{
    if ((all->mouse.x >= sfST(af.Texte.text).width + 17 && all->mouse.x <=
    sfST(ae.Texte.text).width + sfST(af.Texte.text).width + 37)
    && all->mouse.y >= 0 && all->mouse.y <= 25 && all->random.infobarV == 0) {
        sfRenderWindow_drawRectangleShape(aw, ae.Rect.name, NULL);
        all->random.fichier = 0;
        all->random.edit = 1;
        all->random.help = 0;
        if (sfTrue == sfMouse_isButtonPressed(sfMouseLeft))
            all->random.infobarC = 1;
    }
}

void gestion_bouton(struct alll *all)
{
    sfRectangleShape_setFillColor(af.Rect.name, sfTransparent);
    sfText_setColor(af.Texte.text, sfBlack);
    sfRectangleShape_setFillColor(ae.Rect.name, sfTransparent);
    sfText_setColor(ae.Texte.text, sfBlack);
    if ((all->mouse.x >= 0 && all->mouse.x <= sfST(af.Texte.text).width + 17)
    && all->mouse.y >= 0 && all->mouse.y <= 25 && all->random.infobarV == 0) {
        sfRenderWindow_drawRectangleShape(aw, af.Rect.name, NULL);
        all->random.fichier = 1;
        all->random.edit = 0;
        all->random.help = 0;
        if (sfTrue == sfMouse_isButtonPressed(sfMouseLeft))
            all->random.infobarC = 1;
    }
    gestion_bouton_next(all);
    gestion_bouton2(all);
}
