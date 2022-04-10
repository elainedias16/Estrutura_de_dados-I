#ifndef LISTA_DE_LIVROS_H
#define LISTA_DE_LIVROS_H

#include  "livro.h"

typedef struct listadpl ListaDpl;

ListaDpl* inicializa_lista(void);

ListaDpl* insere_livro(ListaDpl* lista, Livro* livro);

ListaDpl* retira_livro(ListaDpl* lista, char* titulo);

void imprime_lista(ListaDpl* lista);

void libera_lista(ListaDpl* lista);


#endif  /*LISTA_DE_LIVROS_H*/