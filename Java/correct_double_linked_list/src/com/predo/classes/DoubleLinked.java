package com.predo.classes;

import java.util.Scanner;

public class DoubleLinked {
    private Node head; //Head da lista
    private Node tail; //Tail da lista

    public static class Node{ //Objeto dos nodes, internos a classe Double Linked
        private int number;
        private Node next;
        private Node prev;
    }

    public void push(int n){
        Node newNode = new Node();

        if(head == null){ //Primeira inserção
            newNode.number = n;
            head = newNode;
            tail = newNode;
        }

        else if(head == tail){ //Segunda Inserção
            if(n >= head.number){ //Caso maior que a head
                newNode.number = n;
                newNode.next = null;
                newNode.prev = head;
                head.next = newNode;
                tail = newNode;
            }
            else{ //Caso menor que a head
                newNode.number = n;
                newNode.next = head;
                newNode.prev = null;
                head.prev = newNode;
                tail = head;
                head = newNode;
            }
        }

        else if(n >= tail.number){ //Maior que o tail insere na frente
            newNode.number = n;
            newNode.next = null;
            newNode.prev = tail;
            tail.next = newNode;
            tail = newNode;
        }

        else if(n < head.number){ //Menor que o head
            newNode.number = n;
            newNode.next = head;
            newNode.prev = null;
            head.prev = newNode;
            head = newNode;
        }

        else{
            Node aux = head;
            boolean inserted = false;
            while(!inserted && aux != null){
                if(n >= aux.number && n <= aux.next.number){
                    newNode.number = n;
                    newNode.next = aux.next;
                    newNode.prev = aux;
                    aux.next.prev = newNode;
                    aux.next = newNode;
                    inserted = true; //Condição de saída
                }
                aux = aux.next;
            }
        }
    }

    public void pop(int n){
        if(head == null){
            System.out.println("\n\tLista vazia impossível remoção!\n");
        }
        else{
            Node aux = head;
            boolean removed = false;
            if(head == tail && n == head.number){ //Remoção do último elemento
                head = null;
                tail = null;
                System.gc();
                removed = true;
            }
            else if(head.number == n){ //Remoção do head
                head.next.prev = null;
                head = head.next;
                System.gc();
                removed = true;
            }
            else if(tail.number == n){ //Remoção do tail
                tail.prev.next = null;
                tail = tail.prev;
                System.gc();
                removed = true;
            }
            else{ //Remoção do resto
                while(aux != null){
                    if(aux.number == n){
                        aux.next.prev = aux.prev;
                        aux.prev.next = aux.next;
                        System.gc();
                        removed = true;
                    }
                    aux = aux.next;
                }
            }

            if(removed){
                System.out.println("\n\tElemento removido com sucesso!\n");
            }
            else{
                System.out.println("\n\tElemento não encontrado na lista!\n");
            }
        }
    }

    public void print(){
        if(head == null){
            System.out.println("\n\tLista vazia impossível impressão!\n");
        }
        else{
            int op;
            boolean exit = false;
            Scanner sc = new Scanner(System.in);
            Node aux = head;

            while (!exit && aux != null){
                System.out.println("\nElemento: " + aux.number);
                System.out.println("Next: " + aux.next + " || Prev: " + aux.prev);
                System.out.println("Head: " + head + " || Tail: " + tail);
                System.out.println("Atual:" + aux);
                System.out.println("(1)-Next || (2)-Prev || (3)-Sair: ");
                op = sc.nextInt();
                switch (op){
                    case 1:
                        aux = aux.next;
                        break;
                    case 2:
                        aux = aux.prev;
                        break;
                    case 3:
                        exit = true;
                        break;
                }
                if(aux == null){
                    System.out.println("\n\tFim da lista atingido, finalizando vizualização...\n");
                    exit = true;
                }
            }
        }
    }
}
