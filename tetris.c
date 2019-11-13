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
        matrix[i][29]='\xB1';
    }
    // ↑ borda linhas & ↓ borda colunas
    for(j=0; j<COLUMNS; j++){  
        matrix[0][j] = '\xB1';
        matrix[59][j] = '\xB1';
    }
    
}

void drawBar(char matrix[ROWS][COLUMNS], Bloco barra, int simbolo){
    switch(barra.orientacao){
        case ORIENTACAO_DOWN:
        case ORIENTACAO_UP:
            if(barra.i+1>=0) matrix[barra.i-3][barra.j] = simbolo;
            if(barra.i+2>=0) matrix[barra.i-3][barra.j] = simbolo;
            if(barra.i-2>=0) matrix[barra.i-2][barra.j] = simbolo;
            if(barra.i-1>=0) matrix[barra.i-1][barra.j] = simbolo;
            matrix[barra.i][barra.j] = simbolo;
            break;
        case ORIENTACAO_RIGHT:
        case ORIENTACAO_LEFT:
            if(barra.j+1>=0) matrix[barra.i][barra.j-3] = simbolo;
            if(barra.j+2>=0) matrix[barra.i][barra.j-3] = simbolo;
            if(barra.j-2>=0) matrix[barra.i][barra.j-2] = simbolo;
            if(barra.j-1>=0) matrix[barra.i][barra.j-1] = simbolo;
            matrix[barra.i][barra.j] = simbolo;
            break;
    }
}

/* void AdrawBar(char matrix[ROWS][COLUMNS], Bloco barra, int simbolo){
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
} */


void initBar(Bloco *barra){
    barra->i = 0;
    barra->j = COLUMNS/2;
    barra->tipo = TIPO_I;
    barra->orientacao = ORIENTACAO_LEFT;
    barra->width = 5;
    barra->height = 1;

    #if DEBUG == 1
        printf("posI: %d  posJ: %d \n", barra->i, barra->j);
        system("pause");
    #endif
}

void rotate(Bloco *bloco){
    if(bloco->orientacao==ORIENTACAO_RIGHT)
        bloco->orientacao = ORIENTACAO_UP;
    else
        bloco->orientacao++;

    //inverte as dimensões do tijolo
    int aux = bloco->width;
    bloco->width = bloco->height;
    bloco->height = aux;

    //resolvendo bug dos cantos
    if(bloco->j < (bloco->width/2))
        bloco->j = bloco->width/2;
    else if(bloco->j > COLUMNS - (bloco->width/2) - 1)
        bloco->j = COLUMNS - (bloco->width/2) - 1;

}

int collisionDetect(char matrix[ROWS][COLUMNS], Bloco barra){
    int retorno = 0;

    //colisão com a base
    if((barra.i + 1) >= ROWS)
        retorno = 1;

    //colisão entre peças
   
    if(matrix[barra.i + 1][barra.j] != EMPTY)
        retorno = 1;

    int t2 = barra.width / 2;
    if(matrix[barra.i+1][barra.j + t2] != EMPTY)
        retorno = 1;
    if(matrix[barra.i+1][barra.j - t2] != EMPTY)
        retorno = 1;

    return retorno;
}

int collisionBar(char matrix[ROWS][COLUMNS], Bloco barra, int collideSides, int side){
    int retorno = 0;

    //colisão de base
    if((barra.i + 1) >= ROWS)
        retorno = 1;

    //colisão da base da barra com outras peças
    if(matrix[barra.i + 1][barra.j] =! EMPTY)
        retorno = 1;

    //colisao com a base horizontal
    int t2 = barra.width / 2;
    if(matrix[barra.i+1][barra.j + t2] != EMPTY)
        retorno = 1;
    if(matrix[barra.i+1][barra.j - t2] != EMPTY)
        retorno = 1;

    if(collideSides==CHECK_SIDE && (barra.orientacao == ORIENTACAO_LEFT || barra.orientacao == ORIENTACAO_RIGHT)){
        if(side==RIGHT && matrix[barra.i][barra.j + t2 + 1] != EMPTY) 
            retorno = 1;

        if(side==RIGHT && matrix[barra.i][barra.j + t2 + 1] >= EMPTY) 
            retorno = 1;
    

    //colisão lateral horizontal
    if(collideSides == 1 && (barra.orientacao == ORIENTACAO_UP || barra.orientacao == ORIENTACAO_DOWN)){
        int i;
        for(i=0; i<barra.height; i++){
        if(side==RIGHT && matrix[barra.i-i][barra.j + 1] != EMPTY) 
            retorno = 1;

        if(side==RIGHT && matrix[barra.i-i][barra.j + 1] != EMPTY) 
            retorno = 1;
        }

        //verificando colisão com o limite lateral da matriz
        if(side==RIGHT && barra.j + 1 >= COLUMNS)
            retorno = 1;


        if(side==LEFT && barra.j - t2 - 1 < 0)
            retorno = 1;
    }

    return retorno;
}