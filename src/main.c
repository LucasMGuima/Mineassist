#include "../include/Mineassist.h"
#include "../include/Interface.h"
#include <stdio.h>
#include <stdlib.h>

void opAdd(List * list){
    printf("Adicionar um novo ponto.\n");
}

void opDel(List * list){
    printf("Remover um ponto.\n");
}

void opShow(List * list){
    printf("Mostrar os pontos.\n");
}

int main(){
    char * operacoes = {"Add", "Del", "Show"}; 
    //menu(&operacoes, 0, 3);
    
    int currsor = 0;
    int num_opcoes = 2;

    menu(&operacoes, currsor, num_opcoes);

    return 0;
}