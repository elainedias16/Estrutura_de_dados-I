#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    Aluno* a = criaAluno("Alice",   2020101901,   5.0);
    Aluno* b = criaAluno("Beatriz", 2020101902,   6.0);
    Aluno* c = criaAluno("Carlos",  2020101903,   7.0);
    Aluno* d = criaAluno("Daniel",  2020101904,   8.0);
    Aluno* e = criaAluno("Eduardo", 2020101905,   9.0);
    Aluno* f = criaAluno("Fabio",   2020101906,   10.0);
    Aluno* g = criaAluno("Gabriela",2020101907,   10.0);
    Aluno* h = criaAluno("Higor",   2020101908,   10.0);


    Arv* arv = criaArvore(a,

                    criaArvore(b, 
                    criaArvore(d, arvCriaVazia() , arvCriaVazia() ),   
                    criaArvore(e, arvCriaVazia() , arvCriaVazia() )
                    ),            

                    criaArvore(c,
                    criaArvore(f, arvCriaVazia() , arvCriaVazia() ), 
                    criaArvore(g, arvCriaVazia() , arvCriaVazia() )
                    )
                );
    printf("Imprimindo a arvore composta por Alice, Beatriz, Carlos, Daniel, Eduardo, Fabio e Gabriela\n");
    imprimeArvore(arv);
    printf("\n");

    int n = folhas (arv); 
    printf("O numero de folhas dessa arvore eh %d\n", n);

    int altura = arvAltura (arv);
    printf("O altura dessa arvore eh %d\n", altura);

    printf("Testando a funcao pertence com o aluno Eduardo: ");
    if(arvPertence(arv, e)){
        printf("Eduardo pertence a arvore\n");
    }
    else{
        printf("Eduardo nao pertence a arvore\n");
    }

    printf("Testando a funcao pertence com o aluno Higor: ");
    if(arvPertence(arv, h)){
        printf("Higor pertence a arvore\n");
    }
    else{
        printf("Higor nao pertence a arvore\n");
    }
    
    int qtd = ocorrencias(arv, "Eduardo");
    printf("A quantidade de ocorrencias do nome nome Eduardo eh %d\n", qtd);

    qtd = ocorrencias(arv, "Higor");
    printf("A quantidade de ocorrencias do nome nome Higor eh %d\n", qtd);


    // Aluno* aluno = info(arv);
    // imprimeAluno(aluno);

    liberaArvore(arv);
    liberaAluno(a);
    liberaAluno(b);
    liberaAluno(c);
    liberaAluno(d);
    liberaAluno(e);
    liberaAluno(f);
    liberaAluno(g);
    liberaAluno(h);
    return 0;
}