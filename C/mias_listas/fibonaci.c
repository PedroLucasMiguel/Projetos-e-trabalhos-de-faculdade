#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int fibonacci(int termos){
    
    if(termos == 1 || termos == 2)
        return 1;

    else
        return (fibonacci(termos-1) + fibonacci(termos-2));
}

int main(){

    printf("%d", fibonacci(9));

    return 0;
}