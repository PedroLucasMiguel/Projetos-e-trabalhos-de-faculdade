#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define max 13

//Usada na maioria dos sorts para realizar a troca de variaveis
void swap(int *n1, int *n2){
    int c = (*n1);
    (*n1) = (*n2);
    (*n2) = c;
}

void merge(int *vet, int low, int mid, int high){
    int com1 = low, com2 = mid+1, comAux = 0, tamanho = (high-low)+1;
    int *vetAUX = (int*)malloc(tamanho*sizeof(int));

    while (com1 <= mid && com2 <= high){
        if(vet[com1] < vet[com2]){
            vetAUX[comAux] = vet[com1];
            com1++;
        }
        else{
            vetAUX[comAux] = vet[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= mid){
        vetAUX[comAux] = vet[com1];
        com1++;
        comAux++;
    }

    while (com2 <= high){
        vetAUX[comAux] = vet[com2];
        com2++;
        comAux++;
    }
    
    for(int i = low; i <= high; i++)
        vet[i] = vetAUX[i-low];

    free(vetAUX);
}

void mergeSort(int *vet, int low, int high){
    if(low < high){
       int meio = (high+low)/2;
       mergeSort(vet, low, meio);
       mergeSort(vet, meio+1, high);
       merge(vet, low, meio, high);
    }
}

int partition(int *vet, int low, int high){
    int i = low-1;
    int pivot = vet[high];
    for(int j = low; j <= high-1; j++){
        if(vet[j] < pivot){
            i++;
            swap(&vet[i], &vet[j]);
        }
    }
    swap(&vet[i+1], &vet[high]);
    return i+1;
}

void quicksort(int *vet, int low, int high){
    if(low < high){
        int pi = partition(vet, low, high);

        quicksort(vet, pi+1, high);
        quicksort(vet, low, pi-1);
    }
}

void selection(int *vet){
    int index;
    for(int i = 0; i < max; i++){
        index = i;
        for(int j = i+1; j < max; j++){
            if(vet[j] < vet[index])
                index = j;
        }
        swap(&vet[i], &vet[index]);
    }
} 

void insertion(int *vet){
    int j, key;
    for(int i = 1; i < max; i++){
        key = vet[i];
        j = i-1;
        while (j >= 0 && vet[j] > key){
            vet[j+1] = vet[j];
            j--;
        }

        vet[j+1] = key; 
    }
}

void bubble(int *vet){
    for(int i = 0; i < max-1; i++){
        for(int j = 0; j < max-1-i; j++){
            if(vet[j] > vet[j+1])
                swap(&vet[j], &vet[j+1]);
        }
    }
}

void printVet(int *vet){
    printf("\nArray: ");
    for(int i = 0; i < max; i++)
        printf("%d ", vet[i]);
    printf("\n");
}

void generate(int *vet){
    srand(123);
    for(int i = 0; i < max; i++)
        vet[i] = rand()%30;
}

int main(){
    int vet[max];
    generate(vet);
    //bubble(vet);
    //insertion(vet);
    //selection(vet);
    //quicksort(vet, 0, max-1);
    mergeSort(vet, 0, max-1);
    printVet(vet);
    return 0;
}