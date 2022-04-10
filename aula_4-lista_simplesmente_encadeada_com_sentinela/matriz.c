#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

struct matriz{
    int nlinhas;
    int ncolunas;
    float** elemento;
};

Matriz* inicializaMatriz (int nlinhas, int ncolunas){
    Matriz *mat = (Matriz*) malloc(sizeof(Matriz));
    mat->nlinhas = nlinhas;
    mat->ncolunas = ncolunas;
    mat->elemento = (float**) malloc( nlinhas * sizeof (float*)); 
    for(int i=0; i< nlinhas; i++){
        mat->elemento[i] = (float*) malloc(ncolunas * sizeof(float));
    }
    return mat;
}

void modificaElemento (Matriz* mat, int linha, int coluna, int elem){
    mat->elemento[linha][coluna] = elem;
}

int recuperaNColunas (Matriz* mat){
    return mat->ncolunas;
}

int recuperaNLinhas (Matriz* mat){
    return mat->nlinhas;
}

void imprimeMatriz(Matriz* mat){
    for(int i=0; i<mat->nlinhas; i++){
        for(int j=0; j<mat->ncolunas; j++){
            printf("%.1f  ", mat->elemento[i][j]);
        }
        printf("\n");
    }
}

int recuperaElemento(Matriz* mat, int linha, int coluna){
    return mat->elemento[linha][coluna];
}

void destroiMatriz(Matriz* mat){
    for(int i=0; i< mat->nlinhas; i++){
        free(mat->elemento[i]);
    }
    free(mat->elemento);
    free(mat);
}

Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){
    int i,j,k;
    Matriz* mat3 = inicializaMatriz(mat1->nlinhas, mat2->ncolunas);
    int v1,v2, v3=0;
    
    for( i=0; i<mat1->nlinhas; i++){
        for( j=0; j<mat2->ncolunas; j++){
            modificaElemento ( mat3, i, j, 0); 
            v3=0;
            for( k=0; k < mat1->ncolunas; k++){
                v1 = recuperaElemento(mat1, i, k);
                v2 = recuperaElemento(mat2, k, j);
                v3 = v3 + v1 * v2;
                modificaElemento (mat3, i, j, v3); 
                 
            }    
        }
    }
    return mat3;
}


Matriz* transposta (Matriz* mat){
    Matriz* t = inicializaMatriz (mat->ncolunas, mat->nlinhas);
    for(int i=0; i<mat->nlinhas; i++){
        for(int j=0; j<mat->ncolunas; j++){
            modificaElemento (t, j, i, mat->elemento[i][j]);
        }
    }
    return t;
}

