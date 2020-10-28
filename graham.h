/*
Arquivo: graham.h
Autoras: Juliana Campos Degenario (NUSP 11275112) e Marina Nastri da Costa Pereira Rodero (NUSP 10093702)
*/

#ifndef GRAHAM_H
#define GRAHAM_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ponto.h"
#include "pilha.h"
#include "lista_circular.h"

extern PONTO p0;

int trocar(PONTO *p1, PONTO *p2);/*função que troca o p2 com p1*/
double distancia(PONTO p1, PONTO p2);/*função que calcula a distancia entre dois pontos*/
int obter_sentido(PONTO p, PONTO q, PONTO r);/*função que obtem o sentido da angulação de uma reta entre 3 pontos*/
int compare(const void *vp1, const void *vp2);/*função que compara dois elementos de um vetor*/
void fecho_convexo(PONTO vet_pontos[], int n, char op, int sentido);/*função que obtem os pontos que formam o fecho convexo dado n pontos através do algoritmo de graham scan*/


#endif