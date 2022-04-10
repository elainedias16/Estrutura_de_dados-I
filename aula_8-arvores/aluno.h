#ifndef ALUNO_H
#define ALUNO_H


typedef struct aluno Aluno;

Aluno* criaAluno(char*nome, int matricula, float CR);

void imprimeAluno(Aluno* aluno);

int getMatricula(Aluno* aluno);

float getCR(Aluno* aluno);

char* getNome(Aluno* aluno);

void liberaAluno(Aluno* aluno);



#endif /*ALUNO_H */