/*
Arquivo: lista_circular.h
Autoras: Juliana Campos Degenario (NUSP 11275112) e Marina Nastri da Costa Pereira Rodero (NUSP 10093702)
*/

#ifndef LISTA_H
#define LISTA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ponto.h"
#include "pilha.h"
#include "graham.h"

/*struct que armazena as informações do No da lista circular duplamente encadeada,
sendo elas o ponto e dois ponteiros (um pro proximo no e outro pro anterior)*/
struct No{
	PONTO p;
	struct No *prox;
	struct No *ant;
};

typedef struct No NO;

/*struct que armazena um ponteiro pro inicio da lista, um ponteiro pro fim da lista e o tamanho da lista*/
struct lista{
	NO *inicio;
	NO *fim;
	int tamanho;
};

typedef struct lista LISTA;

LISTA *criar_lista();	/*função para criar a lista*/
void inserir_na_lista(LISTA *lista, PONTO p);/*função para inserir pontos na lista*/
void imprimir(LISTA *l, double x, double y, int op);/*função para imprimir a lista*/
void liberar_lista(LISTA *l);/*função para desalocar memoria da lista*/

#endif