/* Busca Binária com Recursividade */ 

#include <stdio.h>
#include <stdlib.h>

int BuscaBinaria(int *vet, int x, int esq, int dir){
    int  m;
    m = (dir + esq)/2;
    printf("pivo %d\n", m);
    if (esq > dir)
        printf("Elemento não encontrado\n");
    else if (vet[m] == x)
        return m;
    else if(vet[m] < x){
        esq= m + 1;
        return BuscaBinaria(vet, x, esq, dir);
    }
    else if(vet[m] > x){
        dir = m-1;
        return BuscaBinaria(vet, x, esq, dir);
    }
    return -1;
}

int main(){
    int vet[] = {1, 2, 3, 5, 12, 14, 15, 21, 24, 45, 46, 47, 53, 86, 90, 98};
    int x = 90;
    printf("%d\n", BuscaBinaria(vet, x, 0, 15));
	
	return 0;
}
