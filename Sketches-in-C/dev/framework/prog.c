/**
 * Adaptation de Processing à la programmation en C
 * M Billaud, 13 aout 2019
 *
 * avec l'aide de
 * https://zestedesavoir.com/tutoriels/1014/utiliser-la-sdl-en-langage-c/
 */


#include "SDL.h"
#include "SDL_ttf.h"

#include <stdbool.h>
#include <string.h>

#include "defs.h"

// TODO : variable for default font path
#define DEFAULT_FONT_PATH "/usr/share/fonts/truetype/msttcorefonts/arial.ttf"
#define DEFAULT_FONT_SIZE 24

struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    int width, height;
    Uint32 refresh_delay_ms;
    bool loop_running;
    SDL_Color fill_color, stroke_color;
    TTF_Font *font;

    SDL_Event event;
    Action actions[LAST_ACTION + 1];

    int mouse_x, mouse_y;
    int mouse_px, mouse_py;
    bool mouse_pressed;
    enum button_type button;

    enum key_type key;
    char text[32];                     // TODO use an extensible array
    bool key_pressed;
} context;

void set_action(enum action_type type, Action action)
{
    context.actions[type] = action;
}

int mouse_x(void)
{
    return context.mouse_x;
}

int mouse_y(void)
{
    return context.mouse_y;
}

const char* input(void)
{
    return context.text;
}

enum key_type key()
{
    return context.key;
}

static void process_event();

void setup();
void draw();

void quit()
{
    context.loop_running = false;
}

static void set_defaults(void)
{
    context.width = 640;
    context.height = 480;
    context.refresh_delay_ms = 100;

    for (int a = 0; a <= LAST_ACTION; a++) {
        context.actions[a] = NULL;
    }
    context.text[0] = '\0';
}

void text(const char string[], int x, int y)
{
    SDL_Surface * surface = TTF_RenderUTF8_Solid(context.font,
            string,
            context.fill_color);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(context.renderer,
            surface);
    int w, h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    SDL_Rect rect = {x, y, w, h};
    SDL_RenderCopy(context.renderer, texture, NULL, & rect);
    SDL_DestroyTexture(texture);
}

void textSize(const char string[], int *p_w, int *p_h) {
    TTF_SizeUTF8(context.font, string, p_w, p_h);
}

int main(int argc, char *argv[])
{
    set_defaults();
    setup();

    if (0 != TTF_Init()) {
        fprintf(stderr, "Erreur TTF_Init : %s", TTF_GetError());
        goto ttf_failed;
    }

    context.font = TTF_OpenFont(DEFAULT_FONT_PATH, DEFAULT_FONT_SIZE);
    if (context.font == NULL) {
        fprintf(stderr, "Erreur TTF_OpenFont : %s", TTF_GetError());
        goto init_failed;
    }

    if (0 != SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS)) {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        goto init_failed;
    }

    context.window = SDL_CreateWindow("SDL2",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            context.width,
            context.height,
            SDL_WINDOW_SHOWN);

    if (NULL == context.window) {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        goto window_creation_failed;
    }

    context.renderer = SDL_CreateRenderer(context.window, -1, SDL_RENDERER_ACCELERATED);
    if (NULL == context.renderer) {
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
        goto renderer_creation_failed;
    }
    SDL_StartTextInput();
    context.loop_running = true;
    while (context.loop_running) {
        while (SDL_PollEvent(& context.event)) {
            process_event();
        }
        draw();
        SDL_RenderPresent(context.renderer);
        SDL_Delay(context.refresh_delay_ms);
    }
    SDL_StopTextInput();

    // --------------------------

    SDL_DestroyRenderer(context.renderer);
renderer_creation_failed:
    SDL_DestroyWindow(context.window);
window_creation_failed:
    SDL_Quit();
init_failed:
    TTF_CloseFont(context.font);
    TTF_Quit();
ttf_failed:
    return EXIT_SUCCESS;
}

void fill_rgba(unsigned int r, unsigned int g, unsigned int b, unsigned int a)
{
    SDL_Color color = {r, g, b, a};
    context.fill_color = color;
    // SDL_SetRenderDrawColor(context.renderer, r, g, b, a);
}

