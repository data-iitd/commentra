import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Scanner;
import java.util.stream.IntStream;

public final class Main {
    // Class constants
    private static final int BLANK_COLOR = -1;

    private Main() {
    }

    // Class inner static class: Graph
    static final class Graph {
        // Class fields
        private final HashSet<Integer>[] adjacencyLists;

        // Constructor
        public Graph(int vertices) {
            adjacencyLists = new HashSet[vertices];
            Arrays.setAll(adjacencyLists, i -> new HashSet<>());
        }

        // Methods
        public void addEdge(int nodeA, int nodeB) {
            adjacencyLists[nodeA].add(nodeB);
            adjacencyLists[nodeB].add(nodeA);
        }

        public HashSet<Integer> getAdjacencyList(int vertex) {
            return adjacencyLists[vertex];
        }

        public int getNumVertices() {
            return adjacencyLists.length;
        }
    }

    public static void main(String[] args) {
        // Initialize scanner
        Scanner scanner = new Scanner(System.in);

        // Read input: number of vertices and edges
        int vertices = scanner.nextInt();
        int edges = scanner.nextInt();

        // Initialize graph
        Graph graph = new Graph(vertices);

        // Read input: edges and add them to the graph
        for (int i = 0; i < edges; i++) {
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            graph.addEdge(from, to);
        }

        // Find vertex colors
        int[] colors = findColoring(graph);

        // Print vertex colors
        System.out.println("Vertex Colors:");
        for (int i = 0; i < colors.length; i++) {
            System.out.println("Vertex " + i + ": Color " + colors[i]);
        }

        // Close scanner
        scanner.close();
    }

    // Method to find vertex colors using Depth First Search algorithm
    public static int[] findColoring(Graph graph) {
        // Initialize colors array with blank color for all vertices
        int[] colors = initializeColors(graph.getNumVertices());

        // Sort vertices by the number of their neighbors in descending order
        Integer[] sortedVertices = getSortedNodes(graph);

        // For each vertex in sorted order
        for (int vertex : sortedVertices) {
            // If the current vertex has not been colored yet
            if (isBlank(colors[vertex])) {
                // Compute used colors by current vertex neighbors
                boolean[] usedColors = computeUsedColors(graph, vertex, colors);

                // Find the first unused color
                int newColor = firstUnusedColor(usedColors);

                // Color the current vertex with the found color
                colors[vertex] = newColor;
            }
        }

        return colors;
    }

    // Helper method: check if a color is blank
    private static boolean isBlank(int color) {
        return color == BLANK_COLOR;
    }

    // Helper method: initialize colors array with blank color for all vertices
    private static int[] initializeColors(int numberOfVertices) {
        int[] colors = new int[numberOfVertices];
        Arrays.fill(colors, BLANK_COLOR);
        return colors;
    }

    // Helper method: get sorted nodes (vertices) based on the number of their neighbors
    private static Integer[] getSortedNodes(Graph graph) {
        return IntStream.range(0, graph.getNumVertices())
                .boxed()
                .sorted(Comparator.comparingInt(v -> -graph.getAdjacencyList(v).size()))
                .toArray(Integer[]::new);
    }

    // Helper method: compute used colors by current vertex neighbors
    private static boolean[] computeUsedColors(Graph graph, int vertex, int[] colors) {
        boolean[] usedColors = new boolean[graph.getNumVertices()];
        graph.getAdjacencyList(vertex).stream()
                .map(neighbor -> colors[neighbor])
                .filter(color -> !isBlank(color))
                .forEach(color -> usedColors[color] = true);
        return usedColors;
    }

    // Helper method: find the first unused color among usedColors
    private static int firstUnusedColor(boolean[] usedColors) {
        return IntStream.range(0, usedColors.length)
                .filter(color -> !usedColors[color])
                .findFirst()
                .orElse(-1);
    }
}
