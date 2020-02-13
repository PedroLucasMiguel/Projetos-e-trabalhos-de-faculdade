package predo.javacore.testing;

import predo.javacore.classes.Calculator;
import predo.javacore.classes.SumArray;

public class Main {
    public static void main(String[] args){
        Calculator calc = new Calculator();
        SumArray sum = new SumArray();
        System.out.println(calc.calculator(10.5, 3.2, '+'));
        System.out.println(sum.sumArray(1,2,3,4,5));
    }
}
