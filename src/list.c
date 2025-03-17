#include "../include/Mineassist.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void addPos(List * list, Position pos){
    // Cria um novo no para a lista
    List * newNode = (List *) malloc(sizeof(List));
    if(newNode == NULL){
        printf("Erro ao alocar memoria\n");
        return;
    }

    // Atribui o valor da posição ao novo no
    newNode->position = (Position *) malloc(sizeof(Position));
    if(newNode->position == NULL){
        printf("Erro ao alocar memoria\n");
        return;
    }

    newNode->position->nome = strdup(pos.nome);
    newNode->position->x = pos.x;
    newNode->position->y = pos.y;
    newNode->position->z = pos.z;

    // Set o proximo no como NULL por padrão
    newNode->next = NULL;

    // Insere o novo no No no começo da lista
    newNode->next = list->next;
    list->next = newNode;
}

void delPos(List * list, Position pos){
    List * current = list->next;
    List * previous = NULL;

    while (current != NULL && strcmp(current->position->nome, pos.nome) != 0){
        previous = current;
        current = current->next;
    }

    if(current == NULL){
        printf("Elemento não encontrado\n");
        return;
    }

    if(previous == NULL){
        // O elemento é o primeiro da lista
        list->next = current->next;
    }else{
        previous->next = current->next;
    }

    free(current->position->nome);
    free(current->position);
    free(current);
}

void showList(List * list){
    List * current = list->next;

    while (current != NULL){
        printf("c%s\n", current->position->nome);
        printf("\tX:%d Y:%d Z:%d\n", current->position->x, current->position->y, current->position->z);

        current = current->next;
    }
}