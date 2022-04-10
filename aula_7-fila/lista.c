#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct celula{
    Livro* livro;
    Celula* prox;
};

struct lista{  //sentinela
    Celula* prim;
    Celula* ult;
    int tam;
};

// inicializa uma lista vazia
Lista* inicializa_lista(){
    Lista* lista = (Lista*)malloc( sizeof(Lista) );
    lista->prim = NULL;
    lista->ult = NULL;
    lista->tam =0;
    return lista;
}

//inserindo um livro no final da lista
void insere(Livro* livro, Lista* lista){
    Celula* nova = (Celula*)malloc(sizeof(Celula));
    nova->livro = livro;
    nova->prox = NULL;

   
    if(lista->tam != 0)
        lista->ult->prox = nova;
    
    lista->ult = nova;

    if(lista->tam == 0){
        lista->prim = nova;
    }
    lista->tam++;

 
}

//vai retirar o primeiro
Livro* retira(Lista* lista){
    Celula* aux = lista->prim;
    lista->prim = aux->prox;
    lista->tam--;
    Livro* l = aux->livro;
    free(aux);
    return l;

}

void imprime_lista(Lista* lista){
    Celula* aux;
    for( aux = lista->prim;  aux!=NULL; aux = aux->prox ){
        imprime_livro(aux->livro);
        printf("\n\n");
    }
    
}

//destroi a lista toda, liberando a memoria toda
void libera_lista(Lista* lista){
    Celula* aux;
    Celula* aux1;
    aux= lista->prim;
    
    while(aux != NULL){
        aux1 = aux->prox;
        free(aux);
        aux = aux1 ;
    }
    
    free(lista);
}