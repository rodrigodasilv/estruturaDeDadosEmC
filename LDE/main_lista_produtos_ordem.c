#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LDE.h"
#include "Produto.h"

void mostra_p( void *x ){
	Produto *p = x;
	mostra_produto( *p );
}

int compara_codigo( void *x, void *y ){
	Produto *a = x, *b = y;
	
	return a->codigo - b->codigo;
}

int compara_preco( void *x, void *y ){
	Produto *a = x, *b = y;
	
	if( a->preco > b->preco )
		return 1;
	if( a->preco < b->preco )
		return -1;
	return 0;
}

int compara_descricao( void *x, void *y ){
	Produto *a = x, *b = y;
	
	return strcmp( a->descricao, b->descricao );
}

int main(int argc, char *argv[]) {
	LDE l1;
	Produto x;
	
	inicializa_lista( &l1, sizeof(Produto) );

	inicializa_produto( &x, 456, "Cafe expresso", 5 );
	insere_pos( &l1, &x,0);
	mostra_lista( l1, mostra_p );
	
	inicializa_produto( &x, 123, "Cafe com leite", 2.5 );
	insere_fim( &l1, &x);
	mostra_lista( l1, mostra_p );
	
	inicializa_produto( &x, 9, "Capuccino", 10 );
	insere_fim( &l1, &x);
	mostra_lista( l1, mostra_p );
	
	inicializa_produto( &x, 1212, "Bolo de cenoura", 3.5 );
	insere_fim( &l1, &x);
	mostra_lista( l1, mostra_p );
	mostra_listra_invertida_v2(l1, mostra_p );
	remove_pos(&l1,&x,0);
	mostra_p(&x);
	mostra_lista( l1, mostra_p );
	mostra_listra_invertida_v2(l1, mostra_p );

	
	limpa_lista( &l1 );
	return 0;
}
