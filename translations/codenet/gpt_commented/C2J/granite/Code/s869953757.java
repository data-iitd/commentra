
import java.util.Scanner;

public class s869953757{
    private static final int WHITE = 0; // Color code for white (unvisited)
    private static final int GRAY = 1; // Color code for gray (visited but not fully explored)
    private static final int BLACK = 2; // Color code for black (fully explored)
    private static final int MAX_VERTICES = 100; // Maximum number of vertices in the graph
    private static final int INFINITY = 1000000; // Distance value for unvisited vertices

    private static int n; // Number of vertices in the graph
    private static int[][] T; // Adjacency matrix to represent the graph
    private static int[] color; // Array to store the color of each vertex
    private static int[] d; // Array to store the distance of each vertex
    private static int[] Q; // Queue for BFS implementation
    private static int head = 0; // Index of the head element in the queue
    private static int tail = 0; // Index of the tail element in the queue

    // Function to add an element to the queue
    private static void enqueue(int x) {
        Q[tail] = x; // Add element x to the queue
        tail = (tail + 1) % MAX_VERTICES; // Update tail index in a circular manner
    }

    // Function to remove and return an element from the queue
    private static int dequeue() {
        int x;
        x = Q[head]; // Get the front element of the queue
        head = (head + 1) % MAX_VERTICES; // Update head index in a circular manner
        return x; // Return the dequeued element
    }

    // Function to perform Breadth-First Search (BFS) starting from vertex s
    private static void bfs(int s) {
        int i, u, v;

        // Initialize all vertices as unvisited and set their distances to a large value
        for (i = 0; i < n; i++) {
            color[i] = WHITE; // Set color to white (unvisited)
            d[i] = INFINITY; // Set distance to a large number (infinity)
        }

        // Start BFS from the source vertex s
        color[s] = GRAY; // Mark the source vertex as gray (visited)
        d[s] = 0; // Distance to source vertex is 0
        enqueue(s); // Enqueue the source vertex

        // Continue BFS until the queue is empty
        while (head!= tail) {
            u = dequeue(); // Dequeue a vertex from the queue
            // Explore all adjacent vertices of u
            for (v = 0; v < n; v++) {
                // If there is an edge from u to v and v is unvisited
                if (T[u][v] == 1 && color[v] == WHITE) {
                    color[v] = GRAY; // Mark v as gray (visited)
                    d[v] = d[u] + 1; // Update distance to v
                    enqueue(v); // Enqueue vertex v for further exploration
                }
            }
            color[u] = BLACK; // Mark u as black (fully explored)
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of vertices
        n = scanner.nextInt();

        // Initialize the adjacency matrix to zero (no edges)
        T = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                T[i][j] = 0; // No edge between vertices i and j
            }
        }

        // Read the edges of the graph
        for (int i = 0; i < n; i++) {
            int u = scanner.nextInt() - 1; // Read vertex u and number of edges k
            int k = scanner.nextInt(); // Read number of edges k
            for (int j = 0; j < k; j++) {
                int v = scanner.nextInt() - 1; // Read each adjacent vertex v
                T[u][v] = 1; // Set the edge from u to v in the adjacency matrix
            }
        }

        // Perform BFS starting from vertex 0
        color = new int[n];
        d = new int[n];
        Q = new int[MAX_VERTICES];
        bfs(0);

        // Output the distance from the source vertex to each vertex
        for (int i = 0; i < n; i++) {
            if (d[i] == INFINITY) d[i] = -1; // If distance is still infinity, set it to -1
            System.out.printf("%d %d\n", i + 1, d[i]); // Print vertex number and its distance
        }

        scanner.close();
    }
}

