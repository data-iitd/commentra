public class DepthFirstSearch {
    static final int N = 200; // Maximum number of nodes
    static final int SHIRO = 0; // Color constant for unvisited nodes
    static final int HAI = 1; // Color constant for visiting nodes
    static final int KURO = 2; // Color constant for visited nodes

    // Function prototypes
    static void aaaaa(); // Function to perform depth-first search (DFS) and print discovery and finishing times
    static void bbbbb(int k); // Recursive function to visit nodes in DFS

    static int n, A[][] = new int[N][N]; // Number of nodes and adjacency matrix
    static int[] color = new int[N], d = new int[N], f = new int[N]; // Arrays to store colors, discovery times, and finishing times
    static int TT; // Global variable to keep track of time during DFS

    public static void main(String[] args) {
        int u, k, v; // Variables for input: u = node, k = number of edges, v = adjacent node
        int i, j; // Loop counters

        // Read the number of nodes
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();

        // Initialize the adjacency matrix to zero (no edges)
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                A[i][j] = 0;
            }
        }

        // Read the edges for each node
        for (i = 0; i < n; i++) {
            u = scanner.nextInt() - 1; // Convert to zero-based index
            k = scanner.nextInt();
            for (j = 0; j < k; j++) {
                v = scanner.nextInt() - 1; // Convert to zero-based index
                A[u][v] = 1; // Mark the edge in the adjacency matrix
            }
        }

        // Call the DFS function to process the graph
        aaaaa();
    }

    // Function to perform DFS and initialize variables
    static void aaaaa() {
        int u, i;

        // Initialize all nodes to unvisited (SHIRO)
        for (i = 0; i < n; i++) {
            color[i] = SHIRO;
        }

        TT = 0; // Reset the time counter

        // Perform DFS for each unvisited node
        for (u = 0; u < n; u++) {
            if (color[u] == SHIRO) {
                bbbbb(u); // Call DFS for the unvisited node
            }
        }

        // Print the discovery and finishing times for each node
        for (i = 0; i < n; i++) {
            System.out.println((i + 1) + " " + d[i] + " " + f[i]); // Output format: node index, discovery time, finishing time
        }
    }

    // Recursive function to visit nodes in DFS
    static void bbbbb(int k) {
        int v;
        color[k] = HAI; // Mark the current node as visiting (HAI)
        TT++; // Increment the time counter
        d[k] = TT; // Set the discovery time for the current node

        // Visit all adjacent nodes
        for (v = 0; v < n; v++) {
            if (A[k][v] == 0) continue; // Skip if there is no edge
            if (color[v] == SHIRO) { // If the adjacent node is unvisited
                bbbbb(v); // Recursively visit the adjacent node
            }
        }

        color[k] = KURO; // Mark the current node as visited (KURO)
        f[k] = ++TT; // Set the finishing time for the current node
    }
}
