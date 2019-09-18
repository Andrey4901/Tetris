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

//          Função principal

int main(){
    char matrix[ROWS][COLUMNS];
    int posI, posJ;
    int keypressed=0;
    
    //posicao inicial do personagem
    posI = 0;
    posJ = COLUMNS/2;
    //inicializando matriz
    init(matrix);

    //apagar o cursor da tela
    ShowConsoleCursor(0);
    system("cls");

    //animação
    while(keypressed != ESC){
        gotoxy(0,0);

        matrix[posI][posJ] = '\xFE';

        printMatrix(matrix);
        bordas(matrix);

        matrix[posI][posJ] = ' ';
        
        if(posI < ROWS-2) posI++;

        //lê as teclas
        keypressed = 0;
        if(kbhit()) keypressed = getch();
        if(keypressed==ARROWS) keypressed = getch();
        

        switch (keypressed){
            case TECLA_A:
            case LEFT: 
                if(posJ > 0) posJ--; break;
            case TECLA_D:
            case RIGHT:
                if(posJ < (COLUMNS-1)) posJ++; break;
            
        }

    }

    system("pause");

    return 0;
}
// . . .