#ifndef PRA_H_INCLUDE
#define PRA_H_INCLUDE

#include "Lista.h"
#include "ABP.h"

#define SUCESSO 1
#define ESQUERDA 1
#define DIREITA	0

typedef struct {
	int nSimbolo; 
	char simbolo;
	char cod[32];
}Info;

int TotalSimbolos;

int Lado;

Lista Frequencia;

Lista F;

Lista SubArvore;

ABP Arvore;

int Nbits;

void Comprimir();

void Descomprimir();

void Huffman();

void GerarCodigo(NoABP *a);

void Codigo(char *codigo)

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