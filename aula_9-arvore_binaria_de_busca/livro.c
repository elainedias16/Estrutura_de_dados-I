#include "livro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct livro{
    char* titulo;
    char* autor;
    char* genero;
    float nota;
};


Livro* inicializa_livro(char* titulo, char* autor, char* genero, float nota){
    Livro* livro = (Livro*) malloc(sizeof(Livro));
    livro->nota = nota;
    livro->titulo = strdup(titulo);
    livro->autor = strdup(autor);
    livro->genero = strdup(genero);
    return livro;
}

void imprime_livro(Livro* livro){
    printf("Titulo:%s   ", livro->titulo);
    // printf("Genero:%s \n", livro->genero);
    // printf("Autor:%s \n", livro->autor);
    printf("Nota:%.2f\n", livro->nota);
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

float getNota(Livro* livro){
    return livro->nota;
}
