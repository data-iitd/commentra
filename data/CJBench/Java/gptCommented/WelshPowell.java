import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Scanner;
import java.util.stream.IntStream;

public final class Main {
    // Constant representing a blank color
    private static final int BLANK_COLOR = -1;

    // Private constructor to prevent instantiation
    private Main() {
    }

    // Inner class representing a Graph using adjacency lists
    static final class Graph {
        private final HashSet<Integer>[] adjacencyLists;

        // Constructor to initialize the graph with a given number of vertices
        private Graph(int vertices) {
            adjacencyLists = new HashSet[vertices];
            // Initialize each adjacency list as a new HashSet
            Arrays.setAll(adjacencyLists, i -> new HashSet<>());
        }

        // Method to add an edge between two nodes in the graph
        private void addEdge(int nodeA, int nodeB) {
            adjacencyLists[nodeA].add(nodeB);
            adjacencyLists[nodeB].add(nodeA);
        }

        // Method to get the adjacency list of a specific vertex
        HashSet<Integer> getAdjacencyList(int vertex) {
            return adjacencyLists[vertex];
        }

        // Method to get the number of vertices in the graph
        int getNumVertices() {
            return adjacencyLists.length;
        }
    }

    public static void main(String[] args) {
        // Create a scanner to read input from the console
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of vertices and edges from input
        int vertices = scanner.nextInt();
        int edges = scanner.nextInt();
        
        // Initialize the graph with the specified number of vertices
        Graph graph = new Graph(vertices);
        
        // Read each edge and add it to the graph
        for (int i = 0; i < edges; i++) {
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            graph.addEdge(from, to);
        }
        
        // Find the coloring of the graph
        int[] colors = findColoring(graph);
        
        // Output the colors assigned to each vertex
        System.out.println("Vertex Colors:");
        for (int i = 0; i < colors.length; i++) {
            System.out.println("Vertex " + i + ": Color " + colors[i]);
        }
        
        // Close the scanner to free resources
        scanner.close();
    }

    // Method to find a valid coloring for the graph
    public static int[] findColoring(Graph graph) {
        // Initialize colors for all vertices to blank
        int[] colors = initializeColors(graph.getNumVertices());
        
        // Get the vertices sorted by their degree in descending order
        Integer[] sortedVertices = getSortedNodes(graph);
        
        // Assign colors to each vertex
        for (int vertex : sortedVertices) {
            // If the vertex is uncolored, proceed to color it
            if (isBlank(colors[vertex])) {
                // Determine which colors are already used by adjacent vertices
                boolean[] usedColors = computeUsedColors(graph, vertex, colors);
                
                // Find the first unused color
                int newColor = firstUnusedColor(usedColors);
                
                // Assign the new color to the vertex
                colors[vertex] = newColor;
            }
        }
        return colors; // Return the array of colors assigned to vertices
    }

    // Method to check if a color is blank (unassigned)
    private static boolean isBlank(int color) {
        return color == BLANK_COLOR;
    }

    // Method to initialize the colors array with blank colors
    private static int[] initializeColors(int numberOfVertices) {
        int[] colors = new int[numberOfVertices];
        Arrays.fill(colors, BLANK_COLOR); // Fill with blank color
        return colors;
    }

    // Method to get the vertices sorted by their degree in descending order
    private static Integer[] getSortedNodes(Graph graph) {
        return IntStream.range(0, graph.getNumVertices())
                .boxed()
                .sorted(Comparator.comparingInt(v -> -graph.getAdjacencyList(v).size()))
                .toArray(Integer[]::new);
    }

    // Method to compute which colors are used by adjacent vertices
    private static boolean[] computeUsedColors(Graph graph, int vertex, int[] colors) {
        boolean[] usedColors = new boolean[graph.getNumVertices()];
        
        // Check the colors of all adjacent vertices
        graph.getAdjacencyList(vertex).stream()
                .map(neighbor -> colors[neighbor])
                .filter(color -> !isBlank(color))
                .forEach(color -> usedColors[color] = true);
        
        return usedColors; // Return the array indicating used colors
    }

    // Method to find the first unused color
    private static int firstUnusedColor(boolean[] usedColors) {
        return IntStream.range(0, usedColors.length)
                .filter(color -> !usedColors[color])
                .findFirst()
                .orElse(-1); // Return -1 if no unused color is found
    }
}
