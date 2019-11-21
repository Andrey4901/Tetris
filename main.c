/*

        Jogo interativo Car Racing implementado em C para uso 
    no console (terminal de comando)
    
        Para executar:
            > start p.exe

        Autor: Andrey Willians Dias Cardoso
        Data: 28/08/2019

*/
#include "tetris.h"
#include "display.h"

/*
    Parte principal do programa, responsável por iniciar e 
    chamar as funções auxiliares.
*/
int main(){
    char matrix[ROWS][COLUMNS];
    Bloco tijolo;
    int keypressed=0;
    int cont=0;
    int velocidade=2;

    //apagar o cursor da tela
    ShowConsoleCursor(0);
    system("cls");

    //posicao inicial do personagem
    initBar(&tijolo);

    //inicializando matriz
    init(matrix);

    //animação do jogo
    while(keypressed != ESC){        
        gotoxy(0,0);

        #if DEBUG == 1
            printf("posicao = (%d, %d)\n", tijolo.i, tijolo.j);
            printf("dimensao = (%d, %d)\n", tijolo.width, tijolo.height);
        #endif

        //posicionar o @ no meio da tela
        drawBar(matrix, tijolo, PIXEL);

        //mostro a matriz na tela
        printMatrix(matrix);

        //faça posição anterior do @ ser apagada
        if(!collisionBar(matrix, tijolo, UNCHECK_SIDE, NONE)){
            drawBar(matrix, tijolo, EMPTY);
            
            //faço a posição da @ ir para a direita
            if(cont%velocidade==0){
                if(tijolo.i < (ROWS-1)) tijolo.i++;
            }

        }else{
            initBar(&tijolo);
        }



        //lendo teclas
        keypressed = 0;         
        if(kbhit()) keypressed = getch();            
        if(keypressed==ARROWS) keypressed = getch();

        switch(keypressed){
            case (int)'a':
            case (int)'A':
            case LEFT: 
                if(!collisionBar(matrix, tijolo, CHECK_SIDE, LEFT))
                    tijolo.j--; //vai para esquerda
            break; 
            case TECLA_d:
            case TECLA_D:
            case RIGHT: 
                if(!collisionBar(matrix, tijolo, CHECK_SIDE, RIGHT))
                    tijolo.j++; //vai para a direita 
            break; 
            case TECLA_ESPACO:
                rotate(&tijolo);
            break;
            case 'v':
                if(velocidade==2){
                    velocidade = 1;
                }else{
                    velocidade = 2;
                }
        }

        cont++;
    }

    system("pause");

    return 0;
}

// . . .