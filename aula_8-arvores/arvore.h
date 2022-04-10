#ifndef ARVORE_H
#define ARVORE_H

#include "aluno.h"

typedef struct arvore Arv;

//cria uma arvore vazia
Arv* arvCriaVazia(void);

//cria uma arvores com suas subarvores
Arv* criaArvore(Aluno* aluno, Arv* sae, Arv* sad);

//libera uma arvore da memoria
Arv* liberaArvore(Arv* arvore);

//verifica se uma arvore eh vazia
int arvVazia(Arv* a);

//verifica se o aluno pertence à arvore
int arvPertence(Arv* a, Aluno* aluno);

//imprime uma arvore
void imprimeArvore(Arv* arvore);

//calcula a altura de uma arvore
int arvAltura (Arv* a);

//calcula o número de folhas da árvore
int folhas (Arv* a); 

//retorna o número de vezes que o aluno aparece na árvor
int ocorrencias (Arv* a , char* nome);

static int max2( int a , int b);


Aluno* info(Arv* a);



#endif /* ARVORE_H */