import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class BitMatching {
    static final int MN = 520;
    static ArrayList<Integer>[] G = new ArrayList[2 * MN]; // Graph representation using adjacency list
    static int[] match = new int[2 * MN]; // Array to store the match of each node
    static boolean[] used = new boolean[2 * MN]; // Array to keep track of used nodes in DFS

    // Initialize the graph
    static void init() {
        for (int i = 0; i < 2 * MN; i++) {
            G[i] = new ArrayList<>(); // Clear all edges
        }
    }

    // Add an edge between node a and node b in the bipartite graph
    static void add(int a, int b) {
        G[a].add(b + MN); // Add edge from a to b + MN
        G[b + MN].add(a); // Add edge from b + MN to a
    }

    // Depth-First Search to find augmenting paths
    static boolean dfs(int v) {
        used[v] = true; // Mark the node as visited
        for (int u : G[v]) {
            int w = match[u];
            if (w < 0 || (!used[w] && dfs(w))) { // If the node is not matched or can find an augmenting path
                match[v] = u; // Assign the match
                match[u] = v; // Assign the match
                return true; // Return true as we found an augmenting path
            }
        }
        return false; // Return false if no augmenting path is found
    }

    // Execute the bipartite matching algorithm
    static int exec() {
        int res = 0; // Initialize the result
        Arrays.fill(match, -1); // Initialize all matches to -1 (no match)
        for (int v = 0; v < MN; v++) {
            if (match[v] < 0) { // If the node is not matched
                Arrays.fill(used, false); // Reset the used array
                if (dfs(v)) { // Perform DFS from the node
                    res++; // Increment the result if an augmenting path is found
                }
            }
        }
        return res; // Return the total number of matches found
    }

    // Function to compute the greatest common divisor (GCD) of two numbers
    static long gcd(long a, long b) {
        if (b == 0) return a; // Base case: if b is 0, return a
        return gcd(b, a % b); // Recursive call: compute GCD of b and the remainder of a divided by b
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            int n = scanner.nextInt();
            int m = scanner.nextInt(); // Read the number of elements in the two sets
            if (n == 0) break; // If n is 0, break the loop
            init(); // Initialize the bipartite graph
            int[] a = new int[n]; // Array to store the elements of the first set
            int[] b = new int[m]; // Array to store the elements of the second set
            for (int i = 0; i < n; i++) {
                a[i] = scanner.nextInt(); // Read the elements of the first set
            }
            for (int i = 0; i < m; i++) {
                b[i] = scanner.nextInt(); // Read the elements of the second set
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (gcd(a[i], b[j]) != 1) { // Check if the GCD is not 1
                        add(i, j); // Add an edge between the corresponding nodes if GCD is not 1
                    }
                }
            }
            System.out.println(exec()); // Execute the bipartite matching and print the result
        }
        scanner.close();
    }
}
// <END-OF-CODE>
