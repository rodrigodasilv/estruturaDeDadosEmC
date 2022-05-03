#include "stdio.h"
#include "stdlib.h"

void calcula_circulo(float raio, float *pPerimetro, float *pArea){
	*pPerimetro = 2*3.14*raio;
	*pArea = 3.14*(raio*raio);	
}


int main(){
	float raio;
	float pPerimetro, pArea;
	scanf("%f", &raio);
	calcula_circulo(raio,&pPerimetro,&pArea);
	printf("Perimetro = %f Area = %f", pPerimetro, pArea);
	return 0;
}
