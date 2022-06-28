#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LDE.h"

//Privado------------------------

EleDuplo *aloca_elemento( void *info, int tam ) {
	EleDuplo *p = malloc( sizeof(EleDuplo) );
	if( p == NULL )
		return NULL; // Erro, falta de memória!
	p->info = malloc( tam );
	if( p->info == NULL ){
		free(p);
		return NULL; // Erro, falta de memória!
	}
	memcpy(p->info, info, tam);
	return p; // Sucesso!
}

//-------------------------------


void inicializa_lista( LDE *p, int t ){
	p->tamInfo = t;
	p->cabeca = NULL;
	p->qtd = 0;
}

int lista_vazia ( LDE l ){
	return l.cabeca == NULL;
}

int insere_inicio( LDE *p, void *info ){
	EleDuplo *novo = aloca_elemento( info, p->tamInfo );
	if( novo == NULL )
		return 0; // Erro, falta de memória!

	novo->suc = p->cabeca;
	p->cabeca = novo;
	p->qtd++;
	novo->ant = NULL;
 	if( novo->suc != NULL )
 		novo->suc->ant = novo;
	return 1; // Sucesso!
}

int remove_inicio( LDE *p, void *info ){
	if( lista_vazia( *p ) )
		return ERRO_LISTA_VAZIA;

	EleDuplo *aux = p->cabeca;
	memcpy( info, aux->info, p->tamInfo );
	p->cabeca = aux->suc;
	free( aux->info );
	free( aux );
	p->qtd--;
	if( p->cabeca != NULL )
 		p->cabeca->ant = NULL;
	return 1; // Sucesso!
}

int insere_fim( LDE *p, void *info ){
	if( lista_vazia( *p ) )
		return insere_inicio( p, info );

	EleDuplo *aux = p->cabeca;
	while( aux->suc != NULL )
		aux = aux->suc;

	EleDuplo *novo = aloca_elemento( info, p->tamInfo );
	if( novo == NULL )
    	return 0; // Erro, falta de memória!

	aux->suc = novo;
	novo->ant = aux;
	novo->suc = NULL;
	p->qtd++;
	return 1; // Sucesso!
}

int remove_fim( LDE *p, void *info ){
   if( lista_vazia( *p ) )
      return ERRO_LISTA_VAZIA;
   if( p->qtd == 1 )
      return remove_inicio( p, info );
   EleDuplo *aux = p->cabeca;
   while( aux->suc->suc != NULL )
      aux = aux->suc;
   EleDuplo *ultimo = aux->suc;
   memcpy( info, ultimo->info, p->tamInfo );
   free( ultimo->info );
   free( ultimo );
   aux->suc = NULL;
   p->qtd--;
   return 1; // Sucesso!
}

int insere_pos( LDE *p, void *info , int pos ){
	if( pos < 0 || pos > p->qtd )
		return ERRO_POS_INVALIDA;
		
	if( pos == 0 )
		return insere_inicio( p, info );
	
	EleDuplo *aux = p->cabeca;
	int cont;
	for( cont = 0 ; cont < pos-1 ; cont++ )
		aux = aux->suc; // Vai até EleDuplo em pos-1
	
	EleDuplo *novo = aloca_elemento( info, p->tamInfo );
	if( novo == NULL )
		return 0; // Erro, falta de memória!
	
	novo->suc = aux->suc;
	aux->suc = novo;
	if(aux!=NULL)
		novo->ant = aux;	
	p->qtd++;
	return 1; // Sucesso!
}

int remove_pos( LDE *p, void *info , int pos ){
	if( lista_vazia( *p ) )
		return ERRO_LISTA_VAZIA;

	if( pos < 0 || pos >= p->qtd )
		return ERRO_POS_INVALIDA;
	
	if( pos == 0 )
		return remove_inicio( p, info );

	EleDuplo *aux = p->cabeca;
	int cont;
	for( cont = 0 ; cont < pos-1 ; cont++ )
		aux = aux->suc; // Vai até pos-1
	
	EleDuplo *x = aux->suc;
	aux->suc = x->suc;
	if(aux!=NULL)
		x->ant=aux;
	memcpy( info, x->info, p->tamInfo );
	free( x->info );
	free( x );
	p->qtd--;
	return 1; // Sucesso!
}

