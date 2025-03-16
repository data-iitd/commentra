import java.util.Scanner;

class P {
    String name;
    int t;

    P(String name, int t) {
        this.name = name;
        this.t = t;
    }
}

public class Main {
    static final int LEN = 100005;
    static P[] Q = new P[LEN];
    static int head, tail, n;

    static void enqueue(P x) {
        Q[tail] = x;
        tail = (tail + 1) % LEN;
    }

    static P dequeue() {
        P x = Q[head];
        head = (head + 1) % LEN;
        return x;
    }

    static int min(int a, int b) {
        return a < b ? a : b;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int elaps = 0, c;
        int i, q;
        P u;

        n = scanner.nextInt();
        q = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        for (i = 1; i <= n; i++) {
            String name = scanner.nextLine();
            int t = scanner.nextInt();
            scanner.nextLine(); // Consume the newline character
            Q[i] = new P(name, t);
        }
        head = 1;
        tail = n + 1;

        while (head != tail) {
            u = dequeue();
            c = min(q, u.t);
            u.t -= c;
            elaps += c;
            if (u.t > 0) {
                enqueue(u);
            } else {
                System.out.println(u.name + " " + elaps);
            }
        }

        scanner.close();
    }
}

// <END-OF-CODE>
