import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize a Scanner object to read input from the standard input
        Scanner sc = new Scanner(System.in);

        // Read the number of vertices (nodes) in the graph from the standard input
        int n = sc.nextInt();

        // Initialize a 2D integer array 'g' of size (n+1) x (n+1) to represent the adjacency matrix of the graph
        int[][] g = new int[n+1][n+1];

        // Read the edges (connections) of the graph from the standard input and fill the adjacency matrix 'g' accordingly
        for (int i = 0; i < n; i++) {
            int u = sc.nextInt(); // Read the source vertex
            int k = sc.nextInt(); // Read the number of neighbors

            for (int j = 0; j < k; j++) { // Iterate through the neighbors
                int v = sc.nextInt(); // Read the destination vertex
                g[u][v] = 1; // Set the corresponding entry in the adjacency matrix to 1
            }
        }

        // Initialize an integer array 'd' of size (n+1) to store the shortest distance from the source vertex to all other vertices
        int[] d = new int[n+1];
        for (int i = 0; i <= n; i++) {
            d[i] = -1; // Initialize all distances to -1, indicating that they are not yet known
        }

        // Initialize an empty LinkedList 'que' to store the vertices to be processed in BFS traversal
        Queue<Integer> que = new LinkedList<Integer>();

        // Add the source vertex (vertex 1) to the queue and set its distance to 0
        que.add(1);
        d[1] = 0;

        // Perform BFS traversal using the queue and update the distances of all reachable vertices
        while (!que.isEmpty()) {
            int top = que.poll(); // Dequeue the vertex with the shortest distance
            for (int j = 1; j <= n; j++) { // Iterate through all adjacent vertices
                if (g[top][j] == 1 && d[j] == -1) { // Check if the adjacent vertex is not yet visited
                    que.add(j); // Add the adjacent vertex to the queue
                    d[j] = d[top] + 1; // Update its distance
                }
            }
        }

        // Print the shortest distances from the source vertex to all other vertices
        for (int i = 1; i <= n; i++) {
            System.out.println(i + " " + d[i]);
        }
    }
}
