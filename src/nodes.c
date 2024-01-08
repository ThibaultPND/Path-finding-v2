#include "nodes.h"

void afficher10x10Tab(node_t tab[GRID_SIZE][GRID_SIZE]);
node_t *LowestFcost(nodeList_t *nodes);
void add_node(nodeList_t **nodes, node_t data);
void delete_node(nodeList_t **nodes, node_t data);
void freeNodeList(nodeList_t *nodes);
SDL_bool equalNodes(node_t first, node_t second);
node_t *inList(nodeList_t *nodes, node_t *data);
int distanceFromStart(nodeList_t *node, node_t *start_node);
int distanceBetweenTwoPoint(int x1, int y1, int x2, int y2);
void afficherListNode(nodeList_t *nodes);

node_t setTile(node_t tab[GRID_SIZE][GRID_SIZE], SDL_Point position,tileState_t state);
void findWay(node_t tab[GRID_SIZE][GRID_SIZE], node_t start_node, node_t end_node){
    nodeList_t *open = (nodeList_t*)malloc(sizeof(nodeList_t));
    open->data = start_node;
    open->prev = NULL;
    open->next = NULL;
    
    nodeList_t *closed = NULL;
    node_t *current = NULL;
    while (SDL_TRUE)
    {
        current = LowestFcost(open);
        if (current == NULL)
        {
            printf("Il n'y a pas de chemin possible vers la fin !");
            break;
        }
        
        printf("current pos = %d:%d   > %d\n", current->position.x, current->position.y, current->f_cost);;
        
        delete_node(&open, *current);
        printf("delete de open\n");
        add_node(&closed, *current);

        printf("Noeud supprimé et ajouter !\n");
        
        if (current->f_cost == 0)
        {
            printf("Chemin trouvé !\n");
            break;
        }
        
        printf("Traitement des voisins :\n");
        int count = 0;
        for (int i = -1; i < 2; i++)
        {
            for (int j = -1; j < 2; j++)
            {
                if ((i == 0 && j == 0) ||
                    (current->position.y + i < 0         ||
                    current->position.y + i > GRID_SIZE ||
                    current->position.x + j < 0         ||
                    current->position.x + j > GRID_SIZE )
                ){
                    continue;
                }
                printf("Voisin N°%d\n", count++);

                
                node_t *neighbour = &tab[current->position.y + i][current->position.x +j];

                if ((inList(closed, neighbour) != NULL) ||
                    neighbour->state == wall)
                {
                    continue;
                }

                if (!inList(open, neighbour) && !inList(closed, neighbour))
                {
                    neighbour->f_cost = distanceBetweenTwoPoint(
                        neighbour->position.x,
                        neighbour->position.y,
                        end_node.position.x,
                        end_node.position.y
                    );
                    if (neighbour->parent == NULL)
                    {
                        neighbour->parent = current;
                    }
                    
                    add_node(&open, *neighbour);
                }
                

            }
        }
        printf("Tout les voisins traités.");
        // remove current from open
        printf("");
        
        // afficherListNode(open);

        printf("\n\n...\n\n");
        // SDL_Delay(50);
    }

    node_t *index = current->parent;
    while (index->state != start){
        printf("-> %d:%d\n", index->position.x, index->position.y);
        int posx = index->position.x*10;
        int posy = index->position.y*10;

        setTile(tab, (SDL_Point){.x = posx, .y = posy}, path);
        
        index = index->parent;
    }
    

    freeNodeList(open);
    freeNodeList(closed);
}

void afficher10x10Tab(node_t tab[GRID_SIZE][GRID_SIZE]){
    printf("10x10:\n");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%4.d ",tab[i][j].f_cost);
        }
        printf("\n");
    }
    
    printf("-=-=-=-=-=-=-=-\n");
}

void afficherListNode(nodeList_t *nodes){
    printf("Liste de noeuds:\n");

    nodeList_t *current = nodes;
    while (current != NULL){
        printf("- %d:%d  > %d\n", current->data.position.x, current->data.position.y, current->data.f_cost);
        current = current->next;
    }
    printf("--------------\n\n");
}

