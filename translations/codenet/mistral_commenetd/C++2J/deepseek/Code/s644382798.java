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

    static void enqueue(Process x) {
        Q[tail] = x;
        tail = (tail + 1) % 100005;
    }

    static Process dequeue() {
        Process x = Q[head];
        head = (head + 1) % 100005;
        return x;
    }

    static int min(int a, int b) {
        return a < b ? a : b;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int elaps = 0, q = 0;
        int i;
        Process u;

        n = scanner.nextInt();
        q = scanner.nextInt();

        for (i = 0; i < n; i++) {
            String name = scanner.next();
            int time = scanner.nextInt();
            enqueue(new Process(name, time));
        }

        while (head != tail) {
            u = dequeue();
            int c = min(q, u.time);
            u.time -= c;
            elaps += c;
            if (u.time > 0)
                enqueue(u);
            else
                System.out.println(u.name + " " + elaps);
        }

        scanner.close();
    }
}
