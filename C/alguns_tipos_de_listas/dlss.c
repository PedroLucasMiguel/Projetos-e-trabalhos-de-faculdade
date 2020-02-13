#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct nodes{
    int num;
    struct nodes *next;
    struct nodes *prev;
}node;

//Meu lindo bb que insere arrumadinho, tenho muito orgulho dele
void sortedInsertion(node **head, node **tail, int n, int *totalI){
    node *new = (node*)malloc(sizeof(node));
    node *aux, *prox;
    bool inserido = false;

    //Primeira inserção
    if((*head) == NULL){
        new->num = n;
        new->next = NULL;
        new->prev = NULL;
        (*head) = new;
        (*tail) = (*head);
        (*totalI)++;
    }

    //Apenas um elemento
    else if((*head) == (*tail)){
        if(n > (*head)->num){
            new->num = n;
            new->next = NULL;
            new->prev = (*head);
            (*head)->next = new;
            (*tail) = new;
            (*totalI)++;
        }
        
        else{
            new->num = n;
            new->next = (*head);
            new->prev = NULL;
            (*head)->prev = new;
            (*head) = new;
            (*totalI)++;
        }
    }

    //Demais inserções

    //Caso o elemento a ser inserido seja maior que o tail
    else if(n > (*tail)->num){
        new->num = n;
        new->next = NULL;
        new->prev = (*tail);
        (*tail)->next = new;
        (*tail) = new;
        (*totalI)++;
    }

    //Caso o elemento a ser inserido seja menor que minha head
    else if(n < (*head)->num){
        new->num = n;
        new->prev = NULL;
        new->next = (*head);
        (*head)->prev = new;
        (*head) = new;
        (*totalI)++;
    }

    else{
        aux = (*head);
        while(aux != NULL && !inserido){
            if(n > aux->num && n < aux->next->num){
                new->num = n;
                new->next = aux->next;
                new->prev = aux;
                aux->next->prev = new;
                aux->next = new;
                (*totalI)++;
                inserido = true;
            }
            aux = aux->next;
        }
    }
}

//eu estava fazendo litreralmente a mesma coisa que o geeks for geeks estava falando para fazer e estava errado
//copiei o codigo deles mudando os nomes de variaveis e deu certo
//eu odeio minha vida de verdade
void selection(node **head){
    node *aux = (*head), *min, *r;
    int c;

    while(aux != NULL){
        min = aux;
        r = aux->next;

        while(r != NULL){
            if(min->num > r->num)
                min = r;
            r = r->next;
        }

        c = aux->num;
        aux->num = min->num;
        min->num = c;

        aux = aux->next;
    }    
}

void insertion(node **head, node **tail){
    node *aux, *aux2 = (*head)->next; //Sempre começo no segundo elemento para fazer a comparação
    int c;                            //Com o elemento anterior
    bool parar = false;

    while(aux2 != NULL){
        aux = aux2; //Faz com que a cada inicio de ciclo
        //Eu esteja sempre uma posição a frente de onde eu comecei a ordenar

        while (aux->prev->num > aux->num){
            c = aux->prev->num;
            aux->prev->num = aux->num;
            aux->num = c;
            if(aux->prev->prev != NULL) //Se eu conseguir andar para para o prev sem que o próximo prev
                aux = aux->prev;        //se torne nulo, faça com que o auxiliar se torne o prev
        }

        aux2 = aux2->next; //Caminha para frente enquanto o aux2 não for o tail
                           //Ja que e o prev do tail é NULL
    }
}

void bublle(node **head, node **tail, int *totalI){
    int c;
    node *aux;
    if((*head) == NULL || (*totalI) == 1)
        printf("Não é possível ordenar\n");
    else{
        for(int i = 0; i < (*totalI)-1; i++){
            aux = (*head);
            for(int j = 0; j < (*totalI)-1-i; j++){
                if(aux->num > aux->next->num){
                    c = aux->next->num;
                    aux->next->num = aux->num;
                    aux->num = c;
                }
                aux = aux->next;
            }
        }
    }
}

