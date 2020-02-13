package predo.javacore.classes;

import javax.sound.midi.SysexMessage;
import javax.swing.*;

public class Calculator {
    private double resutlt;

    public double calculator(double n1, double n2 ,char op) {
        switch (op) {
            case '+':
                resutlt = n1+n2;
                break;

            case '-':
                resutlt = n1-n2;
                break;

            case '*':
                resutlt = n1*n2;
                break;

            case '/':
                resutlt = n1/n2;
                break;

            default:
                System.out.println("Operação inválida!");
                break;
        }

        return resutlt;
    }
}
