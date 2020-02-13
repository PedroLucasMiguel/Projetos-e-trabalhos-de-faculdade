#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct nodes {
    char nome[64];
    struct nodes *next;
}node;

void pop(node **head, node **tail, char *name){
    node *aux, *aux2;
    bool removido = false;
    if((*head) == NULL)
        printf("\nNada pode ser removido\n");
    else{
        if((*head) == (*tail) && strcmp((*head)->nome, name) == 0){
            aux = (*head);
            (*head) = NULL;
            (*tail) = NULL;
            free(aux);
        }
        else if(strcmp((*head)->nome, name) == 0){
            aux = (*head);
            (*head) = (*head)->next;
            free(aux);
        }
        else{
            aux = (*head);
            while (aux != NULL && !removido) {
                if(strcmp(aux->next->nome, name) == 0){
                    aux2 = aux->next;
                    aux->next = aux->next->next;
                    free(aux2);
                    removido = true;
                }
                aux = aux->next;
            }

            if(removido)
                printf("Elemento removido com sucesso!\n");
            else
                printf("Elemento não encontrado!\n");
        }
    }
}

void push(node **head, node **tail, char *name){
    node *new = (node*)malloc(sizeof(node));
    node *aux = (*head);
    bool inserido = false;

    if((*head) == NULL){//Lista vazia
        printf("\n1\n");
        strcpy(new->nome, name);
        new->next = NULL;
        (*head) = new;
        (*tail) = new;
    }

    else if((*head) == (*tail)){ //Apenas um elemento
        if(strcmp(name, (*head)->nome) < 0){
            printf("\n2.1\n");
            strcpy(new->nome, name);
            new->next = (*head);
            (*head)->next = NULL;
            (*tail) = (*head);
            (*head) = new;
        }

        else if(strcmp(name, (*head)->nome) >= 0){
            printf("\n2.2\n");
            strcpy(new->nome, name);
            new->next = NULL;
            (*head)->next = new;
            (*tail) = new;
        }
    }

    else if(strcmp(name, (*head)->nome) < 0){
        strcpy(new->nome, name);
        new->next = (*head);
        (*head) = new;
    }

    else if(strcmp(name, (*tail)->nome) > 0){ //Maior que o tail
        printf("\n3\n");
        strcpy(new->nome, name);
        new->next = NULL;
        (*tail)->next = new;
        (*tail) = new;
    }

    else{ //Resto
        while (aux->next != NULL && !inserido){
            printf("\n4\n");
            if(strcmp(name, aux->nome) > 0 && strcmp(name, aux->next->nome) <= 0){
                strcpy(new->nome, name);
                new->next = aux->next;
                aux->next = new;
                inserido = true;
            }
            aux = aux->next;
        }
    }
}

void show(node **head){
    node *aux = (*head);
    int op;
    while (aux != NULL){
        printf("\n\nNome: %s\n", aux->nome);
        printf("Next: %p\n", aux->next);
        printf("(1)-Next || (2)-Sair: ");
        scanf("%d", &op);
        switch (op){
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
    node *tail = NULL;
    char nome[64];
    char input[64];

    for(int i = 0; i < 5; i++){
        setbuf(stdin, NULL);
        scanf("%[^\n]s", nome);
        push(&head, &tail, nome);
    }
    show(&head);
    setbuf(stdin, NULL);
    scanf("%[^\n]s", input);
    pop(&head, &tail, input);;
    show(&head);
    setbuf(stdin, NULL);
    scanf("%[^\n]s", input);
    pop(&head, &tail, input);
    show(&head);
    setbuf(stdin, NULL);
    scanf("%[^\n]s", input);
    pop(&head, &tail, input);
    show(&head);
    return 0;
}