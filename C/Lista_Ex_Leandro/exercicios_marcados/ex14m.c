#include <stdio.h>
#include <stdlib.h>

int main(){

    float salaraio, porcentagem, valor_final;

    printf("\nDigite o valor atual do salario:\n");
    scanf("%f", &salaraio);
    printf("\nDigite a porcentagem de aumento (0-100):\n");
    scanf("%f", &porcentagem);

    valor_final = ((porcentagem/100)*salaraio)+salaraio;

    printf("\nO valor apos o aumento eh de %f\n", valor_final);

    return 0;


}