#include <stdio.h>
#include <stdlib.h>
#include "listaMat.h"

#define NLINHAS 2
#define NCOLUNAS 3


int main(){

    //criando matries para teste:
    Matriz* a = inicializaMatriz(NLINHAS,NCOLUNAS);
    Matriz* b = inicializaMatriz(NLINHAS,NCOLUNAS);
    Matriz* c = inicializaMatriz(NLINHAS,NCOLUNAS);
    Matriz* d = inicializaMatriz(NLINHAS,NCOLUNAS);
 
     for (int i=0;i<NLINHAS;i++){
        for (int j=0;j<NCOLUNAS; j++){
            modificaElemento(a, i, j, rand() % 100);
            modificaElemento(b, i, j, rand() % 100);
            modificaElemento(c, i, j, rand() % 100);
            modificaElemento(d, i, j, rand() % 100);
        }
    }

    Lista* l1 = inicializa_lista();
    insere (a, l1);
    insere (b, l1);
    insere (c, l1);
    insere (d, l1);

    printf("Imprimindo a lista de matrizes:\n");
    imprime_lista(l1);

    //fazendo as matrizes transpostas e colocando-as em outra lista
    Matriz* t1 = transposta (a);
    Matriz* t2 = transposta (b);
    Matriz* t3 = transposta (c);
    Matriz* t4 = transposta (d);

    Lista* l2 = inicializa_lista();
    insere (t1, l2);
    insere (t2, l2);
    insere (t3, l2);
    insere (t4, l2);

    printf("Imprimindo a lista de matrizes transpostas de a, b,c,d respectivamente:\n");
    imprime_lista(l2);

    printf("Retirando a primeira matriz da lista 1\n");
    retira(l1, 0);
    imprime_lista(l1);

    printf("Retirando a ultima matriz da lista 1\n");
    retira(l1, 2); //como ja foi retirada uma matriz, a ultima posicao agora eh o 2
    imprime_lista(l1);

    printf("Retirando uma matriz sem ser a ultima e a primeira da lista 2 (lista das transpostas)\n");
    retira(l2, 1); 
    imprime_lista(l2);

    printf("Inserindo todas as matrizes ja retiradas e imprimindo as listas novamente:\n");
    insere(a, l1);
    insere(d, l1);
    insere(t2, l2);

    printf("lista l1:\n");
    imprime_lista(l1); 
    printf("lista l2:\n");
    imprime_lista(l2);


    //liberando as listas
    libera_lista(l1);
    libera_lista(l2);


    return 0;
}