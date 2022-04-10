#include "lista_de_livros.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    char titulo[100];
    char autor[100];
    char genero[100];
    int nota;

    printf("Vamos fazer uma lista de livros!\n\n");

    ListaDpl* lista; 
    lista = inicializa_lista();
   
    Livro* l1 = inicializa_livro("As brumas de Avalon", "Marion Zimmer Bradley", "Drama", 10);
    Livro* l2 = inicializa_livro("A cidade do sol", "Khaled Hosseini", "Romance", 10);
    Livro* l3 = inicializa_livro("Game of thrones", "George R.R", "Ficcao", 10);
    Livro* l4 = inicializa_livro("Harry Potter", "J.K. Rowling", "Ficcao", 10);
    Livro* l5 = inicializa_livro("O Doador de Memorias", "Lois Lowry" ,"Distopia", 10);

    lista = insere_livro(lista, l1);
    lista = insere_livro(lista, l2);
    lista = insere_livro(lista, l3);
    lista = insere_livro(lista, l4);
    lista = insere_livro(lista, l5);

    imprime_lista(lista);

    printf("Retirando o primeiro livro da lista:\n");
    lista = retira_livro(lista, "O Doador de Memorias"); 
    imprime_lista(lista); 

    printf("Retirando o ultimo livro da lista:\n");
    lista = retira_livro(lista, "As brumas de Avalon"); 
    imprime_lista(lista); 

    printf("Retirando um livro do meio da lista:\n");
    lista = retira_livro(lista, "Game of thrones"); 
    imprime_lista(lista); 

    printf("Inserindo os livros que foram retirados:\n");
    lista = insere_livro(lista, l1);
    lista = insere_livro(lista, l3);
    lista = insere_livro(lista, l5);
    imprime_lista(lista);

    libera_livro(l1);
    libera_livro(l2);
    libera_livro(l3);
    libera_livro(l4);
    libera_livro(l5);
    libera_lista(lista);

    return 0;
}