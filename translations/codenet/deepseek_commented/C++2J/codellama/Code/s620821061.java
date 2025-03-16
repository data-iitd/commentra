#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
using ll = long long;

/**
 * Bit Matching Algorithm
 *
 * Time Complexity: O(EV)
 */
class BitMatching {
    private int V; // Number of vertices
    private int E; // Number of edges
    private int[] match; // Array to store the match of each node
    private boolean[] used; // Array to keep track of used nodes in DFS
    private int[][] G; // Graph representation using adjacency list

    /// Initialize the graph
    public void init(int V) {
        this.V = V;
        this.E = 0;
        match = new int[2*V];
        used = new boolean[2*V];
        G = new int[2*V][];
        for (int i = 0; i < 2*V; i++) {
            G[i] = new int[0]; // Clear all edges
        }
    }

    /// Add an edge between node a and node b in the bipartite graph
    public void add(int a, int b) {
        G[a].push(b+V); // Add edge from a to b+V
        G[b+V].push(a); // Add edge from b+V to a
        E++;
    }

    /// Depth-First Search to find augmenting paths
    public boolean dfs(int v) {
        used[v] = true; // Mark the node as visited
        for (int i = 0; i < G[v].length; i++) {
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
    public int exec() {
        int res = 0; // Initialize the result
        for (int i = 0; i < 2*V; i++) {
            match[i] = -1; // Initialize all matches to -1 (no match)
        }
        for (int v = 0; v < V; v++) {
            if (match[v] < 0) { // If the node is not matched
                for (int i = 0; i < 2*V; i++) {
                    used[i] = false; // Reset the used array
                }
                if (dfs(v)) { // Perform DFS from the node
                    res++; // Increment the result if an augmenting path is found
                }
            }
        }
        return res; // Return the total number of matches found
    }
}

public class Main {
    public static void main(String[] args) {
        BitMatching bm = new BitMatching();
        while (true) {
            int n, m;
            cin >> n >> m; // Read the number of elements in the two sets
            if (!n) break; // If n is 0, break the loop
            bm.init(n); // Initialize the bipartite graph
            int a[] = new int[n]; // Arrays to store the elements of the two sets
            int b[] = new int[m];
            for (int i = 0; i < n; i++) {
                cin >> a[i]; // Read the elements of the first set
            }
            for (int i = 0; i < m; i++) {
                cin >> b[i]; // Read the elements of the second set
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (gcd(a[i], b[j]) != 1) { // Check if the GCD is not 1
                        bm.add(i, j); // Add an edge between the corresponding nodes if GCD is not 1
                    }
                }
            }
            cout << bm.exec() << endl; // Execute the bipartite matching and print the result
        }
    }

    /// Function to compute the greatest common divisor (GCD) of two numbers
    public static long gcd(long a, long b) {
        if (b == 0) return a; // Base case: if b is 0, return a
        return gcd(b, a%b); // Recursive call: compute GCD of b and the remainder of a divided by b
    }
}

