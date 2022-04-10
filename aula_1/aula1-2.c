#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Exercicio 2.1
//#define PI 3.14

// void calc_esfera (float r, float* area, float* volume){
//     *area = 4 * PI * r * r;
//     *volume = *area * r / 3 ;
// }

// int main(){
//     int r;
//     float Area, Vol;
//     float* area;
//     float* volume;

//     area = &Area;
//     volume = &Vol;

//     printf("Digite um inteiro qualquer maior que zero para ser o raio de uma esfera\n");
//     scanf("%d",&r);
//     calc_esfera (r, area, volume);

//     printf("O valor da area dessa esfera eh %.2f\n", Area);
//     printf("O valor do volume dessa esfera eh %.2f\n", Vol);

//     return 0;
// }


//Exercicio 2.2  
// void raizes (float a, float b, float c, float* x1, float* x2){  //como sao duas raizes, fiz uma funcao void
//     float delta = b*b - 4 * a * c; 
//     float raizQuad = sqrt(delta) ;

//     *x1 = ( -b + raizQuad )  / ( 2 * a) ; 
//     *x2 = ( -b - raizQuad)  / ( 2 * a) ;    
// }

// int main(){
//     float a, b, c;
//     float r1,r2;
//     float* x1;
//     float* x2;
//     x1= &r1;
//     x2= &r2;

//     printf("Digite 3 numeros quaisquer para que sejam os coeficientes de uma equação de segundo grau\n");
//     scanf("%f %f %f",&a,&b,&c);

//     raizes ( a,  b,  c,  x1,  x2);
//     printf("As raizes dessa equacao sao: %.2f e %.2f\n", r1, r2);

//     return 0;
// }


//Exercicio 2.3

//Retorna quantos numeros pares tem no vetor  
// int pares (int n, int* vet){
//     int counter=0;

//     for (int i=0; i<n ; i++){
//         if( vet[i] % 2 == 0) counter ++ ;
//     }

//     return counter;
// }


// int main(){
//     int n;
//     int qtd;
//     printf("Digite um numero n postivo maior que zero para ser o tamanho de um vetor\n");
//     scanf("%d",&n);
    
//     int *vet;
//     vet = (int *) malloc ( n * sizeof(int));

//     printf("Agora digite %d numeros para preencher o vetor\n", n);

//     for ( int j = 0; j< n; j++){
//         scanf("%d", &vet[j]);
//     }
//     qtd = pares(n,vet);

//     printf("A quantidade de numeros pares nesse vetor eh %d\n", qtd);

//    free(vet);

//     return 0;    
// }


//Exercicio 2.4  
// void inverte (int n, int*vet){
//     int qtd = n; 
//     int aux=0;
    
//     for(int i= 0; i< qtd; i++, qtd--){
//         aux = vet[qtd-1];
//         vet[qtd-1] = vet[i];
//         vet[i] = aux;
//     }

// }

// int main(){
//     int n;
//     printf("Digite um numero n postivo maior que zero para ser o tamanho de um vetor\n");
//     scanf("%d",&n);

//     int  *vet;
//     vet = (int* ) malloc ( n * sizeof(int));
//     printf("Agora digite %d numeros para preencher o vetor\n", n);
//     for ( int j = 0; j< n; j++){
//         scanf("%d", &vet[j]);
//     }

//     inverte (n, vet);

//     printf("Invertendo os numeros, o vetor fica da seguinte forma:\n");
//     for ( int k = 0; k< n; k++){
//         printf("%d ", vet[k]);
//     }
//     printf("\n");
//     free(vet);
//     return 0;    
// }


//Exercicio 2.5  
double avalia (double* poli, int grau, double x){
    double resultado = poli[0];
    
    for(int i = 1 ;  i <= grau   ; i++){
        resultado += poli[i] * pow(x , i);
    }
    return resultado;
}

int main(){
    double* poli;
    int grau;
    double x, resultado;
    printf("Vamos fazer a avaliacao de um polinomio!\n");
    printf("Digite o grau desse polinomio\n");
    scanf("%d",&grau);

    poli = (double*) malloc ( (grau + 1) * sizeof (double));

    printf("Agora digite os coeficientes desse polinomio comecando pelo coeficiente de maior grau \n");

    for(int i = grau; i >= 0 ; i--){
        scanf("%lf", &poli[i]);
       
    }
    printf("Por fim, digite um numero qualquer para fazermos as contas!\n");
    scanf("%lf", &x);
    resultado = avalia (poli,  grau,  x);
    printf("O resultado desse polinomio com o valor de x igual %lf eh %lf\n", x, resultado);
    
    free(poli);
    return 0;
}
