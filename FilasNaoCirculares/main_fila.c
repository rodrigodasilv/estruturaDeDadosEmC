#include <stdio.h>
#include <stdlib.h>
#include "FilaGenerica.h"

void mostra_int( void *x ){
	int *p = x;
	printf("%d\n", *p);
}

int main(int argc, char *argv[]) {
	FilaGenerica f1;
	inicializa_fila( &f1, 4, sizeof(int) );
	mostra_fila( f1, mostra_int );
	
	int k = 3;
	inserir( &f1, &k );
	mostra_fila( f1, mostra_int );
	
	k = 6;
	inserir( &f1, &k );
	mostra_fila( f1, mostra_int );
	
	k = 9;
	inserir( &f1, &k );
	mostra_fila( f1, mostra_int );
	
	k = 12;
	inserir( &f1, &k );
	mostra_fila( f1, mostra_int );
	
	k = 15;
	inserir( &f1, &k );
	mostra_fila( f1, mostra_int );
	
	int x;
	remover( &f1, &x );
	mostra_fila( f1, mostra_int );
	printf("X = %d\n\n", x);
	
	remover( &f1, &x );
	mostra_fila( f1, mostra_int );
	printf("X = %d\n\n", x);
	
	k = 15;
	inserir( &f1, &k );
	mostra_fila( f1, mostra_int );
	
	k = 18;
	inserir( &f1, &k );
	mostra_fila( f1, mostra_int );
	
	desaloca_fila( &f1 );
	
	return 0;
}
