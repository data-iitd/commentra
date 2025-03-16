import java.util.Scanner;
import java.util.LinkedList;
import java.util.Queue;

public class BFS {
    static final int M = 100; // Maximum number of vertices in the graph
    static final int whi = 0; // Color code for white (unvisited)
    static final int gra = 1; // Color code for gray (visited but not fully explored)
    static final int bla = 2; // Color code for black (fully explored)

    static int n; // Number of vertices in the graph
    static int[][] T = new int[M][M]; // Adjacency matrix to represent the graph
    static int[] color = new int[M], d = new int[M]; // Arrays to store the color and distance of each vertex

    // Function to perform Breadth-First Search (BFS) starting from vertex s
    static void bfs(int s) {
        // Initialize all vertices as unvisited and set their distances to a large value
        for (int i = 0; i < n; i++) {
            color[i] = whi; // Set color to white (unvisited)
            d[i] = 1000000; // Set distance to a large number (infinity)
        }

        // Start BFS from the source vertex s
        color[s] = gra; // Mark the source vertex as gray (visited)
        d[s] = 0; // Distance to source vertex is 0
        Queue<Integer> queue = new LinkedList<>(); // Create a queue for BFS
        queue.add(s); // Enqueue the source vertex

        // Continue BFS until the queue is empty
        while (!queue.isEmpty()) {
            int u = queue.poll(); // Dequeue a vertex from the queue
            // Explore all adjacent vertices of u
            for (int v = 0; v < n; v++) {
                // If there is an edge from u to v and v is unvisited
                if (T[u][v] == 1 && color[v] == whi) {
                    color[v] = gra; // Mark v as gray (visited)
                    d[v] = d[u] + 1; // Update distance to v
                    queue.add(v); // Enqueue vertex v for further exploration
                }
            }
            color[u] = bla; // Mark u as black (fully explored)
        }
    }

    // Main function
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of vertices
        n = scanner.nextInt();

        // Initialize the adjacency matrix to zero (no edges)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                T[i][j] = 0; // No edge between vertices i and j
            }
        }

        // Read the edges of the graph
        for (int i = 0; i < n; i++) {
            int u = scanner.nextInt() - 1; // Read vertex u and convert to zero-based index
            int k = scanner.nextInt(); // Read number of edges k
            for (int j = 0; j < k; j++) {
                int v = scanner.nextInt() - 1; // Read each adjacent vertex v and convert to zero-based index
                T[u][v] = 1; // Set the edge from u to v in the adjacency matrix
            }
        }

        // Perform BFS starting from vertex 0
        bfs(0);

        // Output the distance from the source vertex to each vertex
        for (int i = 0; i < n; i++) {
            if (d[i] == 1000000) d[i] = -1; // If distance is still infinity, set it to -1
            System.out.println((i + 1) + " " + d[i]); // Print vertex number and its distance
        }

        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
