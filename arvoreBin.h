#ifndef ARVOREBIN_H_INCLUDE
#define ARVOREBIN_H_INCLUDE

typedef int TipoDado;

struct No {
	TipoDado info;
	struct No *esq;
	struct No *dir;
};
typedef struct No No;

No *Inicializar();

No *Criar (TipoDado valor, No *esq, No *dir);

No *Inserir (TipoDado valor, No *raiz);

int Vazia (No *raiz);

No *BuscaBinaria (TipoDado x, No *raiz);

void PreOrdem (No *raiz);

void EmOrdem (No *raiz);

void PosOrdem(No *raiz);

int Altura (No *raiz);

int QuantidadeNos (No *raiz);

int QuantidadeFolhas (No *raiz);

void Liberar(No *raiz);

#endif  
