#ifndef PRA_H_INCLUDE
#define PRA_H_INCLUDE

#include "Lista.h"
#include "ABP.h"

#define SUCESSO 1

typedef struct {
	int nSimbolo; 
	char simbolo;
}Info;

int TotalSimbolos;

Lista Frequencia;

Lista SubArvore;

void Comprimir();

void Descomprimir();

void Huffman();  

void LerArquivo (char arquivo[32]);

void InserirSimbolo(char c);

int CompararSimbolo(void *a, void *b);

void Imprimir(void* info);

#endif