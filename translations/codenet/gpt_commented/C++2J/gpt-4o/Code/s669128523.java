import java.util.Scanner;

public class DFS {
    // Define constants for maximum number of nodes and colors
    static final int N = 100; // Maximum number of nodes
    static final int WHITE = 0; // Color for unvisited nodes
    static final int GRAY = 1; // Color for nodes being visited
    static final int BLACK = 2; // Color for fully visited nodes

    // Adjacency matrix to represent the graph, number of nodes, and arrays for DFS
    static int[][] M = new int[N][N]; // M is the adjacency matrix
    static int n; // Number of nodes
    static int[] color = new int[N], d = new int[N], f = new int[N]; // Arrays to store colors, discovery times, finish times
    static int tt; // Time counter

    // Function to visit nodes in DFS
    static void dfsVisit(int u) {
        // Mark the current node as being visited
        color[u] = GRAY;
        // Set the discovery time for the current node
        d[u] = ++tt;

        // Explore all adjacent nodes
        for (int v = 0; v < n; v++) {
            // Skip if there is no edge from u to v
            if (M[u][v] == 0)
                continue;
            // If the adjacent node is unvisited, recursively visit it
            if (color[v] == WHITE) {
                dfsVisit(v);
            }
        }
        // Mark the current node as fully visited
        color[u] = BLACK;
        // Set the finish time for the current node
        f[u] = ++tt;
    }

    // Function to perform DFS on the graph
    static void dfs() {
        // Initialize all nodes as unvisited
        for (int i = 0; i < n; i++) {
            color[i] = WHITE;
        }
        tt = 0; // Reset the time counter

        // Perform DFS for each unvisited node
        for (int u = 0; u < n; u++) {
            if (color[u] == WHITE)
                dfsVisit(u);
        }

        // Output the discovery and finish times for each node
        for (int i = 0; i < n; i++)
            System.out.println((i + 1) + " " + d[i] + " " + f[i]);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int k, u, v;

        // Read the number of nodes
        n = scanner.nextInt();
        // Initialize the adjacency matrix to zero
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                M[i][j] = 0;
        }
        // Read the graph edges
        for (int i = 0; i < n; i++) {
            u = scanner.nextInt();
            k = scanner.nextInt(); // Read the number of edges
            u--; // Convert to zero-based index
            for (int j = 0; j < k; j++) {
                v = scanner.nextInt(); // Read each adjacent node
                v--; // Convert to zero-based index
                M[u][v] = 1; // Mark the edge in the adjacency matrix
            }
        }

        // Perform DFS on the graph
        dfs();

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
