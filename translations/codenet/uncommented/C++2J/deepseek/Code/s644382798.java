public class Main {
    static class P {
        String name;
        int t;
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int q = scanner.nextInt();

        P[] Q = new P[100005];
        for (int i = 0; i < 100005; i++) {
            Q[i] = new P();
        }

        for (int i = 0; i < n; i++) {
            Q[i].name = scanner.next();
            Q[i].t = scanner.nextInt();
        }

        int head = 0;
        int tail = n;
        int elaps = 0;

        while (head != tail) {
            P u = Q[head];
            head = (head + 1) % 100005;
            int c = Math.min(q, u.t);
            u.t -= c;
            elaps += c;
            if (u.t > 0) {
                Q[tail] = u;
                tail = (tail + 1) % 100005;
            } else {
                System.out.println(u.name + " " + elaps);
            }
        }
    }
}
