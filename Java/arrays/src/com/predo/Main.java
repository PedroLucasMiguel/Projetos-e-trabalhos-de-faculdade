package com.predo;

import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
	    int[] array = new int[6]; //Declaração de array em java
        for(int  i = 0; i < array.length; i++){
            array[i] = i;
            Arrays.sort(array);
            System.out.println(array[i]);
        }

        //Bidimensionais funcionam também
        int[][] matrix = new int[6][6]; //Declaração

        final int A = 10; //Constantes (por convensão tudo maiúsculo)

        float c = (float)(10/3);

        System.out.println(c);
    }
}
