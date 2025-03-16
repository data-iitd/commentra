import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Edge {
    int source; // Source vertex of the edge
    int target; // Target vertex of the edge
    int weight; // Weight of the edge

    Edge(int source, int target, int weight) {
        this.source = source;
        this.target = target;
        this.weight = weight;
    }
}

public class Main {
    static final int INF = 1000000001; // Define a constant for infinity (a large value)
    static final int N = 100000; // Define a constant for the maximum number of vertices

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int V = scanner.nextInt(); // Number of vertices
        int E = scanner.nextInt(); // Number of edges
        int r = scanner.nextInt(); // Source vertex

        List<Edge> edges = new ArrayList<>(); // List to store all edges of the graph

        // Read all edges from input and store them in the edges list
        for (int i = 0; i < E; i++) {
            int source = scanner.nextInt();
            int target = scanner.nextInt();
            int distance = scanner.nextInt();
            edges.add(new Edge(source, target, distance)); // Add the new edge to the edges list
        }

        int[] distances = new int[N]; // Array to store the shortest distances from the source vertex
        int[] prevDistances = new int[N]; // Array to store the previous distances for comparison

        // Initialize distances array to infinity for all vertices
        for (int i = 0; i < N; i++) {
            distances[i] = INF; // Set all distances to a maximum value (infinity)
        }

        distances[r] = 0; // Set the distance to the source vertex to 0

        // Main loop to relax edges V-1 times
        for (int i = 1; i < V; i++) {
            // Copy current distances to previous distances for comparison
            System.arraycopy(distances, 0, prevDistances, 0, V);

            // Relax all edges
            for (Edge edge : edges) {
                // Update the distance to the target vertex if a shorter path is found
                distances[edge.target] = Math.min(distances[edge.source] + edge.weight, distances[edge.target]);
            }

            // Check if any distance was updated in this iteration
            boolean same = true; // Flag to check if distances remain the same
            for (int j = 0; j < V; j++) {
                if (distances[j] != prevDistances[j]) {
                    same = false; // If any distance changed, set flag to false
                    break;
                }
            }

            // If no distances were updated, break out of the loop early
            if (same) break;
        }

        // Output the shortest distances from the source vertex to all other vertices
        for (int i = 0; i < V; i++) {
            if (distances[i] == INF) {
                System.out.println("INF"); // Print "INF" if the vertex is unreachable
            } else {
                System.out.println(distances[i]); // Print the shortest distance
            }
        }

        scanner.close();
    }
}

// <END-OF-CODE>
