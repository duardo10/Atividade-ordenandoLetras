#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ordenandoLetra.h"
#include"ordenandoLetra.c"

int main(){
    Palavra* lista = (Palavra*) malloc(sizeof(Palavra));
    int tam = 0;
    
    while(scanf("%s", lista[tam].nome) != EOF){
        tam++;
        lista = (Palavra*) realloc(lista, sizeof(Palavra) * (tam + 1));
    }
    imprimir(lista, tam);
}