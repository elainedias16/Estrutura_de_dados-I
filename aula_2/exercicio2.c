#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *nome;
    int matricula;
    float p1;
    float p2;
    float p3;
}Aluno;

void imprime_aprovados (int n, Aluno** turma); //Imprime na tela os alunos aprovados. O aluno é aprovado quando a média 
//das 3 provas for maior ou igual a 5; n é o números de alunos na turma.
float media_turma (int n, Aluno** turma); //Retorna a média da turma inteira; n é o número de alunos da turma.

int main(){
    int n; //numero de alunos da turma
    char nomeAux[100];
    float mediaTurma=0;
    printf("Digite um numero positivo maior que zero para ser a quantidade de alunos de uma turma\n");
    scanf("%d",&n);
   
    Aluno** turma;
    turma = (Aluno**) malloc( n * sizeof(Aluno*) );

    //leitura da turma
    for(int i = 0; i < n ; i++ ){
        turma[i] = (Aluno*) malloc( sizeof (Aluno));
        printf("Digite o nome do aluno\n");
        scanf(" %[^\n]", nomeAux);  //precisei colocar o espaco antes para a leitura ficar correta
        turma[i]->nome = strdup(nomeAux);

        printf("Agora digite a matricula e as notas da p1,p2 e p3\n");
        scanf("%d %f %f %f", &turma[i]->matricula, &turma[i]->p1, &turma[i]->p2, &turma[i]->p3 );
    }

    //imprimindo a turma
    printf("\nOs alunos da turma e seus dados sao:\n");
    for(int j=0; j< n; j++){
        printf("%s  matricula: %d  notas: %.2f %.2f %.2f\n", turma[j]->nome, turma[j]->matricula, turma[j]->p1, turma[j]->p2, turma[j]->p3);
    }

    printf("\nA lista de alunos aprovados é a seguinte:\n");
    imprime_aprovados(n, turma);

    mediaTurma = media_turma (n, turma);
    printf("\nA media da turma é %.2f\n", mediaTurma);

    //liberando da memoria
    for(int i = 0; i < n ; i++){
        free(turma[i]->nome);
        free(turma[i]);
    }
    free(turma);

 
    return 0;
}