void stroke_rgba(unsigned int r, unsigned int g, unsigned int b, unsigned int a)
{
    SDL_Color color = {r, g, b, a};
    context.stroke_color = color;
    // SDL_SetRenderDrawColor(context.renderer, r, g, b, a);
}

void background_rgb(unsigned int r, unsigned int g, unsigned int b)
{
    SDL_SetRenderDrawColor(context.renderer, r, g, b, 255);
    SDL_RenderClear(context.renderer);
}

void rectangle(int x, int y, int w, int h)
{
    SDL_SetRenderDrawColor(context.renderer,
            context.fill_color.r,
            context.fill_color.g,
            context.fill_color.b,
            context.fill_color.a);
    SDL_Rect rect = {x, y, w, h};
    SDL_RenderFillRect(context.renderer, & rect);
}


void line(int x1, int y1, int x2, int y2)
{
    SDL_SetRenderDrawColor(context.renderer,
            context.stroke_color.r,
            context.stroke_color.g,
            context.stroke_color.b,
            context.stroke_color.a);
    SDL_RenderDrawLine(context.renderer, x1, y1, x2, y2);
}

static void process_window_event()
{
    if (context.event.type == SDL_WINDOWEVENT_CLOSE) {
        context.loop_running = false;
    }
}

static void process_keyboard_event(bool pressed, Action action)
{
    context.key_pressed = pressed;
    switch (context.event.key.keysym.sym) {
        case SDLK_UP: context.key = UP_ARROW;
            break;
        case SDLK_DOWN: context.key = DOWN_ARROW;
            break;
        case SDLK_LEFT: context.key = LEFT_ARROW;
            break;
        case SDLK_RIGHT: context.key = RIGHT_ARROW;
            break;

        case SDLK_ESCAPE: context.key = ESCAPE_KEY;
            break;
        case SDLK_BACKSPACE: context.key = BACKSPACE_KEY;
            break;
        case SDLK_DELETE: context.key = DELETE_KEY;
            break;
        case SDLK_RETURN: context.key = RETURN_KEY;
            break;

        default:
            context.key = OTHER_KEY;
    }

    if (action != NULL) {
        action();
    }
}

static void process_mouse_button_event(bool pressed, Action action)
{
    context.mouse_x = context.event.button.x;
    context.mouse_y = context.event.button.y;
    context.mouse_pressed = pressed;
    switch (context.event.button.button) {
        case SDL_BUTTON_LEFT:
            context.button = LEFT_BUTTON;
            break;
        case SDL_BUTTON_RIGHT:
            context.button = RIGHT_BUTTON;
            break;
        case SDL_BUTTON_MIDDLE:
            context.button = MIDDLE_BUTTON;
            break;
    }

    if (action != NULL) {
        action();
    }
}

static void process_mouse_motion_event(Action action)
{
    context.mouse_px = context.mouse_x;
    context.mouse_py = context.mouse_y;

    context.mouse_x = context.event.motion.x;
    context.mouse_y = context.event.motion.y;

    if (action != NULL) {
        action();
    }
}

static void process_event()
{
    // printf("Processing type %d\n", context.event.type);
    switch (context.event.type) {
        case SDL_QUIT:
            context.loop_running = false;
            break;
        case SDL_WINDOWEVENT:
            process_window_event();
            break;
        case SDL_MOUSEBUTTONDOWN:
            process_mouse_button_event(true, context.actions[MOUSE_PRESSED]);
            break;
        case SDL_MOUSEBUTTONUP:
            process_mouse_button_event(false, context.actions[MOUSE_RELEASED]);
            break;
        case SDL_MOUSEMOTION:
            process_mouse_motion_event(context.actions[context.mouse_pressed ?
                    MOUSE_DRAGGED : MOUSE_MOVED]);
            break;
        case SDL_TEXTINPUT:
            strcpy(context.text, context.event.text.text);
            if (context.actions[TEXT_INPUT] != NULL) {
                context.actions[TEXT_INPUT]();
            }
            break;
        case SDL_KEYDOWN:
            process_keyboard_event(true, context.actions[KEY_PRESSED]);
            break;
        case SDL_KEYUP:
            process_keyboard_event(false, context.actions[KEY_RELEASED]);
            break;
        default:
            break;
    }
}
