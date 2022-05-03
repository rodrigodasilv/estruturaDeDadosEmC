#include "stdio.h"
#include "stdlib.h"

void troca_valor(float *x, float *y){
	float troca = *x;
	*x = *y;
	*y = troca;
}

int main(){
	float x, y;
	scanf("%f", &x);
	scanf("%f", &y);
	printf("A = %f | B = %f\n", x, y);
	troca_valor(&x,&y);
	printf("A = %f | B = %f\n", x, y);
	return 0;
}
