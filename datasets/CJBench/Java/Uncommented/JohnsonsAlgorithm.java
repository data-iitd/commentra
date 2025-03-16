
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
public class JohnsonsAlgorithm {
    private static final int INF = Integer.MAX_VALUE;
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int vertices = scanner.nextInt();
        int[][] graph = new int[vertices][vertices];
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                String value = scanner.next();
                graph[i][j] = value.equals("INF") ? INF : Integer.parseInt(value);
            }
        }
        int[][] shortestPaths = johnsonsAlgorithm(graph);
        printDistances(shortestPaths);
    }
    public static int[][] johnsonsAlgorithm(int[][] graph) {
        int vertices = graph.length;
        int[] modifiedWeights = bellmanFord(graph);
        int[][] reweightedGraph = reweightGraph(graph, modifiedWeights);
        int[][] shortestPaths = new int[vertices][vertices];
        for (int i = 0; i < vertices; i++) {
            shortestPaths[i] = dijkstra(reweightedGraph, i, modifiedWeights);
        }
        return shortestPaths;
    }
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
        for (int i = 0; i < vertices; i++) {
            if (dist[i] != INF) {
                dist[i] = dist[i] - weights[source] + weights[i];
            }
        }
        return dist;
    }
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
