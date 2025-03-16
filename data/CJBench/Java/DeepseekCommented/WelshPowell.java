import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Scanner;
import java.util.stream.IntStream;
public final class Main {
    private static final int BLANK_COLOR = -1; // Constant to represent a blank color
    private Main() {
    }
    // Graph class to represent the graph using adjacency lists
    static final class Graph {
        private final HashSet<Integer>[] adjacencyLists; // Array of hash sets to store adjacency lists
        // Constructor to initialize the graph with a given number of vertices
        private Graph(int vertices) {
            adjacencyLists = new HashSet[vertices];
            Arrays.setAll(adjacencyLists, i -> new HashSet<>()); // Initialize each adjacency list
        }
        // Method to add an edge between two nodes
        private void addEdge(int nodeA, int nodeB) {
            adjacencyLists[nodeA].add(nodeB); // Add nodeB to nodeA's adjacency list
            adjacencyLists[nodeB].add(nodeA); // Add nodeA to nodeB's adjacency list
        }
        // Method to get the adjacency list of a vertex
        HashSet<Integer> getAdjacencyList(int vertex) {
            return adjacencyLists[vertex];
        }
        // Method to get the number of vertices in the graph
        int getNumVertices() {
            return adjacencyLists.length;
        }
    }
    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int vertices = scanner.nextInt(); // Read the number of vertices
        int edges = scanner.nextInt(); // Read the number of edges
        Graph graph = new Graph(vertices); // Create a new graph with the given vertices
        for (int i = 0; i < edges; i++) { // Read each edge and add it to the graph
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            graph.addEdge(from, to);
        }
        int[] colors = findColoring(graph); // Find and print the coloring of the graph
        System.out.println("Vertex Colors:");
        for (int i = 0; i < colors.length; i++) {
            System.out.println("Vertex " + i + ": Color " + colors[i]);
        }
        scanner.close(); // Close the scanner
    }
    // Method to find the coloring of the graph using a greedy approach
    public static int[] findColoring(Graph graph) {
        int[] colors = initializeColors(graph.getNumVertices()); // Initialize colors array
        Integer[] sortedVertices = getSortedNodes(graph); // Get sorted nodes based on adjacency list size
        for (int vertex : sortedVertices) { // Assign colors to each vertex
            if (isBlank(colors[vertex])) { // Check if the vertex is blank (uncolored)
                boolean[] usedColors = computeUsedColors(graph, vertex, colors); // Compute used colors by neighbors
                int newColor = firstUnusedColor(usedColors); // Find the first unused color
                colors[vertex] = newColor; // Assign the new color to the vertex
            }
        }
        return colors;
    }
    // Helper method to check if a color is blank (unassigned)
    private static boolean isBlank(int color) {
        return color == BLANK_COLOR;
    }
    // Helper method to initialize the colors array with BLANK_COLOR
    private static int[] initializeColors(int numberOfVertices) {
        int[] colors = new int[numberOfVertices];
        Arrays.fill(colors, BLANK_COLOR);
        return colors;
    }
    // Helper method to get the nodes sorted based on the number of adjacent nodes
    private static Integer[] getSortedNodes(Graph graph) {
        return IntStream.range(0, graph.getNumVertices())
                .boxed()
                .sorted(Comparator.comparingInt(v -> -graph.getAdjacencyList(v).size()))
                .toArray(Integer[]::new);
    }
    // Helper method to compute which colors are used by the neighbors of a vertex
    private static boolean[] computeUsedColors(Graph graph, int vertex, int[] colors) {
        boolean[] usedColors = new boolean[graph.getNumVertices()];
        graph.getAdjacencyList(vertex).stream()
                .map(neighbor -> colors[neighbor])
                .filter(color -> !isBlank(color))
                .forEach(color -> usedColors[color] = true);
        return usedColors;
    }
    // Helper method to find the first available color for a vertex
    private static int firstUnusedColor(boolean[] usedColors) {
        return IntStream.range(0, usedColors.length)
                .filter(color -> !usedColors[color])
                .findFirst()
                .orElse(-1);
    }
}
