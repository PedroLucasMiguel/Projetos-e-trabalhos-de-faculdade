package predo.javacore.classes;

public class List {
    private int num;
    private List next;
    private static List head;
    private static List tail;

    public void push(int n){
        List aux, aux2; //Auxiliares para inserção

        if(List.head == null){ //Primeira isnerção
            this.num = n;
            this.next = null;
            changeHead(this); //Chama o método estático para realizar a alteração na head;
            //Se você passa apenas this como parametro, você passa o objeto atual inteiro como parametro!
            changeTail(this);
        }

        else if(List.head.next == null){
            if(n >= List.head.num){
                List.head.next = new List();
                aux = List.head.next; //Facilita no acesso do proximo elemento
                aux.num = n;
                aux.next = null;
                changeTail(aux);
            }

            else{
                aux = new List();
                aux.num = n;
                aux.next = List.head;
                changeTail(List.head);
                changeHead(aux);
            }
        }

        else if(n < List.head.num){
            aux = new List();
            aux.num = n;
            aux.next = List.head;
            changeHead(aux);
        }

        else if(n > List.tail.num){
            aux = new List();
            aux.num = n;
            aux.next = null;
            List.tail.next = aux;
            changeTail(aux);
        }

        else{
            aux = List.head;
            boolean complete = false;
            while(aux != null && !complete){
                if(n >= aux.num && n <= aux.next.num){
                    aux2 = new List();
                    aux2.num = n;
                    aux2.next = aux.next;
                    aux.next = aux2;
                    complete = true;
                }

                aux = aux.next;
            }
        }
    }

    public void pop(int n) {
        List aux, aux2;
        boolean removed = false;

        if(List.head == null) {
            System.out.println("Lista vazizia! Impossível remoção.");
        }

        else{
            if(n == List.head.num){ //Remoção do head
                aux = List.head;
                changeHead(List.head.next);
                aux = null;
                removed = true;
                System.gc(); //Comando que força a inicialização do garbage collector
            }

            else if(n == List.tail.num){ //Remoção do tail
                aux = List.head;
                while(aux.next != List.tail){
                    aux = aux.next;
                }
                aux2 = aux.next;
                changeTail(aux);
                aux.next = null;
                aux2 = null;
                removed = true;
                System.gc();
            }

            else{
                aux = List.head;
                while(aux.next != null && !removed){
                    if(aux.next.num == n){
                        aux2 = aux.next;
                        aux.next = aux.next.next;
                        aux2 = null;
                        removed = true;
                        System.gc();
                    }
                    aux = aux.next;
                }
            }

            if(removed) {
                System.out.println("Item removido com sucesso!");
            }
            else{
                System.out.println("Item não encontrado");
            }
        }
    }

    private static void changeHead(List newHead) { //Muda o valor estático de head
        List.head = newHead;
    }

    private static void changeTail(List newTail) { //Muda o valor estático de tail
        List.tail = newTail;
    }

    public void print(){
        List aux = List.head;
        if(head == null){
            System.out.println("Lista vazia! Nenhum elemento pode ser mostrado");
        }
        else {
            while(aux != null){
                System.out.println(aux.num);
                aux = aux.next;
            }
        }
    }
}
