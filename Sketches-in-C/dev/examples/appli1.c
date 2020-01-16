#include "defs.h"
#include <stdio.h>

// -----------------------------------------------
// application

struct {
    int x, y;
} data;

void mouse_pressed()
{
    data.x = mouse_x();
    data.y = mouse_y();
}

void mouse_dragged()
{
    data.x = mouse_x();
    data.y = mouse_y();
}

void text_input()
{
    printf("entrée de texte => %s\n", input());
}

void key_pressed()
{
    // printf("kp\n");
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
    // printf("-> setup\n");
    data.x = 100;
    data.y = 100;
    set_action(MOUSE_PRESSED, mouse_pressed);
    set_action(MOUSE_DRAGGED, mouse_dragged);
    set_action(TEXT_INPUT, text_input);
    set_action(KEY_PRESSED, key_pressed);
}

void draw()
{
    background_rgb(255, 127, 40); // orange
    fill_rgba(96, 96, 255, 255); // bleu
    rectangle(data.x, data.y, 50, 50);
    fill_rgba(256, 0, 0, 128);
    text("ça marche même avec des caractères accentués", 0, 200);
}

