#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "professor.h"

struct professor{
    char* nome;
    int siape;
    float salario;
};


Professor* criaProfessor(char* nome, int siape, float salario){
    Professor* professor = (Professor*) malloc (sizeof(Professor));
    professor->nome = strdup(nome);
    professor->salario = salario;
    professor->siape = siape;
    return professor;
}

void imprimeProfessor(Professor* professor){
    printf("Nome:%s Siape:%d Salario:%.2f\n", professor->nome, professor->siape, professor->salario);
}

int getSiape(Professor* professor){
    return professor->siape;
}

float getSalario(Professor* professor){
    return professor->salario;
}

char* getNomeProfessor(Professor* professor){
    return professor->nome;
}

void liberaProfessor(Professor* professor){
    free(professor->nome);
    free(professor);
}