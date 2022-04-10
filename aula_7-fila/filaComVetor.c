#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

#define TAM 10

struct fila{
    int ini; //indice que representa o inicio da fila
    int n; //numero de elementos(livros) da fila
    Livro* livros[TAM];
};

Fila* inicializaFila(void){
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    fila->ini = 0;
    fila->n = 0;
    return fila;
}

//sempre insere no final da fila
void insereFila(Fila* fila, Livro* livro){
    if( !fila || fila->n == TAM){
        printf("Fila inválida ou cheia!\n");
        //return;
        exit(1);
    }

    int posicao = (fila->ini + fila->n ) % TAM; //achando o final da fila (circular)

    //inserindo no final da fila
   fila->livros[posicao] = livro ;
   fila->n++; //incrementa o numero de livros

}

//sempre retira no inicio da fila
Livro* retiraFila(Fila* fila){
    if( !fila || fila->n == 0){
        printf("Fila invalida ou vazia!\n");
        //return;
        exit(1);
    }
    Livro* livro = fila->livros[fila->ini]; //vai retirar o primeiro livro

    fila-> ini = ( fila->ini + 1 ) % TAM ;  //incremento circular do indice de inicio do vetor
    fila->n--; //decrementando a quantidade de livros

    return livro; 
}


void imprimeFila(Fila* fila){
   int i;
   int posicao = 0;

   if(!fila){
       //return;
       exit(1);
   }

   for(int i = 0; i != fila->n ; i++){

       posicao = (fila->ini + i ) %TAM;
       imprime_livro(fila->livros[posicao]);
       printf("\n");
   }
}

void liberaFila(Fila* fila){
    if(!fila){
        //return;
        exit(1);
    }
    free(fila);
}