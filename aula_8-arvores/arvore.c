#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct arvore{
    Aluno* aluno;
    Arv* sae;
    Arv* sad;
};

Arv* arvCriaVazia(void){
    return NULL;
}

Arv* criaArvore(Aluno* aluno, Arv* sae, Arv* sad){
    Arv* arvore = (Arv*) malloc (sizeof (Arv));
    arvore->aluno = aluno;
    arvore->sae = sae;
    arvore->sad = sad;

    return arvore;
}

int arvVazia(Arv* a){
    if(a == NULL){
        return 1;
    }
    return 0;
}    

Arv* liberaArvore(Arv* a){
    if( !arvVazia(a)){  //se a arvore nao estiver vazia
        liberaArvore(a->sae);  //libera subarvore da esquerda
        liberaArvore(a->sad);  //libera subarvore da direita
        free(a);  //libera raiz
    }
    return NULL; //se a arvore estiver vazia, retorna NULL
}

int arvPertence(Arv* a, Aluno* aluno){
    if( !arvVazia(a)){
        if ( strcmp ( getNome(aluno) , getNome(a->aluno)) == 0 ){
            return 1;
        }
        else {
            return arvPertence(a->sae, aluno) || arvPertence(a->sad, aluno);
        }

    }
    return 0;
}

void imprimeArvore(Arv* a){
    printf("<");
    if( !arvVazia(a)){
        imprimeAluno(a->aluno);
        //printf("\n");
        imprimeArvore(a->sae);
        imprimeArvore(a->sad);
    }
    printf(">");
}


static int max2( int a , int b){
    return (a > b) ? a : b ;
}

int arvAltura (Arv* a){
    if( arvVazia(a)){
        return -1;
    }
    else{
        return 1 + max2( arvAltura(a->sae)  , arvAltura(a->sad) );
    }
}

int folhas (Arv* a){
    if( arvVazia(a->sae) && arvVazia(a->sad)){
        return 1;  
    } 
    else if(  !arvVazia(a->sae)  &&  arvVazia(a->sad) ){
        return folhas(a->sae);
    }
    else if( arvVazia(a->sae) && ! arvVazia(a->sad)){
        return folhas(a->sad);
    }

    return folhas(a->sae) + folhas(a->sad); 
}


int ocorrencias(Arv* a, char* nome){
    int counter = 0;
    if( !arvVazia(a)){
        if ( strcmp ( nome , getNome(a->aluno)) == 0 ){
            counter++;
        }
        else {
            return ocorrencias(a->sae, nome) + ocorrencias(a->sad, nome);
        }

    }
    return counter;
}

Aluno* info(Arv* a){
    if(!arvVazia(a)){
        return a->aluno;
    }
    return NULL;
}