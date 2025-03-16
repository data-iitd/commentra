
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    // Constructor to initialize the number of vertices
    private final int vertexCount;
    public Main(int vertexCount) {
        this.vertexCount = vertexCount;
    }

    // Method to run Dijkstra's algorithm and return the shortest distances from the source vertex to all other vertices
    public int[] run(int[][] graph, int source) {
        // Check if the source vertex is valid
        if (source < 0 || source >= vertexCount) {
            throw new IllegalArgumentException("Incorrect source vertex");
        }

        // Initialize arrays for distances and processed vertices
        int[] distances = new int[vertexCount];
        boolean[] processed = new boolean[vertexCount];

        // Initialize all distances to be maximum value and all processed vertices to be unprocessed
        Arrays.fill(distances, Integer.MAX_VALUE);
        Arrays.fill(processed, false);

        // Set the initial distance of the source vertex to be zero
        distances[source] = 0;

        // Iterate through all vertices except the source vertex
        for (int count = 0; count < vertexCount - 1; count++) {
            // Find the vertex with the minimum distance
            int u = getMinDistanceVertex(distances, processed);
            // Mark the current vertex as processed
            processed[u] = true;

            // Update the distances of neighboring vertices
            for (int v = 0; v < vertexCount; v++) {
                // Check if the neighboring vertex is not processed, has an edge to the current vertex, and the new distance is shorter than the current distance
                if (!processed[v] && graph[u][v] != 0 && distances[u] != Integer.MAX_VALUE && distances[u] + graph[u][v] < distances[v]) {
                    // Update the distance of the neighboring vertex
                    distances[v] = distances[u] + graph[u][v];
                }
            }
        }

        // Return the shortest distances from the source vertex to all other vertices
        return distances;
    }

    // Helper method to find the vertex with the minimum distance
    private int getMinDistanceVertex(int[] distances, boolean[] processed) {
        // Initialize minimum value and index to -1 to represent no minimum found yet
        int min = Integer.MAX_VALUE;
        int minIndex = -1;

        // Iterate through all vertices to find the one with the minimum distance
        for (int v = 0; v < vertexCount; v++) {
            // Check if the vertex is not processed and its distance is less than or equal to the current minimum
            if (!processed[v] && distances[v] <= min) {
                // Update the minimum value and index
                min = distances[v];
                minIndex = v;
            }
        }

        // Return the index of the vertex with the minimum distance
        return minIndex;
    }

    // Main method to read input and run the algorithm
    public static void main(String[] args) {
        // Initialize scanner to read input from the console
        Scanner scanner = new Scanner(System.in);

        // Read the number of vertices from the input
        int vertexCount = scanner.nextInt();

        // Initialize the adjacency matrix to represent the graph
        int[][] graph = new int[vertexCount][vertexCount];

        // Read the edges of the graph from the input
        for (int i = 0; i < vertexCount; i++) {
            for (int j = 0; j < vertexCount; j++) {
                graph[i][j] = scanner.nextInt();
            }
        }

        // Read the source vertex from the input
        int source = scanner.nextInt();

        // Create an instance of the Main class with the number of vertices
        Main dijkstra = new Main(vertexCount);

        // Run the algorithm and print the results
        int[] distances = dijkstra.run(graph, source);
        System.out.println("Shortest distances from source vertex " + source + ":");
        for (int i = 0; i < distances.length; i++) {
            System.out.println("Vertex " + i + " : " + distances[i]);
        }

        // Close the scanner
        scanner.close();
    }
}