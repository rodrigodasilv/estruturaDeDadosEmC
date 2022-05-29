#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaGenerica.h"

void inicializa_fila( FilaGenerica *p , int c, int t ){
	p->fim=-1;
	p->capacidade = c;
	p->tamInfo = t;
	p->dados = malloc( sizeof(void*) * c );
}

int fila_vazia( FilaGenerica f ){
	return f.fim == -1;
}

int fila_cheia( FilaGenerica f ){
	return f.fim == f.capacidade-1;
}

int inserir( FilaGenerica *p, void *info ){
	if( fila_cheia( *p ) )
		return ERRO_FILA_CHEIA;
	p->fim++;
	//int fim = ( p->inicio + p->n ) % p->capacidade;
	p->dados[p->fim] = malloc( p->tamInfo );
	memcpy( p->dados[p->fim], info, p->tamInfo );
	//p->dados[fim] = info;
	return 1; // Sucesso.
}

int remover( FilaGenerica *p, void *info ){
	if( fila_vazia( *p ) )
		return ERRO_FILA_VAZIA;
	
	memcpy( info, p->dados[0], p->tamInfo );
	
	//*info = p->dados[p->inicio];
	//p->inicio = ( p->inicio + 1 ) % p->capacidade;
	int cont;
	for(cont = 0;cont < p->fim ; cont++){
		memcpy(p->dados[cont],p->dados[cont+1], p->tamInfo );
	}
	free( p->dados[p->fim] );
	p->fim--;
	return 1; // Sucesso;
}

void mostra_fila( FilaGenerica f, void (*mostra)(void*) ){
	if( fila_vazia( f ) )
		printf("Fila vazia!\n");
	else{
		printf("Dados da Fila:\n");
		int i, cont;
		for( cont = 0; cont <= f.fim ; cont++ ){
		
			printf("[%d] ", cont);
			mostra( f.dados[cont] );
		}
	}
	printf("\n");
}

void desaloca_fila( FilaGenerica *p ){
	int i, cont;
	for( cont = 0;cont <= p->fim ; cont++){
		
		free( p->dados[cont] );
	}
		
	free( p->dados );
}


