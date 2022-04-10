#include "fila.h"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    Livro* l1 = inicializa_livro("As brumas de Avalon", "Marion Zimmer Bradley", "Drama", 10);
    Livro* l2 = inicializa_livro("A cidade do sol", "Khaled Hosseini", "Romance", 10);
    Livro* l3 = inicializa_livro("Game of thrones", "George R.R", "Ficcao", 10);
    Livro* l4 = inicializa_livro("Harry Potter", "J.K. Rowling", "Ficcao", 10);
    Livro* l5 = inicializa_livro("O Doador de Memorias", "Lois Lowry" ,"Distopia", 10);
    

    Fila* fila1 = inicializaFila();
    Fila* fila2 = inicializaFila(); 

    //inserindo livros na fila 1 
    //sempre insere no final da fila
    insereFila(fila1, l1);
    insereFila(fila1, l2);
    insereFila(fila1, l3);
    insereFila(fila1, l4);
    insereFila(fila1, l5);

    printf("Imprimindo a fila 1\n");
    imprimeFila(fila1);

    
    insereFila( fila2, retiraFila(fila1) ); //retira o primieiro livro, no caso As brumas de Avalon e coloca no final da fila 2
    insereFila( fila2, retiraFila(fila1) ); //retira o proximo primeiro livro, A cidade do sol e coloca no final da fila 2
    insereFila( fila2, retiraFila(fila1) ); //retira Game of thrones e coloca na fila 2
  

    printf("\n\n\nImprimindo a fila 1 e 2:\n\n");
    //Na fila 1 foram retirados os 3 primeiros livros, entao so devem aparecer Harry Potter e O doador de memorias
    printf("Fila 1:\n");
    imprimeFila(fila1);

    
    printf("\n\n\nFila 2:\n");
    imprimeFila(fila2);

    //liberando da memoria
    liberaFila(fila1);
    liberaFila(fila2);
    libera_livro(l1);
    libera_livro(l2);
    libera_livro(l3);
    libera_livro(l4);
    libera_livro(l5);
   

    return 0;
}