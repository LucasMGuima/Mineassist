#include "Mineassist.h"
#ifndef _INTERFACE_H
#define _INTERFACE_H

void setInputMode();

// Define um tipo ponteiro de função
typedef void (*func_type)(void);

// Mostra o menu na tela imprimindo as opcoes entradas 
int menu(char ** options, int cursor, int n_options);

// Processa a chave entrada
int processKey(char key);

// Controla a incersão na lista
void opAdd(List * list);

// Controla a remosão na lista
void opDel(List * list);

// Controla o mostrar a lista
void opShow(List * list);

#endif