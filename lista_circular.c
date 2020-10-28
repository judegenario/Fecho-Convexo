/*
Arquivo: lista_circular.c
Autoras: Juliana Campos Degenario (NUSP 11275112) e Marina Nastri da Costa Pereira Rodero (NUSP 10093702)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ponto.h"
#include "pilha.h"
#include "graham.h"
#include "lista_circular.h"

/*função para criar a lista circular duplamente encadeada, setando NULL nos ponteiros e 0 nos valores inteiros*/
LISTA * criar_lista(){
	LISTA *novo_no = (LISTA *)malloc(sizeof(LISTA));
	novo_no->inicio = NULL;
	novo_no->fim = NULL;
	novo_no->tamanho = 0;
	return novo_no;
}

/*função para inserir pontos na lista circular*/
void inserir_na_lista(LISTA * l, PONTO p){
	/*criação de um no auxiliar*/
	NO *novo_no = (NO*)malloc(sizeof(NO));
	
	/*o novo no recebe o ponto da pilha*/
	novo_no->p = p;

	/*se a lista estiver vazia, o inicio e o fim serão o mesmo elemento*/
	if(l->tamanho == 0){	
		l->inicio = novo_no;
		l->fim = novo_no;
		l->tamanho++;
	}
	/*faz o encadeamento entre os ponteiros pro primeiro elemento*/
	else if(l->tamanho == 1){
		l->inicio->prox = novo_no;
		l->inicio->ant = novo_no;
		l->fim = novo_no;
		novo_no->ant = l->inicio;
		novo_no->prox = l->inicio;
		l->tamanho++;
	}
	/*faz o encadeamento entre os ponteiros quando tem mais de 1 elemento*/
	else{
		l->inicio->ant = novo_no;
		novo_no->prox = l->inicio;
		novo_no->ant = l->fim;
		l->fim->prox = novo_no;
		l->fim = novo_no;
		l->tamanho++;
	}
}

/*função para imprimir os pontos da lista*/
void imprimir(LISTA *l, double x, double y, int sentido){
	/*criação de um no para percorrer a lista, que recebe o inicio da lista*/
	NO *atual = l->inicio;

	/*enquanto o ponto que estiver sendo percorrido não for o ponto que estamos procurando, passa para o próximo ponto*/
	while(atual->p.x != x && atual->p.y != y){
		atual = atual->prox;
	}

	/*quando encontrar o ponto, printa o ponto*/
	printf("%.2lf %.2lf\n", atual->p.x, atual->p.y);
	printf("\n");

	/*verifica o sentido que se deseja printar os pontos, caso seja 1 printa no sentido antihorario,
	caso seja 0 printa no sentido horario*/
	if (sentido == 1){
		/*cria um auxiliar para receber o atual*/
		NO *aux = atual;
		/*faz o atual ser o proximo*/
		atual = atual->prox;
		/*enquanto o atual não voltar a ser o primeiro ponto printado, printa os pontos e faz atual ser o proximo, para assim printar no sentido antihorario*/
		while(atual != aux){
			printf("%.2lf %.2lf\n", atual->p.x, atual->p.y);
			printf("\n");
			atual = atual->prox;
		}
	}else{
		/*cria um auxiliar para receber o atual*/
		NO *aux = atual;
		/*faz o atual ser o anterior*/
		atual = atual->ant;
		/*enquanto o atual não voltar a ser o primeiro ponto printado, printa os pontos e faz atual ser o anterior, para assim printar no sentido horario*/
		while(atual != aux){
			printf("%.2lf %.2lf\n", atual->p.x, atual->p.y);
			printf("\n");
			atual = atual->ant;
		}
	}
	
}

/*percorre a lista desalocando a memoria*/
void liberar_lista(LISTA *l){
	NO *atual = l->inicio->prox;
	NO *proximo;
	l->inicio = NULL;
	while(atual->prox!=NULL){
		proximo=atual->prox;
		free(atual);
		proximo = atual;
	}
	free(l);
}

