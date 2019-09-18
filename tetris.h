/*

        Jogo interativo Tetris implementado em C para uso 
    no console (terminal de comando)

        Autor: Andrey Willians Dias Cardoso
        Data: 28/08/2019

*/
#include <stdio.h>
#include <stdlib.h>
/* Configuração das dimensões da
 matriz pricipal do jogo */
#define COLUMNS 60
#define ROWS 25

//Assinaturas

//Inicializa a matriz principal com os espaços vazios
void init(char matrix[ROWS][COLUMNS]);
//Mostra o conteúdo principal da matriz na tela
void printMatrix(char matrix[ROWS][COLUMNS]);
//cria bordas
void bordas(char matrix[ROWS][COLUMNS]);
