#include <stdio.h>
#include <stdlib.h>
#include "pra.h"
#include "Lista.h"
#include "ABP.h"

void Comprimir(char *arquivo){
	FILE *texto;
	char c; 
	
	texto = fopen(arquivo, "r");

	if(texto == NULL){
		exit(1);
	}

	/*while((c = fgetc(texto)) != EOF){
		busca_APB(Arvore, c, ComparaInfo);

	}*/
	
}


int ComparaInfo(void *a, void *b){
	if(Lado == DIREITA)
       return 1;

    if(Lado == ESQUERDA)
       return -1;

    return 0;
}

void Descomprimir(){

}

void Huffman(){
	Info aux;
	ABP sub;	
	int t = TotalSimbolos;
	inicializa_lista(&SubArvore, sizeof(ABP));

	while(!listaVazia(&Frequencia)){
		removeNaPosicao(&Frequencia, &aux, ProcuraMaior());
		sub = CriarFolhas(&aux);
		insereNoInicio(&SubArvore, &sub);	
	}
		
	while(t > 1){
		sub = CriarSubArvore();
		insereNoInicio(&SubArvore, &sub);
		t--;
	}
	removeDoInicio(&SubArvore, &Arvore);
	mostra_estrutura(Arvore, MostraInfo);
}  

void GerarCodigo(NoABP *a, char *codAnterior){
	int lado;
	char codigoNovo[32];

	if (a->esq != NULL){
		lado = ESQUERDA;
		codigoNovo = Codigo(a, codAnterior, lado);
		GerarCodigo(a->esq, codigoNovo);
	}
	if (a->dir != NULL)
		lado = DIREITA;
		codigoNovo = Codigo(a, codAnterior, lado);
		GerarCodigo(a->dir, codigoNovo);
	}
} 

void Codigo(NoABP *no, char *codAnterior, int lado){
	Info *aux;
	if (lado == ESQUERDA){
		aux = (Info *) (no->info);
		printf("%s\n",aux->codigo);
		strcat(codAnterior, "1");
		printf("%s\n",codAnterior);
		strcpy(aux->codigo, codAnterior);
		printf("%s\n",aux->codigo);
	}

	if (lado == DIREITA){
		aux = (Info *) (no->info);
		printf("%s\n",aux->codigo);
		strcat(codAnterior, "0");
		printf("%s\n",codAnterior);
		strcpy(aux->codigo, codAnterior);
		printf("%s\n",aux->codigo);
	} 
}

int ProcuraMaior(){
	Info *aux;
	Elemento *p;
	int i = 0, pos = 0, maior;
	
	p = Frequencia.cabeca;
	aux = (Info *) (p->info);
	maior = aux->nSimbolo;

	while (p->proximo != NULL){
	    p = p->proximo;
		i++;
		aux = (Info *) (p->info);
		if (maior <= aux->nSimbolo){
			maior = aux->nSimbolo;
			pos = i;
		}
	}
	return pos;
}

ABP CriarSubArvore(){
	ABP aEsq, aDir, aRaiz;
	Info *iEsq, *iDir, *iRaiz;
	NoABP *noEsq, *noDir, *noRaiz; 

	Nbits++;

	// SubArvore Esquerda
	removeDoInicio(&SubArvore, &aEsq);	
	noEsq = aEsq.raiz;
	iEsq = (Info*) (noEsq->info);

	//SubArvore Direita
	removeDoInicio(&SubArvore, &aDir);
	noDir = aDir.raiz;
	iDir = (Info *) (noDir->info);

	//Cria subarvore
	inicializa_ABP(&aRaiz, sizeof(Info)); 
	
	iRaiz = malloc(sizeof(Info));	
	iRaiz->nSimbolo = (iEsq->nSimbolo) + (iDir->nSimbolo);

	// insere info na raiz da subarvore
	insere_ABP(&aRaiz, iRaiz , ComparaInfo);

	noRaiz = aRaiz.raiz;

	// insere subarvore esquerda	
	noRaiz->esq = aEsq.raiz;
	// insere subarvore direita
	noRaiz->dir = aDir.raiz;
	
	return aRaiz;
}
 
ABP CriarFolhas(Info *aux){
	ABP subArvore;

	inicializa_ABP(&subArvore, sizeof(Info)); 
	insere_ABP(&subArvore, aux, ComparaInfo);
	return subArvore;
} 

void MostraInfo(void *info){
	Info *p = (Info *) info;
	printf("nSimbolo %d simbolo %c \n", p->nSimbolo, p->simbolo, p->cod);
}

void MostraLista(void *info){
	ABP *p = (ABP *) info;
	if (p != NULL)
		mostra_estrutura(*p, MostraInfo);
}

void LerArquivo (char *arquivo){
	FILE *fp;
	char c; 
	
	fp = fopen(arquivo, "r");

	if(fp == NULL){
		exit(1);
	}

	inicializa_lista(&Frequencia, sizeof(Info));
	inicializa_lista(&F, sizeof(Info));

	while((c = fgetc(fp)) != EOF)
		InserirSimbolo(c);
	
	mostra_lista(Frequencia, Imprimir);
	printf("Total simbolos %d\n", TotalSimbolos);
	fclose(fp);
}

void InserirSimbolo(char c){
	Info aux;
	int pos;
	aux.simbolo = c;
	if ((pos = elementoExiste(&Frequencia, &aux, CompararSimbolo)) != -1){
		aux.nSimbolo++;
		modificaNaPosicao(&Frequencia, &aux, pos);
		modificaNaPosicao(&F, &aux, pos);
	}else{
		TotalSimbolos++;
		aux.nSimbolo = 1;
		aux.codigo = "";
		insereNoFim(&Frequencia, &aux);
		insereNoFim(&F, &aux);
	} 
}

int CompararSimbolo(void *a, void *b){
   	Info *aux1 = (Info*) a;
    Info *aux2 = (Info*) b;
    if (aux1->simbolo == aux2->simbolo)
    	return 0;
	return 1;
}

void Imprimir(void* info){
	Info *aux = (Info*) info;
	printf("%c %d\n", aux->simbolo, aux->nSimbolo);
 }

