package predo.javacore.main;

import predo.javacore.classes.Lista;

public class Main {
    public static void main(String[] args) {
        Lista nova = new Lista();
        nova.inserir(2, nova);
        nova.inserir(1, nova);
        nova.mostrar(nova);
    }
}
