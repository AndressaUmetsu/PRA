all:
	gcc -o arvore arvoreBin.c main.c
	./arvore

rm:
	rm arvore
