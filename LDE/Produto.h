
typedef struct{
	int codigo;
	char descricao[20];
	float preco;
}Produto;

void le_produto( Produto *p );
void inicializa_produto( Produto *p, int c, char *d, float pr );
void mostra_produto( Produto x );
int busca_produto( Produto *v, int n, int codigo );
int * busca_produtos_por_preco( Produto *v, int n, float preco );
int carrega_arquivo( char *nome_arq, Produto **pV, int *pN );

