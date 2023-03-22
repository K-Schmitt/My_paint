/*
** EPITECH PROJECT, 2022
** lib csfml
** File description:
** lib csfml
*/

#pragma once

#include <SFML/Graphics.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <SFML/Audio.h>
#include <stdbool.h>

#define AW all->window
#define aw all->window
#define ms microseconds
#define ssbp struct stocksprite *bob
#define ssbp2 struct stocksprite bob
#define af all->cadre.infobar.fichier
#define ae all->cadre.infobar.edition
#define aa all->cadre.infobar.aide
#define ai all->cadre.infobar
#define sfST sfText_getLocalBounds
#define sfGB sfSprite_getGlobalBounds
#define sfKeyP sfKeyboard_isKeyPressed
#define w_s sfRenderWindow_getSize(aw)
#define mp all->mouse
#define left_click sfMouse_isButtonPressed(sfMouseLeft)
#define right_click sfMouse_isButtonPressed(sfMouseRight)
#define bs all->button.size_brush
#define ps all->button.size_pencil
#define az all->zoom
#define scal all->image.scale
#define sizze all->image.size
#define posi all->image.pos
#define rev all->image.scale_r
#define im all->bouton_im
#define cp create_perso
#define es all->button.size_eraser



struct stocksprite {
    sfTexture *img_texture;
    sfVector2u size;
    sfSprite *img_sprite;
    sfVector2f scale;
    sfVector2f scale_r;
    sfVector2f pos;
    sfIntRect z;
    sfClock *Clock;
    float frame;
    float r;
    int click;
    int speed;
};

struct circle {
    sfCircleShape *circle;
    sfVector2f pos;
    sfColor color;
    int radius;
    struct circle *next;
};

struct stocktext {
    char *name;
    sfFont *font;
    sfText *text;
    struct stocktext *next;
};

struct stockcercle {
    int radius;
    sfVector2f pos;
    sfCircleShape *name;
    struct stockcercle *next;
};

struct stockrect {
    int radius;
    sfVector2f pos;
    sfRectangleShape *name;
    struct stockrect *next;
};

struct stockfps {
    sfClock *Clockfp;
    float fp;
    float fps;
};

struct zone {
    sfFloatRect size;
    struct stockrect fond;
    float xsize;
};

struct bouton_text {
    struct stocktext Texte;
    struct stockrect Rect;
};

struct info_bar {
    struct bouton_text fichier;
    struct bouton_text edition;
    struct bouton_text aide;

    struct stockrect Rect_fichier;
    struct bouton_text nfile;
    struct bouton_text opfile;
    struct bouton_text save;
    struct bouton_text presave;

    struct stockrect Rect_edit;
    struct bouton_text pencil;
    struct bouton_text eraser;
    struct bouton_text picker;
    struct bouton_text fill;

    struct stockrect Rect_help;
    struct bouton_text about;
    struct bouton_text help;
    struct bouton_text racc;
};

struct cadree {
    struct zone haut;
    struct zone gauche;
    struct zone midle;
    struct zone droite;
    struct zone bas;
    struct info_bar infobar;
    float toolbar;
    int MGV;
    int MDV;
};

struct simule {
    struct stocknode *node;
    float zoom;
    struct stocknode *stocknode;
    int indexnode;
};

struct bin {
    int click;
    int infobarV;
    int infobarV2;
    int infobarC;
    int saveR;
    int saveR2;
    int saveC;
    int fichier;
    int edit;
    int help;
};

typedef struct button_t {
    int size_pencil;
    int size_brush;
    int size_eraser;
    float size_shape;
    int size_x;
    int size_y ;
    int rotate;
    int color;
    sfColor cur_color;
} button;

struct stockbouton {
    struct stocksprite stylo;
    struct stocksprite feutre;
    struct stocksprite gomme;
    struct stocksprite hand;
    struct stocksprite zoom;
    struct stocksprite carré;
    struct stocksprite picker;
    struct stocksprite color;
    struct stocksprite size_plus;
    struct stockrect rect_size;
    struct stocktext cligg_text;
    struct stocktext cligd_text;
    struct stocksprite size_moins;
    struct stockrect color_rect;
    struct stockrect clicg_rect;
    struct stockrect clicd_rect;
    char *clicg_s;
    char *clicd_s;
};

typedef struct files_t {
    sfRenderWindow *window;
    sfRenderWindow *window2;
    sfVector2u window_size;
    float rect_x;
    float rect_y;
    float rect_px;
    float rect_py;
    char *buffer;
    char *path;
    char *buffer_open;
    char *path_open;
    int option;
    int inputLength;
    char *input;
    int open_inputLength;
    char *open_input;
    int open_active;
    int save;
    sfTexture *jpg_texture;
    sfSprite *jpg_sprite;
    sfTexture *png_texture;
    sfSprite *png_sprite;
    sfTexture *bmp_texture;
    sfSprite *bmp_sprite;
    sfTexture *cancel_texture;
    sfSprite *cancel_sprite;
    sfTexture *save_texture;
    sfSprite *save_sprite;
    sfTexture *cancel_texture2;
    sfSprite *cancel_sprite2;
    sfTexture *save_texture2;
    sfSprite *save_sprite2;
    sfSprite *yes_sprite;
    sfTexture *yes_texture;
    sfSprite *no_sprite;
    sfTexture *no_texture;
    sfVector2u open_size;
    sfClock *timer;
    sfFont *font;
    sfText *text;
    sfText *open_text;
    sfText *help;
    sfText *ex;
    sfText *open;
    sfRectangleShape *rectangle;
    sfRectangleShape *rect_png;
    sfRectangleShape *rect_jpg;
    sfRectangleShape *rect_bmp;
} files;

