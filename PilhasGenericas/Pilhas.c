#include "Pilhas.h"
#include "string.h"

void inicializa_pilha ( PilhaGenerica *p, int c,int t ){
	p->topo = -1;
	p->dados = malloc(sizeof(void*)*c);
	p->capacidade = c;
	p->tamInfo = t;
}

int pilha_vazia ( PilhaGenerica p ) {
	return p.topo == -1;
}

int pilha_cheia ( PilhaGenerica p ) {
	return p.topo == p.capacidade - 1;
}

void desaloca_pilha(PilhaGenerica *p){
	free(p->dados);
}

int empilha ( PilhaGenerica *p, void* info ) {
	if( pilha_cheia ( *p ) )
		return ERRO_PILHA_CHEIA;
	p->topo++;
	p->dados[p->topo] = malloc(p->tamInfo);
	memcpy(p->dados[p->topo], info, p->tamInfo);
	//p->dados[p->topo] = info;
	return 1; // Sucesso
}

int desempilha ( PilhaGenerica *p, void *info ) {
	if ( pilha_vazia ( *p ) )
		return ERRO_PILHA_VAZIA;
	
	memcpy(info,p->dados[p->topo],p->tamInfo);
	free(p->dados[p->topo]);
	//*info = p->dados[p->topo];
	p->topo--;
	return 1; // Sucesso
}

int le_topo ( PilhaGenerica p, int *info ) {
	if ( pilha_vazia( p ) )
		return ERRO_PILHA_VAZIA;
	*info = p.dados[p.topo];
	return 1; // Sucesso
}

void mostra_pilha ( PilhaGenerica p ) {
	if( pilha_vazia ( p ) )
		printf("Pilha Generica vazia!\n");
	else{
		printf("Dados da Pilha Generica:\n");
		int i;
		for(i=0; i <= p.topo; i++)
			printf("%d\n", p.dados[i]);
		}
}
