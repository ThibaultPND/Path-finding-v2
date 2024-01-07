#ifndef __PROJECT_H__
#define __PROJECT_H__

// Inclusions
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

// Maccros dimension fenêtre
#define HAUTEUR_FENETRE 800
#define LARGEUR_FENETRE 800
#define GRID_SIZE 80
#define TILE_SIZE 10

typedef enum tileState{
    start,
    end,
    none,
    path,
}tileState_t;

extern SDL_Renderer *renderer;
extern SDL_Window *window;

void renderEmptyGrid(); // 80x80
void renderTile(SDL_Point position,tileState_t state);



#endif // __PROJECT_H__