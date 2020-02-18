package com.predo.javacore.main;

import com.predo.javacore.classes.DoubleLinked;

import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        DoubleLinked list = new DoubleLinked();//Crio a instancia do objeto
        boolean exit = false;
        int op;
        int num;
        Scanner scan = new Scanner(System.in);

        while(!exit){
            System.out.println("\t----Lista duplamente encadeada em JAVA com serializacao e deserializacao---\n");
            System.out.println("Opcoes:");
            System.out.println("(1)-Carregar lista de um arquivo || (2)-Criar lista nova");
            op = scan.nextInt();

            switch (op){
                case 1:
                    list.deserialize();
                    exit = true;
                    break;
                case 2:
                    exit = true;
                    break;
                default:
                    System.out.println("\t\nOpcao invalida!\n");
                    break;
            }
        }

        exit = false;

        while(!exit){
            System.out.println("\n\t----Opcoes da lista----\n");
            System.out.println("(1)-Inserir || (2)-Remover || (3)-Mostrar");
            System.out.println("(4)-Serializar || (5)-Sair");
            op = scan.nextInt();
            switch (op){
                case 1:
                    System.out.println("Digite um numero");
                    num = scan.nextInt();
                    list.push(num);
                    break;
                case 2:
                    System.out.println("Digite um numero");
                    num = scan.nextInt();
                    list.pop(num);
                    break;
                case 3:
                    list.print();
                    break;
                case 4:
                    list.serialize();
                    break;
                case 5:
                    exit = true;
                    list.serialize();
                    System.out.println("Finalizando programa....");
                    break;
            }
        }
    }
}
