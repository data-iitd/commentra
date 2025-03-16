
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/**
 * This class implements Johnson's algorithm for finding all-pairs shortest paths in a weighted,
 * directed graph that may contain negative edge weights.
 *
 * Johnson's algorithm works by using the Bellman-Ford algorithm to compute a transformation of the
 * input graph that removes all negative weights, allowing Dijkstra's algorithm to be used for
 * efficient shortest path computations.
 *
 * Time Complexity: O(V^2 * log(V) + V*E)
 * Space Complexity: O(V^2)
 *
 * Where V is the number of vertices and E is the number of edges in the graph.
 *
 * For more information, please visit {@link https://en.wikipedia.org/wiki/Johnson%27s_algorithm}
 */
public class JohnsonsAlgorithm {

    private static final int INF = Integer.MAX_VALUE;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input the number of vertices
        int vertices = scanner.nextInt();

        // Input the adjacency matrix
        int[][] graph = new int[vertices][vertices];
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                String value = scanner.next();
                graph[i][j] = value.equals("INF") ? INF : Integer.parseInt(value);
            }
        }

        // Run Johnson's Algorithm and print the results
        int[][] shortestPaths = johnsonsAlgorithm(graph);
        printDistances(shortestPaths);
    }

    /**
     * Executes Johnson's algorithm on the given graph.
     * Steps:
     * 1. Add a new vertex to the graph and run Bellman-Ford to compute modified weights
     * 2. t the graph using the modified weights
     * 3. Run Dijkstra's algorithm for each vertex to compute the shortest paths
     * The final result is a 2D array of shortest distances between all pairs of vertices.
     *
     * @param graph The input graph represented as an adjacency matrix.
     * @return A 2D array representing the shortest distances between all pairs of vertices.
     */
    public static int[][] johnsonsAlgorithm(int[][] graph) {
        int vertices = graph.length;

        // Step 1: Reweight graph using Bellman-Ford
        int[] modifiedWeights = bellmanFord(graph);

        // Step 2: Reweight the graph
        int[][] reweightedGraph = reweightGraph(graph, modifiedWeights);

        // Step 3: Run Dijkstra's for all vertices
        int[][] shortestPaths = new int[vertices][vertices];
        for (int i = 0; i < vertices; i++) {
            shortestPaths[i] = dijkstra(reweightedGraph, i, modifiedWeights);
        }

        return shortestPaths;
    }

    /**
     * Implements the Bellman-Ford algorithm to compute the shortest paths from a new vertex
     * to all other vertices. This is used to calculate the weight function h(v) for reweighting.
     *
     * @param edges The edge list of the graph.
     * @param numVertices The number of vertices in the original graph.
     * @return An array of modified weights for each vertex.
     */
    private static int[] bellmanFord(int[][] graph) {
        int vertices = graph.length + 1;
        int[] dist = new int[vertices];
        Arrays.fill(dist, INF);
        dist[vertices - 1] = 0;

        List<int[]> edges = new ArrayList<>();
        for (int i = 0; i < graph.length; i++) {
            for (int j = 0; j < graph.length; j++) {
                if (graph[i][j] != INF) {
                    edges.add(new int[] {i, j, graph[i][j]});
                }
            }
        }
        for (int i = 0; i < vertices - 1; i++) {
            edges.add(new int[] {vertices - 1, i, 0});
        }

        for (int i = 0; i < vertices; i++) {
            for (int[] edge : edges) {
                int u = edge[0], v = edge[1], w = edge[2];
                if (dist[u] != INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        for (int[] edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                throw new IllegalArgumentException("Graph contains a negative weight cycle.");
            }
        }

        return Arrays.copyOf(dist, graph.length);
    }

    /**
     * Reweights the graph using the modified weights computed by Bellman-Ford.
     *
     * @param graph The original graph.
     * @param modifiedWeights The modified weights from Bellman-Ford.
     * @return The reweighted graph.
     */
    private static int[][] reweightGraph(int[][] graph, int[] weights) {
        int vertices = graph.length;
        int[][] reweightedGraph = new int[vertices][vertices];
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (graph[i][j] != INF) {
                    reweightedGraph[i][j] = graph[i][j] + weights[i] - weights[j];
                } else {
                    reweightedGraph[i][j] = INF;
                }
            }
        }
        return reweightedGraph;
    }

    /**
     * Implements Dijkstra's algorithm for finding shortest paths from a source vertex.
     *
     * @param reweightedGraph The reweighted graph to run Dijkstra's on.
     * @param source The source vertex.
     * @param modifiedWeights The modified weights from Bellman-Ford.
     * @return An array of shortest distances from the source to all other vertices.
     */
    private static int[] dijkstra(int[][] graph, int source, int[] weights) {
        int vertices = graph.length;
        int[] dist = new int[vertices];
        boolean[] visited = new boolean[vertices];
        Arrays.fill(dist, INF);
        dist[source] = 0;

        for (int count = 0; count < vertices - 1; count++) {
            int u = minDistance(dist, visited);
            visited[u] = true;

            for (int v = 0; v < vertices; v++) {
                if (!visited[v] && graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }

        // Adjust distances back to original weights
        for (int i = 0; i < vertices; i++) {
            if (dist[i] != INF) {
                dist[i] = dist[i] - weights[source] + weights[i];
            }
        }

        return dist;
    }

    /**
     * Finds the vertex with the minimum distance value from the set of vertices
     * not yet included in the shortest path tree.
     *
     * @param dist Array of distances.
     * @param visited Array of visited vertices.
     * @return The index of the vertex with minimum distance.
     */
    private static int minDistance(int[] dist, boolean[] visited) {
        int min = INF, minIndex = -1;
        for (int v = 0; v < dist.length; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                minIndex = v;
            }
        }
        return minIndex;
    }

    private static void printDistances(int[][] distances) {
        System.out.println("All-pairs shortest paths:");
        for (int[] row : distances) {
            for (int dist : row) {
                System.out.print((dist == INF ? "INF" : dist) + " ");
            }
            System.out.println();
        }
    }
}
