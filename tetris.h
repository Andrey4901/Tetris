/*

        Jogo interativo Tetris implementado em C para uso 
    no console (terminal de comando)

        Autor: Andrey Willians Dias Cardoso
        Data: 28/08/2019

*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
/* Configuração das dimensões da
 matriz pricipal do jogo */
#define COLUMNS 60
#define ROWS 25
// Teclas
#define ESC 27
#define ARROWS 224
#define LEFT 75
#define RIGHT 77
#define TECLA_a 97
#define TECLA_d 100
#define tecla_A 65
#define tecla_D 68
//Orientações p/ as peças
#define ORIENTACAO_UP 1
#define ORIENTACAO_DOWN 2
#define ORIENTACAO_LEFT 3
#define ORIENTACAO_RIGHT 4
//Tipos de peças
#define TIPO_L 1
#define TIPO_L_R 2 //L reverso
#define TIPO_T 3
#define TIPO_Z 4
#define TIPO_Z_R 5 //Z reverso
#define TIPO_O 6   //Quadrado
#define TIPO_I 7
// configurar layout
#define PIXEL 254 
#define EMPTY 32 

// Estrutura padrão de componentes
typedef struct {
    int i; //posic. nas linhas
    int j; //posic. nas colunas
    int orientacao; 
    int tipo; //(7 peças)
    int width; //largura peça
    int height; //altura peça
}Bloco;


//Assinaturas

//Inicializa a matriz principal com os espaços vazios
void init(char matrix[ROWS][COLUMNS]);
//Mostra o conteúdo principal da matriz na tela
void printMatrix(char matrix[ROWS][COLUMNS]);
//cria bordas
void bordas(char matrix[ROWS][COLUMNS]);
