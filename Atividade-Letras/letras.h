#include <stdio.h>
#include <stdlib.h>

void swap(char **vetor, int pos, int pai);
void heapify(char **vetor, int tamanho, int pos);
void HeapSort(char ***vetor, int tamanho);

int ler(char *palavra);
int preencher_lista(char ***vetor);
void imprimir_lista(char **vetor, int tamanho);