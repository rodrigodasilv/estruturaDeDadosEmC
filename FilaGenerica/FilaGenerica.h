#define ERRO_FILA_VAZIA - 1
#define ERRO_FILA_CHEIA - 1

typedef struct{
	void **dados;
	int inicio, n;
	int capacidade;
	int tamInfo;
}FilaGenerica;

void inicializa_fila( FilaGenerica *p , int c, int t );
int fila_vazia( FilaGenerica f );
int fila_cheia( FilaGenerica f );
int inserir( FilaGenerica *p, void *info );
int remover( FilaGenerica *p, void *info );
void mostra_fila( FilaGenerica f, void (*mostra)(void*) );
void desaloca_fila( FilaGenerica *p );

