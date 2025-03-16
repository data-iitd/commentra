
import java.util.*;

public class s620821061{
    static class BitMatching {
        List<Integer>[] G; // Graph representation using adjacency list
        int[] match; // Array to store the match of each node
        boolean[] used; // Array to keep track of used nodes in DFS

        /// Initialize the graph
        void init() {
            G = new ArrayList[2*V]; // Initialize the graph with 2*V nodes
            for (int i = 0; i < 2*V; i++) {
                G[i] = new ArrayList<>(); // Initialize all edges as empty
            }
        }

        /// Add an edge between node a and node b in the bipartite graph
        void add(int a, int b) {
            G[a].add(b+V); // Add edge from a to b+V
            G[b+V].add(a); // Add edge from b+V to a
        }

        /// Depth-First Search to find augmenting paths
        boolean dfs(int v) {
            used[v] = true; // Mark the node as visited
            for (int i = 0; i < G[v].size(); i++) {
                int u = G[v][i], w = match[u];
                if (w < 0 || (!used[w] && dfs(w))) { // If the node is not matched or can find an augmenting path
                    match[v] = u; // Assign the match
                    match[u] = v; // Assign the match
                    return true; // Return true as we found an augmenting path
                }
            }
            return false; // Return false if no augmenting path is found
        }

        /// Execute the bipartite matching algorithm
        int exec() {
            int res = 0; // Initialize the result
            match = new int[2*V]; // Initialize all matches to -1 (no match)
            Arrays.fill(match, -1);
            for (int v = 0; v < V; v++) {
                if (match[v] < 0) { // If the node is not matched
                    Arrays.fill(used, false); // Reset the used array
                    if (dfs(v)) { // Perform DFS from the node
                        res++; // Increment the result if an augmenting path is found
                    }
                }
            }
            return res; // Return the total number of matches found
        }
    }

    static long gcd(long a, long b) {
        if (b == 0) return a; // Base case: if b is 0, return a
        return gcd(b, a%b); // Recursive call: compute GCD of b and the remainder of a divided by b
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            int n = sc.nextInt(); // Read the number of elements in the first set
            int m = sc.nextInt(); // Read the number of elements in the second set
            if (n == 0) break; // If n is 0, break the loop
            BitMatching bm = new BitMatching(); // Create an instance of BitMatching
            int[] a = new int[n]; // Array to store the elements of the first set
            int[] b = new int[m]; // Array to store the elements of the second set
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt(); // Read the elements of the first set
            }
            for (int i = 0; i < m; i++) {
                b[i] = sc.nextInt(); // Read the elements of the second set
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (gcd(a[i], b[j])!= 1) { // Check if the GCD is not 1
                        bm.add(i, j); // Add an edge between the corresponding nodes if GCD is not 1
                    }
                }
            }
            System.out.println(bm.exec()); // Execute the bipartite matching and print the result
        }
    }
}

Translate the above Java code to Python and end with comment "