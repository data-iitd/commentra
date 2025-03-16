import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Task {
    String name;
    int time;

    Task(String name, int time) {
        this.name = name;
        this.time = time;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int q = scanner.nextInt();
        int elaps = 0;
        Queue<Task> queue = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            String name = scanner.next();
            int time = scanner.nextInt();
            queue.add(new Task(name, time));
        }

        while (!queue.isEmpty()) {
            Task p = queue.poll();
            if (p.time <= q) {
                elaps += p.time;
                System.out.println(p.name + " " + elaps);
            } else {
                p.time -= q;
                elaps += q;
                queue.add(p);
            }
        }
    }
}
