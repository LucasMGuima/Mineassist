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
    menu(&operacoes, 0, 3);
    /*
    int currsor = 0;
    int num_opcoes = 2;
    while(1){
        system("clear");
        printf("%c Add\n%c Del\n%c Show\n", 
            (currsor == 0) ? '>' : ' ', 
            (currsor == 1) ? '>' : ' ' , 
            (currsor == 2) ? '>' : ' ');

        char c = getchar();
        switch (c)
        {
            case 'w':
                // Move o marcador para cima
                currsor--;
                if(currsor < 0){
                    currsor = num_opcoes;
                }
                break;
            
            case 's':
                // Move o marcador para baixo
                currsor++;
                if(currsor > num_opcoes){
                    currsor = 0;
                }
                break;
            
            default:
                break;
        }
    }*/

    return 0;
}