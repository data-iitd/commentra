import java.util.Arrays;
import java.util.Scanner;

public class Main {
    // Number of vertices in the graph
    private final int vertexCount;

    // Constructor to initialize the vertex count
    public Main(int vertexCount) {
        this.vertexCount = vertexCount;
    }

    // Method to run Dijkstra's algorithm and find shortest paths from the source vertex
    public int[] run(int[][] graph, int source) {
        // Validate the source vertex index
        if (source < 0 || source >= vertexCount) {
            throw new IllegalArgumentException("Incorrect source vertex");
        }

        // Array to hold the shortest distances from the source vertex
        int[] distances = new int[vertexCount];
        // Array to track processed vertices
        boolean[] processed = new boolean[vertexCount];

        // Initialize distances to infinity and processed array to false
        Arrays.fill(distances, Integer.MAX_VALUE);
        Arrays.fill(processed, false);
        
        // Distance from source to itself is always 0
        distances[source] = 0;

        // Main loop to find shortest paths for all vertices
        for (int count = 0; count < vertexCount - 1; count++) {
            // Get the vertex with the minimum distance that hasn't been processed yet
            int u = getMinDistanceVertex(distances, processed);
            // Mark the vertex as processed
            processed[u] = true;

            // Update distances for adjacent vertices of the processed vertex
            for (int v = 0; v < vertexCount; v++) {
                // Check if the vertex is not processed, there is an edge, and the distance can be updated
                if (!processed[v] && graph[u][v] != 0 && distances[u] != Integer.MAX_VALUE && distances[u] + graph[u][v] < distances[v]) {
                    distances[v] = distances[u] + graph[u][v]; // Update the distance
                }
            }
        }
        // Return the array of shortest distances
        return distances;
    }

    // Helper method to find the vertex with the minimum distance value that has not been processed
    private int getMinDistanceVertex(int[] distances, boolean[] processed) {
        int min = Integer.MAX_VALUE; // Initialize minimum distance
        int minIndex = -1; // Initialize index of the vertex with minimum distance

        // Loop through all vertices to find the minimum distance vertex
        for (int v = 0; v < vertexCount; v++) {
            if (!processed[v] && distances[v] <= min) {
                min = distances[v]; // Update minimum distance
                minIndex = v; // Update index of the vertex
            }
        }
        // Return the index of the vertex with the minimum distance
        return minIndex;
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of vertices from input
        int vertexCount = scanner.nextInt();
        // Initialize the graph as a 2D array
        int[][] graph = new int[vertexCount][vertexCount];

        // Read the graph's adjacency matrix from input
        for (int i = 0; i < vertexCount; i++) {
            for (int j = 0; j < vertexCount; j++) {
                graph[i][j] = scanner.nextInt();
            }
        }

        // Read the source vertex from input
        int source = scanner.nextInt();
        
        // Create an instance of the Main class and run Dijkstra's algorithm
        Main dijkstra = new Main(vertexCount);
        int[] distances = dijkstra.run(graph, source);
        
        // Output the shortest distances from the source vertex
        System.out.println("Shortest distances from source vertex " + source + ":");
        for (int i = 0; i < distances.length; i++) {
            System.out.println("Vertex " + i + " : " + distances[i]);
        }
        
        // Close the scanner to prevent resource leaks
        scanner.close();
    }
}
