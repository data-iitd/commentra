import java.util.Scanner;

class Process {
    String name;
    int time;

    Process(String name, int time) {
        this.name = name;
        this.time = time;
    }
}

public class RoundRobin {
    static Process[] Q = new Process[100005];
    static int head = 0, tail = 0, n;

    public static void enqueue(Process x) {
        Q[tail] = x;
        tail = (tail + 1) % 100005;
    }

    public static Process dequeue() {
        Process x = Q[head];
        head = (head + 1) % 100005;
        return x;
    }

    public static int min(int a, int b) {
        return a < b ? a : b;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int elaps = 0, c;
        int i, q;
        Process u;

        n = scanner.nextInt();
        q = scanner.nextInt();

        for (i = 0; i < n; i++) {
            Q[i] = new Process(scanner.next(), scanner.nextInt());
        }

        tail = n;

        while (head != tail) {
            u = dequeue();
            c = min(q, u.time);
            u.time -= c;
            elaps += c;

            if (u.time > 0) {
                enqueue(u);
            } else {
                System.out.println(u.name + " " + elaps);
            }
        }

        scanner.close();
    }
}
