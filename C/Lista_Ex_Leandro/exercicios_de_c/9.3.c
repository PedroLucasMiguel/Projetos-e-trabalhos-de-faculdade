#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    int dia, mes, ano;

    printf("\nDigite o dia. (Formato DD)\n");
    scanf("%d",&dia);
    printf("\nDigite o mês. (Formato MM)\n");
    scanf("%d",&mes);
    printf("\nDigite o ano. (Formato AA)\n");
    scanf("%d",&ano);

    printf("\n%d/%d/%d\n",dia,mes,ano);

}