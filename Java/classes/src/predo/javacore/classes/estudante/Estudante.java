package predo.javacore.classes.estudante;

public class Estudante {
    public String nome;
    public String matricula;
    public int idade;
    public float media;

    public void mostrar() {
        System.out.println("Nome: " + nome);
        System.out.println("Matricula: " + matricula);
        System.out.println("Idade: " + idade);
        System.out.println("Media: " + media);
    }
}
