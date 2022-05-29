#include "Pilhas.h"

typedef struct{
	PilhaGenerica p1,p2;
	int capacidade,fim;
	int tamInfo;
} FilaDePilhas;

void inicializa_fila( FilaDePilhas *p , int c, int t );
int fila_vazia( FilaDePilhas f );
int fila_cheia( FilaDePilhas f );
int inserir( FilaDePilhas *p, void *info );
int remover( FilaDePilhas *p, void *info );
void mostra_fila( FilaDePilhas f,void(*mostra)(void*));
void desaloca_fila( FilaDePilhas *p );
