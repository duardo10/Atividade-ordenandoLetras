#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char **vetor, int pos, int pai);
void heapify(char **vetor, int tamanho, int pos);
void HeapSort(char ***vetor, int tamanho);
int ler(char *palavra);
int preencher_lista(char ***vetor);
void imprimir_lista(char **vetor, int tamanho);

int main(int argc, char *argv[]) {
	char *vet = (char) malloc(sizeof(char));
	int tam;
	
	tam = preencher_lista(&vet);
	HeapSort(&vet, tam);
	imprimir_lista(vet, tam);
	
	return 0;
}

void swap(char **vetor, int pos, int pai){
	char *temp = vetor[pos];
	vetor[pos] = vetor[pai];
	vetor[pai] = temp;
}

void heapify(char **vetor, int tamanho, int pos){
	int pai = pos;
	int esq = 2 * pos + 1;
	int dir = 2 * pos + 2;
	
	if(esq < tamanho && strcmp(vetor[esq], vetor[pai]) > 0)
		pai = esq;
	
	if(dir < tamanho && strcmp(vetor[dir], vetor[pai]) > 0)
		pai = dir;
	
	if(pai != pos){
		swap(vetor, pos, pai);
		heapify(vetor, tamanho, pai);
	}
}

void HeapSort(char ***vetor, int tamanho){
	int i;
	
	for(i = tamanho / 2 - 1; i >= 0; i--)
		heapify(*vetor, tamanho, i);
	
	for(i = tamanho - 1; i >= 0; i--){
		swap(*vetor, 0, i);
		heapify(*vetor, i, 0);
	}
}

void SelectionSort(char *palavra, int tam){
	int i, j, menor;
	char aux;
	
	for(i = 0; i < tam; i++){
		menor = i;
		
		for(j = i + 1; j < tam; j++)
			if(palavra[j] < palavra[menor]) menor = j;
		
		if(menor != i){
			aux = palavra[menor];
			palavra[menor] = palavra[i];
			palavra[i] = aux;
		}
	}
}

int ler(char *palavra){
	char c;
	int i = 0;
	
	scanf("%c", &c);
	
	while(c != '\n'){
		palavra[i] = c;
		palavra = (char*) realloc(palavra, sizeof(char) * (++i + 1));
		scanf("%c", &c);
	}
	
	palavra[i] = '\0';
	
	return i;
}

int preencher_lista(char ***vetor){
	char *palavra;
	int i = 0, tam;
	
	(vetor)[i] = (char) malloc(sizeof(char));
	
	while(tam = ler((*vetor)[i])){
		SelectionSort((*vetor)[i], tam);
		vetor = (char) realloc(*vetor, sizeof(char) * (++i + 1));
		(vetor)[i] = (char) malloc(sizeof(char));
	}
	
	return i;
}

void imprimir_lista(char **vetor, int tamanho){
	int i;
	
	for(i = 0; i < tamanho; i++)
		printf("%s\n", vetor[i]);
}