#include "defs.h"
#include <stdio.h>

/**
 * This application is mostly a test for 
 * keyboard related functions
 * - input() function for text
 * - key() for keys
 */

#define SQUARE_SIDE 50

struct {
  int x, y;    // Top left corner of the square
} data;

void move_square()
{
  data.x = mouse_x() - SQUARE_SIDE / 2;
    data.y = mouse_y() - SQUARE_SIDE / 2;
}

void text_input()
{
    printf("Text was typed => %s\n", input());
}

void key_pressed()
{
    switch (key()) {
        case UP_ARROW: data.y -= 10;
            break;
        case DOWN_ARROW: data.y += 10;
            break;
        case LEFT_ARROW: data.x -= 10;
            break;
        case RIGHT_ARROW: data.y += 10;
            break;
        default:
            break;
    }
}

void setup()
{
    data.x = 100;
    data.y = 100;
    set_action(MOUSE_PRESSED, move_square);
    set_action(MOUSE_DRAGGED, move_square);
    set_action(TEXT_INPUT, text_input);
    set_action(KEY_PRESSED, key_pressed);
}

void draw()
{
    background_rgb(255, 128, 40); // orange

    fill_rgba(0, 0, 255, 255); //  blue
    rectangle(data.x, data.y, SQUARE_SIDE, SQUARE_SIDE);

    fill_rgba(255, 0, 0, 255) ;  // red      
    text("Déplacez le carré avec les flèches (key) ou un clic", 25, 200);

    fill_rgba(0, 255, 0 ,255);   // green    
    text("ça marche avec les caractères accentués !", 25, 250);    
}

