#ifndef WINDOW
#define WINDOW

#include <SDL2/SDL.h>

#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 600
#define WINDOW_NAME "RUNNER"

typedef struct {
    SDL_Renderer    *renderer;
    SDL_Window      *window;

} Win;

#endif /* !WINDOW */