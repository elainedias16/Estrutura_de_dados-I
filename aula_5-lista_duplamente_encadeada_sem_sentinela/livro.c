#include "livro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct livro{
    char* titulo;
    char* autor;
    char* genero;
    int nota;
};


Livro* inicializa_livro(char* titulo, char* autor, char* genero, int nota){
    Livro* livro = (Livro*) malloc(sizeof(Livro));
    livro->titulo = strdup(titulo);
    livro->autor = strdup(autor);
    livro->genero = strdup(genero);
    livro->nota = nota;
    return livro;
}

void imprime_livro(Livro* livro){
    printf("Titulo:%s \n", livro->titulo);
    printf("Genero:%s \n", livro->genero);
    printf("Autor:%s \n", livro->autor);
    printf("Nota:%d \n", livro->nota);
}


void libera_livro(Livro* livro){
    free(livro->titulo);
    free(livro->genero);
    free(livro->autor);
    free(livro);
}


char* get_titulo(Livro* livro){
    return livro->titulo;
}