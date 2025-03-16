
import java.util.*;

public class s620821061{
    static class BitMatching {
        List<Integer>[] G; // Adjacency list for the bipartite graph
        int[] match; // Array to store matches for vertices
        boolean[] used; // Array to track visited vertices during DFS

        /// Initializes the graph by clearing the adjacency list
        void init() {
            G = new ArrayList[2 * V];
            for (int i = 0; i < 2 * V; i++) {
                G[i] = new ArrayList<>();
            }
        }

        /// Adds an edge between vertex a and vertex b in the bipartite graph
        /// Note: b is adjusted by adding V to differentiate between the two sets
        void add(int a, int b) {
            G[a].add(b + V); // Connect a to b in the second set
            G[b + V].add(a); // Connect b to a in the first set
        }

        /// Depth-First Search to find an augmenting path
        boolean dfs(int v) {
            used[v] = true; // Mark the current vertex as visited
            for (int i = 0; i < G[v].size(); i++) {
                int u = G[v].get(i), w = match[u]; // Get the matched vertex for u
                // If u is unmatched or we can find an augmenting path
                if (w < 0 || (!used[w] && dfs(w))) {
                    match[v] = u; // Match v with u
                    match[u] = v; // Match u with v
                    return true; // Found a match
                }
            }
            return false; // No match found
        }

        /// Executes the matching algorithm and returns the size of the maximum matching
        int exec() {
            int res = 0; // Result variable to count matches
            match = new int[2 * V]; // Initialize matches to -1 (unmatched)
            Arrays.fill(match, -1);
            for (int v = 0; v < V; v++) {
                if (match[v] < 0) { // If vertex v is unmatched
                    Arrays.fill(used, false); // Reset visited array
                    if (dfs(v)) { // Try to find a match for v
                        res++; // Increment the result if a match is found
                    }
                }
            }
            return res; // Return the total number of matches
        }
    }

    static final int MN = 520; // Maximum number of vertices
    static BitMatching bm = new BitMatching(); // Create an instance of BitMatching

    /// Function to compute the greatest common divisor (GCD) of two numbers
    static long gcd(long a, long b) {
        if (b == 0) return a; // Base case: if b is 0, return a
        return gcd(b, a % b); // Recursive case: GCD of b and a mod b
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            int n = sc.nextInt(), m = sc.nextInt(); // Number of elements in two sets
            if (n == 0) break; // Exit if n is 0 (no more input)

            bm.init(); // Initialize the BitMatching instance
            int[] a = new int[n], b = new int[m]; // Arrays to hold the elements of the two sets
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt(); // Read elements of the first set
            }
            for (int i = 0; i < m; i++) {
                b[i] = sc.nextInt(); // Read elements of the second set
            }

            // Build the bipartite graph based on the GCD condition
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (gcd(a[i], b[j])!= 1) { // If GCD is not 1, add an edge
                        bm.add(i, j);
                    }
                }
            }

            // Execute the matching algorithm and print the result
            System.out.println(bm.exec());
        }
    }
}

