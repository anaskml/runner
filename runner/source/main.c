#include <stdio.h>
#include "input.h"
#include "init.h"
#include "draw.h"
#include "window.h"

int main()
{
    Win *app = malloc(sizeof(Win));
    Entity *player = malloc(sizeof(Entity));
    Entity *ennemy = malloc(sizeof(Entity));
    Entity *obstacle = malloc(sizeof(Entity));
    if (initSDL(app) < 0) 
    {
        return -1;
    }

    player->pos_x = 100;
    player->pos_y = 250;
    player->width = 200;
    player->height = 100;
    player->texture = loadTexture(app, "ressource/player.png");

    ennemy->pos_x = 1200;
    ennemy->pos_y = 200;
    ennemy->width = 200;
    ennemy->height = 100;
    ennemy->texture = loadTexture(app, "ressource/ennemy.png");

    obstacle->pos_x = 1100;
    obstacle->pos_y = 400;
    obstacle->width = 200;
    obstacle->height = 200;
    obstacle->texture = loadTexture(app, "ressource/obstacle.png");

    SDL_SetRenderDrawColor(app->renderer, 0, 0, 0, 0);
    while (input_handler(player, obstacle, ennemy) == 0)
    {
        prepareCanvas(app);
        if (drawEntity(app, player, obstacle, ennemy) == -1){
            return 0;
        }
        presentCanvas(app);
        SDL_Delay(16);
    }
    
    return 0;
}