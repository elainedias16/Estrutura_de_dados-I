#include "lista_de_livros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct listadpl{
    Livro* livro;
    ListaDpl* prox;
    ListaDpl* ant;
};

ListaDpl* inicializa_lista(void){
    return NULL;
}

//insere no inicio da lista
ListaDpl* insere_livro(ListaDpl* lista, Livro* livro){
    ListaDpl* nova = (ListaDpl*) malloc (sizeof(ListaDpl));
    nova->livro = livro;
    nova->ant = NULL;
    nova->prox = lista;

    if(lista != NULL){
        lista->ant = nova;
    }
    return nova;
}

static ListaDpl* busca(ListaDpl* lista, char* titulo){
    ListaDpl* p;

    for(p = lista; lista != NULL; p = p->prox){
        if (strcmp ( get_titulo(p->livro) , titulo) == 0){
            return p;
        }
    }
    return NULL;
}

ListaDpl* retira_livro(ListaDpl* lista, char* titulo){
    ListaDpl* p = busca(lista, titulo) ;

    if( p== NULL){ //nao encontrou o livro
        return lista;
    }

    if(p== lista){ //se for o primeiro livro da lista
        lista = p->prox;
    }
    else{
        p->ant->prox = p->prox;
    }

    if(p->prox != NULL){  
        p->prox->ant = p->ant;
    }

    free(p);

    return lista;
}


void imprime_lista(ListaDpl* lista){
    ListaDpl* p;
    for(p = lista; p != NULL; p = p->prox){
        imprime_livro(p->livro);
        printf("\n");
    }
}

void libera_lista(ListaDpl* lista){
    ListaDpl* p = lista;
    ListaDpl* t;

    while(p != NULL){
        t = p->prox;
        free(p);
        p = t;
    }
}