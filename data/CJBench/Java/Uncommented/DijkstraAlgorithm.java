
import java.util.Arrays;
import java.util.Scanner;
public class DijkstraAlgorithm {
    private final int vertexCount;
    public DijkstraAlgorithm(int vertexCount) {
        this.vertexCount = vertexCount;
    }
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
