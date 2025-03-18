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
        printf("setInputMode called on Windows.\n");
        HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
        DWORD mode;

        // Pega o estado atual do console
        if(!GetConsoleMode(hStdin, &mode)){
            fprintf(stderr, "Não foi possível obter o modo do console\n");
            return;
        }

        mode &= ~ENABLE_LINE_INPUT; // Desabilita a entrada de linha (não precisa apertar enter)
        mode &= ~ENABLE_ECHO_INPUT; // Desabilita o eco (não mostra o que foi digitado)
        mode &= ~ENABLE_PROCESSED_INPUT; // Desabilita o processamento de entrada (Ctrl+C, Ctrl+Z, etc)

        // Define o novo estado do console
        if(!SetConsoleMode(hStdin, mode)){
            fprintf(stderr, "Não foi possível definir o modo do console\n");
            return;
        }
    #else // Linux
        struct termios tattr;
        tcgetattr(STDIN_FILENO, &tattr);
        tattr.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &tattr);
    #endif
}

void linuxKeyHandler(int * cursor, int n_options){
    // Código para Linux
    // Funciona bem no Linux, no windows não
    char inp = getchar();
    switch (inp)
    {
        case 'w':
            // Move o marcador para cima
            (*cursor)--;
            if(*cursor < 0){
                *cursor = n_options;
            }
            break;
        
        case 's':
            // Move o marcador para baixo
            (*cursor)++;
            if(*cursor > n_options){
                *cursor = 0;
            }
            break;
        
        default:
            break;
    }
}

void windowsKeyHandler(int * cursor, int n_options){
    if (GetAsyncKeyState('W') & 0x8000) {
        (*cursor)--; // Decrementa o valor
        if (*cursor < 0) {
            *cursor = n_options;
        }
        Sleep(200); // Prevent rapid input
    } else if (GetAsyncKeyState('S') & 0x8000) {
        (*cursor)++;
        if (*cursor > n_options) {
            *cursor = 0;
        }
        Sleep(200); // Prevent rapid input
    }
}

int menu(char ** options, int cursor, int n_options){
    setInputMode();
    while(1){
        (_WIN32) ? system("cls") : system("clear");

        printf("%c Add\n%c Del\n%c Show\n", 
            (cursor == 0) ? '>' : ' ', 
            (cursor == 1) ? '>' : ' ' , 
            (cursor == 2) ? '>' : ' ');
        
        // Espera até o cursor mudar de posição 
        int old_cursor = cursor;
        while(old_cursor == cursor){
            // Chama o handler de input, especifico para o OS
            (_WIN32) ? windowsKeyHandler(&cursor, n_options) : linuxKeyHandler(&cursor, n_options);
            Sleep(100); // Reduz o uso de CPU
        }
    }
}