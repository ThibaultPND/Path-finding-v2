#ifndef __PROJECT_H__
#define __PROJECT_H__

// Inclusions
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "nodes.h"

// Maccros dimension fenêtre
#define HAUTEUR_FENETRE 800
#define LARGEUR_FENETRE 800


extern SDL_Renderer *renderer;
extern SDL_Window *window;

void renderEmptyGrid(); // 80x80
node_t setTile(node_t tab[GRID_SIZE][GRID_SIZE], SDL_Point position,tileState_t state);
void renderGrid(node_t tab[GRID_SIZE][GRID_SIZE]);


#endif // __PROJECT_H__