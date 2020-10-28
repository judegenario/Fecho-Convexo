/*
Arquivo: ponto.c
Autoras: Juliana Campos Degenario (NUSP 11275112) e Marina Nastri da Costa Pereira Rodero (NUSP 10093702)
*/

#include <stdio.h>
#include "ponto.h"
#include "graham.h"

int trocar(PONTO *p1, PONTO *p2){
    
    PONTO aux = *p1; /*faz a variavel auxiliar aux receber o valor de p1*/
    *p1 = *p2;  	/*faz p1 receber o valor de p2*/
    *p2 = aux; 		/*faz o valor de p2 receber o valor de aux, que armazena o antigo valor de p1*/
   
	return 0;
}

double calcular_distancia(PONTO p1, PONTO p2){

	/*retorna o quadrado da distância entre os pontos*/
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
    
}

int obter_sentido(PONTO p, PONTO q, PONTO r){
    
	/*realiza o cálculo do coeficiente angular entre os pontos*/
    double res = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y); 

    if (res == 0) return 0; /*retorna 0 se os pontos forem colineares*/
	if (res > 0){
		return 1;			/*retorna 1 se res for > 0, indicando sentido horario*/
	}else{
		return -1;			/*retorna -1 se res for < 0, indicando sentido anti-horario*/
	}
}

int compare(const void *vp1, const void *vp2){

	/*Cria um ponteiro p1 e seta ao valor de vp1*/
    PONTO *p1 = (PONTO *)vp1; 
    PONTO *p2 = (PONTO *)vp2;

	/*res recebe o sentido da angulação da reta dado pela função obter_sentido*/
    int res = obter_sentido(p0, *p1, *p2);

	/*caso os pontos sejam colineares, compara as ditancias e, se a distancia de (p0, *p2) for maior
	 retorna -1(sentido anti-horario), caso contrário 1(sentido hoŕario)*/
    if (res == 0){
		if (calcular_distancia(p0, *p2) >= calcular_distancia(p0, *p1)){
			return -1;
		}else{
			return 1;
		}	
	}

	/*retorna -1 se for anti-horário e 1 se for horário*/
    return (res == -1) ? -1 : 1; 
}

/*recebe a qtd total de pontos e o tamanho da pilha, que são os pontos do fecho convexo, e com base nisso calcula a porcentagem de pontos que fazem parte do fecho convexo*/
void calcular_porcentagem(int tam, int tam_pilha){
	printf("%.2f\n", ((float)tam/tam_pilha)*100);
}