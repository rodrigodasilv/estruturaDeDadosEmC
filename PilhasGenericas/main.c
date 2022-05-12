#include <stdio.h>
#include <stdlib.h>
#include "Pilhas.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void mostra_float(void *x){
	float *p = x;
	printf("%.2f\n", *p);
}


int main(int argc, char *argv[]) {
	PilhaGenerica p1;
	
	inicializa_pilha(&p1,20,sizeof(float));
	
	float x = 3.5;
	empilha(&p1,&x);
	x = 7;
	empilha(&p1,&x);
	x = 10;
	empilha(&p1,&x);
	
	mostra_pilha(p1,mostra_float);
	
	while(!pilha_vazia(p1)){
		float y;
		desempilha(&p1, &y);
		printf("%.2f\n", y);
	}
	
	desaloca_pilha(&p1);
	return 0;
}
