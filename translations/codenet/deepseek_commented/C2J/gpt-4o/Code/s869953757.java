import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class GraphBFS {
    static final int M = 100;
    static final int whi = 0;
    static final int gra = 1;
    static final int bla = 2;

    static int n; // Number of nodes in the graph
    static int[][] T = new int[M][M]; // Adjacency matrix to represent the graph
    static int[] color = new int[M], d = new int[M]; // Arrays to keep track of colors and distances

    // Function to perform Breadth-First Search (BFS) starting from node s
    static void bfs(int s) {
        // Initialize all nodes to white, set distance to infinity
        for (int i = 0; i < n; i++) {
            color[i] = whi;
            d[i] = 1000000;
        }

        // Set the color and distance of the source node
        color[s] = gra;
        d[s] = 0;

        Queue<Integer> queue = new LinkedList<>();
        queue.add(s);

        // Continue BFS until the queue is empty
        while (!queue.isEmpty()) {
            int u = queue.poll(); // Dequeue the front node
            // Explore all adjacent nodes
            for (int v = 0; v < n; v++) {
                if (T[u][v] == 1 && color[v] == whi) {
                    color[v] = gra; // Mark as gray
                    d[v] = d[u] + 1; // Update distance
                    queue.add(v); // Enqueue the node
                }
            }
            color[u] = bla; // Mark as black
        }
    }

    // Main function to read the graph, execute BFS, and print distances
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt(); // Read the number of nodes

        // Initialize the adjacency matrix with zeros
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                T[i][j] = 0;
            }
        }

        // Read the edges and construct the adjacency matrix
        for (int i = 0; i < n; i++) {
            int u = scanner.nextInt() - 1; // Convert to 0-based index
            int k = scanner.nextInt();
            for (int j = 0; j < k; j++) {
                int v = scanner.nextInt() - 1; // Convert to 0-based index
                T[u][v] = 1; // Set the edge in the adjacency matrix
            }
        }

        bfs(0); // Execute BFS starting from node 0

        // Print the distances from the source node to all other nodes
        for (int i = 0; i < n; i++) {
            if (d[i] == 1000000) d[i] = -1; // If unreachable, set distance to -1
            System.out.println((i + 1) + " " + d[i]); // Print node number and distance
        }

        scanner.close();
    }
}

// <END-OF-CODE>
