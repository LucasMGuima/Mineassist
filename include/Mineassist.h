#ifndef _MINEASSIST_H
#define _MINEASSIST_H

typedef struct position{
    char * nome;
    // Posição
    short int x;
    short int y;
    short int z;
}Position;

typedef struct list
{
    Position * position;
    struct list * next;
}List;

// Adiciona um novo elemento a lista
void addPos(List * list, Position pos);

// Remove o elemento da lista
void delPos(List * list, Position pos);

// Mostra os elementos da lista
void showList(List * list);

// Ponto médio entre N elementos
Position midPoint(List * list);

// Distancia spherica entre dois pontos
double sphericalDistance(Position pos1, Position pos2);

#endif