#ifndef PRA_H_INCLUDE
#define PRA_H_INCLUDE

typedef struct {
	int nSimbolos; 
	Lista *frequencia; 
}InfoTexto;



void Comprimir();

void Descomprimir();


void Huffman(int n, char vetor);  

InfoTexto LerArquivo (char arquivo[32]);

#endif