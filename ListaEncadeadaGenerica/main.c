#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeadaGenerica.h"

void mostra_float( void *x ){ // mostra um float...
	printf("%.2f\n", *(float *)x ); // a partir de um void*
}

int main(){
	Lista l1;
 	inicializa_lista( &l1 , sizeof(float) );
 	float x = 7.5, y;
 	insere_inicio( &l1 , &x );
 	x = 10;
 	insere_inicio( &l1 , &x );
 	//printf("Quantidade de elementos na lista: %i \n",conta_elementos(l1));
 	//remove_inicio( &l1 , &y );
 	//printf("valor removido: %.2f\n", y);
 	//mostra_lista( l1, mostra_float );
 	//printf("Quantidade de elementos na lista: %i \n",conta_elementos(l1));
 	//remove_inicio( &l1 , &y );
 	printf("Quantidade de elementos na lista: %i \n",conta_elementos(l1));
 	desaloca_lista(&l1);
 	printf("Quantidade de elementos na lista: %i \n",conta_elementos(l1));
}
