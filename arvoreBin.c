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
	
	if (valor < raiz->info){ 
	   	raiz->esq = Inserir (valor, raiz->esq);
	   	return raiz;
	}

	if (valor > raiz->info){
		raiz->dir = Inserir (valor, raiz->dir);
		return raiz;
	}  
}

TipoDado NoMaior (No *x){
	TipoDado maior;
	No *aux;

	if (!Vazia(x->dir))
		return NoMaior (x->dir); // Continua procurando pelo maior elemento 
	
	aux = x;
	maior = x->info;
	x = x->esq; // Filho a esquerda passa a ser o pai
	free (aux); 
	return maior; 
}

void Remover (TipoDado x, No *raiz){
	No *aux;
	
	if(!Vazia (raiz)){		
		if(raiz->info == x){
			aux = raiz;
			
			if (Vazia (raiz->esq) && Vazia (raiz->dir)){ // Folha
				raiz = NULL;
				free (raiz);			
			}
			else if (Vazia (raiz->esq)){ // Filho unico a direita
				raiz = raiz->dir;
				free (aux);
			}
			
			else if (Vazia(raiz->dir)){ //Filho unico a esquerda
				raiz = raiz->esq;
				free (aux);
			}
			
			else // Filho a direita e a esquerda, coloca o maior elemento na subarvore a esquerda
				raiz->info = NoMaior (raiz->esq);
		}
		
		else if (raiz->info < x) // x está na subarvore a direita
			Remover (x, raiz->dir);
		
		else if (raiz->info > x) // x está na subarvore a esquerda
			Remover (x, raiz->esq);
	}

	else printf("Elemento não encontrado\n");
} 		

int Vazia (No *raiz){
	return raiz == NULL;
}

No* BuscaBinaria (TipoDado x, No *raiz){
	if (Vazia(raiz)) 
		return NULL;
	
	if (raiz->info > x) // x está na subarvore a esquerda
	    return BuscaBinaria (x, raiz->esq);
	
	if (raiz->info < x) // x está na subarvore a direita
		return BuscaBinaria (x, raiz->dir);
	
	return raiz;
}

TipoDado MostrarInfo (TipoDado x, No *raiz){
	if(Vazia (raiz))
		return -1;
    
    return raiz->info == x || MostrarInfo (x, raiz->esq) || MostrarInfo (x, raiz->dir); 
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