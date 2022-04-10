#ifndef LISTA_MAT_H_
#define LISTA_MAT_H_

#include "matriz.h"
#include <stdio.h>

typedef struct celula Celula;
typedef struct lista Lista;

Lista* inicializa_lista();

void insere(Matriz* mat, Lista* lista);

void retira(Lista* lista, int indice);

void imprime_lista(Lista* lista);

void libera_lista(Lista* lista);


#endif /* LISTA_MAT_H_ */