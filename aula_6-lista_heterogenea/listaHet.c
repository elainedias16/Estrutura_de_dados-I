#include "listaHet.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROFESSOR 0
#define ALUNO 1

typedef struct cel Celula;

struct cel{
    Celula* prox;
    void* item;  //pode ser aluno ou professor
    int tipo;  //vai dizer se eh aluno ou professor
};


//sentinela
struct listahet{
    Celula* prim;
    Celula* ult;
};

ListaHet* inicializaListaHet(){
    ListaHet* lista = (ListaHet*)malloc(sizeof(ListaHet));
    lista->prim = NULL;
    lista->ult = NULL;
    return lista;
}

void insereAluno(ListaHet* lista, Aluno* aluno){
    Celula* nova = (Celula*)malloc(sizeof(Celula));
    nova->item = aluno;
    nova->tipo = ALUNO ;
    nova-> prox = lista->prim;
    lista->prim = nova;
    if(lista->ult == NULL){
        lista->ult = nova;
    }

}

void insereProfessor(ListaHet* lista, Professor* professor){
    Celula* nova = (Celula*)malloc(sizeof(Celula));
    nova->item = professor;
    nova->tipo = PROFESSOR ;
    nova-> prox = lista->prim;
    lista->prim = nova;
    if(lista->ult == NULL){
        lista->ult = nova;
    }
}

void imprimeListaHet(ListaHet* lista){
    Celula* i;

    for(i = lista->prim; i != NULL ; i= i->prox){
        if(i->tipo == ALUNO){
            printf("Aluno:\n");
            imprimeAluno(i->item);
        }

        if(i->tipo == PROFESSOR){
            printf("Professor:\n");
            imprimeProfessor(i->item);
        }
    }

}



float valorChurrasco(ListaHet* lista){
    Celula* i = lista->prim;
    float valor = 0.0;

    while(i != NULL){

        if(i->tipo == PROFESSOR){
            valor = valor + 0.02* getSalario(i->item);
        }
        if(i->tipo == ALUNO){
            valor = valor + 30.0 ;
        }
        i = i->prox;
    }
    return valor ;
}

void liberaListaHet(ListaHet* lista){
    Celula* p = lista->prim;
    Celula* t;

    while(p != NULL){
        t = p->prox;
        free(p);
        p=t;
    }

    free(lista);
}