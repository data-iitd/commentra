import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Edge {
    long p; // destination vertex
    int i; // index of the edge in the data array
    String s; // source string

    Edge(String s, long p, int i) {
        this.s = s;
        this.p = p;
        this.i = i;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong(); // read the number of vertices
        Edge[] data = new Edge[(int) n]; // array to store edges

        for (int i = 0; i < n; i++) { // for each vertex
            String s = scanner.next(); // read the source string
            long p = scanner.nextLong(); // read the destination vertex
            data[i] = new Edge(s, p, i); // create a new edge
        }

        // sort the edges based on their source strings and destination vertices
        Arrays.sort(data, new Comparator<Edge>() {
            @Override
            public int compare(Edge a, Edge b) {
                int cmp = a.s.compareTo(b.s); // compare source strings first
                if (cmp != 0) return cmp; // if not equal, return comparison result
                return Long.compare(b.p, a.p); // if source strings are equal, compare destination vertices in descending order
            }
        });

        for (int i = 0; i < n; i++) {
            System.out.println(data[i].i + 1); // print the indices of the sorted edges
        }

        scanner.close();
    }
}
//<END-OF-CODE>
