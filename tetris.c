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
 