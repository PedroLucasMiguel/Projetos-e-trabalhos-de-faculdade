#include <stdio.h>
#include <stdlib.h>

int main (){

    float a, b, c;


    printf("\nDigite o primeiro valor\n");
    scanf("%f", &a);
    printf("\nDigite o segund valor\n");
    scanf("%f", &b);
    printf("\nO valor atual da variavel A eh de %f, e o da variavel B eh de %f.\n", a,b);
    
    c = a;
    a = b;
    b = c;

    printf("\nO valor das variaveis apos a troca eh de %f, %f respectivamente.\n", a,b);

    return 0;

}