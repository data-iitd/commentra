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
        int n = scanner.nextInt();
        int q = scanner.nextInt();
        Queue<P> queue = new LinkedList<>();
        int T = 0;

        for (int i = 0; i < n; i++) {
            String name = scanner.next();
            int t = scanner.nextInt();
            queue.add(new P(name, t));
        }

        while (!queue.isEmpty()) {
            P a = queue.poll();
            if (a.t > q) {
                a.t -= q;
                T += q;
                queue.add(a);
            } else {
                T += a.t;
                System.out.println(a.name + " " + T);
            }
        }

        scanner.close();
    }
}

// <END-OF-CODE>
