#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

typedef struct nodes{
    int num;
    struct nodes *next;
    struct nodes *prev;
}node;

void pop(node **head, node **tail, int n){
    node *aux, *aux2;
    bool removido = false;
    if((*head) == NULL)
        printf("\nA lista não possui nenhum elemento para ser removido!\n");
    else{
        if((*head) == (*tail) && n == (*head)->num){ //Remoção do último elemento
            aux = (*head);
            (*head) == NULL;
            (*tail) == NULL;
            free(aux);
            removido = true;
        }
        else if(n == (*head)->num){ //Remoção do head
            aux = (*head);
            (*head)->next->prev = NULL;
            (*head) = (*head)->next;
            free(aux);
            removido = true;
        }
        else if(n == (*tail)->num){ //Remoção do tail
            aux = (*tail);
            (*tail)->prev->next = NULL;
            (*tail) = (*tail)->prev;
            free(aux);
            removido = true;
        }
        else{
            aux = (*head);
            while (aux != NULL && !removido){
                if(n == aux->num){
                    aux2 = aux;
                    aux->prev->next = aux->next;
                    aux->next->prev = aux->prev;
                    free(aux2);
                    removido = true;
                }  
                aux = aux->next; 
            }
        }
    }
}

void push(node **head, node **tail, int n){
    node *new = (node*)malloc(sizeof(node));
    node *aux;
    bool inserido = false; //Evita repetições desncecessárias

    if((*head) == NULL){ //Primeira inserção
        new->num = n;
        new->next = NULL;
        new->prev = NULL;
        (*head) = new;
        (*tail) = new;
    }

    else if((*head) == (*tail)){ //Segunda inserção
        if(n >= (*head)->num){
            new->num = n;
            new->next = NULL;
            new->prev = (*head);
            (*head)->next = new;
            (*tail) = new;
        }

        else if(n <= (*head)->num){
            new->num = n;
            new->next = (*head);
            new->prev = NULL;
            (*head)->prev = new;
            (*head)->next = NULL;
            (*tail) = (*head);
            (*head) = new;
        }
    }

    else if(n >= (*tail)->num){ //Caso possa ser uma nova tail
        new->num = n;
        new->next = NULL;
        new->prev = (*tail);
        (*tail)->next = new;
        (*tail) = new;
    }

    else if(n <= (*head)->num){ //Caso possa ser uma head
        new->num = n;
        new->next = (*head);
        new->prev = NULL;
        (*head)->prev = new;
        (*head) = new;
    }

    //Demais casos
    else{
        aux = (*head)->next;
        while (aux != (*tail) && !inserido){
            if(n >= aux->num && n <= aux->next->num){
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
    if((*head) == NULL)
        printf("\nNão existem elementos para serem mostrados!\n");

    else{
        while(aux != NULL){
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
                    aux = NULL;
                    break;

                default:
                    break;
            }
        }
    }
}

void generateFile(){
    FILE *fp;

    if((fp=fopen("topush.txt", "w+")) == NULL)
        printf("\nErro na criação do arquvivo!\n");
    else{
        srand(rand()%101);
        for(int i = 0; i < MAX; i++)
            fprintf(fp, "%d ", rand()%1001);
        fclose(fp);
    }
}

void pushFromFile(node **head, node **tail){
    FILE *fp;
    int toPush;
    bool parar = false;

    if((fp = fopen("topush.txt", "r+")) == NULL)
        printf("\nErro! Arquivo topush.txt não encontrado na raiz do programa.\n");

    else{
        while(!feof(fp)){
            fscanf(fp, "%d", &toPush);
            push(&(*head), &(*tail), toPush);   
        }

        fclose(fp);
    }
}

void showHundred(node **head, node **tail){
    node *aux = (*head);
    int op;
    if((*head) == NULL)
        printf("\nNão existem elementos para serem mostrados!\n");

    else{
        for(int i = 0; i < MAX && aux != NULL; i ++){
            printf("\n\nElemento: %d\n", aux->num);
            printf("Endereço do elemnto atual: %p\n", aux);
            printf("Next: %p || Prev: %p\n", aux->next, aux->prev);
            printf("Head: %p || Tail %p || Inserção: %d\n\n", (*head), (*tail), i+1);

            aux = aux->next;
        }
    }
}

void writeOnFile(node **head, node **tail){
    FILE *fp = fopen("output.txt", "w+");
    node *aux = (*head);
    while(aux->next != NULL){
        fprintf(fp, "%d ", aux->num);
        aux = aux->next;
    }
}

int main(){
    node *head = NULL, *tail = NULL;
    bool sair = false;
    int op, num;

    while (!sair) {
        printf("\n\t----Menu----\n\n");
        printf("(1)-Gerar arquivo e inserir por ele\n");
        printf("(2)-Remover\n");
        printf("(3)-Mostrar\n");
        printf("(4)-Mostrar os 100\n");
        printf("(-1)-Sair\n");
        printf("Resposta: ");
        scanf("%d", &op);
        switch (op) {
            case 1:;
                generateFile();
                pushFromFile(&head, &tail);
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
                showHundred(&head, &tail);
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