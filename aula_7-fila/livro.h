#ifndef LIVRO_H
#define LIVRO_H


typedef struct livro Livro;

Livro* inicializa_livro(char* titulo, char* genero, char* autor, int nota);

void imprime_livro(Livro* livro);

void libera_livro(Livro* livro);

char* get_titulo(Livro* livro);


#endif /*FILME_H*/