#include <stdio.h>
#include <stdlib.h>
#include "Pilhas.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	PilhaGenerica p1;
	
	inicializa_pilha(&p1,20,sizeof(float));
	
	float x = 3.5;
	empilha(&p1,&x);
	x = 7;
	empilha(&p1,&x);
	x = 10;
	empilha(&p1,&x);
	
	while(!pilha_vazia(p1)){
		float y;
		desempilha(&p1, &y);
		printf("%.2f\n", y);
	}
	
	return 0;
}
