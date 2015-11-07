#include <stdio.h>
#include <stdlib.h>
#include "arvoreBin.h"

No *Inicializar(){
	return NULL;
}

No *Criar (TipoDado valor, No *esq, No *dir) {
	No *no;
	no = (No *) malloc (sizeof(No));
	if (no == NULL){
		printf("Erro ao Criar\n");
		exit(1);
	} 
	no->esq = esq;
	no->dir = dir;
	no->info = valor;
	return no;
}

No *Inserir (TipoDado valor, No *raiz){
	if (Vazia(raiz)){
		raiz = Criar (valor, NULL, NULL);
		return raiz;
	}
	if (valor < raiz->info) 
	   	raiz->esq = Inserir (valor, raiz->esq);
	else if (valor > raiz->info)  
		raiz->dir = Inserir (valor, raiz->dir);
	return raiz;
}

No *Remover (TipoDado x, No *raiz){
	
	if(Vazia(raiz)){
		printf("Nao existe o valor \n");
		return NULL;
	}
	//remocao de folha
    //remocao de pai de filho unico
    //remocao de pai de dois filhos


}



int Vazia (No *raiz){
	return raiz == NULL;
}

No* BuscaBinaria (TipoDado x, No *raiz){
	if (Vazia(raiz)) 
		return NULL;
	if (raiz->info > x) 
	    return BuscaBinaria (x, raiz->esq);
	if (raiz->info < x)  
		return BuscaBinaria (x, raiz->dir);
	return raiz;
}

void PreOrdem (No *raiz){
	if(!Vazia(raiz)){
		printf("%d ", raiz->info);
		PreOrdem (raiz->esq);
		PreOrdem (raiz->dir);
	}
}

void EmOrdem (No *raiz){
	if(!Vazia(raiz)){
		EmOrdem (raiz->esq);
		printf("%d \n", raiz->info);
		EmOrdem (raiz->dir);
	}
}	

void PosOrdem (No *raiz){
	if(!Vazia(raiz)){
		PosOrdem (raiz->esq);
		PosOrdem (raiz->dir);
		printf("%d ", raiz->info);
	}
}

TipoDado Maior (TipoDado a, TipoDado b){
	return (a>b)? a:b;
}

int Altura (No *raiz){
   	if((Vazia (raiz)) || ( Vazia (raiz->esq) && Vazia (raiz->dir)))
       return 0;
   	return 1 + Maior(Altura(raiz->esq), Altura(raiz->dir));
}

int QuantidadeNos (No *raiz){
	if(Vazia(raiz))
		return 0;
	return 1 + QuantidadeNos (raiz->esq) + QuantidadeNos (raiz->dir);
}

int QuantidadeFolhas (No *raiz){
	if(Vazia (raiz))
		return 0;
	if(Vazia (raiz->esq) && Vazia (raiz->dir))
		return 1;
	return QuantidadeFolhas (raiz->esq) + QuantidadeFolhas (raiz->dir); 
}

void Liberar(No *raiz){
	if (!Vazia(raiz)){
		Liberar (raiz->esq);
		Liberar (raiz->dir);
		free(raiz);
	}
}