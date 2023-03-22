/*
** EPITECH PROJECT, 2022
** my paint
** File description:
** gestion raccourci
*/

#include "../lib/my/my.h"
#include "../lib/my/csfmLib/csfmlib.h"
#include <stdio.h>
#include <stdlib.h>

int create_raccourci(struct alll *all, files *file)
{
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyLControl) &&
    sfTrue == sfKeyboard_isKeyPressed(sfKeyO))
        print_open_menu(all, file);
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyLControl) &&
    sfTrue == sfKeyboard_isKeyPressed(sfKeyS))
        simple_save(all, file);
    return (0);
}

int raccourci_hide_infobar(struct alll *all)
{
    int i = 0;
    if ((sfTrue == sfKeyP(sfKeyRControl) || sfTrue == sfKeyP(sfKeyLControl))
    && sfTrue == sfKeyP(sfKeyF11) && all->random.infobarV2 == 0) {
        all->random.infobarV2 = 1;
        if (all->random.infobarV == 1) {
            all->random.infobarV = 0;
            i++;
        }
        if (all->random.infobarV == 0 && i == 0)
            all->random.infobarV = 1;
    }
    if ((sfFalse == sfKeyP(sfKeyRControl) || sfFalse == sfKeyP(sfKeyLControl))
    && sfFalse == sfKeyP(sfKeyF11) && all->random.infobarV2 == 1)
        all->random.infobarV2 = 0;
    return (0);
}

int gestion_raccourci(struct alll *all, files *file)
{
    raccourci_hide_infobar(all);
    create_raccourci(all, file);
    if (mp.y >= 26 && all->random.fichier == 1)
        gestion_bouton_fichier(all, file);
    if (mp.y >= 26 && all->random.edit == 1)
        gestion_bouton_edit(all);
    if (mp.y >= 26 && all->random.click != 1 && left_click)
        all->random.infobarC = 0;
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyLControl) &&
    (sfTrue == sfKeyboard_isKeyPressed(sfKeyAdd) ||
    sfTrue == sfKeyboard_isKeyPressed(sfKeyEqual)))
        all->zoom += 0.001;
    if (sfTrue == sfKeyboard_isKeyPressed(sfKeyLControl) &&
    (sfTrue == sfKeyboard_isKeyPressed(sfKeyDash) ||
    sfTrue == sfKeyboard_isKeyPressed(sfKeySubtract)))
        all->zoom -= 0.001;
    if (sfTrue == sfKeyP(sfKeyQ))
        all->cadre.toolbar = (all->mouse.x / sfRenderWindow_getSize(aw).x);
    return (0);
}
