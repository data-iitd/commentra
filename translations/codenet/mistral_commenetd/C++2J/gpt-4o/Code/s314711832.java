import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Edge {
    int source;
    int target;
    int weight;

    Edge(int source, int target, int weight) {
        this.source = source;
        this.target = target;
        this.weight = weight;
    }
}

public class BellmanFord {
    static final int INF = 1000000001;
    static final int N = 100000;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int V = scanner.nextInt(); // number of vertices
        int E = scanner.nextInt(); // number of edges
        int r = scanner.nextInt(); // source vertex

        List<Edge> edges = new ArrayList<>();

        // Read edges
        for (int i = 0; i < E; i++) {
            int source = scanner.nextInt();
            int target = scanner.nextInt();
            int distance = scanner.nextInt();
            edges.add(new Edge(source, target, distance));
        }

        int[] distances = new int[N];
        int[] prevDistances = new int[N];

        // Initialize distances array with maximum value
        for (int i = 0; i < N; i++) {
            distances[i] = INF; // max value
        }

        // Set initial distance of source vertex to 0
        distances[r] = 0;

        // Bellman-Ford algorithm
        for (int i = 1; i < V; i++) {
            // Initialize previous distances array with current distances
            System.arraycopy(distances, 0, prevDistances, 0, V);

            // Update distances for all edges
            for (Edge edge : edges) {
                if (distances[edge.source] != INF) {
                    distances[edge.target] = Math.min(distances[edge.source] + edge.weight, distances[edge.target]);
                }
            }

            // Check if all distances have been updated
            boolean same = true;
            for (int j = 0; j < V; j++) {
                if (distances[j] != prevDistances[j]) {
                    same = false;
                    break;
                }
            }

            // If all distances have been updated, break the loop
            if (same) break;
        }

        // Print results
        for (int i = 0; i < V; i++) {
            if (distances[i] == INF) {
                System.out.println("INF");
            } else {
                System.out.println(distances[i]);
            }
        }

        scanner.close();
    }
}

// <END-OF-CODE>
