#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pra.h"

int main(int argc, char *argv[])
{

	if (argc < 2){
		printf("Falta arquivo txt\n");
		exit(1);
	} 
	
	LerArquivo(argv[1]);




	return 0;
}