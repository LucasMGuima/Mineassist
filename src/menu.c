#include "../include/Interface.h"
#include <stdlib.h>
#include <stdio.h>

#ifdef _WIN32 // Windows
#include <Windows.h>
#else // Linux
#include <termios.h>
#include <unistd.h>
#endif

// Faz com que não precise ser usado o enter
void setInputMode(){
    #ifdef _WIN32 // Windows
        HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
        DWORD mode;
        GetConsoleMode(hStdin, &mode);
        mode &= ~ENABLE_LINE_INPUT; // Desabilita a entrada de linha (não precisa apertar enter)
        mode &= ~ENABLE_ECHO_INPUT; // Desabilita o eco (não mostra o que foi digitado)
        SetConsoleMode(hStdin, mode);
    #else // Linux
        struct termios tattr;
        tcgetattr(STDIN_FILENO, &tattr);
        tattr.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &tattr);
    #endif
}

int menu(char ** options, int cursor, int n_options){
    setInputMode();

    while(1){
        (_WIN32) ? system("cls") : system("clear");

        printf("%c Add\n%c Del\n%c Show\n", 
            (cursor == 0) ? '>' : ' ', 
            (cursor == 1) ? '>' : ' ' , 
            (cursor == 2) ? '>' : ' ');

        char inp = getchar();
        switch (inp)
        {
            case 'w':
                // Move o marcador para cima
                cursor--;
                if(cursor < 0){
                    cursor = n_options;
                }
                break;
            
            case 's':
                // Move o marcador para baixo
                cursor++;
                if(cursor > n_options){
                    cursor = 0;
                }
                break;
            
            default:
                break;
        }
    }
}