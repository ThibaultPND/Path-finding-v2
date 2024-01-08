/***************************************************************
**  Auteur : Thibault Chassagne
**  MAJ : 07/01/2024
*  
**  Nom : Path finding
*  
*?  Description : Ce logiciel à pour but de crée un simulateur de path finding
*
gcc -o prog -Iinclude -Iinclude/SDL2 src/*.cpp -Llib -lSDL2main -lSDL2 -static -DSDL_MAIN_HANDLED && bin\monProgramme.exe
***************************************************************/
#include <Project.h>
#include <SDL2/SDL.h>
#include "TxUtils.h"


int main(int argc, char* argv[]) {
    printf("Debut du programme...\n\n");
    
    // Initialisation
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        // Erreur init SDL.
        fprintf(stderr, "Erreur lors de l'initalisation de SDL\n");
    }

    window = SDL_CreateWindow("MonProgramme", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, LARGEUR_FENETRE, HAUTEUR_FENETRE, 0);
    if (window == NULL) {
        SDL_Quit();
        // Erreur lors de la création de la fenêtre.
    }

    renderer = SDL_CreateRenderer(window , -1, SDL_RENDERER_SOFTWARE);
    if (renderer == NULL) {
        SDL_DestroyWindow(window);
        SDL_Quit();
        // Erreur création du rendu
    }
    srand(SDL_GetTicks());

    renderEmptyGrid();
    SDL_RenderPresent(renderer);
    
    tileState_t tab[GRID_SIZE][GRID_SIZE];
    for (int i = 0; i < GRID_SIZE; i++){
        for (int j = 0; j < GRID_SIZE; j++){
            tab[i][j] = none;
        }
    }
    

    // Programme
    SDL_bool programLaunched = SDL_TRUE;
    while (programLaunched){
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                programLaunched = SDL_FALSE;
                break;
            case  SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT) {
                    setTileAs(tab, (SDL_Point){event.button.x,event.button.y}, start);
                    renderGrid(tab);
                    
                } else if (event.button.button == SDL_BUTTON_RIGHT) {
                    setTileAs(tab, (SDL_Point){event.button.x,event.button.y}, end);
                    renderGrid(tab);
                    
                }else if (event.button.button == SDL_BUTTON_MIDDLE) {
                    setTileAs(tab, (SDL_Point){event.button.x,event.button.y}, wall);
                    renderGrid(tab);
                }
            default: break;
            }
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }
    

    // Libération des ressources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    printf("...fin du programme\n");
    

    return EXIT_SUCCESS;
}