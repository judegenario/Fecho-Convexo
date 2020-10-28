/*
Arquivo: pilha.c
Autoras: Juliana Campos Degenario (NUSP 11275112) e Marina Nastri da Costa Pereira Rodero (NUSP 10093702)
*/

#include <stdio.h>
#include "ponto.h"
#include "graham.h"
#include "pilha.h"
#include "lista_circular.h"


/*Função de criação da pilha*/
PILHA *criar_pilha(unsigned tam){
    PILHA *pilha = (PILHA *)malloc(sizeof(PILHA));
    pilha->tamanho = tam;
    pilha->topo = -1;
    pilha->vet = (PONTO *)malloc(pilha->tamanho * sizeof(int));
    return pilha;

}

/*Função que verifica se a pilha está cheia*/
int pilha_cheia(PILHA *pilha){
    return pilha->topo == pilha->tamanho - 1;
}

/*Função que verifica se a pilha está vazia*/
int pilha_vazia(PILHA *pilha){
    return pilha->topo == -1;
}

/*Função para adicionar um elemento na pilha*/
void inserir_na_pilha(PILHA *pilha, PONTO item){
    if (pilha_cheia(pilha))
        return;
    pilha->vet[++pilha->topo] = item;
    //stack->tam++;
}

/*Função que remove o elemento do topo da pilha*/
PONTO retirar_da_pilha(PILHA *pilha){
    if (!pilha_vazia(pilha))   
		return pilha->vet[pilha->topo--];
	
	return pilha->vet[pilha->topo];
}


/*Função que indica o topo da pilha*/
PONTO topo(PILHA *pilha){
    if (!pilha_vazia(pilha))
        return pilha->vet[pilha->topo];
	
	return pilha->vet[pilha->topo-1];
}

/*Função que indica proximo elemento depois do topo da pilha*/
PONTO prox_da_pilha(PILHA *pilha){

    PONTO p = topo(pilha);
    retirar_da_pilha(pilha);
    PONTO res = topo(pilha);
    inserir_na_pilha(pilha, p);
    return res;
}