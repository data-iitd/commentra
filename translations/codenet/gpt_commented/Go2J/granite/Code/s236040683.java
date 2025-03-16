
import java.util.Scanner;

public class s236040683{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the number of nodes (N) and edges (M) from input
        int N = sc.nextInt();
        int M = sc.nextInt();

        // Create a 2D array to represent the graph
        int[][] graph = new int[N][N];

        // Read M edges and populate the graph
        for (int i = 0; i < M; i++) {
            int from = sc.nextInt() - 1; // Read the edge endpoints (0-indexed)
            int to = sc.nextInt() - 1; // Read the edge endpoints (0-indexed)
            graph[from][to] = 1; // Set the connection from 'from' to 'to'
            graph[to][from] = 1; // Set the connection from 'to' to 'from' (undirected graph)
        }

        // Output the degree (number of connections) of each node
        for (int i = 0; i < N; i++) {
            int degree = 0; // Initialize the degree to 0
            for (int j = 0; j < N; j++) {
                if (graph[i][j] == 1) { // If there is a connection from node i to node j
                    degree++; // Increment the degree
                }
            }
            System.out.println(degree); // Print the degree of node i
        }
    }
}
