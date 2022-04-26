#include <stdlib.h>
#include <stdio.h>
#include "matriz.h"

void inicializa_matriz(Matriz *p,int l,int c){
	int i,j;
	(*p).dados= malloc(sizeof(int *)*l);
	for(i=0;i<l;i++){
		(*p).dados[i] = malloc(sizeof(int)*c);
		for(j=0; j<c;j++){
			(*p).dados[i][j] = 0;
		}
	}
	(*p).lin = l;
	(*p).col = c;
}

void mostra_matriz(Matriz *x){
	printf("Dados da Matriz (%dx%d):\n",(*x).lin,(*x).col);
	int i,j;
	for(i=0;i< (*x).lin; i++){
		for(j=0;j< (*x).col; j++){
			printf("%4i ", (*x).dados[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void desaloca_matriz(Matriz *y){
	int i;
	for(i=0; i<(*y).lin ;i++){
		free((*y).dados[i]);
	}
	free((*y).dados);
}

int set_valor(Matriz *z, int l, int c, int valor){
	if (l>=(*z).lin || c>=(*z).col)
		return COORDENADA_INVALIDA;
	(*z).dados[l][c] = valor;
	return 0;
}
