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
	Elemento *aux = Frequencia->cabeca;
	
	while(aux != NULL){
		CriarFolhas(&aux);
	
		aux = aux->proximo;
	}




}  

void CriarFolhas(Elemento *no){
	ABP aux;
	inicializa_ABP(&aux, sizeof(no));
	insere_ABP(&aux, no, );

}


int CompararInfo(void *a, void *b){
	Info *aux1 = (Info*) a;
    Info *aux2 = (Info*) b;
   	
   	
   	return ;



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
	printf("%d\n", TotalSimbolos);
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

