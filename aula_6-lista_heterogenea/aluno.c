#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno{
    char* nome;
    int matricula;
    float CR;
};

Aluno* criaAluno(char* nome, int matricula, float CR){
    Aluno* aluno = (Aluno*) malloc (sizeof(Aluno));
    aluno->nome = strdup(nome);
    aluno->CR = CR;
    aluno->matricula= matricula;
    return aluno;
}

void imprimeAluno(Aluno* aluno){
    printf("Nome:%s Matricula:%d CR:%.2f\n", aluno->nome, aluno->matricula, aluno->CR);
}

int getMatricula(Aluno* aluno){
    return aluno->matricula;
}

float getCR(Aluno* aluno){
    return aluno->CR;
}

char* getNome(Aluno* aluno){
    return aluno->nome;
}

void liberaAluno(Aluno* aluno){
    free(aluno->nome);
    free(aluno);
}