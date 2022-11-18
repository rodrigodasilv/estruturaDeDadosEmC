#include "arvoreB.h"

ArvoreB* criaArvore(int ordem) {
    ArvoreB* a = malloc(sizeof(ArvoreB));
    a->ordem = ordem;    
	a->raiz = criaNo(a);
	return a;
}

No* criaNo(ArvoreB* arvore) {
	int max = arvore->ordem * 2;    
	No* no = malloc(sizeof(No));    
	no->pai = NULL;    
	no->chaves = malloc(sizeof(int) * (max + 1));    
	no->filhos = malloc(sizeof(No) * (max + 2));    
	no->total = 0;
	for (int i = 0; i < max + 2; i++)        
		no->filhos[i] = NULL;
	return no;
}
	
void percorreArvore(No* no, void (visita)(int chave)) {
	if (no != NULL) {
		for (int i = 0; i < no->total; i++){
	        percorreArvore(no->filhos[i], visita);            
			visita(no->chaves[i]);        
		}        
	percorreArvore(no->filhos[no->total], visita);    
	}
}

int localizaChave(ArvoreB* arvore, int chave) {
    No *no = arvore->raiz;
	while (no != NULL) {
		int i = pesquisaBinaria(no, chave);
		if (i < no->total && no->chaves[i] == chave) {
			return1; //encontrou        
		}else{
            no = no->filhos[i];        
		}    
	}
	return 0; //n�o encontrou
}

int pesquisaBinaria(No* no, int chave) {
	int inicio = 0, fim = no->total - 1, meio;
	while (inicio <= fim) {
        meio = (inicio + fim) / 2;
		if (no->chaves[meio] == chave) {
			return meio; //encontrou        
		}else if (no->chaves[meio] > chave) {            
			fim= meio - 1;        
		} else {            
			inicio = meio + 1;        
		}    
	}
	return inicio; //n�o encontrou
}

No* localizaNo(ArvoreB* arvore, int chave) {
	    No *no = arvore->raiz;
		while (no != NULL) {
			int i = pesquisaBinaria(no, chave);
			if (no->filhos[i] == NULL)
				return no; //encontrou n�
			else            
				no = no->filhos[i];    
		}
	return NULL; //n�o encontrou nenhum n�
}

void adicionaChaveNo(No* no, No* direita, int chave) {
	int i = pesquisaBinaria(no, chave);
	for (int j = no->total - 1; j >= i; j--) {
        no->chaves[j + 1] = no->chaves[j];        
		no->filhos[j + 2] = no->filhos[j + 1];    
	}    
	no->chaves[i] = chave;    
	no->filhos[i + 1] = direita;    
	no->total++;
}

int transbordo(ArvoreB *arvore, No *no) {
	return no->total > arvore->ordem * 2;
}

No* divideNo(ArvoreB* arvore, No* no) {
	int meio = no->total / 2;    
	No* novo = criaNo(arvore);    
	novo->pai = no->pai;
	for (int i = meio + 1; i < no->total; i++) {        
		novo->filhos[novo->total] = no->filhos[i];        
		novo->chaves[novo->total] = no->chaves[i];
		if (novo->filhos[novo->total] != NULL) 
			novo->filhos[novo->total]->pai = novo;        
		novo->total++;    
	}    
	novo->filhos[novo->total] = no->filhos[no->total];
	if (novo->filhos[novo->total] != NULL) 
		novo->filhos[novo->total]->pai = novo;     
	no->total = meio;
	return novo;
}

void adicionaChave(ArvoreB* arvore, int chave) {    
	No* no = localizaNo(arvore, chave);    
	adicionaChaveRecursivo(arvore, no, NULL, chave);
}

void adicionaChaveRecursivo(ArvoreB* arvore, No* no, No* novo, int chave) {    
	adicionaChaveNo(no, novo, chave);
	if (transbordo(arvore, no)) {
		int promovido = no->chaves[arvore->ordem];        
		No* novo = divideNo(arvore, no);
		if (no->pai == NULL) {            
			No* raiz = criaNo(arvore);             
			raiz->filhos[0] = no;            
			adicionaChaveNo(pai, novo, promovido);            
			no->pai = raiz;            
			novo->pai = raiz;            
			arvore->raiz = raiz;        
		} else            
			adicionaChaveRecursivo(arvore, no->pai, novo, promovido);    
	}
}
