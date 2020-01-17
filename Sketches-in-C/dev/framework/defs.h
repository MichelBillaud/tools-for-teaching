#ifndef DEFS_H
#define DEFS_H

/**
 * Enum for action types
 */ 
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

/**
 * Enum for button numbers.
 */
enum button_type {
    LEFT_BUTTON,
    RIGHT_BUTTON,
    MIDDLE_BUTTON
};

/**
 * types for key events
 */
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

/**
 * Actions are fonction pointers
 */
typedef void (*Action)(void);

/**
 * Set the action for a given type of event.
 */
void set_action(enum action_type type, Action action);

/**
 * Leave the program
 */
void quit(void);

/** 
 * set color for "fill" operations 
 * @param r   red, 0..255
 * @param g   green, 0..255
 * @param b   blue, 0..255
 * @param a   alpha, 0..255, 0 is invisible, 255 opaque
 */

void fill_rgba(unsigned int r, unsigned int g, unsigned int b, unsigned int a);

/** 
 * set color for "stroke" operations 
 * @param r   red, 0..255
 * @param g   green, 0..255
 * @param b   blue, 0..255
 * @param a   alpha, 0..255,  0 is invisible, 255 opaque
 */

void stroke_rgba(unsigned int r, unsigned int g, unsigned int b, unsigned int a);


/** 
 * draw background with color
 * @param r   red, 0..255
 * @param g   green, 0..255
 * @param b   blue, 0..255
 */
void background_rgb(unsigned int r, unsigned int g, unsigned int b);

/**
 * draw rectangle with letf-corner position and dimensions, using
 * fillColor and strokeColor for border.
 * @param x  
 * @param y
 * @param w
 * @param h
 */
void rectangle(int x, int y, int w, int h);

/**
 * draw text at position (top left corner given).
 *
 * @param x  
 * @param y
 * @param text  a multibyte encoded string.
 */

void text(const char string[], int x, int y);

/**
 * get dimensions for a text with current font.
 * @param string  multi-byte string
 * @param p_w   address of width
 * @param p_h   address of height
 */

void textSize(const char string[], int *p_w, int *p_h);

/**
 * Draw line between two points
 * @param x1  
 * @param y1
 * @param x2  
 * @param y2
 */

void line(int x1, int y1, int x2, int y2);

/**
 * get mouse x position on screen
 * @return x
 */
int mouse_x(void);

/**
 * get mouse y position on screen
 * @return y
 */
int mouse_y(void);

/**
 * type of last key typed.
 * @return type
 */
enum key_type key();

/**
 * last character entered, if key_typed() returned OTHER_KEY.
 * @return the address of a static multi-byte string containing the
 * character.
 */
const char *input(void);

/**
 * The setup() function must be defined by the user application
 */
void setup(void);

/**
 * The draw() function must be defined by the user application
 */
void draw(void);

#endif
