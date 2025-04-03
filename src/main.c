#include "../include/Mineassist.h"
#include "../include/Interface.h"
#include <stdio.h>
#include <stdlib.h>

void opAdd(List * list){
    Position nova_pos;
    char * nome;

    printf("Entre com o nome do novo ponto: ");
    scanf("%s", &nome);

    nova_pos.nome = nome;

    addPos(list, nova_pos);
}

void opDel(List * list){
    printf("Remover um ponto.\n");
}

void opShow(List * list){
    showList(list);
    scanf("");
}

int main(){
    char * operacoes = {"Add", "Del", "Show"};
    List * root;
    int currsor = 0;
    int num_opcoes = 2;

    int op_ecolida = menu(&operacoes, currsor, num_opcoes);

    switch (op_ecolida)
    {
        case 0:
            opAdd(root);
            break;
        
        case 1:
            opDel(root);
            break;
        
        case 2:
            opShow(root);
            break;
        
        default:
            break;
    }

    return 0;
}