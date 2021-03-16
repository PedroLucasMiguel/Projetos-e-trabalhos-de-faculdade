#include <iostream>
#include <string>

int main(){

    std::string a = "Hey! Finalmente strings existem!\n";

    std::cout << a;

    a = a + " || E da para concaternar usando operadores!\n";

    std::cout << a;

    return 0;
}