/*

        Jogo interativo Car Racing implementado em C para uso 
    no console (terminal de comando)

        Autor: Andrey Willians Dias Cardoso
        Data: 28/08/2019

*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Configuração das dimensões da matriz principal do jogo
#define COLUMNS 30
#define ROWS 30

//Configuração de teclas
#define ESC 27
#define ARROWS 224
#define LEFT 75
#define RIGHT 77
#define TECLA_a 97
#define TECLA_d 100
#define TECLA_A 65
#define TECLA_D 68
#define TECLA_ESPACO 32

//Criando as orientações para as peças
#define ORIENTACAO_UP 1
#define ORIENTACAO_LEFT 2
#define ORIENTACAO_DOWN 3
#define ORIENTACAO_RIGHT 4
//Criando os tipos de peças
#define TIPO_L 1
#define TIPO_L_R 2 // L reverso
#define TIPO_T 3
#define TIPO_Z 4
#define TIPO_Z_R 5 // Z reverso
#define TIPO_O 6   // Quadrado
#define TIPO_I 7

//Configurações de layout
#define PIXEL 219
#define EMPTY 32

//Configurações do mecanismo de colisão
#define CHECK_SIDE 1
#define UNCHECK_SIDE 0
#define NONE 0

//Estrutura padrão de componentes
typedef struct{
    int i;  //posicao nas linhas da matriz
    int j; //posicao nas colunas da matriz
    int orientacao; //orientacao da peça
    int tipo; //o tipo de peça (7 possíveis)
    int width; //largura da peça
    int height; //altura da peça
}Bloco;

/*
    Inicializa a matriz principal com 'espaços vazios'
*/
void init(char matrix[ROWS][COLUMNS]);

/*
    Mostra o conteúdo da matriz principal na tela 
    do computador.
*/
void printMatrix(char matrix[ROWS][COLUMNS]);

/*
    Desenhar uma barra usando o simbolo do caracter ASCII
    passado por parâmetro.
*/
void drawBar(char matrix[ROWS][COLUMNS], Bloco barra, int simbolo);

/*
    Inicializar a peça do tipo barra
*/
void initBar(Bloco *barra);

/*
    Rotaciona blocos do jogo
*/
void rotate(Bloco *bloco);

/*
    Verifica a colisão de blocos
*/
int collisionDetect(char matrix[ROWS][COLUMNS], Bloco barra);

/*
    Verifica a colisão de barras
*/
int collisionBar(char matrix[ROWS][COLUMNS], Bloco barra, int collideSides, int side);