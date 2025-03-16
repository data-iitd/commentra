import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Constant representing infinity
    private static final int INF = Integer.MAX_VALUE;

    public static void main(String[] args) {
        // Create a scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of vertices in the graph
        int vertices = scanner.nextInt();
        
        // Initialize the adjacency matrix for the graph
        int[][] graph = new int[vertices][vertices];
        
        // Read the graph's edge weights from input
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                String value = scanner.next();
                // Set the weight to INF if the input is "INF", otherwise parse the integer
                graph[i][j] = value.equals("INF") ? INF : Integer.parseInt(value);
            }
        }
        
        // Compute the shortest paths using Johnson's algorithm
        int[][] shortestPaths = johnsonsAlgorithm(graph);
        
        // Print the resulting shortest path distances
        printDistances(shortestPaths);
    }

    // Method to implement Johnson's algorithm for finding all-pairs shortest paths
    public static int[][] johnsonsAlgorithm(int[][] graph) {
        int vertices = graph.length;
        
        // Step 1: Use Bellman-Ford to find modified weights
        int[] modifiedWeights = bellmanFord(graph);
        
        // Step 2: Reweight the graph using the modified weights
        int[][] reweightedGraph = reweightGraph(graph, modifiedWeights);
        
        // Initialize the shortest paths array
        int[][] shortestPaths = new int[vertices][vertices];
        
        // Step 3: Use Dijkstra's algorithm for each vertex to find shortest paths
        for (int i = 0; i < vertices; i++) {
            shortestPaths[i] = dijkstra(reweightedGraph, i, modifiedWeights);
        }
        
        return shortestPaths;
    }

    // Method to perform the Bellman-Ford algorithm to detect negative weight cycles
    private static int[] bellmanFord(int[][] graph) {
        int vertices = graph.length + 1; // Include an extra vertex for the algorithm
        int[] dist = new int[vertices];
        
        // Initialize distances to infinity
        Arrays.fill(dist, INF);
        dist[vertices - 1] = 0; // Distance to the new vertex is 0
        
        // Create a list to store edges for relaxation
        List<int[]> edges = new ArrayList<>();
        
        // Add all edges from the original graph to the edge list
        for (int i = 0; i < graph.length; i++) {
            for (int j = 0; j < graph.length; j++) {
                if (graph[i][j] != INF) {
                    edges.add(new int[] {i, j, graph[i][j]});
                }
            }
        }
        
        // Add edges from the new vertex to all other vertices with weight 0
        for (int i = 0; i < vertices - 1; i++) {
            edges.add(new int[] {vertices - 1, i, 0});
        }
        
        // Relax edges up to (vertices - 1) times
        for (int i = 0; i < vertices; i++) {
            for (int[] edge : edges) {
                int u = edge[0], v = edge[1], w = edge[2];
                // Relaxation step
                if (dist[u] != INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
        
        // Check for negative weight cycles
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                throw new IllegalArgumentException("Graph contains a negative weight cycle.");
            }
        }
        
        // Return the distance array excluding the extra vertex
        return Arrays.copyOf(dist, graph.length);
    }

    // Method to reweight the graph based on the distances obtained from Bellman-Ford
    private static int[][] reweightGraph(int[][] graph, int[] weights) {
        int vertices = graph.length;
        int[][] reweightedGraph = new int[vertices][vertices];
        
        // Reweight each edge in the graph
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (graph[i][j] != INF) {
                    reweightedGraph[i][j] = graph[i][j] + weights[i] - weights[j];
                } else {
                    reweightedGraph[i][j] = INF; // Maintain INF for no connection
                }
            }
        }
        
        return reweightedGraph;
    }

    // Method to perform Dijkstra's algorithm from a given source vertex
    private static int[] dijkstra(int[][] graph, int source, int[] weights) {
        int vertices = graph.length;
        int[] dist = new int[vertices];
        boolean[] visited = new boolean[vertices];
        
        // Initialize distances to infinity
        Arrays.fill(dist, INF);
        dist[source] = 0; // Distance to the source is 0
        
        // Main loop to find shortest paths
        for (int count = 0; count < vertices - 1; count++) {
            // Get the vertex with the minimum distance that hasn't been visited
            int u = minDistance(dist, visited);
            visited[u] = true; // Mark the vertex as visited
            
            // Update distances for adjacent vertices
            for (int v = 0; v < vertices; v++) {
                if (!visited[v] && graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
        
        // Adjust distances based on the original weights
        for (int i = 0; i < vertices; i++) {
            if (dist[i] != INF) {
                dist[i] = dist[i] - weights[source] + weights[i];
            }
        }
        
        return dist;
    }

    // Helper method to find the vertex with the minimum distance
    private static int minDistance(int[] dist, boolean[] visited) {
        int min = INF, minIndex = -1;
        for (int v = 0; v < dist.length; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                minIndex = v; // Update the index of the minimum distance vertex
            }
        }
        return minIndex;
    }

    // Method to print the shortest path distances
    private static void printDistances(int[][] distances) {
        System.out.println("All-pairs shortest paths:");
        for (int[] row : distances) {
            for (int dist : row) {
                // Print "INF" for infinite distances, otherwise print the distance
                System.out.print((dist == INF ? "INF" : dist) + " ");
            }
            System.out.println(); // New line for each row
        }
    }
}
