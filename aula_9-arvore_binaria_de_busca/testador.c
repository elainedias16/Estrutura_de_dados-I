#include "tree.h"
#include <stdio.h>
#include <stdlib.h>


int main(){

    Livro* l1 = inicializa_livro("Dom Quixote", "Miguel de Cervantes", "Aventura" , 7.9);
    Livro* l2 = inicializa_livro("Guerra e Paz", "Tolstoi", "drama" ,8.5);
    Livro* l3 = inicializa_livro("Cem anos de solidao", "Gabriel Gacia Marquez", "drama" , 9);
    Livro* l4 = inicializa_livro("As cronicas de Gelo e Fogo", "daniela", "Ficcao" , 10);
    Livro* l5 = inicializa_livro("As Cronicas de Narnia", "C.S Lewis", "Ficcao" , 8.9);

    Tree* t1 = initTree();
    //Inserindo os livros desordenadamente na árvore
    printf("Inserindo os livros desordenadamente na arvore...\n");
    t1 = insert( t1, l1);
    t1 = insert( t1, l2);
    t1 = insert( t1, l3);
    t1 = insert( t1, l4);
    t1 = insert( t1, l5);
    printf("\nImprimindo a arvore:\n\n");
    printTree(t1);
    printf("\nComo pode ser visto, a arvore ja fica ordenada por nota!\n\n");
    
    
    printf("\nRemovendo o livro de maior nota...\n");
    t1 = remover(t1, l4);
    printTree(t1);

    printf("\nRemovendo o livro de menor nota...\n");
    t1 = remover(t1, l1);
    printTree(t1);
    
    printf("\nInserindo novamente esses livros na arvore...\n");

    t1 = insert(t1, l1);
    t1 = insert(t1, l4);
    printTree(t1);

    printf("\n...Procurando o livro nota 10...\n");
    Tree* t2 = search(t1, 10);
    printTree(t2);

    libera(t1);
    libera_livro(l1);
    libera_livro(l2);
    libera_livro(l3);
    libera_livro(l4);
    libera_livro(l5);
    

    return 0;
}