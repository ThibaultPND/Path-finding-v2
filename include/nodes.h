#if !defined(__NODES_H__)
#define __NODES_H__

#define GRID_SIZE 80
#define TILE_SIZE 10


#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

typedef enum{
    start,
    end,
    none,
    path,
    wall,
}tileState_t;

typedef struct node{
    // Position
    SDL_Point position;

    // Dst from end
    int f_cost;

    // Generator of this node.
    struct node *parent;

    // Etat du noeud
    tileState_t state;
}node_t;

typedef struct nodeList{
    node_t data;

    struct nodeList* next;
    struct nodeList* prev;
}nodeList_t;

void initNodeList(node_t*);
void append(node_t*);

void findWay(node_t tab[GRID_SIZE][GRID_SIZE], node_t start, node_t end);

#endif // __NODES_H__
