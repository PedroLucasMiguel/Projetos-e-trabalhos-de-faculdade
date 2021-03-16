#include <iostream>
#include <climits> // Biblioteca que inclui o valor máximo de cada tipo de variável
                   // Não que o sizeof() não consiga resolver, mas o povo de C++ é bem chato com isso

int main(){

    int numero_legal = 12;

    std::cout << "Mostrarei um numero bem legal: " << numero_legal << " mas isso n deixa de ser feio ;-;\n";
    std::cout << "Agora digite um numero legal tbm \\o/: ";
    std::cin >> numero_legal;
    std::cout << "Mostrarei seu numero bem legal: " << numero_legal << std::endl;
    std::cout << INT_MAX << std::endl; // Printa o valor máximo de um int
    printf("Eu ja estou incluso!");
    std::cout << static_cast<int>(numero_legal) << std::endl; // static_cast<type>(variable) = jeio "certo" de fazer cast em C++

    return 0;
}