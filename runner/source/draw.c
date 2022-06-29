#include "draw.h"

void prepareCanvas(Win *app)
{
    SDL_RenderClear(app->renderer);
}

void presentCanvas(Win *app)
{
    SDL_RenderPresent(app->renderer);
}

SDL_Texture *loadTexture(Win *app, char *img_path)
{
    SDL_Texture *texture;
    
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading: %s", img_path);
    texture = IMG_LoadTexture(app->renderer, img_path);
    if (texture == NULL) {
        printf("Failed to load texture %s\n", IMG_GetError());
    }
    return texture;
}

int check_collision( SDL_Rect *A, SDL_Rect *B )
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;
 
    leftA = A->x;
    rightA = A->x + A->w;
    topA = A->y;
    bottomA = A->y + A->h;
 
    leftB = B->x;
    rightB = B->x + B->w;
    topB = B->y;
    bottomB = B->y + B->h;

    if( bottomA <= topB )
    {
        return 0;
    }
 
    if( topA >= bottomB )
    {
        return 0;
    }
 
    if( rightA <= leftB )
    {
        return 0;
    }
 
    if( leftA >= rightB )
    {
        return 0;
    }
    return 1;
}

int drawEntity(Win *app, Entity *entity, Entity *ennemy, Entity *obstacle){
    SDL_Rect dest= {entity->pos_x, entity->pos_y, entity->width, entity->height};
    SDL_Rect destination = {obstacle->pos_x, obstacle->pos_y, obstacle->width, obstacle->height};
    SDL_Rect desti = {ennemy->pos_x, ennemy->pos_y, ennemy->width, ennemy->height};
    SDL_RenderCopy(app->renderer, obstacle->texture, NULL, &destination);
    SDL_RenderCopy(app->renderer, ennemy->texture, NULL, &desti);
    SDL_RenderCopy(app->renderer, entity->texture, NULL, &dest);

    if (check_collision(&dest, &destination)){
        printf ("Game Over!\n");
        return -1;
    }
    if (check_collision(&dest, &desti)){
        printf ("Game Over!\n");
        return -1;
    }
    return 0;
}