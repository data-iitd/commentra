import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

// Define a class to hold edge information
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
    // Define a large number to represent infinity
    static final long INF = (1L << 62) - (1L << 31);
    // Define a modulo value
    static final int MOD = 1000000007;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of edges
        long n = scanner.nextLong();
        Edge[] data = new Edge[(int) n];

        // Read each edge's string and long long value, and store the index
        for (int i = 0; i < n; i++) {
            String s = scanner.next();
            long p = scanner.nextLong();
            data[i] = new Edge(s, p, i);
        }

        // Sort the edges using a custom comparator
        Arrays.sort(data, new Comparator<Edge>() {
            @Override
            public int compare(Edge a, Edge b) {
                int cmp = a.s.compareTo(b.s);
                if (cmp != 0) return cmp;
                return Long.compare(b.p, a.p); // Sort by p in descending order
            }
        });

        // Print the indices of the edges in the sorted order
        for (int i = 0; i < n; i++) {
            System.out.println(data[i].i + 1);
        }

        scanner.close();
    }
}

// <END-OF-CODE>
