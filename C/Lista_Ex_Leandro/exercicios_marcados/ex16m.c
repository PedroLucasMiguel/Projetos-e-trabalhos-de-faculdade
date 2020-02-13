#include <stdio.h>
#include <stdlib.h>

int main(){

    /*slb = Salário bruto, vhe = Valor das horas extras, sll = Salário liquido, nhe = Número de horas extras */
    float slb, vhe, sll;
    int nhe;

    printf("\nDigite o valor do salario bruto:\n");
    scanf("%f", &slb);
    printf("\nDigite o valor das horas extras:\n");
    scanf("%f", &vhe);
    printf("\nDigite o numero de horas extras:\n");
    scanf("%d", &nhe);

    sll = (slb+(vhe*nhe))-((slb+(vhe*nhe))*0.08);

    printf("\nO valor do salario liquido eh de RS %f\n", sll);

    return 0;

}