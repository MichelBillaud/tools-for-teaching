
#include <stdio.h>
#include <string.h>

#include "defs.h"

// -----------------------------------------------
// application

struct {
    char line[20];
} data;


void text_input()
{
    printf("entrée de texte => %s\n", input());
    strcat(data.line, input());
}

void remove_last_utf8_char(char buffer[]) {   
    char *last = buffer;
    // first byte of an utf8 char representation has leftmost bit set
    for(char *p = buffer; *p != '\0'; p++) {
	if ((*p & 0x80) == 0) last = p;
    }
    *last = '\0';
}

void key_pressed()
{
    switch (key()) {
    case BACKSPACE_KEY:
	remove_last_utf8_char(data.line);
	break;
    case RETURN_KEY:
	data.line[0] = '\0';
	break;
    default:
	break;
    }
}

void setup()
{
    strcpy(data.line, "abc");
    set_action(TEXT_INPUT, text_input);
    set_action(KEY_PRESSED, key_pressed);
}

void draw()
{
    background_rgb(255, 127, 40); // fond orange

    fill_rgba(255, 255, 255, 255); // rectangle blanc
    
    rectangle(0, 150, 400, 200);
    fill_rgba(0, 0, 0, 0);
    text(data.line, 100, 200);

    int w, h;
    textSize(data.line, &w, &h);
    stroke_rgba(0,0, 255,0);
    line(100+w, 150, 100+w, 350);
}

