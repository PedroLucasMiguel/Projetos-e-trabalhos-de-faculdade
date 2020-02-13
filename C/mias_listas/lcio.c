#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodes{
    int num;
    struct nodes *next;
    struct nodes *prev;
}node;

void push(node **head, node **tail, int n){
    node *new = (node*)malloc(sizeof(node));
    node *aux;
    bool inserido = false;

    if((*head) == NULL){
        printf("1");
        new->num = n;
        new->next = new;
        new->prev = new;
        (*head) = new;
        (*tail) = new;
    }
    
    else if((*head) == (*tail)){
        if(n >= (*head)->num){
            printf("2.1");
            new->num = n;
            new->prev = (*head);
            new->next = (*head);
            (*head)->next = new;
            (*head)->prev = new;
            (*tail) = new;
        }
        else{
            printf("2.2");
            new->num = n;
            new->next = (*head);
            new->prev = (*head);
            (*head)->prev = new;
            (*head)->next = new;
            (*tail) = (*head);
            (*head) = new;
        }
    }

    else if(n <= (*head)->num && n < (*tail)->num){
        printf("3");
        new->num = n;
        new->next = (*head);
        new->prev = (*tail);
        (*tail)->next = new;
        (*head)->prev = new;
        (*head) = new;
    }

    else if(n >= (*tail)->num){
        printf("4");
        new->num = n;
        new->next = (*head);
        new->prev = (*tail);
        (*tail)->next = new;
        (*head)->prev = new;
        (*tail) = new;
    }

    else{
        aux = (*head);
        while(aux != (*tail) && !inserido){;
            if(aux->num <= n && aux->next->num >= n){
                printf("5");
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

int main(){
    node *head = NULL, *tail = NULL;
    int a;
    srand(123);
    for(int i = 0; i < 10; i++){
        a = rand()%20;
        printf("\n%d ", a);
        push(&head, &tail, a);
    }


    show(&head, &tail);
    return 0;
}