int distanceFromStart(nodeList_t *node, node_t *start_node) {
    node_t *current = &node->data;
    int count = 0;
    while (!equalNodes(*current, *start_node))
    {
        current = current->parent;
        count++;
    }
    return count;
}

int distanceBetweenTwoPoint(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    
    int diagonal = dx < dy ? dx : dy;
    int straight = abs(dx - dy);

    return diagonal * 14 + straight * 10;
}

node_t *inList(nodeList_t *nodes, node_t *data){
    nodeList_t *current = nodes;
    while (current != NULL)
    {
        if (equalNodes(current->data, *data))
        {
            return &current->data;
        }
        current = current->next;
    }

    return NULL;
}

void freeNodeList(nodeList_t *nodes) {
    if (nodes == NULL) {
        return;
    }

    nodeList_t *current = nodes->next;
    nodeList_t *temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    free(nodes);
}

void add_node(nodeList_t **nodes, node_t data) {
    nodeList_t *newNode = (nodeList_t*)malloc(sizeof(nodeList_t));
    if (newNode == NULL) {
        // Gestion de l'échec de l'allocation de mémoire
        fprintf(stderr, "Erreur d'allocation de mémoire pour le nouveau nœud.\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = NULL;

    // Si la liste est vide, le nouveau nœud est le premier nœud.
    if (*nodes == NULL) {
        *nodes = newNode;
        return;
    }

    // Trouver le dernier nœud existant.
    nodeList_t *current = *nodes;
    while (current->next != NULL) {
        current = current->next;
    }

    // Relier le nouveau nœud à la fin de la liste existante.
    current->next = newNode;
}

SDL_bool equalNodes(node_t first, node_t second){
    if (first.position.x == second.position.x &&
        first.position.y == second.position.y)
    {
        return SDL_TRUE;
    }
    return SDL_FALSE;
    
}

void delete_node(nodeList_t **nodes, node_t data) {
    if(nodes == NULL || *nodes == NULL){
        printf("Erreur de pointeur nul");
        return;
    }

    nodeList_t *current = *nodes;
    printf("A\n");
    while (current != NULL) {
        
        printf("B\n");
        if (equalNodes(current->data, data)) {
            printf("C\n");
            // Le nœud à supprimer a été trouvé.

            if (current->prev == NULL) {
                printf("D\n");
                // Le nœud à supprimer est le premier.
                *nodes = current->next;
            } else {
                printf("Dbis\n");
                // Le nœud à supprimer n'est pas le premier.
                current->prev->next = current->next;
                printf("E\n");
                if (current->next != NULL) {
                    printf("F\n");
                    current->next->prev = current->prev;
                    printf("G\n");
                }
            }

            // Libérer la mémoire du nœud supprimé (si nécessaire).
            free(current);
            return;
        }
        printf("Cbis\n");
        // Avancer au nœud suivant.
        current = current->next;
    }
}

node_t *LowestFcost(nodeList_t *nodes) {
    // Liste vide, aucuns chemin trouvé vers la cible.
    if (nodes == NULL)
    {
        return NULL;
    }
    
    node_t *lowest = &nodes->data;
    nodeList_t *current = nodes->next;

    while (current != NULL){
        if (current->data.f_cost < lowest->f_cost)
        {
            lowest = &current->data;
        }

        current = current->next;
    }
    afficherListNode(nodes);
    printf("Selectionné : %d:%d > %d\n", lowest->position.x, lowest->position.y, lowest->f_cost);
    return lowest;
}



/*

if (inList(open, current) != NULL)
{
    add_node(open, (node_t){
        .f_cost = distanceBetweenTwoPoint(
            current->pos_x,
            current->pos_y,
            end_node.pos_x,
            end_node.pos_y
        ),
        .parent = NULL,
        .pos_x = current->pos_x,
        .pos_y = current->pos_y
    });
}
*/