#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodes{
    int num;
    struct nodes *next;
}node;

int pop(node **head){
    node *aux;

    if((*head) == NULL)
        return -1;

    else{
        aux = (*head);
        (*head) = (*head)->next;
        free(aux);
    }
}

void push(node **head, int n){
    node *new = (node*)malloc(sizeof(node));

    if((*head) == NULL){
        new->num = n;
        new->next = NULL;
        (*head) = new;
    }

    else{
        new->num = n;
        new->next = (*head);
        (*head) = new;
    }
}

void toBinary(node **head, int n){
    if(n/2 == 1 || n/2 == 0){
        push(&(*head), n%2);
        push(&(*head), n/2);
    }
    else{
        push(&(*head), n%2);
        toBinary(&(*head), n/2);
    }
}

void show(node **head){
    printf("\n");
    while ((*head) != NULL) {
        printf("%d", (*head)->num);
        pop(&(*head));
    }
    printf("\n\n");
}

int main(){
    node *head = NULL;
    int num;
    printf("\nDigite um numero: ");
    scanf("%d", &num);
    toBinary(&head ,num);
    show(&head);
    return 0;
}