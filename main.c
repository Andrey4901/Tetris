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
#define DEBUG 1 // ← alterar se precisar debugar


//          Função principal

int main(){
    char matrix[ROWS][COLUMNS];
    Bloco tijolo;
    int keypressed=0;
    
    //posicao inicial do personagem
    tijolo.i = 0;
    tijolo.j = COLUMNS/2;
    tijolo.tipo = TIPO_I;
    tijolo.orientacao = ORIENTACAO_LEFT;
    tijolo.width = 5;
    tijolo.height = 1;
    //inicializando matriz
    init(matrix);

    //apagar o cursor da tela
    ShowConsoleCursor(0);
    system("cls");

    //animação
    while(keypressed != ESC){
        gotoxy(0,0);

        #if DEBUG == 1
            printf("Posicao = \xFE (%d, %d)\n", tijolo.i, tijolo.j);
            printf("Dimensao = (%d, %d)\n", tijolo.width, tijolo.height);
        #endif
        //desenha o pixel na tela
        drawBar(matrix, tijolo, PIXEL);
        //
        printMatrix(matrix);
        bordas(matrix);
        //
        //apaga a posição anterior do pixel
        AdrawBar(matrix, tijolo, EMPTY);
        
        if(tijolo.i < ROWS-2) tijolo.i++;

        //lê as teclas
      keypressed = 0;         
        if(kbhit()) keypressed = getch();            
        if(keypressed==ARROWS) keypressed = getch();

        switch(keypressed){
            case (int)'a':
            case (int)'A':
            case LEFT: 
                if((tijolo.j - (tijolo.width/2)) > 0) tijolo.j--; //vai para esquerda
            break; 
            case TECLA_d:
            case TECLA_D:
            case RIGHT: 
                if((tijolo.j + (tijolo.width/2)) < (COLUMNS-1)) tijolo.j++; //vai para a direita 
            break; 
            case TECLA_ESPACO:
                if(tijolo.orientacao==ORIENTACAO_RIGHT)
                    tijolo.orientacao = ORIENTACAO_UP;
                else
                    tijolo.orientacao++;

                //inverte as dimensões do tijolo
                int aux = tijolo.width;
                tijolo.width = tijolo.height;
                tijolo.height = aux;
                
                //resolvendo bug dos cantos
                if(tijolo.j < (tijolo.width/2))
                    tijolo.j = tijolo.width/2;
                else if(tijolo.j > COLUMNS - (tijolo.width/2) - 1)
                    tijolo.j = COLUMNS - (tijolo.width/2) - 1;
        }

    }   

    system("pause");

    return 0;
}
// . . .
