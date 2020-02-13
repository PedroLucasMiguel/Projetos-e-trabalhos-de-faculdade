package predo.javacore.classes;

public class Lista {
    private int num;
    private Lista next;
    private Lista head;

    public void inserir(int n, Lista atual) {
        Lista aux;

        //Primeira inserção
        if(this.head == null){
            this.num = n;
            this.next = null;
            this.head = atual;
        }

        //Segunda inserção
        else if(this.head.next == null){
            if(n >= head.num){
                System.out.println("Condição 1");
                head.next = new Lista();
                aux = head.next;
                aux.head = this.head;
                aux.next = null;
                aux.num = n;
            }

            else{
                System.out.println("Condição 2");
                aux = new Lista();
                aux.num = n;
                aux.next = this.head;
                aux.head = aux;
                head.head = aux;
            }
        }
    }

    public void mostrar(Lista atual){
        Lista aux = this.head;
        while (aux != null){
            System.out.println(aux.num);
            aux = aux.next;
        }
    }
}
