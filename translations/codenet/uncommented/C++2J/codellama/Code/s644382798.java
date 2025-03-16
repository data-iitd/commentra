
import java.util.Scanner;

class P {
    String name;
    int t;

    P(String name, int t) {
        this.name = name;
        this.t = t;
    }
}

class Queue {
    P[] Q;
    int head, tail, n;

    Queue(int n) {
        Q = new P[n + 1];
        head = 1;
        tail = n + 1;
    }

    void enqueue(P x) {
        Q[tail] = x;
        tail = (tail + 1) % (Q.length);
    }

    P dequeue() {
        P x = Q[head];
        head = (head + 1) % (Q.length);
        return x;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        Queue q1 = new Queue(n);
        for (int i = 1; i <= n; i++) {
            String name = sc.next();
            int t = sc.nextInt();
            q1.enqueue(new P(name, t));
        }
        int elaps = 0, c;
        P u;
        while (q1.head != q1.tail) {
            u = q1.dequeue();
            c = Math.min(q, u.t);
            u.t -= c;
            elaps += c;
            if (u.t > 0)
                q1.enqueue(u);
            else
                System.out.println(u.name + " " + elaps);
        }
    }
}

