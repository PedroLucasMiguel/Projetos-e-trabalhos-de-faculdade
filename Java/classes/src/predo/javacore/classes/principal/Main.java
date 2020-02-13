package predo.javacore.classes.principal;

import predo.javacore.classes.estudante.Estudante;

public class Main {
    public static void main(String[] args){
        Estudante novo = new Estudante();

        novo.nome = "Pedro";
        novo.matricula = "16sadsad";
        novo.idade = 10;
        novo.media = 8.5F;

        novo.mostrar();
    }
}
