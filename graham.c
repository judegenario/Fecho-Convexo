/*
Arquivo: graham.c
Autoras: Juliana Campos Degenario (NUSP 11275112) e Marina Nastri da Costa Pereira Rodero (NUSP 10093702)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ponto.h"
#include "graham.h"
#include "pilha.h"
#include "lista_circular.h"
#include "tempo.h"

#define MAX 1000000

PONTO p0;
/*Função responsável por receber os pontos e determinar o fecho convexo*/
void fecho_convexo(PONTO vet_pontos[], int n, char op, int sentido){

	LISTA *l = criar_lista();
	double start = seconds(), menor_y = vet_pontos[0].y, y_atual=0;
    PONTO L, R, D, U;/*pontos que armazenam coordenadas específicas*/
	L.x = 0, L.y = 0, R.x = 0, R.y = 0, D.x = 0, D.y = 0, U.x = 0, U.y = 0;
	int pos = 0, i = 0;


	/*percorre todos os pontos em busca do ponto que possui menor coordenada y*/
    for (int i = 1; i < n; i++){
        y_atual = vet_pontos[i].y;
        
        /*Seleciona o ponto com menor coordenada y e, em caso de dois pontos terem a mesma coordenada y, seleciona o ponto com menor coordenada x*/
        if ((y_atual < menor_y) || (y_atual == menor_y && vet_pontos[i].x < vet_pontos[pos].x))
            menor_y = vet_pontos[i].y, pos = i;
    }

	/*chama a função para colocar o ponto que tem menor coordenada y na pos inicial do vetor de pontos*/
	trocar(&vet_pontos[0], &vet_pontos[pos]);

	/*faz p0 receber o ponto da pos 0 do vetor, o que tem menor coordenada y, para ser usado como referência futuramente*/
	p0 = vet_pontos[0];

	/*chama a função qsort para ordenar o vetor de acordo com a angulação das retas*/
	qsort(&vet_pontos[1], n - 1, sizeof(PONTO), compare);

	/*se n, que é a qtd de pontos, for menor que 3, é impossível formar um fecho convexo. Logo, apresenta mensagem de erro.*/
	if (n < 3) {
		printf("ERRO\n");
		return;
	}

	/*se a qtd de pontos for maior que 3, esses pontos precisam ficar armazenados em uma pilha. Cria uma pilha e insere os 3 primeiros prontos para servirem de referência para as retas*/
	PILHA *pilha = criar_pilha(MAX);
	inserir_na_pilha(pilha, vet_pontos[0]);
	inserir_na_pilha(pilha, vet_pontos[1]);
	inserir_na_pilha(pilha, vet_pontos[2]);

	/*insere os pontos restantes na pilha*/
	for (i = 3; i < n; i++){
		/*retira os pontos que não fazem parte do fecho*/
		if (obter_sentido(prox_da_pilha(pilha), topo(pilha), vet_pontos[i]) == 1){
			retirar_da_pilha(pilha);
		}
		/*insere os pontos que fazem parte da pilha, incluindo os colineares*/
    	inserir_na_pilha(pilha, vet_pontos[i]);
	}

	/*finaliza a contagem do tempo de execução*/
	double end = seconds() - start;

	/*percorre a pilha armazenando pontos específicos nos pontos auxiliares criados e inserindo os pontos da pilha na lista circular*/
	for(i=0;i<pilha->topo+1;i++){

		/*insere o ponto mais a esquerda e mais inferior (menor x menor y) da pilha no ponto L*/
		if(pilha->vet[i].x < L.x || (pilha->vet[i].x == L.x && pilha->vet[i].y < L.y)){
			L.x = pilha->vet[i].x;
			L.y = pilha->vet[i].y;
		}

		/*insere o ponto mais a direita mais inferior (maior x menor y) da pilha no ponto R*/
		if(pilha->vet[i].x > R.x || (pilha->vet[i].x == R.x && pilha->vet[i].y < L.y)){
			R.x = pilha->vet[i].x;
			R.y = pilha->vet[i].y;
		}

		/*insere o ponto mais inferior e mais a esquerda (menor y menor x) da pilha no ponto D*/
		if(pilha->vet[i].y < D.y || (pilha->vet[i].y == D.y && pilha->vet[i].x < D.x)){
			D.x = pilha->vet[i].x;
			D.y = pilha->vet[i].y;
		}

		/*insere o ponto mais ato mais a esquerda (maior y menor x) da pilha no ponto U*/
		if(pilha->vet[i].y > U.y || (pilha->vet[i].y == U.y && pilha->vet[i].x < L.x)){
			U.x = pilha->vet[i].x;
			U.y = pilha->vet[i].y;
		}

		/*insere todos os pontos da pilha, um a um, na lista circular duplamente encadeada*/
		inserir_na_lista(l, pilha->vet[i]);

	}

	/*prints apenas para efeito de teste*/
  	printf(" Mais a esquerda: %.2lf %.2lf\n Mais a direita: %.2lf %.2lf\n Mais baixo: %.2lf %.2lf\n Mais alto: %.2lf %.2lf\n", L.x, L.y, R.x, R.y, D.x, D.y, U.x, U.y);
	printf("\n");
	printf(" Tamanho pilha = %d\n", pilha->topo+1);
	printf(" Tamanho n = %d\n", n);
	printf(" -------------------------------------------------\n");
    
	printf("\n");

	/*switch case que imprime os pontos de acordo com o ponto incial e o sentido desejados*/
	switch(op){
		case 'L':
			imprimir(l, L.x, L.y, sentido);
		break;
		case 'R':
			imprimir(l, R.x, R.y, sentido);
		break;
		case 'D':
			imprimir(l, D.x, D.y, sentido);
		break;
		case 'U':
			imprimir(l, U.x, U.y, sentido);
		break;
	}

	/*calcula a porcentagem de pontos usados no fecho convexo e imprime o resultado na tela*/
	calcular_porcentagem(pilha->topo+1, n);

	/*printf para teste do tempo decorrido*/
	printf("\nTempo decorrido para encontrar o fecho: %lf", end);
	
	
	/*liberar_lista(l);*/

}
