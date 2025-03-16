
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Scanner;
import java.util.stream.IntStream;

"""

import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Scanner;
import java.util.stream.IntStream;

/**
 * The Welsh-Powell algorithm is a graph coloring algorithm that aims to color a graph
 * using the minimum number of colors such that no two adjacent vertices share the same color.
 *
 * <p>
 * The algorithm works by:
 * <ol>
 * <li>Sorting the vertices in descending order based on their degrees (number of edges connected).</li>
 * <li>Iterating through each vertex and assigning it the smallest available color that has not been used by its adjacent vertices.</li>
 * <li>Coloring adjacent vertices with the same color is avoided.</li>
 * </ol>
 * </p>
 *
 * <p>
 * For more information, see <a href="https://en.wikipedia.org/wiki/Graph_coloring">Graph Coloring</a>.
 * </p>
 */
public final class Main {
    private static final int BLANK_COLOR = -1;

    private Main() {
    }

    /**
     * Represents a graph using an adjacency list.
     */
    static final class Graph {
        private final HashSet<Integer>[] adjacencyLists;

        /**
         * Initializes a graph with a specified number of vertices.
         *
         * @param vertices the number of vertices in the graph
         * @throws IllegalArgumentException if the number of vertices is negative
         */
        private Graph(int vertices) {
            adjacencyLists = new HashSet[vertices];
            Arrays.setAll(adjacencyLists, i -> new HashSet<>());
        }

        /**
         * Adds an edge between two vertices in the graph.
         *
         * @param nodeA one end of the edge
         * @param nodeB the other end of the edge
         * @throws IllegalArgumentException if the vertices are out of bounds or if a self-loop is attempted
         */
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

        // Input the number of vertices and edges
        int vertices = scanner.nextInt();
        int edges = scanner.nextInt();

        Graph graph = new Graph(vertices);

        // Input edges
        for (int i = 0; i < edges; i++) {
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            graph.addEdge(from, to);
        }

        // Perform Welsh-Powell algorithm
        int[] colors = findColoring(graph);

        // Print the vertex colors
        System.out.println("Vertex Colors:");
        for (int i = 0; i < colors.length; i++) {
            System.out.println("Vertex " + i + ": Color " + colors[i]);
        }

        scanner.close();
    }

    /**
     * Finds the coloring of the given graph using the Welsh-Powell algorithm.
     *
     * @param graph the input graph to color
     * @return an array of integers where each index represents a vertex and the value represents the color assigned
     */
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

    /**
     * Helper method to check if a color is unassigned
     *
     * @param color the color to check
     * @return {@code true} if the color is unassigned, {@code false} otherwise
     */
    private static boolean isBlank(int color) {
        return color == BLANK_COLOR;
    }

    /**
     * Initializes the colors array with blank color
     *
     * @param numberOfVertices the number of vertices in the graph
     * @return an array of integers representing the colors assigned to the vertices
     */
    private static int[] initializeColors(int numberOfVertices) {
        int[] colors = new int[numberOfVertices];
        Arrays.fill(colors, BLANK_COLOR);
        return colors;
    }

    /**
     * Sorts the vertices by their degree in descending order
     *
     * @param graph the input graph
     * @return an array of integers representing the vertices sorted by degree
     */
    private static Integer[] getSortedNodes(Graph graph) {
        return IntStream.range(0, graph.getNumVertices())
               .boxed()
               .sorted(Comparator.comparingInt(v -> -graph.getAdjacencyList(v).size()))
               .toArray(Integer[]::new);
    }

    /**
     * Computes the colors already used by the adjacent vertices
     *
     * @param graph the input graph
     * @param vertex the vertex to check
     * @param colors the array of colors assigned to the vertices
     * @return an array of booleans representing the colors used by the adjacent vertices
     */
    private static boolean[] computeUsedColors(Graph graph, int vertex, int[] colors) {
        boolean[] usedColors = new boolean[graph.getNumVertices()];
        graph.getAdjacencyList(vertex).stream()
               .map(neighbor -> colors[neighbor])
               .filter(color ->!isBlank(color))
               .forEach(color -> usedColors[color] = true);
        return usedColors;
    }

    /**
     * Finds the first unused color
     *
     * @param usedColors the array of colors used by the adjacent vertices
     * @return the first unused color
     */
    private static int firstUnusedColor(boolean[] usedColors) {
        return IntStream.range(0, usedColors.length)
               .filter(color ->!usedColors[color])
               .findFirst()
               .orElse(-1);
    }
}

