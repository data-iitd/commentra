import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        while (true) {
            int n, m;
            try {
                n = Integer.parseInt(System.console().readLine()); // Read the number of elements in the two sets
                m = Integer.parseInt(System.console().readLine());
            } catch (Exception e) {
                break; // If n is 0, break the loop
            }
            BitMatching bm = new BitMatching(); // Create an instance of BitMatching
            int[] a = new int[n], b = new int[m]; // Arrays to store the elements of the two sets
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(System.console().readLine()); // Read the elements of the first set
            }
            for (int i = 0; i < m; i++) {
                b[i] = Integer.parseInt(System.console().readLine()); // Read the elements of the second set
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

    /// Function to compute the greatest common divisor (GCD) of two numbers
    static int gcd(int a, int b) {
        if (b == 0) return a; // Base case: if b is 0, return a
        return gcd(b, a%b); // Recursive call: compute GCD of b and the remainder of a divided by b
    }
}

class BitMatching {
    ArrayList<Integer>[] G; // Graph representation using adjacency list
    int[] match; // Array to store the match of each node
    boolean[] used; // Array to keep track of used nodes in DFS

    /// Initialize the graph
    public BitMatching() {
        G = new ArrayList[2*MN]; // Create an array of size 2*MN
        for (int i = 0; i < 2*MN; i++) {
            G[i] = new ArrayList<Integer>(); // Initialize all edges
        }
        match = new int[2*MN]; // Initialize the match array
        used = new boolean[2*MN]; // Initialize the used array
    }

    /// Add an edge between node a and node b in the bipartite graph
    public void add(int a, int b) {
        G[a].add(b+MN); // Add edge from a to b+MN
        G[b+MN].add(a); // Add edge from b+MN to a
    }

    /// Depth-First Search to find augmenting paths
    public boolean dfs(int v) {
        used[v] = true; // Mark the node as visited
        for (int i = 0; i < G[v].size(); i++) {
            int u = G[v].get(i), w = match[u];
            if (w < 0 || (!used[w] && dfs(w))) { // If the node is not matched or can find an augmenting path
                match[v] = u; // Assign the match
                match[u] = v; // Assign the match
                return true; // Return true as we found an augmenting path
            }
        }
        return false; // Return false if no augmenting path is found
    }

    /// Execute the bipartite matching algorithm
    public int exec() {
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
}

