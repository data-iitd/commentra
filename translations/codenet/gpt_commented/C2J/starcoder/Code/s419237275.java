import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, A[][] = new int[N][N], color[] = new int[N], d[] = new int[N], f[] = new int[N];
        int TT = 0, u, k, v, i, j;

        // Read the number of nodes
        n = sc.nextInt();

        // Initialize the adjacency matrix to zero (no edges)
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                A[i][j] = 0;
            }
        }

        // Read the edges for each node
        for (i = 0; i < n; i++) {
            u = sc.nextInt(); // Read node u and number of edges k
            u--; // Convert to zero-based index
            k = sc.nextInt();
            for (j = 0; j < k; j++) {
                v = sc.nextInt(); // Read each adjacent node v
                v--; // Convert to zero-based index
                A[u][v] = 1; // Mark the edge in the adjacency matrix
            }
        }

        // Call the DFS function to process the graph
        aaaaa();

        // Print the discovery and finishing times for each node
        for (i = 0; i < n; i++) {
            System.out.printf("%d %d %d\n", i + 1, d[i], f[i]); // Output format: node index, discovery time, finishing time
        }
    }

    // Function to perform DFS and initialize variables
    public static void aaaaa() {
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
    }

    // Recursive function to visit nodes in DFS
    public static void bbbbb(int k) {
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

