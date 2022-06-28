#include "Produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void le_produto( Produto *p ){
	printf("Digite o codigo: ");
	scanf("%d", &p->codigo);
	printf("Digite a descricao: ");
	scanf(" %[^\n]", p->descricao);
	printf("Digite o preco: ");
	scanf("%f", &p->preco);
}

void inicializa_produto( Produto *p, int c, char *d, float pr ){
	p->codigo = c;
	strcpy( p->descricao, d );
	p->preco = pr;
}

void mostra_produto( Produto x ){
	printf("(%d, %s, %.2f)\n", x.codigo, x.descricao, x.preco );
}

int busca_produto( Produto *v, int n, int codigo ){
	int i;
	for( i = 0 ; i < n ; i++ ){
		if( v[i].codigo == codigo )
			return i; // Encontrou no índice i
	}
	return -1; // Não encontrou
}

int * busca_produtos_por_preco( Produto *v, int n, float preco ){
	int i, cont = 0;
	for( i = 0 ; i < n ; i++ ){
		if( v[i].preco == preco )
			cont++;
	}

	int *p = malloc( sizeof(int) * (cont+1) );
	int j = 0;
	for( i = 0 ; i < n ; i++ ){
		if( v[i].preco == preco ){
			p[j] = i;
			j++;
		}
	}
	p[j] = -1;
	return p;
}

int carrega_arquivo( char *nome_arq, Produto **pV, int *pN ){
	FILE *f = fopen( nome_arq, "rt");
	if( f == NULL ){
		return 0; // Erro!
	}
	int n;
	fscanf(f, "%d", &n);
	Produto *v = malloc( sizeof(Produto) * n );
	int i;
	for( i = 0 ; i < n ; i++ ){
		fscanf(f, "%d", &v[i].codigo);
		fscanf(f, " %[^\n]", v[i].descricao);
		fscanf(f, "%f", &v[i].preco);
	}
	fclose( f );
	*pV = v;
	*pN = n;
	return 1; // Sucesso!
} 



