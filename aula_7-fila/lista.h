#ifndef LISTA_LIVRO_H_
#define LISTA_LIVRO_H_

#include "livro.h"
#include <stdio.h>

typedef struct celula Celula;
typedef struct lista Lista;

Lista* inicializa_lista();

void insere(Livro* livro, Lista* lista);

Livro* retira(Lista* lista);

void imprime_lista(Lista* lista);

void libera_lista(Lista* lista);


#endif /* LISTA_LIVRO_H_ */