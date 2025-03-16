
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Scanner;
import java.util.stream.IntStream;
public final class WelshPowell {
    private static final int BLANK_COLOR = -1;
    private WelshPowell() {
    }
    static final class Graph {
        private final HashSet<Integer>[] adjacencyLists;
        private Graph(int vertices) {
            adjacencyLists = new HashSet[vertices];
            Arrays.setAll(adjacencyLists, i -> new HashSet<>());
        }
        private void addEdge(int nodeA, int nodeB) {
            adjacencyLists[nodeA].add(nodeB);
            adjacencyLists[nodeB].add(nodeA);
        }
        HashSet<Integer> getAdjacencyList(int vertex) {
            return adjacencyLists[vertex];
        }
        int getNumVertices() {
            return adjacencyLists.length;
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int vertices = scanner.nextInt();
        int edges = scanner.nextInt();
        Graph graph = new Graph(vertices);
        for (int i = 0; i < edges; i++) {
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            graph.addEdge(from, to);
        }
        int[] colors = findColoring(graph);
        System.out.println("Vertex Colors:");
        for (int i = 0; i < colors.length; i++) {
            System.out.println("Vertex " + i + ": Color " + colors[i]);
        }
        scanner.close();
    }
    public static int[] findColoring(Graph graph) {
        int[] colors = initializeColors(graph.getNumVertices());
        Integer[] sortedVertices = getSortedNodes(graph);
        for (int vertex : sortedVertices) {
            if (isBlank(colors[vertex])) {
                boolean[] usedColors = computeUsedColors(graph, vertex, colors);
                int newColor = firstUnusedColor(usedColors);
                colors[vertex] = newColor;
            }
        }
        return colors;
    }
    private static boolean isBlank(int color) {
        return color == BLANK_COLOR;
    }
    private static int[] initializeColors(int numberOfVertices) {
        int[] colors = new int[numberOfVertices];
        Arrays.fill(colors, BLANK_COLOR);
        return colors;
    }
    private static Integer[] getSortedNodes(Graph graph) {
        return IntStream.range(0, graph.getNumVertices())
                .boxed()
                .sorted(Comparator.comparingInt(v -> -graph.getAdjacencyList(v).size()))
                .toArray(Integer[]::new);
    }
    private static boolean[] computeUsedColors(Graph graph, int vertex, int[] colors) {
        boolean[] usedColors = new boolean[graph.getNumVertices()];
        graph.getAdjacencyList(vertex).stream()
                .map(neighbor -> colors[neighbor])
                .filter(color -> !isBlank(color))
                .forEach(color -> usedColors[color] = true);
        return usedColors;
    }
    private static int firstUnusedColor(boolean[] usedColors) {
        return IntStream.range(0, usedColors.length)
                .filter(color -> !usedColors[color])
                .findFirst()
                .orElse(-1);
    }
}
