import java.util.Scanner;

public class DFS {
    static final int MAX = 101; // Define the maximum number of vertices
    static final int WHITE = 0;  // Color constant for unvisited nodes
    static final int BLACK = 2;   // Color constant for fully explored nodes
    static final int GRAY = 1;    // Color constant for nodes currently being explored

    static int time, n; // Global variables: time counter and number of vertices
    static int[][] g = new int[MAX][MAX]; // Adjacency matrix
    static int[] d = new int[MAX]; // Discovery time
    static int[] f = new int[MAX]; // Finish time
    static int[] color = new int[MAX]; // Color of nodes

    // Function to perform DFS visit on a node
    static void visit(int u) {
        color[u] = GRAY; // Mark the node as being explored
        d[u] = ++time;   // Set the discovery time for the node

        // Explore all adjacent nodes
        for (int i = 0; i < n; i++) {
            if (g[u][i] == 0) // If there is no edge to node i, skip
                continue;
            if (color[i] == WHITE) // If the adjacent node is unvisited
                visit(i); // Recursively visit the adjacent node
        }

        color[u] = BLACK; // Mark the node as fully explored
        f[u] = ++time;    // Set the finish time for the node
    }

    // Function to perform Depth-First Search on the graph
    static void dfs() {
        time = 0; // Initialize time counter

        // Visit all nodes in the graph
        for (int i = 0; i < n; i++)
            if (color[i] == WHITE) // If the node is unvisited
                visit(i); // Start a DFS visit

        // Print the discovery and finish times for each node
        for (int i = 0; i < n; i++)
            System.out.println((i + 1) + " " + d[i] + " " + f[i]); // Output: node index, discovery time, finish time
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of vertices
        n = scanner.nextInt();

        // Read the graph edges
        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt(); // Read the node
            int y = scanner.nextInt(); // Read the number of edges
            for (int j = 0; j < y; j++) {
                int z = scanner.nextInt(); // Read each adjacent node
                g[x - 1][z - 1] = 1; // Update the adjacency matrix
            }
        }

        // Perform DFS on the graph
        dfs();
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
