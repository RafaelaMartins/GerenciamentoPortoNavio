#include <stdio.h>

#ifndef _TRABED_H
#define _TRABED_H


typedef struct fila Fila;
typedef struct headP HeadP;
typedef struct pilha Pilha;
typedef struct head HeadF;
typedef struct atracamento Atracamento;
typedef struct portos Portos;

struct fila{
	int id;
	int tempo;
	int qtd;
	HeadP *P1;
	HeadP *P2;
	HeadP *P3;
	HeadP *P4;
	Fila* prox;
	Fila* ant;
};

struct pilha{
	int valor;
	Pilha* prox;
};

struct headP{
	Pilha *topo;
	int tam;
};

struct head{
	Fila* inicio;
	Fila* fim;
	int tam;
};

struct atracamento{
	HeadF *FNavios;
	HeadP *P1;
	HeadP *P2;
	HeadP *P3;
	HeadP *P4;
	HeadP *P5;
};
struct portos{
	Atracamento* A1;
	Atracamento* A2;
	Atracamento* A3;
	Atracamento* A4;
};


Portos *AtendeNavio(Portos *P);
Atracamento* Desenfila(Atracamento *P);
Pilha* DesempilhaGrua(HeadP *P);
Pilha* DesempilhaNavio(Fila *S);
HeadP *EmpilhaNavio(HeadP *P,Pilha *item);
Portos *VerificaAtracamento(Portos *P);
HeadF *AdicionaNavio(HeadF *FNavios);
Fila* AdicionaItemNavio(Fila* Navio);
HeadP* AdicionaPilha(HeadP* P, int valor);
HeadP*CriaHeapHead(HeadP* P);
Portos* CriaPortos();

#endif