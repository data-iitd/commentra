import java.util.Scanner;

class Person {
    String name;
    int t;

    Person(String name, int t) {
        this.name = name;
        this.t = t;
    }
}

class Queue {
    private Person[] Q;
    private int head, tail;

    Queue(int size) {
        Q = new Person[size + 1];
        head = 0;
        tail = 0;
    }

    void Enqueue(Person x) {
        if (tail == Q.length) tail = 0;
        Q[tail] = x;
        tail++;
    }

    Person Dequeue() {
        if (head == Q.length) head = 0;
        return Q[head++];
    }

    boolean isEmpty() {
        return head == tail;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int q = scanner.nextInt();
        Queue queue = new Queue(100005);

        for (int i = 0; i < n; i++) {
            String name = scanner.next();
            int t = scanner.nextInt();
            queue.Enqueue(new Person(name, t));
        }

        int T = 0;
        while (!queue.isEmpty()) {
            Person a = queue.Dequeue();
            if (a.t > q) {
                a.t -= q;
                T += q;
                queue.Enqueue(a);
            } else {
                T += a.t;
                System.out.println(a.name + " " + T);
                n--;
            }
        }
    }
}

