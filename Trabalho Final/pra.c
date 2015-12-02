#include <stdio.h>
#include <stdlib.h>
#include "pra.h"

void Comprimir(){

}

void Descomprimir(){

}

void Huffman(InfoTexto info){

}  

InfoTexto LerArquivo (char *arquivo){
	FILE *fp;
	char c;
	fp = fopen(arquivo, "r");

	if(fp == NULL){
		exit(1);
	}

	while((c = fgetc(fp) != EOF){
		putchar(c);


	}




	fclose(fp);
	
}