struct alll {
    struct stockfps gfps;
    struct stocksprite fond;
    struct stocksprite cursor;
    struct stocksprite image;
    struct stocksprite back;
    struct stocksprite about;
    struct stocksprite help;
    struct stocksprite shortcut;
    struct stockbouton bouton_im;
    struct cadree cadre;
    struct simule simule;
    struct bin random;
    struct circle *node;
    files *file;
    button button;
    sfVector2f mouse;
    sfVector2f mouse_pos;
    sfVector2f brush_pos;
    sfRenderWindow *window;
    sfView *area;
    sfFloatRect size;
    sfEvent event;
    sfClock *Clock;
    sfClock *c_select;
    float zoom;
    int mouse_mod;
    int mouse_mod2;
    sfRenderTexture* r_text;
};

sfIntRect recti(int l, int t, int w, int h);
sfFloatRect rectf(int l, int t, int w, int h);
sfVector2f vecf(float x, float y);
sfVector2i veci(float x, float y);
sfVector2u vecu(unsigned int x, unsigned int y);
void detect_fps(struct alll *all);
void sizemin(struct sfRenderWindow *window);
void closew(struct alll *all);
void actuwindow(struct alll *all);
void actudraw(struct alll *all, struct stocksprite bob);
sfVector2f nscale(struct alll *all, float x, float y);
sfSprite *create_perso(struct stocksprite *bob, char *path, sfVector2f z,
sfVector2i t);
sfSprite *create_sprite(ssbp, char *path, sfVector2f scale);
void animate(struct stocksprite *bob, float x);
void set_mh(struct alll *all);
void set_mg(struct alll *all);
void set_mm(struct alll *all);
void set_md(struct alll *all);
void set_mb(struct alll *all);
int move_mg(struct alll *all);
int move_mm(struct alll *all);
int create_cadre(struct alll *all);
int draw_cadre(struct alll *all);
int create_node(struct alll *all);
int struct_save_open(files *file);
sfVector2f centre(struct stocksprite bob, struct alll *all, sfVector2i pos);
int init(struct alll *all);
void init_map(struct alll *all);
void init_all(struct alll *all, files *file);
void event_click_save_open(struct alll *all, files *file);
files *init_file(void);
int sizmap(char *map);
void makemap(char *pmap, struct alll *all);
void simulation(struct alll *all, files *file);
int init_open_image(struct alll *all, files *file);
int open_file(char *str, files *file, int option);
void draw_image(struct alll *all, files *file);
void get_image_from_file(files *file, struct alll *all);
void event_save(struct alll *all, files *file);
void print_save_menu(files *file, struct alll *all);
void print_open_menu(struct alll *all, files *file);
int init_save_image(files *file, struct alll *all, sfVector2f pos);
void init_save_menu(files *file);
void init_open_menu(files *file);
int init_open_image(struct alll *all, files *file);
void init_all(struct alll *all, files *file);
int actu_all(struct alll *all, files *file);
void event_click_save_open(struct alll *all, files *file);
void brush(struct alll *all);
int init_bouton(struct alll *all);
int create_text(struct stocktext *x, char *str, int charasize, sfVector2f pos);
void create_rect(struct stockrect *x, sfVector2f size, sfVector2f pos, int opt);
void gestion_bouton(struct alll *all);
void show_fichier(struct alll *all);
void show_edit(struct alll *all);
void show_help(struct alll *all);
void select_color(struct alll *all);
void eraser(struct alll *all);
int gestion_raccourci(struct alll *all, files *file);
void gestion_bouton_fichier(struct alll *all, files *file);
void gestion_bouton_edit(struct alll *all);
void create_bouton(struct alll *all, int x_pos, int y_pos, int mode);
void circle(struct alll *all);
void rectangle(struct alll *all);
void simple_save(struct alll *all, files *file);
sfVector2f nscale_reverse(struct alll *all, float x, float y);
void new_file(struct alll *all, files *file, int option);
void wanna_save(files *file, struct alll *all);
void actu_toolbar(struct alll *all);
void init_toolbar(struct alll *all);
void gestion_bouton_toolbar(struct alll *all);
void create_bouton_image(struct alll *all, struct stocksprite *tutu,
sfVector2i z, int mode);
void select_color2(struct alll *all);
void init_struct_all(struct alll *all);
void init_sprite(struct alll *all);
void pos_clictool(struct alll *all);
void create_bouton_addminus(struct alll *all, struct stocksprite *tutu,
sfVector2i z, int mode);
void bouton_addminus(struct alll *all, struct stocksprite *tutu, sfVector2i z,
int option);
void pencil(struct alll *all);
void gestion_mouse(struct alll *all, int opt);
void gestion_mouse2(struct alll *all, int opt);
void actu_addminus(struct alll *all);
void actu_nbr_size(struct alll *all);
void draw_shape(struct alll *all);
void add_node(struct circle **node, struct alll *all);
void show_help2(struct alll *all);
void save_bip(files* file, struct alll *all);
