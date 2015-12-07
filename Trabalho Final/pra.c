#include <stdio.h>
#include <stdlib.h>
#include "pra.h"
#include "Lista.h"
#include "ABP.h"

/*http://www2.unitins.br/BibliotecaMidia/Files/Documento/AVA_633682985082488750aula_6.pdf*/


void Comprimir(){

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
	

	//sub = CriarSubArvore();


	
	while(t > 1){
		sub = CriarSubArvore();
		insereNoInicio(&SubArvore, &sub);
		t--;
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

	







	ABP aEsq, aDir, aRaiz, subArvore;
	Info *iEsq, *iDir, *iRaiz;
	NoABP *noEsq, *noDir, *noRaiz; 

	// SubArvore Esquerda
	removeDoInicio(&SubArvore, &aEsq);	
	noEsq = aEsq.raiz;
	iEsq = (Info*) (noEsq->info);

	//SubArvore Direita
	removeDoInicio(&SubArvore, &aDir);
	noDir = aDir.raiz;
	iDir = (Info *) (noDir->info);
	
	//Cria raiz A
	inicializa_ABP(&aRaiz, sizeof(Info)); 
	
	iRaiz = malloc(sizeof(Info));	
	iRaiz->nSimbolo = (iEsq->nSimbolo) + (iDir->nSimbolo);
		
	// insere info na raiz A
	insere_ABP(&aRaiz, iRaiz , ComparaInfo);

	//****** Criar subarvore **********
	//inicializa_ABP(&subArvore, sizeof(ABP));
	
	// insere raiz 
	//insere_ABP(&subArvore, iRaiz, ComparaInfo);
	noRaiz = aRaiz.raiz;

	// insere subarvore esquerda	
	noRaiz->esq = aEsq.raiz;

	/*Lado = ESQUERDA;
	insere_ABP(&subArvore, iEsq, ComparaInfo);*/

	// insere subarvore direita
	noRaiz->dir = aDir.raiz;
	/*Lado = DIREITA;
	insere_ABP(&subArvore, iDir, ComparaInfo);*/

	//mostra_estrutura(subArvore, MostraInfo);

	limpa_ABP(&aEsq);
	limpa_ABP(&aDir);
	return aRaiz;
}
 
ABP CriarFolhas(Info *aux){
	ABP subArvore;

	inicializa_ABP(&subArvore, sizeof(Info)); 
	insere_ABP(&subArvore, aux, ComparaInfo);
	return subArvore;
} 

int ComparaInfo(void *a, void *b){
	if(Lado == DIREITA)
       return 1;

    if(Lado == ESQUERDA)
       return -1;

    return 0;
}

void MostraInfo(void *info){
	Info *p = (Info *) info;
	printf("nSimbolo %d simbolo %c\n", p->nSimbolo, p->simbolo);
}

void MostraLista(void *info){
	ABP *p = (ABP *) info;
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

	while((c = fgetc(fp)) != EOF)
		InserirSimbolo(c);
	
	mostra_lista(Frequencia, Imprimir);
	printf("Tota simbolo %d\n", TotalSimbolos);
	fclose(fp);
}

void InserirSimbolo(char c){
	Info aux;
	int pos;
	aux.simbolo = c;
	if ((pos = elementoExiste(&Frequencia, &aux, CompararSimbolo)) != -1){
		aux.nSimbolo++;
		modificaNaPosicao(&Frequencia, &aux, pos);
	}else{
		TotalSimbolos++;
		aux.nSimbolo = 1;
		insereNoFim(&Frequencia, &aux);
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

