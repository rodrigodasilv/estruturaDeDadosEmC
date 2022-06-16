#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "Produto.h"

void mostra_p( void *x ){
	Produto *p = x;
	mostra_produto( *p );
}

int main(int argc, char *argv[]) {
	Lista l1;
	Produto x;
	
	inicializa_lista( &l1, sizeof(Produto) );
	
	inicializa_produto( &x, 123, "Cafe com leite", 2.5 );
	insere_fim( &l1, &x );
	mostra_lista( l1, mostra_p );
	
	inicializa_produto( &x, 456, "Cafe expresso", 5 );
	insere_fim( &l1, &x );
	mostra_lista( l1, mostra_p );
	
	inicializa_produto( &x, 999, "Capuccino", 10 );
	insere_fim( &l1, &x );
	mostra_lista( l1, mostra_p );
	
	inicializa_produto( &x, 12, "Bolo de cenoura", 3.5 );
	insere_pos( &l1, &x, 2 );
	mostra_lista( l1, mostra_p );
	
	Produto y;
	/*
	le_valor( l1, &y, 2 );
	printf("Valor lido: ");
	mostra_produto( y );
	
	le_produto( &y );
	
	modifica_valor( l1, &y, 2);
	mostra_lista( l1, mostra_p );
	*/
	int i;
	printf("Digite o indice do produto que deseja remover: ");
	scanf("%d", &i);
	if( remove_pos( &l1, &y, i ) == ERRO_POS_INVALIDA )
		printf("Indice invalido!!\n");
	else{
		printf("Produto removido: ");
		mostra_produto( y );
		mostra_lista( l1, mostra_p );
	}
	
	
	printf("\nPercorrendo a lista...\n");

	for( i = 0 ; le_valor( l1, &y, i) != ERRO_POS_INVALIDA ; i++){
		mostra_produto( y );
	}
	
	
	limpa_lista( &l1 );
	return 0;
}
