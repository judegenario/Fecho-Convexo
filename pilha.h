/*
Arquivo: pilha.h
Autoras: Juliana Campos Degenario (NUSP 11275112) e Marina Nastri da Costa Pereira Rodero (NUSP 10093702)
*/

#ifndef PILHA_H
#define PILHA_H
#include <stdlib.h>
#include "ponto.h"

/*struct que armazena as informações da pilha, que são o topo, o tamanho e um vetor de pontos*/
struct pilha{
    int topo;
    unsigned tamanho;
    PONTO *vet;
};

typedef struct pilha PILHA;

PILHA *criar_pilha(unsigned tam);/*função para criar a pilha*/
int pilha_cheia(PILHA *pilha);/*função para verificar se a pilha está cheia*/
int pilha_vazia(PILHA *pilha);/*função para verificar se a pilha está vazia*/
void inserir_na_pilha(PILHA *pilha, PONTO item);/*função para inserir um ponto na pilha*/
PONTO retirar_da_pilha(PILHA *pilha);/*função para retirar um ponto da pilha*/
PONTO topo(PILHA *pilha);/*função que retorna o topo da pilha*/
PONTO prox_da_pilha(PILHA *pilha);/*função que retorna o pro ponto da pilha, depois do topo*/

#endif