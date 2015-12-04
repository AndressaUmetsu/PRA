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
	int t = TotalSimbolos-1;

	inicializa_lista(&SubArvore, sizeof(ABP));

	while(!listaVazia(&Frequencia)){
		removeNaPosicao(&Frequencia, &aux, ProcuraMaior());
		sub = CriarFolhas(&aux);
		insereNoInicio(&SubArvore, &sub);	
	}
	

	while(t > 1){
		sub = CriarSubArvore();
		insereNoInicio(&SubArvore, &sub);
		//mostra_lista(SubArvore, MostraLista);
		t--;
	}
	//mostra_lista(SubArvore, MostraLista);
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
	ABP a1, a2;
	ABP an;
	Info *aux1, *aux2, *auxn;
	NoABP *no, *no2, *noR; 

	auxn = malloc(sizeof(Info));

	removeDoInicio(&SubArvore, &a1);
	
	mostra_estrutura(a1, MostraInfo);
	
	no = a1.raiz;
	aux1 = (Info*) (no->info);

	removeDoInicio(&SubArvore, &a2);

	mostra_estrutura(a2, MostraInfo);

	no2 = a2.raiz;
	aux2 = (Info *) (no2->info);
	
	inicializa_ABP(&an, sizeof(Info)); 

	auxn->nSimbolo = (aux1->nSimbolo) + (aux2->nSimbolo);
	MostraInfo(&auxn);
	insere_ABP(&an, &auxn , ComparaInfo);
	//mostra_estrutura(an, MostraInfo);
	insere_ABP(&an, no->info, ComparaInfo);
	//mostra_estrutura(an, MostraInfo);
	insere_ABP(&an, no2->info, ComparaInfo);
	mostra_estrutura(an, MostraInfo);
	limpa_ABP(&a1);
	limpa_ABP(&a2);
	return an;
}
 
ABP CriarFolhas(Info *aux){
	ABP subArvore;

	inicializa_ABP(&subArvore, sizeof(Info)); 
	insere_ABP(&subArvore, aux, ComparaInfo);
	return subArvore;
} 

int ComparaInfo(void *a, void *b){
	Info *pa = (Info *) a;
    Info *pb = (Info *) b;
    
    if(pa->nSimbolo > pb->nSimbolo)
       return 1;

    if(pa->nSimbolo < pb->nSimbolo)
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

