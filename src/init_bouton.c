/*
** EPITECH PROJECT, 2022
** gestion sprite
** File description:
** gestion sprite
*/

#include "../lib/my/csfmLib/csfmlib.h"
#include "../lib/my/my.h"

static void init_bouton_fichier(struct alll *all)
{
    create_rect(&ai.Rect_fichier,
    vecf(200, 126), vecf(3, 32), 1);
    create_text(&ai.nfile.Texte, "New File..", 20, vecf(15, 35));
    create_rect(&ai.nfile.Rect, vecf(200, 30), vecf(2, 33), 3);
    create_text(&ai.opfile.Texte, "Open File..", 20, vecf(15, 67));
    create_rect(&ai.opfile.Rect, vecf(200, 30), vecf(2, 65), 3);
    create_text(&ai.presave.Texte, "Save as..", 20, vecf(15, 99));
    create_rect(&ai.presave.Rect, vecf(200, 30), vecf(2, 97), 3);
    create_text(&ai.save.Texte, "Save", 20, vecf(15, 131));
    create_rect(&ai.save.Rect, vecf(200, 30), vecf(2, 129), 3);
}

static void init_bouton_edit(struct alll *all)
{
    create_rect(&ai.Rect_edit, vecf(200, 128),
    vecf(sfST(af.Texte.text).width + 20, 32), 1);
    create_text(&ai.pencil.Texte, "Pencil", 20,
    vecf(sfST(af.Texte.text).width + 32, 35));
    create_rect(&ai.pencil.Rect, vecf(200, 30),
    vecf(sfST(af.Texte.text).width + 20, 33), 3);
    create_text(&ai.eraser.Texte, "Eraser", 20,
    vecf(sfST(af.Texte.text).width + 32, 67));
    create_rect(&ai.eraser.Rect, vecf(200, 30),
    vecf(sfST(af.Texte.text).width + 20, 65), 3);
    create_text(&ai.picker.Texte, "Picker", 20,
    vecf(sfST(af.Texte.text).width + 32, 99));
    create_rect(&ai.picker.Rect, vecf(200, 30),
    vecf(sfST(af.Texte.text).width + 20, 97), 3);
    create_text(&ai.fill.Texte, "Brush", 20,
    vecf(sfST(af.Texte.text).width + 32, 131));
    create_rect(&ai.fill.Rect, vecf(200, 30),
    vecf(sfST(af.Texte.text).width + 20, 129), 3);
}

static void init_bouton_help(struct alll *all)
{
    sfVector2f pos = sfRectangleShape_getPosition(ai.aide.Rect.name);
    create_rect(&ai.Rect_help, vecf(200, 94), vecf(pos.x, 32), 1);
    create_text(&ai.about.Texte, "About", 20, vecf(pos.x + 12, 35));
    create_rect(&ai.about.Rect, vecf(200, 30), vecf(pos.x, 33), 3);
    create_text(&ai.help.Texte, "Help", 20, vecf(pos.x + 12, 67));
    create_rect(&ai.help.Rect, vecf(200, 30), vecf(pos.x, 65), 3);
    create_text(&ai.racc.Texte, "Shortcuts", 20, vecf(pos.x + 12, 99));
    create_rect(&ai.racc.Rect, vecf(200, 30), vecf(pos.x, 97), 3);
}

int init_bouton(struct alll *all)
{
    create_text(&af.Texte, "File", 20, vecf(8, 0));
    create_rect(&af.Rect,vecf(sfST(af.Texte.text).width + 15, 25),
    vecf(2, 2), 0);
    create_text(&ae.Texte, "Edit", 20,
    vecf(sfST(af.Texte.text).width + 25, 0));
    create_rect(&ae.Rect, vecf(sfST(ae.Texte.text).width + 15, 25),
    vecf(sfST(af.Texte.text).width + 20, 2), 0);
    create_text(&aa.Texte, "Help", 20, vecf(sfST(af.Texte.text).width
    + sfST(ae.Texte.text).width + 43, 0));
    create_rect(&aa.Rect, vecf(sfST(aa.Texte.text).width + 15, 25),
    vecf(sfST(af.Texte.text).width + sfST(ae.Texte.text).width + 38, 2), 0);
    init_bouton_fichier(all);
    init_bouton_edit(all);
    init_bouton_help(all);
    return (0);
}