void pop(node **head, node **tail, int n, int *totalI){
    node *aux, *aux2;

    if((*head) == NULL)
        printf("Nada pode ser removido\n");
    
    else if((*head) == (*tail) && (*head)->num == n){
        aux = (*head);
        (*tail) = NULL;
        (*head) = NULL;
        free(aux);
        (*totalI)--;
    }

    else if((*head)->num == n){
        aux = (*head);
        (*head) = (*head)->next;
        (*head)->prev = NULL;
        free(aux);
        (*totalI)--;
    }

    else if((*tail)->num == n){
        aux = (*tail);
        (*tail) = (*tail)->prev;
        (*tail)->next = NULL;
        free(aux);
        (*totalI)--;
    }

    else{
        aux = (*head)->next;
        bool removido = false;
        while(aux != NULL && !removido){
            if(aux->num == n){
                aux2 = aux;
                aux->next->prev = aux->prev;
                aux->prev->next = aux->next;
                aux = aux->next;
                free(aux2);
                removido = true;
                (*totalI)--;
            }
            aux = aux->next;
        }
        if(!removido)
            printf("Elemento não encontrado\n");
    }
}

void push(node **head, node **tail, int n, int *totalI){
    node *new = (node*)malloc(sizeof(node));

    //vazio
    if((*head) == NULL){
        new->num = n;
        new->next = NULL;
        new->prev = NULL;
        (*head) = new;
        (*tail) = (*head);
        (*totalI)++;
    }

    //Apenas um elemento
    else if((*head) == (*tail)){
        new->num = n;
        new->next = NULL;
        new->prev = (*tail);
        (*tail) = new;
        (*head)->next = (*tail);
        (*totalI)++;
    }

    //Demais elementos
    else{
        new->num = n;
        new->next = NULL;
        new->prev = (*tail);
        (*tail)->next = new;
        (*tail) = new;
        (*totalI)++;
    }
}

void randomGenerate(node **head, node **tail, int *totalI){
    srand(123);
    for(int i = 0; i < 10; i++)
        push(&(*head), &(*tail), rand()%100, totalI);
}

void show(node **head, node **tail){
    node *aux = (*head);
    bool sair = false;
    int op;

    printf("\n\t----Resultados----\n");

    if(aux == NULL){
        printf("Nada pode ser mostrado\n");
    }

    while (aux != NULL){
        printf("Numero: %d\n", aux->num);
        printf("Endereco: %p\n", aux);
        printf("Next: %p || Prev: %p\n", aux->next, aux->prev);
        printf("Head: %p || Tail: %p\n", (*head), (*tail));
        printf("(1) - Next || (2) - Prev || (3) - Sair: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            aux = aux->next;
            break;
        
        case 2:
            aux = aux->prev;
            break;
        
        case 3:
            aux = NULL;
            break;
        }
    }
    
}

int main(){
    node *head = NULL, *tail = NULL;
    bool sair = false;
    int op, num, totalInsert = 0;
    while(!sair){
        printf("\t\n\n----The ultimate estudo para o filho de uma puta do Aleardo----\n");
        printf("\tTipo da lista: Duplamente encadeada\n\n");
        printf("(1)  - Inserir\n");
        printf("(2)  - Remover\n");
        printf("(3)  - Mostrar\n");
        printf("(4)  - Gerar aleatorios\n");
        printf("(5)  - Bubble\n");
        printf("(6)  - Insertion\n");
        printf("(7)  - Selection\n");
        printf("(8)  - Insercao ordenada (nao funciona corretamente se a lista se encontra desorganizada)\n");
        printf("(12) - Sair\n");
        printf("Resposta: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Digite um numero: ");
            scanf("%d", &num);
            push(&head, &tail, num, &totalInsert);
            break;
        
        case 2:
            printf("Digite um numero: ");
            scanf("%d", &num);
            pop(&head, &tail, num, &totalInsert);
            break;
        
        case 3:
            show(&head, &tail);
            break;

        case 4:
            randomGenerate(&head, &tail, &totalInsert);
            break;

        case 5:
            bublle(&head, &tail, &totalInsert);
            break;
        
        case 6:
            insertion(&head, &tail);
            break;

        case 7:
            selection(&head);
            break;

        case 8:
            printf("Digite um numero: ");
            scanf("%d", &num);
            sortedInsertion(&head, &tail, num, &totalInsert);
            break;

        case 12:
            sair = true;
            break;
        
        default:
            break;
        }
    }

    return 0;
}