#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ordenandoLetra.h"

struct palavra{
    char nome;
    struct palavra *ant, *prox;
};


void heapSort(Palavra * cabeca){
    Palavra * pos = cabeca;
    while (pos->prox != NULL){
        pos = pos->prox;
    }
    
    for(Palavra * i = pos->ant; i != NULL; i = i->ant)
        heapMaximo(i);

}

void heapMaximo(Palavra * posList){
    Palavra * pai = posList;
    Palavra * filho_esq = posList->prox;
    Palavra * filho_dir;
    if(filho_esq == NULL)
        filho_dir = NULL;
    else
        filho_dir = filho_esq->prox;

    if(filho_esq != NULL && filho_esq->nome > pai->nome){
        pai = filho_esq;
    }
    if(filho_dir != NULL && filho_dir->nome > pai->nome){
        pai = filho_dir;
    }

    if(pai != posList){
        troca(posList,pai);
        heapMaximo(pai);
    }
}

void troca(Palavra *posList, Palavra *pai){
    char *aux = posList->nome;
    posList->nome = pai->nome;
    pai->nome = aux;
}


void imprimir(Palavra *lista, int tam){
    int i;
    
    printf("%-10s%-5s\n", "NOME");
    
    for(i = 0; i < tam; i++)
        printf("%-10s%-5.2f\n", lista[i].nome);
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