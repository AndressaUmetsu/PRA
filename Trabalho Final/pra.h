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

int ProcuraMaior();

ABP CriarSubArvore();

ABP CriarFolhas(Info *aux);

int ComparaInfo(void *a, void *b);

void MostraInfo(void *info);

void MostraLista(void *info);

void LerArquivo (char *arquivo);

void InserirSimbolo(char c);

int CompararSimbolo(void *a, void *b);

void Imprimir(void* info);

#endif