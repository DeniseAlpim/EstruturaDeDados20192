#include <stdio.h> //Biblioteca padr�o
#include <stdbool.h> //Defini��o do tipo Booleano
#include <stdlib.h> //define v�rias fun��es para executar fun��es gerais (malloc, system, etc.)
#include <string.h> // Manipular strings
#include <ctype.h> //declara v�rias fun��es que s�o �teis para manipular caracteres. (isdigit() por exemplo)
#include <locale.h> //Configurar local/regi�o/pa�s
#include "funcoesdosistema.h"

#define MENSAGEM_DE_ERRO "Mensagem de erro do compilador"
#define TAMANHO_DO_ALFABETO 26
#define CODIGO_FECHA_PROGRAMA 6
#define TAMANHO_DA_LINHA 20

//Defini��o da vari�vel debug
bool DEBUG = true;

//Defini��o tipo string
typedef char* string;

//Definir estrutura de um item da �rvore
typedef struct itemDaArvore
{
	int chave;
	struct itemDaArvore* proximaLetra[TAMANHO_DO_ALFABETO];
}itemDaArvore;

//Declarar ponteiro da �rvore
itemDaArvore* raiz = NULL;