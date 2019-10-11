/*

        Jogo interativo Tetris implementado em C para uso 
    no console (terminal de comando)

        Autor: Andrey Willians Dias Cardoso
        Data: 28/08/2019

*/
#include "tetris.h"

//              Funções

void init(char matrix[ROWS][COLUMNS]){
    int i,j;
    for(i=0; i<ROWS; i++){
        for(j=0; j<COLUMNS; j++){
            matrix[i][j] = ' ';
        }
    }
}

void printMatrix(char matrix[ROWS][COLUMNS]){
    int i,j;
	
    for(i=0; i<ROWS; i++){
        printf("\t\t\t");
        for(j=0; j<COLUMNS; j++){
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}   

void bordas(char matrix[ROWS][COLUMNS]){
    int i, j;
    for(i=0; i<ROWS; i++){
        matrix[i][0]= '\xB1';
        matrix[i][59]='\xB1';
    }
    // ↑ borda linhas & ↓ borda colunas
    for(j=0; j<COLUMNS; j++){  
        matrix[0][j] = '\xB1';
        matrix[24][j] = '\xB1';
    }
    
}

void drawBar(char matrix[ROWS][COLUMNS], Bloco barra, int simbolo){
    switch(barra.orientacao){
        case ORIENTACAO_DOWN:
        case ORIENTACAO_UP:
            if(barra.i-3>=0) matrix[barra.i-3][barra.j] = simbolo;
            if(barra.i-2>=0) matrix[barra.i-2][barra.j] = simbolo;
            if(barra.i-1>=0) matrix[barra.i-1][barra.j] = simbolo;
            matrix[barra.i][barra.j] = simbolo;
            break;
        case ORIENTACAO_RIGHT:
        case ORIENTACAO_LEFT:
            if(barra.j-3>=0) matrix[barra.i][barra.j-3] = simbolo;
            if(barra.j-2>=0) matrix[barra.i][barra.j-2] = simbolo;
            if(barra.j-1>=0) matrix[barra.i][barra.j-1] = simbolo;
            matrix[barra.i][barra.j] = simbolo;
            break;
    }
}

void AdrawBar(char matrix[ROWS][COLUMNS], Bloco barra, int simbolo){
    switch(barra.orientacao){
        case ORIENTACAO_DOWN:
        case ORIENTACAO_UP:
            if(barra.i-3>=0) matrix[barra.i-3][barra.j] = EMPTY;
            if(barra.i-2>=0) matrix[barra.i-2][barra.j] = EMPTY;
            if(barra.i-1>=0) matrix[barra.i-1][barra.j] = EMPTY;
            matrix[barra.i][barra.j] = EMPTY;
            break;
        case ORIENTACAO_RIGHT:
        case ORIENTACAO_LEFT:
            if(barra.j-3>=0) matrix[barra.i][barra.j-3] = EMPTY;
            if(barra.j-2>=0) matrix[barra.i][barra.j-2] = EMPTY;
            if(barra.j-1>=0) matrix[barra.i][barra.j-1] = EMPTY;
            matrix[barra.i][barra.j] = EMPTY;
            break;
    }
}