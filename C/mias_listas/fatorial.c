#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned int fac(unsigned int n){
    if(n == 0)
        return 1;

    else
        return n*fac(n-1);
}

int main(){

    printf("%d", fac(12));

    return 0;
}