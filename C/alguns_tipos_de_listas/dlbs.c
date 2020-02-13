#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodes{
    int num;
    struct nodes *next;
    struct nodes *prev;
}node;

int countElements(node **head, node **tail){
    node *aux = (*head);
    int count = 0;
    while(aux != NULL){
        count++;
        aux = aux->next;
    }
    return count;
}

node *binary(node **head, node **tail, int n, int l, int h, node **low){ //node **low = elemento que sera referente ao low. Usado para tirar a necessidade de utilizar mais laços de repetição
    bool found = false;
    if(l < h){
        int i, j;
        node *aux = (*low);
        int mid = (h+l)/2;

        //Caminha até mid
        for(j = l; j <= mid; j++)
            aux = aux->next;

        if(aux->num == n)
            return aux;
        
        if(n > aux->num){
            aux = aux->next;
            binary(&(*head), &(*tail), n, mid+1, h, &aux);
        }
    
        else
            binary(&(*head), &(*tail), n, l, mid-1, &aux);
    }
}

int pop(node **head, node **tail, int n){
    node *aux;

    //Remoção do unico elemento na lista
    if((*head) == (*tail)){
        aux = (*head);
        (*head) = NULL;
        (*tail) = NULL;
        free(aux);
    }
    
    //Caso seja o head
    else if((*head)->num == n){
        aux = (*head);
        (*head)->next->prev == NULL;
        (*head) = (*head)->next;
        free(aux);
    }

    //Caso seja o tail
    else if((*tail)->num == n){
        aux = (*tail);
        (*tail)->prev->next = NULL;
        (*tail) = (*tail)->prev;
        free(aux);
    }
    
    //O resto
    else {
        node *toRemove = binary(&(*head), &(*tail), n, 0, countElements(&(*head), &(*tail)), &(*head));

        if(toRemove != NULL){
            toRemove->prev->next = toRemove->next;
            toRemove->next->prev = toRemove->prev;
            free(toRemove);
        }

        else
            return -1;
    }
}

void push(node **head, node **tail, int n){
    node *new = (node*)malloc(sizeof(node));
    node *aux = (*head);
    bool inserido = false; //Evita repetições desnecessárias no loop de iserção

    //Primeiro elemento
    if((*head) == NULL){
        new->num = n;
        new->next = NULL;
        new->prev = NULL;
        (*head) = new;
        (*tail) = new;
    }

    //Segundo elemento
    else if((*head) == (*tail)){
        if(n >= (*head)->num){ //Se maior do que o valor da minha head, coloque ele na frente
            new->num = n;
            new->next = NULL;
            new->prev = (*head);
            (*head)->next = new;
            (*tail) = new;
        }
        else{ //Se for menor, torne o novo head
            new->num = n;
            new->next = (*head);
            new->prev = NULL;
            (*head)->prev = new;
            (*tail) = (*head);
            (*head) = new;
        }
    }

    //Demais elementos
    else if(n >= (*tail)->num){ //Maior que o tail torna o novo tail
        new->num = n;
        new->next = NULL;
        new->prev = (*tail);
        (*tail)->next = new;
        (*tail) = new;
    }

    else{
        while(aux != NULL && !inserido){
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

void printList(node **head, node **tail){
    node *aux = (*head);
    int op;
    printf("\n\t----Mostrando lista----\n");
    if(aux == NULL)
        printf("\nLista vazia, nada pode ser mostrado\n");
    while(aux != NULL){
        printf("Numero: %d\n", aux->num);
        printf("Next: %p || Prev: %p\n", aux->next, aux->prev);
        printf("Endereco do elemento atual: %p\n", aux);
        printf("Head: %p || Tail: %p\n\n", (*head), (*tail));
        printf("(1)-Next || (2)-Prev || (3)-Sair\n");
        printf("Resposta: ");
        scanf("%d", &op);
        printf("\n\n");
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

void generate20(node **head, node **tail){
    for(int i = 1; i <= 20; i++)
       push(&(*head), &(*tail), i); 
}

void binarySearch(node **head, node **tail, int n){
    node *aux = binary(&(*head), &(*tail), n, 0, countElements(&(*head), &(*tail)), &(*head));
    if(aux == NULL)
        printf("\nElemento não encontrado na lista\n");
    else{
        printf("\nElemento encontrado!\n");
        printf("Valor: %d || Endereço de memória: %p\n", aux->num, aux);
    }
}

int main(){
    node *head = NULL, *tail = NULL;
    bool sair = false;
    int op, num;
    //system("clear");
    while(!sair){
        printf("\n\t----MENU----\n");
        printf("(1)-Inserir elemento\n");
        printf("(2)-Remover elemento\n");
        printf("(3)-Busca binaria por elemento\n");
        printf("(4)-Mostrar lista\n");
        printf("(5)-Adicionar 20 valores a lista\n");
        printf("(-1)-Sair do programa\n");
        printf("Resposta: ");
        scanf("%d", &op);
        switch (op){
        case 1:
            printf("Numero: ");
            scanf("%d", &num);
            push(&head, &tail, num);
            break;

        case 2: //Sim é feio fazer isso mas ta valendo
            if(head == NULL)
                printf("Nada pode ser removido");
            else{
                printf("Numero: ");
                scanf("%d", &num);
                if((pop(&head, &tail, num)) == -1)
                    printf("\n\nElemento não encontrado\n\n");
            }
            break;
        
        case 3:
            printf("Numero: ");
            scanf("%d", &num);
            binarySearch(&head, &tail, num);
            break;

        case 4:
            printList(&head, &tail);
            break;

        case 5:
            generate20(&head, &tail);
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
