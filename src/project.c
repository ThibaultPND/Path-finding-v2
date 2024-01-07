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

void renderTile(SDL_Point position, tileState_t state){
    position.x -= position.x%TILE_SIZE;
    position.y -= position.y%TILE_SIZE;

    switch (state)
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
    case none:
        SDL_SetRenderDrawColor(renderer, 255,255,255,255);
        break;
    }
    SDL_Rect square = {
        .h = TILE_SIZE,
        .w = TILE_SIZE,
        .x = position.x,
        .y = position.y
    };
    SDL_RenderFillRect(renderer, &square);
    printf("yolo\n");
}