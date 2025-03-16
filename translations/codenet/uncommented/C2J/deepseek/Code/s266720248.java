import java.util.Scanner;

class P {
    String name;
    int t;
}

class Queue {
    P[] Q;
    int head, tail, n;

    Queue(int size) {
        Q = new P[size];
        head = 0;
        tail = 0;
    }

    void enqueue(P x) {
        Q[tail] = x;
        tail = (tail + 1) % Q.length;
    }

    P dequeue() {
        P x = Q[head];
        head = (head + 1) % Q.length;
        return x;
    }

    int min(int a, int b) {
        return a < b ? a : b;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int q = scanner.nextInt();

        Queue queue = new Queue(n + 1);

        for (int i = 0; i < n; i++) {
            P p = new P();
            p.name = scanner.next();
            p.t = scanner.nextInt();
            queue.enqueue(p);
        }

        int elaps = 0;
        while (queue.head != queue.tail) {
            P u = queue.dequeue();
            int c = queue.min(q, u.t);
            u.t -= c;
            elaps += c;
            if (u.t > 0) {
                queue.enqueue(u);
            } else {
                System.out.println(u.name + " " + elaps);
            }
        }

        scanner.close();
    }
}

