// Constantes de erro
#define ERRO_LISTA_VAZIA	-1
#define ERRO_POS_INVALIDA	-2

// EleDuplo de lista
typedef struct eleDuplo {
	void *info;
	struct eleDuplo *ant, *suc;
} EleDuplo;

// Cabeçalho de LDE
typedef struct {
	EleDuplo *cabeca;
	int tamInfo, qtd;
} LDE;

void inicializa_lista( LDE *p, int t );
int lista_vazia ( LDE l );
int insere_inicio( LDE *p, void *info );
int remove_inicio( LDE *p, void *info );
int insere_fim( LDE *p, void *info );
int remove_fim( LDE *p, void *info );
int insere_pos( LDE *p, void *info , int pos );
int remove_pos( LDE *p, void *info , int pos );
int le_valor( LDE l, void *info , int pos );
int modifica_valor( LDE l, void *info , int pos );
void mostra_lista( LDE l, void (*mostra)(void *) );
void limpa_lista( LDE *l );
int insere_ordem( LDE *p, void *info, int (*compara)(void*, void*) );
void concatena( LDE *l1, LDE *l2 );
void concatena_v2( LDE *l1, LDE *l2 );
void mostra_listra_invertida_v2( LDE l, void (*mostra)(void *) );

int conta_elementos( LDE l ); // Função inútil na prática, pois temos o campo 'qtd'.

