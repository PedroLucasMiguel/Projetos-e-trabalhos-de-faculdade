#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct nodes{
    char nome[64];
    struct nodes *next;
    struct nodes *prev;
}node;

void pop(node **head, node **tail, char *name){
    node *aux, *aux2;
    bool removido = false;

    if((*head) == NULL)
        printf("Impossivel remoção, lista vazia!\n");
    else{
        if((*head) == (*tail) && strcmp(name, (*head)->nome) == 0){
            aux = (*head);
            (*head) = NULL;
            (*tail) = NULL;
            free(aux);
            removido = true;
        }

        else if(strcmp(name, (*head)->nome) == 0){ //Remoção do head
            aux = (*head);
            (*head)->next->prev = NULL;
            (*head) = (*head)->next;
            free(aux);
            removido = true;
        }

        else if(strcmp(name, (*tail)->nome) == 0){ //Remoção tail
            aux = (*tail);
            (*tail)->prev->next = NULL;
            (*tail) = (*tail)->prev;
            free(aux);
            removido = true;
        }

        else{
            aux = (*head)->next;
            while(aux != NULL && !removido){
                if(strcmp(aux->nome, name) == 0){
                    aux2 = aux;
                    aux->prev->next = aux->next;
                    aux->next->prev = aux->prev;
                    free(aux2);
                    removido = true;
                }
                aux = aux->next;
            }
        }

        if(!removido)
            printf("Elemento não encontrado na lista!\n");
    }
}

void push(node **head, node **tail, char *name){
    node *new = (node*)malloc(sizeof(node));
    node *aux;
    bool inserido = false;

    if((*head) == NULL){ //Primeira inserção
        strcpy(new->nome, name);
        new->next = NULL;
        new->prev = NULL;
        (*head) = new;
        (*tail) = new;
    }

    else if((*head) == (*tail)){ //Segunda inserção
        if(strcmp(name, (*head)->nome) >= 0){
            strcpy(new->nome, name);
            new->next = NULL;
            new->prev = (*head);
            (*head)->next = new;
            (*tail) = new;
        }
        else if(strcmp(name, (*head)->nome) <= 0){
            strcpy(new->nome, name);
            new->next = (*head);
            new->prev = NULL;
            (*tail) = (*head);
            (*head)->prev = new;
            (*head) = new;
        }
    }

    else if(strcmp(name, (*tail)->nome) > 0){
        strcpy(new->nome, name);
        new->next = NULL;
        new->prev = (*tail);
        (*tail)->next = new;
        (*tail) = new;
    }

    else if(strcmp(name, (*head)->nome) < 0){
        strcpy(new->nome, name);
        new->next = (*head);
        new->prev = NULL;
        (*head)->prev = new;
        (*head) = new;
    }

    else{
        aux = (*head);
        while(aux != NULL && !inserido){
            if(strcmp(name, aux->nome) >= 0 && strcmp(name ,aux->next->nome) <= 0){
                strcpy(new->nome, name);
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

    if((*head) == NULL)
        printf("\nNão existem elementos na lista!\n");
    else{
        while(aux != NULL){
            printf("\n\nNome: %s\n", aux->nome);
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
                    aux = NULL;
                    break;

                default:
                    break;
            }
        }
    }
}

int main(){
    node *head = NULL, *tail = NULL;
    char nome[64];

    for(int i = 0; i < 5; i++){
        setbuf(stdin, NULL);
        scanf("%[^\n]s", nome);
        push(&head, &tail, nome);
    }
    
   for(int i = 0; i < 5; i++){
        setbuf(stdin, NULL);
        scanf("%[^\n]s", nome);
        pop(&head, &tail, nome);

        show(&head, &tail);
    }

    return 0;
}