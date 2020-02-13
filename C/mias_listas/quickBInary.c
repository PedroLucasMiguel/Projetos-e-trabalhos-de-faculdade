#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define m 100

int binary(int *vet, int n,int low, int high){
    if(low < high){
        int mid = (high-low);

        if(vet[mid] == n)
            return vet[mid];
        
        else if(n > vet[mid])
            binary(vet, n, mid+1, high);

        else
            binary(vet, n, low, mid-1);
    }

    else{
        return -1;
    }
}

void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

int partition(int *vet, int low, int high){
    int i = low-1;
    int pivot = vet[high];
    for(int j = low; j <= high-1; j++){
        if(vet[j] < pivot){
            i++;
            swap(&vet[j], &vet[i]);
        }
    }
    i++;
    swap(&vet[high], &vet[i]);
    return i; 
}

void quickSort(int *vet, int low, int high){
    if(low < high){
        int pi = partition(vet, low, high);

        quickSort(vet, low, pi-1);
        quickSort(vet, pi+1, high);
    }
}

void generate(int *vet){
    srand(123);
    for(int i = 0; i < m; i++)
        vet[i] = rand()%101;
}

int main(){
    int vet[m];

    generate(vet);
    quickSort(vet, 0, m-1);
    for(int i = 0; i < 10; i++)
        printf("%d ", vet[i]);
    printf("\n%d\n", binary(vet, 4, 0, m-1));
    return 0;
}