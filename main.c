#include <stdio.h>
#include <stdlib.h>
#include "arvoreBin.h"

int main(int argc, char const *argv[])
{
	No *arvore, *b;
	arvore = Inicializar();
    Inserir (50, &arvore);
    Inserir (40, &arvore);
    Inserir (60, &arvore);
    Inserir (35, &arvore);
    Inserir (45, &arvore);
    Inserir (70, &arvore);
    //arvore = Inserir (5, arvore);
    PreOrdem (arvore);
    printf("\n");
    Remover (60, &arvore);
    /*b = BuscaBinaria (11, arvore);
    if (b != NULL)
		printf ("\n\nValor 11 encontrado\n");
    b = BuscaBinaria (12, arvore);
    if (b == NULL)
    	printf ("Valor 12 nao encontrado\n");
    printf("Altura = %d \n",Altura(arvore));
    printf("nos = %d \n",QuantidadeNos(arvore));
    printf("folhas = %d \n",QuantidadeFolhas(arvore));*/
    //arvore = Inserir (4, arvore);
    //arvore = Inserir (8, arvore);
    //arvore = Inserir (15, arvore);
    //arvore = Inserir (12, arvore);
    PreOrdem (arvore);

    /*b = BuscaBinaria (12, arvore);
    if (b != NULL)
    	printf ("Valor 12 encontrado\n");
*/
    Liberar(arvore);
	return 0;
}
