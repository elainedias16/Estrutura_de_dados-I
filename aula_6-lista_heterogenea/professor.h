#ifndef PROFESSOR_H
#define PROFESSOR_H

typedef struct professor Professor;

Professor* criaProfessor(char* nome, int siape, float salario);

void imprimeProfessor(Professor* professor);

void liberaProfessor(Professor* professor);

int getSiape(Professor* professor);

float getSalario(Professor* professor);

char* getNomeProfessor(Professor* professor);



#endif /*PROFESSOR_H */