/*

        Jogo interativo Tetris implementado em C para uso 
    no console (terminal de comando)
    
        Para executar:
            > start p.exe

        Autor: Andrey Willians Dias Cardoso
        Data: 28/08/2019

*/
#include "tetris.h"
#include "display.h"
#define DEBUG 0 // ← alterar se precisar debugar


//          Função principal

int main(){
    char matrix[ROWS][COLUMNS];
    Bloco tijolo;
    int keypressed=0;
    
    //posicao inicial do personagem
    tijolo.i = 0;
    tijolo.j = COLUMNS/2;
    tijolo.tipo = TIPO_I;
    tijolo.orientacao = ORIENTACAO_UP;
    tijolo.width = 1;
    tijolo.height = 4;
    //inicializando matriz
    init(matrix);

    //apagar o cursor da tela
    ShowConsoleCursor(0);
    system("cls");

    //animação
    while(keypressed != ESC){
        gotoxy(0,0);

        #if DEBUG == 1
            printf("\xFE = (%d, %d)\n", tijolo.i, tijolo.j);
        #endif
        //desenha o pixel na tela
        switch(tijolo.orientacao){
            case ORIENTACAO_UP:
                if(tijolo.i-3>=0) matrix[tijolo.i-3][tijolo.j] = PIXEL;
                if(tijolo.i-2>=0) matrix[tijolo.i-2][tijolo.j] = PIXEL;
                if(tijolo.i-1>=0) matrix[tijolo.i-1][tijolo.j] = PIXEL;
                matrix[tijolo.i][tijolo.j] = PIXEL;
                break;
            case ORIENTACAO_LEFT:
            //
            break;
        }
        
        printMatrix(matrix);
        bordas(matrix);

        //apaga a posição anterior do pixel
        if(tijolo.i-3>=0) matrix[tijolo.i-3][tijolo.j] = EMPTY;
        if(tijolo.i-2>=0) matrix[tijolo.i-2][tijolo.j] = EMPTY;
        if(tijolo.i-1>=0) matrix[tijolo.i-1][tijolo.j] = EMPTY;
        matrix[tijolo.i][tijolo.j] = EMPTY;
        
        if(tijolo.i < ROWS-2) tijolo.i++;

        //lê as teclas
        keypressed = 0;
        if(kbhit()) keypressed = getch();
        if(keypressed==ARROWS) keypressed = getch();
        

        switch (keypressed){
        	case tecla_A:
            case TECLA_a:
            case LEFT: 
                if(tijolo.j > 0) tijolo.j--; break;
            case tecla_D:
            case TECLA_d:
            case RIGHT:
                if(tijolo.j < (COLUMNS-1)) tijolo.j++; break;
            
        }

    }

    system("pause");

    return 0;
}
// . . .
