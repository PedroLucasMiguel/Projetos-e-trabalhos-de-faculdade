package predo.javacore.main;

import predo.javacore.classes.List;

public class Main {
    public static void main(String[] args) {
        List lista = new List();

        lista.push(0);
        lista.push(8);
        lista.push(64);

        lista.print();

        System.out.println("###############");
        lista.pop(8);
        System.out.println("###############");
        lista.print();

        System.out.println("###############");
        lista.pop(0);
        System.out.println("###############");
        lista.print();

        System.out.println("###############");
        lista.pop(64);
        System.out.println("###############");
        lista.print();

        System.out.println("###############");
        lista.pop(7);
        System.out.println("###############");
        lista.print();

    }
}
