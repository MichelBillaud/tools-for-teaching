#ifndef DEFS_H
#define DEFS_H

enum action_type {
    MOUSE_PRESSED,
    MOUSE_RELEASED,
    MOUSE_MOVED,
    MOUSE_DRAGGED,
    KEY_PRESSED,
    KEY_RELEASED,
    TEXT_INPUT,
    LAST_ACTION = TEXT_INPUT
};

enum button_type {
    LEFT_BUTTON,
    RIGHT_BUTTON,
    MIDDLE_BUTTON
};

enum key_type {
    ESCAPE_KEY,
    BACKSPACE_KEY,
    DELETE_KEY,
    RETURN_KEY,
    UP_ARROW,
    DOWN_ARROW,
    LEFT_ARROW,
    RIGHT_ARROW,
    OTHER_KEY
};

typedef void (*Action)(void);

void set_action(enum action_type type, Action action);
void quit(void);

void fill_rgba(unsigned int r, unsigned int g, unsigned int b, unsigned int a);
void stroke_rgba(unsigned int r, unsigned int g, unsigned int b, unsigned int a);
void background_rgb(unsigned int r, unsigned int g, unsigned int b);
void rectangle(int x, int y, int w, int h);

void text(const char string[], int x, int y);
void textSize(const char string[], int *p_x, int *p_y);
void line(int x1, int y1, int x2, int y2);

// accesseurs

int mouse_x(void);
int mouse_y(void);
const char *input(void);
enum key_type key();

// à définir par l'application
void setup(void);
void draw(void);

#endif
