#include "listaMat.h"
#include <stdio.h>
#include <stdlib.h>

struct celula{
    Matriz* mat;
    Celula* prox;
};

struct lista{  //sentinela
    Celula* prim;
    Celula* ult;
};

// inicializa uma lista vazia
Lista* inicializa_lista(){
    Lista* lista = (Lista*)malloc( sizeof(Lista) );
    lista->prim = NULL;
    lista->ult = NULL;
    return lista;
}

//inserindo uma matriz no inicio da lista
void insere(Matriz* mat, Lista* lista){
    Celula* nova = (Celula*)malloc(sizeof(Celula));
    nova->mat = mat;
    nova->prox = lista->prim;
    lista->prim = nova;

    if(lista->ult == NULL){
        lista->ult = nova;
    }
}

void retira(Lista* lista, int indice){
    Celula* aux = lista->prim;
    Celula* ant = NULL; //celula anterior
    int i=0;
    // Matriz* m;
    while( aux!= NULL && i != indice){
        i++;
        ant = aux;
        aux= aux->prox;
    }
    // m = aux->mat;
    if(aux != NULL){ //encontrou a matriz
        if(aux == lista->prim && aux == lista->ult){  // a lista so tem uma matriz
            lista->prim = lista->ult = NULL; 
        }
        else if(aux == lista->prim){ //a matriz a ser retirada eh a primeira da lista
            lista->prim = aux->prox;
        }
        else if(aux == lista->ult){ //a matriz a ser retirada eh a ultima
            lista->ult = ant;
            ant->prox = NULL;
        }
        else{ //a matriz a ser retirado esta no "meio" da lista,caso generico
                ant->prox = aux->prox;
        }
        free(aux);
    }
   

}

void imprime_lista(Lista* lista){
    Celula* aux;
    for( aux = lista->prim;  aux!=NULL; aux = aux->prox ){
        imprimeMatriz(aux->mat);
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
        destroiMatriz(aux->mat);
        free(aux);
        aux = aux1 ;
    }
    
    free(lista);
}