#include <stdio.h>
#include <stdlib.h>
#include "ABP.h"
#include "FilaEncadeada.h"

void mostra_int(void *info);
int compara_int(void *a, void *b);

int main(int argc, char *argv[])
{
   ABP arvore;
   
   inicializa_ABP(&arvore, sizeof(int));
   percurso_em_ordem(arvore, mostra_int);
   //system("PAUSE");
   //system("CLS");
   
   int x = 10;
   printf("Inserindo %i...\n\n", x);
   insere_ABP(&arvore, &x, compara_int);
   mostra_estrutura(arvore, mostra_int);
   //system("PAUSE");
   //system("CLS");

   x = 5;
   printf("Inserindo %i...\n\n", x);
   insere_ABP(&arvore, &x, compara_int);
   mostra_estrutura(arvore, mostra_int);
   //system("PAUSE");
   //system("CLS");

   x = 8;
   printf("Inserindo %i...\n\n", x);
   insere_ABP(&arvore, &x, compara_int);
   mostra_estrutura(arvore, mostra_int);
   //system("PAUSE");
   //system("CLS");

   x = 7;
   printf("Inserindo %i...\n\n", x);
   insere_ABP(&arvore, &x, compara_int);
   mostra_estrutura(arvore, mostra_int);
   //system("PAUSE");
   //system("CLS");

   x = 20;
   printf("Inserindo %i...\n\n", x);
   insere_ABP(&arvore, &x, compara_int);
   mostra_estrutura(arvore, mostra_int);
   //system("PAUSE");
   //system("CLS");

   x = 15;
   printf("Inserindo %i...\n\n", x);
   insere_ABP(&arvore, &x, compara_int);
   mostra_estrutura(arvore, mostra_int);
   //system("PAUSE");
   //system("CLS");
   
   x = 25;
   printf("Inserindo %i...\n\n", x);
   insere_ABP(&arvore, &x, compara_int);
   mostra_estrutura(arvore, mostra_int);
   //system("PAUSE");
   //system("CLS");
   
   x = 7;
   printf("Removendo %i...\n\n", x);
   remove_ABP(&arvore, &x, compara_int);   
   mostra_estrutura(arvore, mostra_int);
   //system("PAUSE");
   //system("CLS");
   
   percurso_em_ordem(arvore, mostra_int);
   //system("PAUSE");
   //system("CLS");
   
   percurso_pre_ordem(arvore, mostra_int);
   //system("PAUSE");
   //system("CLS");
   
   percurso_pos_ordem(arvore, mostra_int);
   //system("PAUSE");
   //system("CLS");

   percurso_em_largura(arvore, mostra_int);
   //system("PAUSE");
   //system("CLS");

   int y;
   printf("Digite um valor:\n");
   scanf("%i", &y);
   printf("Buscando %i...\n\n", y);
   if(busca_APB(arvore, &y, compara_int))
      printf("%i encontrado!!\n\n", y);
   else
      printf("%i nao encontrado!!\n\n", y);
   //system("PAUSE");
   //system("CLS");

   printf("Limpando arvore...\n\n");
   limpa_ABP(&arvore);
   percurso_em_ordem(arvore, mostra_int);
   mostra_estrutura(arvore, mostra_int);

   printf("Fim da demosntracao.\n\n");

   return 0;
}

void mostra_int(void *info){
   int *p = (int *) info;
   printf("%i\n", *p);
   
}

int compara_int(void *a, void *b){
    int *pa = (int *) a;
    int *pb = (int *) b;
    
    if(*pa > *pb)
       return 1;

    if(*pa < *pb)
       return -1;

    return 0;

}
