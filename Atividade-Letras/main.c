#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"letras.h"
#include"letras.c"


int main(int argc, char *argv[]) {
	char **vet = (char**) malloc(sizeof(char*));
	int tam;
	
	tam = preencher_lista(&vet);
	HeapSort(&vet, tam);
	imprimir_lista(vet, tam);
	
	return 0;
}