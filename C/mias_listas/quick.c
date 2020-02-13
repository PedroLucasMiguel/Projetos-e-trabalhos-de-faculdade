#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 200000

void swap(int *a, int *b){
    int c = (*a);
    (*a) = (*b);
    (*b) = c;
}

int partition(int *vet, int low, int high){
    int i = low-1;
    int pivot = vet[high];
    for(int j = low; j < high; j++){
        if(vet[j] < pivot){
            i++;
            swap(&vet[j], &vet[i]);
        }
    }
    i++;
    swap(&vet[i], &vet[high]);
    return i;
}

void quickSort(int *vet, int low, int high){
    if(low < high){
        int pi = partition(vet, low, high);

        quickSort(vet, pi+1, high);
        quickSort(vet, low, pi-1);
    }
}

void export(int *vet, int type){
    FILE *fp;

    if(type == 1)
        fp = fopen("original.txt", "w+");
    else
        fp = fopen("output.txt", "w+");
    
    for(int i = 0; i < MAX; i++){
        if(i%10 == 0){
            fprintf(fp, "\n");
            fprintf(fp, "%d ", vet[i]);
        }
        fprintf(fp, "%d ", vet[i]);
    }

    fclose(fp);
}

int main(){
    int vet[MAX];
    srand(123);
    for(int i = 0; i < MAX; i++){
        vet[i] = rand()%MAX+1;
    }
    export(vet, 1);
    quickSort(vet, 0, MAX-1);
    export(vet, 2);
    return 0;
}