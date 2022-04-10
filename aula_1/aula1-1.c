#include <stdio.h>
#include <stdlib.h>

int main(){

    int x1, x2 , x3, x4 ;  
    int *px1, *px2, *px3, *px4 ;

    px1 = &x1, 
    px2 = &x2;
    px3 = &x3;
    px4 = &x4;

    //Inicializando as variaveis usando ponteiros. Normalmente não se faz isso por ponteiros.
    *px1 = 1;
    *px2 = 2;
    *px3 = 3;
    *px4 = 4;

    printf("\nO endereço de x1 eh %p\n",px1);
    printf("O endereço de x2 eh %p\n",px2);
    printf("O endereço de x3 eh %p\n",px3);
    printf("O endereço de x4 eh %p\n",px4);

    printf("\nO valor inicial de x1 eh %d e o valor inicial de x3 eh %d\n", x1, x3);
    
    *px1 += 1;
    printf("Somando x1 com 1 obtemos um novo valor de x1 : %d \n", *px1);

    printf("O valor inicial de x2 eh %d e o valor inicial de x4 eh %d \n", *px2, *px4);
    *px2 *= *px2;
    printf("Multiplicando x2 por x2 obtemos %d, que eh o mesmo valor de x4\n", *px2);

    *px3 = 2 * *px3;
    *px4 = *px4 * 2 ;

    printf("Os novos valores das variavies x1,x2,x3,x4 sao: \n x1: %d \n x2: %d \n x3: %d \n x4: %d\n", x1, x2,x3,x4);
    printf("Assim, percebe-se que tudo foi multiplicado por 2 usando ponteiros!\n");


    return 0;
}