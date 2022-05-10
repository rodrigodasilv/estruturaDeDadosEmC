#define ERRO_PILHA_VAZIA -1
#define ERRO_PILHA_CHEIA -2
typedef struct{
	void **dados; // dados da pilha
	int topo, capacidade, tamInfo; // indica o índice do topo
} PilhaGenerica;

void inicializa_pilha ( PilhaGenerica *p, int c, int t );
int pilha_vazia ( PilhaGenerica p );
int pilha_cheia ( PilhaGenerica p );
void desaloca_pilha(PilhaGenerica *p);
int empilha ( PilhaGenerica *p, void *info );
int desempilha ( PilhaGenerica *p, void *info );
int le_topo ( PilhaGenerica p, int *info );
void mostra_pilha ( PilhaGenerica p );
