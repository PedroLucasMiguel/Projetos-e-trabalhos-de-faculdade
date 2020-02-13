package predo.javacore.classes;

public class Aluno {
    private String nome;
    private int idade;
    private String cadastro;
    private float media;

    //Construtores devem ser criados sem nenhum tipo de retorno
    //Na criação de um construtor você obriga a passagem de parametros na criação do objeto
    //Possivel criar sorbrecarga de construtores
    public Aluno(String nome, int idade, String cadastro, float media){
        System.out.println("Dentro do construtor!");
        this.nome = nome;
        this.idade = idade;
        this.cadastro = cadastro;
        this.media = media;
    }

    public void mostrar() {
        System.out.println("Nome: "+this.nome+"\nIdade: "+this.idade+"\nCadastro: "+this.cadastro+"\nMedia: "+this.media);
    }
}
