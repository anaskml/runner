#include "input.h"
#include <stdio.h>
#include "window.h"

#define VITESSE (400)

float x_vel = 0;
float y_vel = 0;

int up = 0;
int down = 0;
int right = 0;
int left = 0;

int input_handler(Entity *entity, Entity *ennemy, Entity *obstacle) 
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
    {
    case SDL_QUIT :
        return -1;
    case SDL_KEYDOWN :
        switch (event.key.keysym.sym)
        {
        case SDLK_UP:
            up = 1;            
            break;
        case SDLK_DOWN:
            down = 1;
            break;
        case SDLK_RIGHT:
            right = 1;
            break;
        case SDLK_LEFT:
            left = 1;
            break;       
        }
        break;
    case SDL_KEYUP :
    switch (event.key.keysym.sym)
        {
        case SDLK_UP:
            up = 0;            
            break;
        case SDLK_DOWN:
            down = 0;
            break;
        case SDLK_RIGHT:
            right = 0;
            break;
        case SDLK_LEFT:
            left = 0;
            break;       
        }
        break;    
    }
    }
    ennemy->pos_x -= 4;
    obstacle->pos_x -= 7;

    x_vel = y_vel = 0;
    if (up && !down) y_vel = -VITESSE;
    if (down && !up) y_vel = VITESSE;
    if (left && !right) x_vel = -VITESSE;
    if (right && !left) x_vel = VITESSE;

    entity->pos_x += x_vel / 60;
    entity->pos_y += y_vel / 60;

    if (entity->pos_x <= 0) entity->pos_x = 0;
    if (entity->pos_y <= 0) entity->pos_y = 0;
    if (entity->pos_x >= WINDOW_WIDTH - entity->width) entity->pos_x = WINDOW_WIDTH - entity->width;
    if (entity->pos_y >= WINDOW_HEIGHT - entity->height) entity->pos_y = WINDOW_HEIGHT - entity->height;

    return 0;
}