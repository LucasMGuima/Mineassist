#include "../include/Mineassist.h"
#include <stdio.h>
#include <stdlib.h>
// Fazer o mesmo para Windows
// Tirar o Enter do terminal, LINUX
#include <termios.h>
#include <unistd.h>

void setInputMode(){
    struct termios tattr;
    tcgetattr(STDIN_FILENO, &tattr);
    tattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &tattr);
}

int main(){
    List * list = malloc(sizeof(List));

    setInputMode();

    int currsor = 0;
    while(1){
        printf("%c Add\n%c Del\n%c Show\n", 
            (currsor == 0) ? '>' : ' ', 
            (currsor == 1) ? '>' : ' ' , 
            (currsor == 2) ? '>' : ' ');

        char c = getchar();
        if(c == 'w'){
            currsor--;
            if(currsor < 0){
                currsor = 2;
            }
        }else if(c == 's'){
            currsor++;
            if(currsor > 2){
                currsor = 0;
            }
        }

        system("clear");
    }

    free(list);
    return 0;
}