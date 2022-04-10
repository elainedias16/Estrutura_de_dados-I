#include "lista.h"
#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

struct fila{
    Lista* lista;
};


Fila* inicializaFila(void){
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    fila->lista = inicializa_lista();
    return fila;
}

//vai inserir sempre no final da fila
void insereFila(Fila* fila, Livro* livro){
    insere(livro, fila->lista);
}

//vai retirar sempre no inicio da lista
Livro* retiraFila(Fila* fila){
    Livro* l = retira(fila->lista);
    return l;
}

void imprimeFila(Fila* fila){
    imprime_lista(fila->lista);
}

void liberaFila(Fila* fila){
    libera_lista(fila-> lista);
    free(fila);
}