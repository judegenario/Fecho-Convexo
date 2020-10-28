/*
Arquivo: main.c
Autoras: Juliana Campos Degenario (NUSP 11275112) e Marina Nastri da Costa Pereira Rodero (NUSP 10093702)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include "graham.h"
#include "pilha.h"
#include "lista_circular.h"
#include "ponto.h"

/*função para ler os pontos dados em um arquivo*/
void ler_arquivo(FILE *fp, PONTO vet_pontos[], int num_pontos) {
    int i;
    for (int i = 0; i < num_pontos; i++) {
        PONTO p;
        fscanf(fp, "%lf", &p.x);
        fscanf(fp, "%lf", &p.y);
        vet_pontos[i] = p;
    }
}

int main(void) {

	int num_pontos, sentido;
    FILE *fp;
	char op;

    fp = fopen("1.in", "r");	/*abre o arquivo*/


	/*verifica se o arquivo existe*/
    if (fp == NULL) {
        printf("Erro");
    }

	/*lê o número de pontos do arquivo*/
    fscanf(fp, "%d", &num_pontos);     
    
	/*cria um vetor de pontos com a qtd de pontos lida do arquivo*/
    PONTO vet_pontos[num_pontos]; 

	/*chama a função para ler os pontos do arquivo*/
    ler_arquivo(fp, vet_pontos, num_pontos); 

	/*lê do arquivo a opção que diz qual será o primeiro ponto printado (L, R, D ou U)*/
	fscanf(fp, "%c", &op);
	/*lê do arquivo o sentido que deve ser printado (0 ou 1 - horario ou antihorario)*/
	fscanf(fp, "%d", &sentido);

	/*criado apenas para testes*/
	op = 'L';
	sentido=0;
    
	/*fecha o arquivo*/
    fclose(fp);

	/*chama a função para encontrar o fecho convexo utilizando o algoritmo de graham_scan*/
    fecho_convexo(vet_pontos, num_pontos, op, sentido);

    return 0;
}
