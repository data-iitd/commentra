import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Edge[] data = new Edge[n];
        for (int i = 0; i < n; i++) {
            data[i] = new Edge();
            data[i].s = scanner.next();
            data[i].p = scanner.nextInt();
            data[i].i = i;
        }
        Arrays.sort(data, (a, b) -> {
            int cmp = a.s.compareTo(b.s);
            if (cmp != 0) return cmp;
            return Long.compare(b.p, a.p);
        });
        for (int i = 0; i < n; i++) {
            System.out.println(data[i].i + 1);
        }
    }

    static class Edge {
        String s;
        long p;
        int i;
    }
}
