import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class BFS {
    static final int M = 100;
    static final int whi = 0;
    static final int gra = 1;
    static final int bla = 2;

    static int n;
    static int[][] T = new int[M][M];
    static int[] color = new int[M];
    static int[] d = new int[M];

    // Breadth First Search Algorithm
    static void bfs(int s) {
        // Initialize all vertices with white color and infinite distance
        for (int i = 0; i < n; i++) {
            color[i] = whi;
            d[i] = 1000000;
        }

        // Initialize source vertex with gray color and zero distance
        color[s] = gra;
        d[s] = 0;

        // Queue for BFS
        Queue<Integer> queue = new LinkedList<>();
        queue.add(s); // Enqueue source vertex

        // Traverse the queue until it is empty
        while (!queue.isEmpty()) {
            int u = queue.poll(); // Dequeue a vertex
            for (int v = 0; v < n; v++) { // Iterate through all adjacent vertices
                if (T[u][v] == 1 && color[v] == whi) { // If the adjacent vertex is unvisited
                    color[v] = gra; // Mark it as visited
                    d[v] = d[u] + 1; // Update its distance
                    queue.add(v); // Enqueue the adjacent vertex
                }
            }
            color[u] = bla; // Mark the current vertex as black
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of vertices
        n = scanner.nextInt();

        // Initialize the adjacency matrix with zeros
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                T[i][j] = 0;
            }
        }

        // Read the edges and add them to the adjacency matrix
        for (int i = 0; i < n; i++) {
            int u = scanner.nextInt() - 1; // Decrease the index of the source vertex by 1
            int k = scanner.nextInt(); // Number of neighbors
            for (int j = 0; j < k; j++) {
                int v = scanner.nextInt() - 1; // Decrease the index of the neighbor vertex by 1
                T[u][v] = 1; // Add an edge between the vertices
            }
        }

        // Perform BFS algorithm starting from the source vertex 0
        bfs(0);

        // Print the results
        for (int i = 0; i < n; i++) {
            if (d[i] == 1000000) d[i] = -1; // Set the distance to -1 if it is unreachable
            System.out.println((i + 1) + " " + d[i]); // Print the vertex index and its distance from the source
        }

        scanner.close();
    }
}

// <END-OF-CODE>
