#include <stdio.h>
#include <stdlib.h>

int main(){

    float a, b, c, d, e, f, div_val;

    printf("\nDigite o valor de A:\n");
    scanf("%f", &a);
    printf("\nDigite o valor de B:\n");
    scanf("%f", &b);
    printf("\nDigite o valor de C:\n");
    scanf("%f", &c);
    printf("\nDigite o valor de D:\n");
    scanf("%f", &d);
    printf("\nDigite o valor de E:\n");
    scanf("%f", &e);
    printf("\nDigite o valor de F:\n");
    scanf("%f", &f);

    div_val = ((a+(b/c))/(d-(2*e/f)))+4*a;

    printf("O valor da equacao eh de %f.", div_val);

    return 0;

}