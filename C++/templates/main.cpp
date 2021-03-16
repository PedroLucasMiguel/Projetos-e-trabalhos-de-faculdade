#include <iostream>
#include <string>

// Templates permitem criar funções com tipos de dados genéricos
// Oq eu fiz neste caso, foi criar uma variavel genérica de nome T, que basicamente consegue armazenar
// qualquer tipo de valor. Assim, permite que eu faça a troca de varios tipos de valores em qualquer tipo
// de variável :)
template <typename T>
void swap(T &var1, T &var2){
    T aux = var1;
    var1 = var2;
    var2 = aux;
}

int main(){
    int a = 10;
    int b = 20;

    swap(a, b);
    std::cout << a << "||" << b << std::endl;

    std::string x = "Jooj";
    std::string y = "Jaaj";

    swap(x, y);

    std::cout << x << "||" << y << std::endl;

    return 0;
}