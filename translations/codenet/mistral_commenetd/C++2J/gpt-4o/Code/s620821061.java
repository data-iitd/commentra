import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class BitMatching {
    private static final int MN = 520; // Maximum number of vertices
    private ArrayList<Integer>[] G; // Adjacency list for the graph
    private int[] match; // Stores the matching result for each vertex
    private boolean[] used; // Stores whether a vertex is being processed or not

    public BitMatching() {
        G = new ArrayList[2 * MN];
        for (int i = 0; i < 2 * MN; i++) {
            G[i] = new ArrayList<>();
        }
        match = new int[2 * MN];
        used = new boolean[2 * MN];
    }

    // Initializes the graph data structures
    public void init() {
        for (int i = 0; i < 2 * MN; i++) {
            G[i].clear(); // Clears the adjacency list for the current vertex
        }
    }

    // Adds an edge between two vertices in the graph
    public void add(int a, int b) {
        G[a].add(b + MN); // Adds the destination vertex to the adjacency list of the source vertex
        G[b + MN].add(a); // Adds the source vertex to the adjacency list of the destination vertex
    }

    // Performs Depth First Search (DFS) algorithm to find a matching between vertices
    private boolean dfs(int v) {
        used[v] = true; // Marks the current vertex as being processed

        for (int u : G[v]) {
            int w = match[u]; // Gets the neighboring vertex and its matching vertex

            if (w < 0 || (!used[w] && dfs(w))) { // If the neighboring vertex is not matched or can be matched
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false; // If no matching is found, return false
    }

    // Executes the Bipartite Graph Matching algorithm
    public int exec() {
        int res = 0; // Initializes the result variable
        Arrays.fill(match, -1); // Initializes the matching array with -1

        for (int v = 0; v < MN; v++) { // Iterates through all vertices in the graph
            if (match[v] < 0) { // If the current vertex is not matched
                Arrays.fill(used, false); // Reset used array
                if (dfs(v)) {
                    res++;
                }
            }
        }
        return res; // Returns the number of matched vertices
    }

    // Computes the greatest common divisor (GCD) of two numbers using Euclidean algorithm
    public static long gcd(long a, long b) {
        if (b == 0) return a; // Base case: if b is 0, return a
        return gcd(b, a % b); // Recursive case: call gcd with b and the remainder of a divided by b
    }

    // Main method to read input data and perform the Bipartite Graph Matching algorithm
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BitMatching bm = new BitMatching();

        while (true) { // Loops through multiple test cases
            int n = scanner.nextInt(); // Reads the number of vertices in the graph
            int m = scanner.nextInt(); // Reads the number of edges in the graph

            if (n == 0) break; // If the number of vertices is 0, breaks the loop

            bm.init(); // Initializes the graph data structures

            int[] a = new int[n]; // Reads the input data for vertices a
            int[] b = new int[m]; // Reads the input data for vertices b

            for (int i = 0; i < n; i++) {
                a[i] = scanner.nextInt();
            }

            for (int i = 0; i < m; i++) {
                b[i] = scanner.nextInt();
            }

            for (int i = 0; i < n; i++) { // Iterates through all vertices a
                for (int j = 0; j < m; j++) { // Iterates through all vertices b
                    if (gcd(a[i], b[j]) != 1) { // If the GCD of a[i] and b[j] is not 1
                        bm.add(i, j); // Adds an edge between them
                    }
                }
            }

            System.out.println(bm.exec()); // Executes the Bipartite Graph Matching algorithm and prints the result
        }

        scanner.close();
    }
}

// <END-OF-CODE>
