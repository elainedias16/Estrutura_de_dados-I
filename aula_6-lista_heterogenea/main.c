#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "professor.h"
#include "listaHet.h"

int main(){
    

    Aluno* fernanda = criaAluno("Fernanda", 2023101903, 10);
    Aluno* maria = criaAluno("Maria",    2023101903,  9);
    Aluno* joao = criaAluno("Joao",     2023101903,  8);
    Aluno* lucas = criaAluno("Lucas",    2023101903,  7);

    //Criando professores
    Professor* roberta = criaProfessor("Roberta",200001903, 14000);
    Professor* marcos = criaProfessor("Marcos",200001903, 15000);

    //Inicializa a lista
    ListaHet* churrasco = inicializaListaHet();

    //Insere alunos e professores na lista
    insereAluno(churrasco, fernanda);
    insereProfessor(churrasco, roberta);
    insereAluno(churrasco, maria);
    insereProfessor(churrasco, marcos);
    insereAluno(churrasco, joao);
    insereAluno(churrasco, lucas);

    //imprimindo a lista
    imprimeListaHet(churrasco);

    //quanto de dinheiro tem para o churrasco
    printf("VALOR:%.2f\n", valorChurrasco(churrasco));

    //liberando da memoria
    liberaListaHet(churrasco);

    //liberando os alunos da memoria
    liberaAluno(fernanda);
    liberaAluno(maria);
    liberaAluno(joao);
    liberaAluno(lucas);

    //liberando os professores
    liberaProfessor(roberta);
    liberaProfessor(marcos);
    

    return 0;
}