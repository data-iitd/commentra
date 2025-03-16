import java.util.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.HashMap;
// AdjacencyList class to represent a graph using an adjacency list
class AdjacencyList<E extends Comparable<E>> {
    // Map to store the graph's edges
    Map<E, ArrayList<E>> adj;
    // Constructor to initialize the adjacency list
    AdjacencyList() {
        adj = new LinkedHashMap<>();
    }
    // Method to add an edge between two vertices
    void addEdge(E from, E to) {
        // Ensure the from vertex is in the adjacency list
        adj.putIfAbsent(from, new ArrayList<>());
        // Add the to vertex to the from vertex's adjacency list
        adj.get(from).add(to);
        // Ensure the to vertex is in the adjacency list
        adj.putIfAbsent(to, new ArrayList<>());
    }
    // Method to get the adjacent vertices of a given vertex
    ArrayList<E> getAdjacents(E v) {
        return adj.get(v);
    }
    // Method to get all the vertices in the graph
    Set<E> getVertices() {
        return adj.keySet();
    }
}
// TopologicalSort class to perform topological sort on a graph
class TopologicalSort<E extends Comparable<E>> {
    // The graph to be sorted
    AdjacencyList<E> graph;
    // Map to store the in-degree of each vertex
    Map<E, Integer> inDegree;
    // Constructor to initialize the topological sort object with a graph
    TopologicalSort(AdjacencyList<E> graph) {
        this.graph = graph;
    }
    // Method to calculate the in-degree of each vertex
    void calculateInDegree() {
        inDegree = new HashMap<>();
        for (E vertex : graph.getVertices()) {
            inDegree.putIfAbsent(vertex, 0);
            for (E adjacent : graph.getAdjacents(vertex)) {
                inDegree.put(adjacent, inDegree.getOrDefault(adjacent, 0) + 1);
            }
        }
    }
    // Method to return the vertices in topological order
    ArrayList<E> topSortOrder() {
        calculateInDegree(); // Calculate in-degrees of all vertices
        Queue<E> q = new LinkedList<>();
        // Add all vertices with in-degree 0 to the queue
        for (var entry : inDegree.entrySet()) {
            if (entry.getValue() == 0) {
                q.add(entry.getKey());
            }
        }
        ArrayList<E> answer = new ArrayList<>();
        int processedVertices = 0;
        // Process vertices from the queue
        while (!q.isEmpty()) {
            E current = q.poll();
            answer.add(current);
            processedVertices++;
            for (E adjacent : graph.getAdjacents(current)) {
                inDegree.put(adjacent, inDegree.get(adjacent) - 1);
                if (inDegree.get(adjacent) == 0) {
                    q.add(adjacent);
                }
            }
        }
        // If not all vertices were processed, a cycle exists
        if (processedVertices != graph.getVertices().size()) {
            throw new IllegalStateException("Graph contains a cycle, topological sort not possible");
        }
        return answer;
    }
}
// Main class to run the topological sort program
public final class Main {
    private Main() {
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int vertices = scanner.nextInt(); // Read the number of vertices
        int edges = scanner.nextInt(); // Read the number of edges
        AdjacencyList<String> graph = new AdjacencyList<>();
        for (int i = 0; i < edges; i++) {
            String from = scanner.next(); // Read the from vertex
            String to = scanner.next(); // Read the to vertex
            graph.addEdge(from, to); // Add an edge between the vertices
        }
        TopologicalSort<String> topSort = new TopologicalSort<>(graph);
        try {
            ArrayList<String> sortedOrder = topSort.topSortOrder();
            System.out.println("Topological Order:");
            for (String s : sortedOrder) {
                System.out.print(s + " "); // Print the sorted order of vertices
            }
            System.out.println();
        } catch (IllegalStateException e) {
            System.out.println(e.getMessage()); // Print an error message if a cycle is detected
        }
        scanner.close(); // Close the scanner
    }
}
