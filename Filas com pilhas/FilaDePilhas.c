#include "FilaDePilhas.h"

void inicializa_fila( FilaDePilhas *p , int c, int t ){
	inicializa_pilha(&p->p1,c,t);
	inicializa_pilha(&p->p2,c,t);
	p->capacidade=c;
	p->tamInfo=t;
	p->fim=-1;
}

int fila_vazia( FilaDePilhas f ){
	return pilha_vazia(f.p2);
}

int fila_cheia( FilaDePilhas f ){
	return pilha_cheia(f.p2);
}

int inserir( FilaDePilhas *p, void *info ){
	while(!pilha_vazia(p->p2)){
		int y;
		desempilha(&p->p2, &y);
		empilha(&p->p1,&y);
	}
	empilha(&p->p1,info);
}

int remover( FilaDePilhas *p, void *info ){
	while(!pilha_vazia(p->p1)){
		int y;
		desempilha(&p->p1, &y);
		empilha(&p->p2,&y);
	}
	desempilha(&p->p2,info);
	while(!pilha_vazia(p->p2)){
		int y;
		desempilha(&p->p2, &y);
		empilha(&p->p1,&y);
	}
}

void mostra_fila( FilaDePilhas f,void(*mostra)(void*)){
	mostra_pilha(f.p1,mostra);
}

void desaloca_fila( FilaDePilhas *p ){
	desaloca_pilha(&p->p1);
	desaloca_pilha(&p->p2);
}


