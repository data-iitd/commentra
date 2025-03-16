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
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int q = scanner.nextInt();
        Process[] Q = new Process[100005];
        int head = 0, tail = 0;

        for (int i = 0; i < n; i++) {
            String name = scanner.next();
            int time = scanner.nextInt();
            Q[tail] = new Process(name, time);
            tail++;
        }

        int elaps = 0;
        while (head != tail) {
            Process u = Q[head];
            head++;
            int c = Math.min(q, u.time);
            u.time -= c;
            elaps += c;
            if (u.time > 0) {
                Q[tail] = u;
                tail++;
            } else {
                System.out.println(u.name + " " + elaps);
            }
        }
        scanner.close();
    }
}
