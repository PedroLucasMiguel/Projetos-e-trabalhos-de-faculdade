#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodes{
    int num;
    struct nodes *next;
}node;

void pushNode(node **head, node *new){
    if((*head) == NULL){
        new->next = NULL;
        (*head) = new;
    }
    else{
        new->next = (*head);
        (*head) = new;
    }
}

node *pop(node **head){
    node *aux;

    if((*head) == NULL)
        return NULL;

    else if((*head)->next == NULL){
        aux = (*head);
        (*head) = NULL;
        return aux;
    }

    else{
        aux = (*head);
        (*head) = (*head)->next;
        return aux;
    }
}

void stackInto(node **head, node **head2){ //head = origem || head2 = destino
    while((*head) != NULL){
        printf("stackinto");
        pushNode(&(*head2), pop(&(*head)));
    }  
}

void push(node **head, int n){
    node *new = (node*)malloc(sizeof(node));
    node *auxStack = NULL;
    bool inserido = false;

    if((*head) == NULL){
        new->num = n;
        new->next = NULL;
        (*head) = new;
    }

    else if((*head)->next == NULL){
        if(n >= (*head)->num){
            new->num = n;
            new->next = (*head);
            (*head) = new;
        }

        else{
            pushNode(&auxStack, pop(&(*head)));
            new->num = n;
            new->next = NULL;
            (*head) = new;
            stackInto(&auxStack, &(*head));
        }
    }

    else if(n >= (*head)->num){
        new->num = n;
        new->next = (*head);
        (*head) = new;
    }

    else{
        while(!inserido && (*head) != NULL){
            if(n < (*head)->num && n >= (*head)->next->num){
                pushNode(&auxStack, pop(&(*head)));
                new->num = n;
                new->next = (*head);
                (*head) = new;
                stackInto(&auxStack, &(*head));
                inserido = true;
            }
            pushNode(&auxStack, pop(&(*head)));
        }
    }
}

void stackShow(node **head){
    node *aux = (*head);
    int op;
    while (aux != NULL){
        printf("\n\nElemento: %d\n", aux->num);
        printf("Next: %p\n", aux->next);
        printf("Endereço desse elemento: %p\n", aux);
        printf("Head: %p\n", (*head));
        printf("(1)-Next || (2)-Sair: ");
        scanf("%d", &op);
        switch (op) {
        case 1:
            aux = aux->next;
            break;

        case 2:
            aux = NULL;
            break;
        
        default:
            break;
        }
    }
    
}

int main(){
    node *head = NULL;
    int a;
    srand(10);
    for(int i = 0; i < 10; i++){
        a = rand()%10;
        printf("%d", a);
        push(&head, a);
    }

    stackShow(&head);

    return 0;
}