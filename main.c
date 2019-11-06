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
    Bloco tijolo;
    int keypressed=0;

    //apagar o cursor da tela
    ShowConsoleCursor(0);
    system("cls");

    //posicao inicial do personagem
    initBar(&tijolo);

    //inicializando matriz
    init(matrix);

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

        if(!collisionDetect(matrix, tijolo)){
            drawBar(matrix, tijolo, EMPTY);
            
            //faço a posição da @ ir para a direita
            if(tijolo.i < (ROWS-1)) tijolo.i++;

        }else{
            initBar(&tijolo);
        }

        //lê as teclas
      keypressed = 0;         
        if(kbhit()) keypressed = getch();            
        if(keypressed==ARROWS) keypressed = getch();

        switch(keypressed){
            case (int)'a':
            case (int)'A':
            case LEFT: 
                if((tijolo.j - (tijolo.width/2)) > 0)
                    if(matrix[tijolo.i][tijolo.j - (tijolo.width/2) - 1] == EMPTY)
                        tijolo.j--; //vai para esquerda
            break; 
            case TECLA_d:
            case TECLA_D:
            case RIGHT: 
                if((tijolo.j + (tijolo.width/2)) < (COLUMNS-1)) 
                    if(matrix[tijolo.i][tijolo.j + (tijolo.width/2) + 1] == EMPTY)
                        tijolo.j++; //vai para a direita 
            break; 
            case TECLA_ESPACO:
                rotate(&tijolo);
            break;
        }

    }   

    system("pause");

    return 0;
}
// . . .
