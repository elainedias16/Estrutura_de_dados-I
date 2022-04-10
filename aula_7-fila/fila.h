#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "livro.h"

typedef struct fila Fila;

Fila* inicializaFila(void);

void insereFila(Fila* fila, Livro* livro); //vai inserir sempre no final da fila

Livro* retiraFila(Fila* fila); //vai retirar sempre no inicio da lista

void imprimeFila(Fila* fila);

void liberaFila(Fila* fila);



#endif