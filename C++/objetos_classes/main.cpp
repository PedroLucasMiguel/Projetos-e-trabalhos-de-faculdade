#include "pessoa.cpp"
#include <iostream>
#include <string>

int main(){

    Pessoa pessoa;
    Pessoa* pessoa2;

    pessoa.criar_pessoa("Jooj", "jiij", "12/12/12");

    pessoa.print_pessoa();

    return 0;
}
