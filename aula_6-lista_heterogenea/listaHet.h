#ifndef LISTAHET_H
#define LISTAHET_H

#include "aluno.h"
#include "professor.h"

typedef struct listahet ListaHet; //vai ser uma lista com sentinela

ListaHet* inicializaListaHet(void);

void insereAluno(ListaHet* lista, Aluno* aluno);

void insereProfessor(ListaHet* lista, Professor* professor);

void imprimeListaHet(ListaHet* lista);

float valorChurrasco(ListaHet* lista);

void liberaListaHet(ListaHet* lista);

#endif /*LISTAHET_H */