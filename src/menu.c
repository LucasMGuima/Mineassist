#include "../include/Interface.h"
#include <stdlib.h>
#include <stdio.h>
// Tirar o Enter do terminal, LINUX
#include <termios.h>
#include <unistd.h>
// Fazer o mesmo para Windows

// Faz com que não precise ser usado o enter
void setInputMode(){
    struct termios tattr;
    tcgetattr(STDIN_FILENO, &tattr);
    tattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &tattr);
}

int menu(char ** options, int cursor, int n_options){
    for(int i = 0; i < n_options; i++){
        printf("%s\n", &options[i]);
    }
    return 1;
}