int le_valor( LDE l, void *info , int pos ){
	if( lista_vazia( l ) )
		return ERRO_LISTA_VAZIA;

	if( pos < 0 || pos >= l.qtd )
		return ERRO_POS_INVALIDA;
		
	EleDuplo *aux = l.cabeca;
	int cont;
	for( cont = 0 ; cont < pos ; cont++ )
		aux = aux->suc; // Vai até EleDuplo em pos
	
	memcpy( info, aux->info, l.tamInfo );
	return 1; // Sucesso!
}

int modifica_valor( LDE l, void *info , int pos ){
	if( lista_vazia( l ) )
		return ERRO_LISTA_VAZIA;

	if( pos < 0 || pos >= l.qtd )
		return ERRO_POS_INVALIDA;
		
	EleDuplo *aux = l.cabeca;
	int cont;
	for( cont = 0 ; cont < pos ; cont++ )
		aux = aux->suc; // Vai até EleDuplo em pos
	
	memcpy( aux->info, info, l.tamInfo );
	return 1; // Sucesso!
}

void mostra_lista( LDE l, void (*mostra)(void *) ){
	if( lista_vazia( l ) )
		printf("LDE vazia!\n");
	else{
		printf("Dados da LDE (%d elementos):\n", l.qtd );
		EleDuplo *p = l.cabeca;
		int cont = 0; // cont é o índice do EleDuplo dentro da LDE.
		while( p != NULL ){
			printf("[%d] ", cont);
			mostra( p->info ); // Invocação por callback
			p = p->suc;
			cont++;
		}
	}
	printf("--------------------------------\n");
}

int conta_elementos( LDE l ){
	int cont = 0;
	EleDuplo *p = l.cabeca;
	while( p != NULL ){
		cont++;
		p = p->suc;
	}
	return cont;
}

void limpa_lista( LDE *l ){
	EleDuplo *p = l->cabeca;
	while( p != NULL ){
		EleDuplo *prox = p->suc;
		free( p->info );
		free( p );
		p = prox;
	}
	l->cabeca = NULL;
	l->qtd = 0;
}

void mostra_listra_invertida_v2( LDE l, void (*mostra)(void *) ){
	if( lista_vazia( l ) )
		printf("LDE vazia!\n");
	else{
		printf("Dados da LDE invertida (%d elementos):\n", l.qtd );
		EleDuplo *p = l.cabeca;
		int cont = 0; // cont é o índice do EleDuplo dentro da LDE.
		
		while( p->suc != NULL ){
			p = p->suc;
			cont++;
		}
		while(p != NULL){
			printf("[%d] ", cont);
			mostra( p->info ); // Invocação por callback
			p = p->ant;
			cont--;
		}
	}
	printf("--------------------------------\n");
}


int insere_ordem( LDE *p, void *info, int (*compara)(void*, void*) ){
	EleDuplo *aux = p->cabeca;
	int cont = 0;
	while( aux != NULL && compara( info, aux->info ) > 0 ){
		aux = aux->suc;
		cont++;
	}
	return insere_pos( p, info, cont );
}

void concatena( LDE *l1, LDE *l2 ){
	EleDuplo *aux = l1->cabeca;
	if( aux != NULL){
		while( aux->suc != NULL)
			aux = aux->suc;
		aux->suc = l2->cabeca;
	}
	else
		l1->cabeca = l2->cabeca;
	
	l2->cabeca = NULL;
	l1->qtd += l2->qtd;
	l2->qtd = 0;	
}

void concatena_v2( LDE *l1, LDE *l2 ){
	void *info = malloc( l2->tamInfo );
	int i;
	for( i = 0; le_valor( *l2, info, i ) != ERRO_POS_INVALIDA; i++ ){
		insere_fim( l1, info );
	}
	limpa_lista( l2 );
	free( info);
}


void percorre( EleDuplo *p, int idc, void (*mostra)(void *) ){
	if( p != NULL ){
		percorre( p->suc, idc+1, mostra );
		printf("[%d] ", idc);
		mostra( p->info );
	}
}

void mostra_lista_invertida( LDE l, void (*mostra)(void *) ){
	if( lista_vazia( l ) )
		printf("LDE vazia!\n");
	else{
		printf("Dados da LDE invertida (%d elementos):\n", l.qtd );
		percorre( l.cabeca, 0, mostra );
	}
	printf("--------------------------------\n");	
}

