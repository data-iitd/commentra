import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class BitMatching {
    static final int MN = 520; // Maximum number of vertices
    ArrayList<Integer>[] G; // Adjacency list for the bipartite graph
    int[] match; // Array to store matches for vertices
    boolean[] used; // Array to track visited vertices during DFS

    // Constructor to initialize the graph
    public BitMatching() {
        G = new ArrayList[2 * MN];
        for (int i = 0; i < 2 * MN; i++) {
            G[i] = new ArrayList<>();
        }
        match = new int[2 * MN];
        used = new boolean[2 * MN];
    }

    // Initializes the graph by clearing the adjacency list
    public void init() {
        for (int i = 0; i < 2 * MN; i++) {
            G[i].clear();
        }
    }

    // Adds an edge between vertex a and vertex b in the bipartite graph
    public void add(int a, int b) {
        G[a].add(b + MN); // Connect a to b in the second set
        G[b + MN].add(a); // Connect b to a in the first set
    }

    // Depth-First Search to find an augmenting path
    public boolean dfs(int v) {
        used[v] = true; // Mark the current vertex as visited
        for (int u : G[v]) {
            int w = match[u]; // Get the matched vertex for u
            // If u is unmatched or we can find an augmenting path
            if (w < 0 || (!used[w] && dfs(w))) {
                match[v] = u; // Match v with u
                match[u] = v; // Match u with v
                return true;  // Found a match
            }
        }
        return false; // No match found
    }

    // Executes the matching algorithm and returns the size of the maximum matching
    public int exec() {
        int res = 0; // Result variable to count matches
        Arrays.fill(match, -1); // Initialize matches to -1 (unmatched)
        for (int v = 0; v < MN; v++) {
            if (match[v] < 0) { // If vertex v is unmatched
                Arrays.fill(used, false); // Reset visited array
                if (dfs(v)) { // Try to find a match for v
                    res++; // Increment the result if a match is found
                }
            }
        }
        return res; // Return the total number of matches
    }

    // Function to compute the greatest common divisor (GCD) of two numbers
    public static long gcd(long a, long b) {
        if (b == 0) return a; // Base case: if b is 0, return a
        return gcd(b, a % b); // Recursive case: GCD of b and a mod b
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BitMatching bm = new BitMatching(); // Create an instance of BitMatching

        while (true) {
            int n = scanner.nextInt(); // Number of elements in the first set
            int m = scanner.nextInt(); // Number of elements in the second set
            if (n == 0) break; // Exit if n is 0 (no more input)

            bm.init(); // Initialize the BitMatching instance
            int[] a = new int[n]; // Array to hold the elements of the first set
            int[] b = new int[m]; // Array to hold the elements of the second set
            for (int i = 0; i < n; i++) {
                a[i] = scanner.nextInt(); // Read elements of the first set
            }
            for (int i = 0; i < m; i++) {
                b[i] = scanner.nextInt(); // Read elements of the second set
            }

            // Build the bipartite graph based on the GCD condition
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (gcd(a[i], b[j]) != 1) { // If GCD is not 1, add an edge
                        bm.add(i, j);
                    }
                }
            }

            // Execute the matching algorithm and print the result
            System.out.println(bm.exec());
        }
        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
