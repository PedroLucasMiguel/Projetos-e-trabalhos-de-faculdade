#include <iostream>
#include <string>

class Pessoa{
    std::string nome;
    std::string sobrenome;
    std::string nascimento;

    public:
        void criar_pessoa(std::string nome_in, std::string sobrenome_in, std::string nascimento_in){
            this->nome = nome_in;
            this->sobrenome = sobrenome_in;
            this->nascimento = nascimento_in;
        }

        void print_pessoa(){
            std::cout << "Nome: " << nome << " Sobrenome: " << sobrenome << " Nascimento: " << nascimento << std::endl;
        }
};