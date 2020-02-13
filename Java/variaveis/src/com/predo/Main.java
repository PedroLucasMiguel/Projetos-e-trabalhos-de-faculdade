package com.predo;

import java.util.Date; //Quando se criou a variavel do tipo Date, o IDEA ja importa a biblioteca

public class Main {

    public static void main(String[] args) {
	    //Tipos primitivos
        byte a = 127; //Armazena valores entre (-128/127), ocupa um byte de memoria
        short b = -32000; //Armazena valores entre (-32k/32k), ocupa 2 bytes na memória
        int c = 2000000000; //Armazena valores entre (-2B/2B), ocupa 4 bytes na memória
        long d = 2000000000000000000L; //Muuuuuuito espaço, tem que se colocar L no fim, ocupa 8 bytes na memória
        float e = 200000000000F; //tem que colocar o F no fim, ocupa 4 bytes na memória
        double f = 20000.0; //ocupa 8 bytes na memória
        char g = 'A'; //Armazena apenas um caracter, ocupa 2 bytes na memória por caracter
        boolean h = true; //True e false, ocupa 1 BIT

        //Tipos de referencia (similar ao que conhecemos em C como structs)
        //Variaveis de referencia não alocam a memória na hora que sao declaradas
        //Por isso se usa new, e assim começa os objetos. Objetos são instancias de uma classe

        //Mais detalhes nas anotações

        Date now = new Date();
	    System.out.println(now);
    }
}
