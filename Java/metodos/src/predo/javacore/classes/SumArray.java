package predo.javacore.classes;

public class SumArray {
    private int result = 0;
    public int sumArray(int... numbers){ //... converte todos os valores do parametro em um array
        for(int num = 0; num < numbers.length; num++){
            this.result += numbers[num];
        }
        return result;
    }
}
