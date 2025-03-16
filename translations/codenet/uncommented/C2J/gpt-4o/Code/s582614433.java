import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Edge {
    long p;
    int i;
    String s;

    Edge(String s, long p, int i) {
        this.s = s;
        this.p = p;
        this.i = i;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        Edge[] data = new Edge[(int) n];

        for (int i = 0; i < n; i++) {
            String s = scanner.next();
            long p = scanner.nextLong();
            data[i] = new Edge(s, p, i);
        }

        Arrays.sort(data, new Comparator<Edge>() {
            @Override
            public int compare(Edge a, Edge b) {
                int cmp = a.s.compareTo(b.s);
                if (cmp != 0) return cmp;
                return Long.compare(b.p, a.p); // Sort by p in descending order
            }
        });

        for (int i = 0; i < n; i++) {
            System.out.println(data[i].i + 1);
        }

        scanner.close();
    }
}
//<END-OF-CODE>
