import java.util.LinkedList;
import java.util.Queue;
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
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int elaps = 0, c;
        int n, q;

        n = scanner.nextInt();
        q = scanner.nextInt();
        Queue<P> queue = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            String name = scanner.next();
            int t = scanner.nextInt();
            queue.add(new P(name, t));
        }

        while (!queue.isEmpty()) {
            P u = queue.poll();
            c = Math.min(q, u.t);
            u.t -= c;
            elaps += c;

            if (u.t > 0) {
                queue.add(u);
            } else {
                System.out.println(u.name + " " + elaps);
            }
        }

        scanner.close();
    }
}

// <END-OF-CODE>
