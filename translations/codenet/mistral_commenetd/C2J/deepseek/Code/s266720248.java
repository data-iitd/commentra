import java.util.Scanner;

class Process {
    String name;
    int time;

    Process(String name, int time) {
        this.name = name;
        this.time = time;
    }
}

public class Main {
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

        int elapsedTime = 0;

        while (head != tail) {
            Process process = Q[head];
            head++;
            int c = Math.min(q, process.time);
            process.time -= c;
            elapsedTime += c;
            if (process.time > 0) {
                Q[tail] = process;
                tail++;
            } else {
                System.out.println(process.name + " " + elapsedTime);
            }
        }
    }
}
