#include"Project.h"

SDL_Renderer *renderer = NULL;
SDL_Window *window = NULL;

void renderEmptyGrid(){
    SDL_SetRenderDrawColor(renderer, 255,255,255,255);
    SDL_RenderClear(renderer);
    
    SDL_SetRenderDrawColor(renderer, 0,0,0,255);
    for (int i = 0; i < GRID_SIZE; i++){
        SDL_RenderDrawLine(renderer, // Horizontal.
        0, 
        i * TILE_SIZE,
        GRID_SIZE * TILE_SIZE,
        i * TILE_SIZE
        );

        SDL_RenderDrawLine(renderer, // Vertical.
        i * TILE_SIZE,
        0,
        i * TILE_SIZE,
        GRID_SIZE * TILE_SIZE
        );
    }
}

SDL_Point PositionInTheGrid(){
    int mouse_x;
    int mouse_y;
    SDL_GetMouseState(&mouse_x, &mouse_y);

    return (SDL_Point){mouse_x/GRID_SIZE, mouse_y/GRID_SIZE};
}


int resetAllTileAs(tileState_t tab[GRID_SIZE][GRID_SIZE], tileState_t state){
    int count = 0;

    for (int i = 0; i < GRID_SIZE; i++)
        for (int j = 0; j < GRID_SIZE; j++)
            if (tab[i][j] == state)
            {
                tab[i][j] = none;
                count++;
            }
    return count;
}

void setTileAs(tileState_t tab[GRID_SIZE][GRID_SIZE], SDL_Point position, tileState_t state){
    position.x = position.x/10;
    position.y = position.y/10;

    resetAllTileAs(tab, state);

    tab[position.y][position.x] = state;
}

void renderGrid(tileState_t tab[GRID_SIZE][GRID_SIZE]) {
    renderEmptyGrid();

    for (int i = 0; i < GRID_SIZE; i++)
        for (int j = 0; j < GRID_SIZE; j++){
            if (tab[i][j] == none){
                continue;
            }
            
            switch (tab[i][j])
            {
            case start:
                SDL_SetRenderDrawColor(renderer, 0,255,0,255);
                break;
            case end:
                SDL_SetRenderDrawColor(renderer, 255,0,0,255);
                break;
            case path:
                SDL_SetRenderDrawColor(renderer, 255,128,0,255);
                break;
            }
            SDL_Rect square = {
                .h = TILE_SIZE,
                .w = TILE_SIZE,
                .x = j*10,
                .y = i*10
            };
            SDL_RenderFillRect(renderer, &square);
        } 
}