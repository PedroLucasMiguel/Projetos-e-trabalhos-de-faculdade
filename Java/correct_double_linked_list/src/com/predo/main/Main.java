package com.predo.main;

import com.predo.classes.DoubleLinked;

import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        DoubleLinked list1 = new DoubleLinked();
        boolean exit  = false;
        int op;
        int input;
        Scanner sc = new Scanner(System.in);
        while (!exit){
            System.out.println("\n\n\t----Lista duplamente encadeada em java!----\n");
            System.out.println("(1) - Inserir");
            System.out.println("(2) - Remover");
            System.out.println("(3) - Mostrar");
            System.out.println("(4) - Sair");
            System.out.println("Resposta: ");
            op = sc.nextInt();
            switch (op){
                case 1:
                    System.out.println("Digite um numero: ");
                    input = sc.nextInt();
                    list1.push(input);
                    break;
                case 2:
                    System.out.println("Digite um numero: ");
                    input = sc.nextInt();
                    list1.pop(input);
                    break;
                case 3:
                    list1.print();
                    break;
                case 4:
                    System.out.println("\n\tFinalizando....\n");
                    exit = true;
                    break;
            }
        }
    }
}
