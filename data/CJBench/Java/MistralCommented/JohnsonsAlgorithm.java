import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/**
 * This class implements the Johnson's algorithm to find the shortest paths between all pairs of vertices in a weighted graph.
 */
public class Main {
    private static final int INF = Integer.MAX_VALUE;

    /**
     * The entry point of the program. Reads the number of vertices and their weights from the standard input, computes the shortest paths using Johnson's algorithm, and prints the results.
     *
     * @param args The command-line arguments, which are not used in this program.
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input from the standard input.
        int vertices = scanner.nextInt(); // Read the number of vertices from the standard input.
        int[][] graph = new int[vertices][vertices]; // Initialize a 2D array to represent the weighted graph.

        // Read the weights of the edges from the standard input and store them in the graph array.
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                String value = scanner.next();
                graph[i][j] = value.equals("INF") ? INF : Integer.parseInt(value);
            }
        }

        int[][] shortestPaths = johnsonsAlgorithm(graph); // Compute the shortest paths using Johnson's algorithm.
        printDistances(shortestPaths); // Print the results to the standard output.

        scanner.close(); // Close the Scanner object to release the system resources.
    }

    /**
     * Computes the shortest paths between all pairs of vertices using Johnson's algorithm.
     *
     * @param graph The weighted graph represented as a 2D array.
     * @return A 2D array containing the shortest paths between all pairs of vertices.
     */
    public static int[][] johnsonsAlgorithm(int[][] graph) {
        int vertices = graph.length;
        int[] modifiedWeights = bellmanFord(graph); // Compute the modified weights using Bellman-Ford algorithm.
        int[][] reweightedGraph = reweightGraph(graph, modifiedWeights); // Create the reweighted graph.
        int[][] shortestPaths = new int[vertices][vertices]; // Initialize a 2D array to store the shortest paths.

        // Run Dijkstra's algorithm from each vertex to find the shortest paths to all other vertices in the reweighted graph.
        for (int i = 0; i < vertices; i++) {
            shortestPaths[i] = dijkstra(reweightedGraph, i, modifiedWeights);
        }

        return shortestPaths;
    }

    /**
     * Computes the modified weights for each vertex using the Bellman-Ford algorithm.
     *
     * @param graph The weighted graph represented as a 2D array.
     * @return An array containing the modified weights for each vertex.
     */
    private static int[] bellmanFord(int[][] graph) {
        int vertices = graph.length + 1;
        int[] dist = new int[vertices]; // Initialize an array to store the shortest distances from the source vertex to all other vertices.
        Arrays.fill(dist, INF); // Set all distances to INF initially.
        dist[vertices - 1] = 0; // Set the distance from the source vertex to itself to 0.

        List<int[]> edges = new ArrayList<>(); // Initialize a list to store the edges in the order they will be processed.

        // Add the edges to the list.
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (graph[i][j] != INF) {
                    edges.add(new int[] {i, j, graph[i][j]});
                }
            }
        }

        // Process the edges V - 1 times.
        for (int i = 0; i < vertices - 1; i++) {
            for (int[] edge : edges) {
                int u = edge[0], v = edge[1], w = edge[2];
                if (dist[u] != INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w; // Update the distance if a shorter path is found.
                }
            }
        }

        // Check for negative-weight cycles.
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                throw new IllegalArgumentException("Graph contains a negative weight cycle.");
            }
        }

        return Arrays.copyOf(dist, graph.length); // Return the modified weights as an array.
    }

    /**
     * Reweights the graph using the modified weights computed in the Bellman-Ford algorithm.
     *
     * @param graph The weighted graph represented as a 2D array.
     * @param weights The modified weights for each vertex.
     * @return A 2D array representing the reweighted graph.
     */
    private static int[][] reweightGraph(int[][] graph, int[] weights) {
        int vertices = graph.length;
        int[][] reweightedGraph = new int[vertices][vertices]; // Initialize a 2D array to store the reweighted graph.

        // Set the weights of the edges in the reweighted graph.
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (graph[i][j] != INF) {
                    reweightedGraph[i][j] = graph[i][j] + weights[i] - weights[j];
                } else {
                    reweightedGraph[i][j] = INF;
                }
            }
        }

        return reweightedGraph; // Return the reweighted graph as a 2D array.
    }

    /**
     * Finds the shortest path from a source vertex to all other vertices in a weighted graph using Dijkstra's algorithm.
     *
     * @param graph The weighted graph represented as a 2D array.
     * @param source The source vertex.
     * @param weights The modified weights for each vertex.
     * @return An array containing the shortest distances from the source vertex to all other vertices.
     */
    private static int[] dijkstra(int[][] graph, int source, int[] weights) {
        int vertices = graph.length;
        int[] dist = new int[vertices]; // Initialize an array to store the shortest distances from the source vertex to all other vertices.
        boolean[] visited = new boolean[vertices]; // Initialize a boolean array to mark the visited vertices.

        Arrays.fill(dist, INF); // Set all distances to INF initially.
        dist[source] = 0; // Set the distance from the source vertex to itself to 0.

        for (int count = 0; count < vertices - 1; count++) {
            int u = minDistance(dist, visited); // Find the unvisited vertex with the minimum distance.
            visited[u] = true; // Mark the vertex as visited.

            for (int v = 0; v < vertices; v++) {
                if (!visited[v] && graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v]; // Update the distance if a shorter path is found.
                }
            }
        }

        return dist; // Return the shortest distances from the source vertex to all other vertices.
    }

    /**
     * Finds the vertex with the minimum distance from the distances array that has not been visited yet.
     *
     * @param dist The array containing the shortest distances from a source vertex to all other vertices.
     * @param visited The boolean array marking the visited vertices.
     * @return The index of the vertex with the minimum distance.
     */
    private static int minDistance(int[] dist, boolean[] visited) {
        int min = Integer.MAX_VALUE, minIndex = -1;
        for (int v = 0; v < dist.length; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                minIndex = v;
            }
        }
        return minIndex;
    }

    /**
     * Prints the shortest distances from each vertex to all other vertices in the shortest paths array.
     *
     * @param shortestPaths The 2D array containing the shortest paths between all pairs of vertices.
     */
    private static void printDistances(int[][] shortestPaths) {
        System.out.println("All-pairs shortest paths:");
        for (int[] row : shortestPaths) {
            for (int dist : row) {
                System.out.print((dist == INF ? "INF" : dist) + " ");
            }
            System.out.println();
        }
    }
}
