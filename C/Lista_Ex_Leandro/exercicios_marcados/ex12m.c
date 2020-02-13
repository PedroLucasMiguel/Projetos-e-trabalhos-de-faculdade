/* Exercício 12 */
#include <stdio.h>
#include <stdlib.h>

int main(){

    int num_mesa,refrigerante,cerveja,pizza,almoco,porcao;
    float val_refrigerante,val_cerveja,val_pizza,val_almoco,val_porcao,val_com,val_fin;

    val_refrigerante = 2.50;
    val_cerveja = 4.00;
    val_pizza = 47.30;
    val_almoco = 15.00;
    val_porcao = 10.50;

    printf("\nDigite o numero da mesa\n");
    scanf("%d",&num_mesa);

    printf("\nQuantos refrigerantes?\n");
    scanf("%d",&refrigerante);

    printf("\nQuantas cervejas?\n");
    scanf("%d",&cerveja);

    printf("\nQuantas pizzas?\n");
    scanf("%d",&pizza);

    printf("\nQuantos almocos?\n");
    scanf("%d",&almoco);

    printf("\nQuantas porcoes?\n");
    scanf("%d",&porcao);

    val_com = (refrigerante*val_refrigerante)+(cerveja*val_cerveja)+(pizza*val_pizza)+(almoco*val_almoco)+(porcao*val_porcao);
    val_fin = (val_com*0.10)+val_com;

    printf("\nO valor total da mesa %d eh de %f com o valor de servico aplicado\n",num_mesa,val_fin);


}