/*
Arquivo: ponto.h
Autoras: Juliana Campos Degenario (NUSP 11275112) e Marina Nastri da Costa Pereira Rodero (NUSP 10093702)
*/

#ifndef PONTO_H
#define PONTO_H

/*struct que armazena as coordenadas de um ponto*/
struct ponto{	
  double x, y;
};

typedef struct ponto PONTO;

int trocar(PONTO *p1, PONTO *p2);/*função que troca o p2 com p1*/
double calcular_distancia(PONTO p1, PONTO p2);/*função que calcula a distancia entre dois pontos*/
int obter_sentido(PONTO p, PONTO q, PONTO r); /*função que obtem o sentido da angulação de uma reta entre 3 pontos*/
int compare(const void *vp1, const void *vp2); /*função que compara dois elementos de um vetor*/
void calcular_porcentagem(int tam, int tam_pilha);/*função que calcula a porcetagem de pontos presentes no fecho convexo em relação aos pontos totais*/

#endif