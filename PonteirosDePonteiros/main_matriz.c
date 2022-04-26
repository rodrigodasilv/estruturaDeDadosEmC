#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main(int argc, char *argv[]) {
	Matriz m;
	inicializa_matriz(&m ,5 , 6);
	mostra_matriz(&m);
	
	
	char resposta;
	do{
		int x, y, valor;
		printf("Digite o valor: ");
		scanf("%d", &valor);
		printf("Digite as coordenadas (x,y): ");
		scanf("%d%d", &x,&y);
		if (set_valor(&m, x, y, valor)==COORDENADA_INVALIDA){
			printf("Coordenada invalida!\n");
		}else{
			printf("Novo estado da matriz: \n");
			mostra_matriz(&m);	
		}
		printf("Deseja inserir mais um valor? (S \\ N)");
		scanf(" %c",&resposta);
		system("CLS");
	}while(resposta=='S');
	desaloca_matriz(&m);
	return 0;
}
