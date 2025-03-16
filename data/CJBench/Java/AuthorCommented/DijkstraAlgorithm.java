
import java.util.Arrays;
import java.util.Scanner;

/**
 * Dijkstra's algorithm for finding the shortest path from a single source vertex to all other vertices in a graph.
 */
public class DijkstraAlgorithm {

    private final int vertexCount;

    /**
     * Constructs a Dijkstra object with the given number of vertices.
     *
     * @param vertexCount The number of vertices in the graph.
     */
    public DijkstraAlgorithm(int vertexCount) {
        this.vertexCount = vertexCount;
    }

    /**
     * Executes Dijkstra's algorithm on the provided graph to find the shortest paths from the source vertex to all other vertices.
     *
     * The graph is represented as an adjacency matrix where {@code graph[i][j]} represents the weight of the edge from vertex {@code i}
     * to vertex {@code j}. A value of 0 indicates no edge exists between the vertices.
     *
     * @param graph The graph represented as an adjacency matrix.
     * @param source The source vertex.
     * @return An array where the value at each index {@code i} represents the shortest distance from the source vertex to vertex {@code i}.
     * @throws IllegalArgumentException if the source vertex is out of range.
     */
    public int[] run(int[][] graph, int source) {
        if (source < 0 || source >= vertexCount) {
            throw new IllegalArgumentException("Incorrect source vertex");
        }

        int[] distances = new int[vertexCount];
        boolean[] processed = new boolean[vertexCount];

        Arrays.fill(distances, Integer.MAX_VALUE);
        Arrays.fill(processed, false);
        distances[source] = 0;

        for (int count = 0; count < vertexCount - 1; count++) {
            int u = getMinDistanceVertex(distances, processed);
            processed[u] = true;

            for (int v = 0; v < vertexCount; v++) {
                if (!processed[v] && graph[u][v] != 0 && distances[u] != Integer.MAX_VALUE && distances[u] + graph[u][v] < distances[v]) {
                    distances[v] = distances[u] + graph[u][v];
                }
            }
        }

        return distances;
    }

    /**
     * Finds the vertex with the minimum distance value from the set of vertices that have not yet been processed.
     *
     * @param distances The array of current shortest distances from the source vertex.
     * @param processed The array indicating whether each vertex has been processed.
     * @return The index of the vertex with the minimum distance value.
     */
    private int getMinDistanceVertex(int[] distances, boolean[] processed) {
        int min = Integer.MAX_VALUE;
        int minIndex = -1;

        for (int v = 0; v < vertexCount; v++) {
            if (!processed[v] && distances[v] <= min) {
                min = distances[v];
                minIndex = v;
            }
        }

        return minIndex;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int vertexCount = scanner.nextInt();

        int[][] graph = new int[vertexCount][vertexCount];
        for (int i = 0; i < vertexCount; i++) {
            for (int j = 0; j < vertexCount; j++) {
                graph[i][j] = scanner.nextInt();
            }
        }

        int source = scanner.nextInt();

        DijkstraAlgorithm dijkstra = new DijkstraAlgorithm(vertexCount);
        int[] distances = dijkstra.run(graph, source);

        System.out.println("Shortest distances from source vertex " + source + ":");
        for (int i = 0; i < distances.length; i++) {
            System.out.println("Vertex " + i + " : " + distances[i]);
        }

        scanner.close();
    }
}
