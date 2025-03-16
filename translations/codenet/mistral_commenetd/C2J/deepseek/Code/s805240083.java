import java.util.Scanner;

class Process {
    String name;
    int t;

    Process(String name, int t) {
        this.name = name;
        this.t = t;
    }
}

class Queue {
    Process[] Q;
    int head, tail;

    Queue(int size) {
        Q = new Process[size];
        head = 0;
        tail = 0;
    }

    void Enqueue(Process x) {
        if (tail == Q.length) {
            tail = 0;
        }
        Q[tail] = x;
        tail++;
    }

    Process Dequeue() {
        Process temp;
        if (head == Q.length) {
            head = 0;
        }
        temp = Q[head];
        head++;
        return temp;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int q = scanner.nextInt();
        Queue queue = new Queue(100005);
        Process a;
        int T = 0;

        for (int i = 0; i < n; i++) {
            String name = scanner.next();
            int t = scanner.nextInt();
            queue.Enqueue(new Process(name, t));
        }

        while (n != 0) {
            a = queue.Dequeue();
            if (a.t > q) {
                a.t = a.t - q;
                T += q;
                queue.Enqueue(a);
            } else {
                T = T + a.t;
                System.out.println(a.name + " " + T);
                n--;
            }
        }

        scanner.close();
    }
}
