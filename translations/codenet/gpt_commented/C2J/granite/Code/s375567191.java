
import java.util.Scanner;

public class s375567191{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int MAX = 101; // Define the maximum number of vertices
        int WHITE = 0; // Color constant for unvisited nodes
        int BLACK = 2; // Color constant for fully explored nodes
        int GRAY = 1; // Color constant for nodes currently being explored
        int time = 0; // Global variable: time counter
        int n; // Number of vertices
        int[][] g = new int[MAX][MAX]; // Adjacency matrix
        int[] d = new int[MAX]; // Discovery time for each node
        int[] f = new int[MAX]; // Finish time for each node
        int[] color = new int[MAX]; // Color of each node

        // Read the number of vertices
        n = scanner.nextInt();

        // Read the graph edges
        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt(); // Node index
            int y = scanner.nextInt(); // Number of edges
            for (int j = 0; j < y; j++) {
                int z = scanner.nextInt(); // Adjacent node index
                g[x - 1][z - 1] = 1; // Update the adjacency matrix
            }
        }

        // Perform DFS on the graph
        for (int i = 0; i < n; i++) {
            if (color[i] == WHITE) { // If the node is unvisited
                visit(i); // Start a DFS visit
            }
        }

        // Print the discovery and finish times for each node
        for (int i = 0; i < n; i++) {
            System.out.println((i + 1) + " " + d[i] + " " + f[i]); // Output: node index, discovery time, finish time
        }
    }

    // Function to perform DFS visit on a node
    public static void visit(int u) {
        int i;

        color[u] = GRAY; // Mark the node as being explored
        d[u] = ++time; // Set the discovery time for the node

        // Explore all adjacent nodes
        for (i = 0; i < n; i++) {
            if (g[u][i] == 0) { // If there is no edge to node i, skip
                continue;
            }
            if (color[i] == WHITE) { // If the adjacent node is unvisited
                visit(i); // Recursively visit the adjacent node
            }
        }

        color[u] = BLACK; // Mark the node as fully explored
        f[u] = ++time; // Set the finish time for the node
    }
}

// Translate the above Java code to Python and end with comment "