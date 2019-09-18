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
    
    //posicao inicial do personagem
    posI = 0;
    posJ = COLUMNS/2;
    //inicializando matriz
    init(matrix);

    //apagar o cursor da tela
    ShowConsoleCursor(0);
    system("cls");

    //animação
    while(1){
        gotoxy(0,0);

        matrix[posI][posJ] = '\xFE';

        printMatrix(matrix);
        bordas(matrix);

        matrix[posI][posJ] = ' ';
        
        if(posI < ROWS-2) posI++;
    }

    system("pause");

    return 0;
}
// . . .