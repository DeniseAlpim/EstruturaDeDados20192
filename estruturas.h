#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//Defini��o tipo string
typedef char* string;

typedef struct tipoPessoa
{
	int codigo;
	char nome[30];
	int idade;
	float altura;
}tipoPessoa;

//Defini��o da estrutura de um item gen�rico de lista
typedef struct tipoItem
{
	string string;
	tipoPessoa pessoa;
	struct tipoItem *anterior;
	struct tipoItem *proximo;
}tipoItem;

//Defini��o da estrutura de uma lista gen�rica
typedef struct tipoLista
{
	string *inicioDaLista;
	string *finalDaLista;
	int tamanhoDaLista;
	bool *listaZerada;
}tipoLista;

//Defini��o da estrutura de uma fila gen�rica
typedef struct tipoFila
{
	int tamanhoDaFila;
}tipoFila;

//Defini��o da estrutura de uma pilha gen�rica
typedef struct tipoPilha
{
	int tamanhoDaPilha;
}tipoPilha;