package com.predo.javacore.classes;

import java.io.*;
import java.util.Scanner;

public class DoubleLinked implements Serializable{
    private int num;
    private DoubleLinked next;
    private DoubleLinked prev;
    private static DoubleLinked head; //Permanencia do mesmo valor de head para cada novo objeto criado
    private static DoubleLinked tail; //O mesmo vale para tail

    private static void changeHead(DoubleLinked newHead){ //Como head é um elemento estático, precisamos de um método estático também!
        head = newHead;
    }

    private static void changeTail(DoubleLinked newTail){
        tail = newTail;
    }

    public void serialize(){
        try {
            FileOutputStream file = new FileOutputStream("list.bin");
            ObjectOutputStream oout = new ObjectOutputStream(file);
            oout.writeObject(this);
            oout.close();
            file.close();
            System.out.println("\n\tLista serializada com sucesso!\n");
        } catch (IOException e) {
            System.out.println("\n\tERRO! Arquivo de sereializacao nao pode ser criado aqui!");
        }
    }

    public void deserialize(){
        try {
            FileInputStream file = new FileInputStream("list.bin");
            ObjectInputStream oinput = new ObjectInputStream(file);
            head = (DoubleLinked) oinput.readObject();
            oinput.close();
            file.close();
            System.out.println("\n\tObjeto lido do arquivo com sucesso!");
        } catch (IOException | ClassNotFoundException e) {
            System.out.println("\n\tERRO! Nenhum arquivo pode ser carregado! Inicializando nova lista");
        }
    }

    public void push(int num){
        //Primeira inserção
        if(head == null){
           this.num = num;
           this.next = null;
           this.prev = null;
           changeHead(this);
           changeTail(this);
        }

        //Segunda inserção
        else if(head.next == null){
            if(num >= head.num){ //Maior que meu head atual
                head.next = new DoubleLinked();
                head.next.num = num;
                head.next.next = null;
                head.next.prev = head;
                changeTail(head.next);
            }
            else{ //Menor que meu head atual
                head.prev = new DoubleLinked();
                head.prev.num = num;
                head.prev.prev = null;
                head.prev.next = head;
                changeTail(head);
                changeHead(head.prev); //O elemento inserido se torna o novo head!
            }
        }

        //Numero maior que o tail
        else if(num >= tail.num){
           tail.next = new DoubleLinked();
           tail.next.num = num;
           tail.next.next = null;
           tail.next.prev = tail;
           changeTail(tail.next);
        }

        //Numero menor que o tail
        else if(num < head.num){
            head.prev = new DoubleLinked();
            head.prev.num = num;
            head.prev.next = head;
            head.prev.prev = null;
            changeHead(head.prev);
        }

        //Demais inserções
        else{
            DoubleLinked aux = head;
            DoubleLinked newElement = new DoubleLinked();
            boolean inserted = false;
            while(!inserted){
              if(num >= aux.num && num <= aux.next.num){
                  newElement.num = num;
                  newElement.next = aux.next;
                  newElement.prev = aux;
                  aux.next.prev = newElement;
                  aux.next = newElement;
                  inserted = true;
              }
              if(aux.next != null){
                  aux = aux.next;
              }
            }
        }
    }

    public void pop(int num){
        if(head == null){
            System.out.println("\n\tImpossível remocao pois a lista se encontra vazia!\n");
        }
        else{
            boolean removed = false;
            boolean stop = false;
            if(num == head.num && head == tail){ //Remoção head==tail
                changeHead(null);
                changeTail(null);
                System.gc(); //Chama o garbage collector para limpar a memória
                removed = true;
            }

            else if(num == head.num){ //Remoção da head
                head.next.prev = null;
                changeHead(head.next);
                System.gc();
                removed = true;
            }

            else if(num == tail.num){
                tail.prev.next = null;
                changeTail(tail.prev);
                System.gc();
                removed = true;
            }

            else{
                DoubleLinked aux = head.next;
                while(!stop){
                    if(num == aux.num){
                        aux.prev.next = aux.next;
                        aux.next.prev = aux.prev;
                        System.gc();
                        removed = true;
                        stop = true;
                    }
                    if(aux.next != null){
                        aux = aux.next;
                    }
                    else{
                        stop = true;
                    }
                }
            }

            if(removed){
                System.out.println("\n\tElemento removido com sucesso!\n");
            }
            else{
                System.out.println("\n\tElemento nao encontrado!\n");
            }
        }
    }

    public void print(){
        DoubleLinked aux = head;
        int option;
        Scanner op = new Scanner(System.in);
        boolean exit = false;

        if(head == null){
            System.out.println("\n\tLista vazia! Impossivel impressao");
        }

        else{
            while (!exit){
                System.out.println("\nNumber: " + aux.num);
                System.out.println("Next: " + aux.next + " || Prev: " + aux.prev);
                System.out.println("Head: " + head + " || Tail: " + tail);
                System.out.println("This: " + aux);
                System.out.println("(1)-Next || (2)-Prev || (3)-Exit");
                option = op.nextInt();

                switch (option){
                    case 1:
                        aux = aux.next;
                        break;
                    case 2:
                        aux = aux.prev;
                        break;
                    case 3:
                        exit = true;
                        break;
                    default:
                        System.out.println("\n\tOperação invalida\n");
                        break;
                }

                if(aux == null){
                    System.out.println("Fim da lista alcançado, finalizando visualizaçao");
                    exit = true;
                }
            }
        }
    }

    public void multiplePush(int n){
        Scanner inputs = new Scanner(System.in);
        int number;
        for(int i = 0; i < n; i++){
            System.out.println("Digite um numero");
            number = inputs.nextInt();
            push(number);
        }
    }
}
