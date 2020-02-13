#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int num;
    struct node *next;
    struct node *prev;
}node;

void pop(node **head, node **tail, int n){
    bool removido = false;
    node *aux, *aux2;
    
    if((*head) == NULL)
        printf("\n\nNão existem mais elementos para serem removidos!\n\n");
    

    else{
        if((*head) == (*tail) && (*head)->num == n){
            aux = (*head);
            (*head) = NULL;
            (*tail) = NULL;
            free(aux);
            removido = true;
        }

        else if(n == (*head)->num){ //Remoção do head
            aux = (*head);
            (*head)->next->prev = (*tail);
            (*head)->prev->next = (*head)->next;
            (*head) = (*head)->next;
            free(aux);
            removido = true;
        }

        else if(n == (*tail)->num){ //Remoção do tail
            aux = (*tail);
            (*head)->prev = (*tail)->prev;
            (*tail)->prev->next = (*tail)->next;
            (*tail) = (*tail)->prev;
            free(aux);
            removido = true;
        }

        else{
            aux = (*head)->next;
            while (aux != (*tail) && !removido){
                if(aux->num == n){
                    aux2 = aux;
                    aux->next->prev = aux->prev;
                    aux->prev->next = aux->next;
                    free(aux2);
                    removido = true;
                }
            }
        }

        if(removido)
            printf("\nElemento removido com sucesso!\n");
        
        else
            printf("\nElemento não encontrado!\n");
    }
    
}

void push(node **head, node **tail, int n){
    node *new = (node*)malloc(sizeof(node));
    node *aux;
    bool inserido = false; //Evita repetições desncessárias na inserção

    //Primeira inserção
    if((*head) == NULL){
        new->num = n;
        new->next = new;
        new->prev = new;
        (*head) = new;
        (*tail) = new;
    }

    //Apenas um elemento
    else if((*head) == (*tail)){
        if(n >= (*head)->num){ //Maior que o head, insere na frente dele
            new->num = n;
            new->next = (*head);
            new->prev = (*head);
            (*head)->next = new;
            (*head)->prev = new;
            (*tail) = new;
        }
        else{ //Menor, define esse como novo head
            new->num = n;
            new->next = (*head);
            new->prev = (*head);
            (*head)->prev = new;
            (*head)->next = new;
            (*tail) = (*head);
            (*head) = new;
        }
    }

    //Caso menor que head
    else if(n <= (*head)->num){
        new->num = n;
        new->next = (*head);
        new->prev = (*tail);
        (*head)->prev = new;
        (*tail)->next = new;
        (*head) = new;
    }

    //Caso maior que tail
    else if(n >= (*tail)->num){
        new->num = n;
        new->next = (*head);
        new->prev = (*tail)->prev;
        (*tail)->next = new;
        (*head)->prev = new;
        (*tail) = new;
    }

    //Varios elementos
    else{
        aux = (*head);
        while(aux != (*tail) && !inserido){
            if(aux->num <= n && aux->next->num >= n){
                new->num = n;
                new->next = aux->next;
                new->prev = aux;
                aux->next->prev = new;
                aux->next = new;
                inserido = true;
            }
            aux = aux->next;
        }
    }
}

void show(node **head, node **tail){
    node *aux = (*head);
    int op;
    bool sair = false;
    if((*head) == NULL)
        printf("\nNão existem elementos na lista!\n");
    else{
        while(!sair){
            printf("\n\nElemento: %d\n", aux->num);
            printf("Endereço do elemnto atual: %p\n", aux);
            printf("Next: %p || Prev: %p\n", aux->next, aux->prev);
            printf("Head: %p || Tail %p\n\n", (*head), (*tail));
            printf("(1)-Next || (2)-Prev || (3)-Sair\n");
            printf("Resposta: ");
            scanf("%d", &op);
            switch (op){
                case 1:
                    aux = aux->next;
                    break;

                case 2:
                    aux = aux->prev;
                    break;

                case 3:
                    sair = true;
                    break;

                default:
                    break;
            }
        }
    }
}

void generateRandom(node **head, node **tail, int qtd){
    srand(123);
    for(int i = 0; i < qtd; i++)
        push(&(*head), &(*tail), rand()%101);
}

int main(){
    node *head = NULL, *tail = NULL;
    bool sair = false;
    int op, num;

    while (!sair) {
        printf("\n\t----Menu----\n\n");
        printf("(1)-Inserir\n");
        printf("(2)-Remover\n");
        printf("(3)-Mostrar\n");
        printf("(4)-Gerar aleatorios\n");
        printf("(-1)-Sair\n");
        printf("Resposta: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("Digite um numero: ");
                scanf("%d", &num);
                push(&head, &tail, num);
                break;
            
            case 2:
                printf("Digite um numero: ");
                scanf("%d", &num);
                pop(&head, &tail, num);
                break;

            case 3:
                show(&head, &tail);
                break;

            case 4:
                printf("Digite a quantidade de elementos: ");
                scanf("%d", &num);
                generateRandom(&head, &tail, num);
                break;

            case -1:
                sair = true;
                break;

            default:
                break;
        }
    }
    
    return 0;
}