import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

// Define a class to hold edge information
class Edge {
    long p; // Weight or value associated with the edge
    long i; // Index of the edge
    String s; // Name or identifier of the edge

    // Constructor
    Edge(String s, long p, long i) {
        this.s = s;
        this.p = p;
        this.i = i;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of edges
        long n = scanner.nextLong();
        Edge[] data = new Edge[(int) n];
        
        // Read edge data from input
        for (long i = 0; i < n; i++) {
            String s = scanner.next();
            long p = scanner.nextLong();
            data[(int) i] = new Edge(s, p, i); // Store edge data
        }
        
        // Sort the edges based on the defined sorting criteria
        Arrays.sort(data, new Comparator<Edge>() {
            @Override
            public int compare(Edge p, Edge q) {
                // First compare by string identifier
                int cmp = p.s.compareTo(q.s);
                if (cmp != 0) return cmp;
                // If identifiers are the same, compare by weight in descending order
                return Long.compare(q.p, p.p);
            }
        });
        
        // Output the original indices of the sorted edges
        for (long i = 0; i < n; i++) {
            System.out.println(data[(int) i].i + 1);
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
