import java.util.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.HashMap;

// Class representing an adjacency list for a directed graph
class AdjacencyList<E extends Comparable<E>> {
    // Map to hold the adjacency list representation of the graph
    Map<E, ArrayList<E>> adj;

    // Constructor to initialize the adjacency list
    AdjacencyList() {
        adj = new LinkedHashMap<>();
    }

    // Method to add a directed edge from 'from' to 'to'
    void addEdge(E from, E to) {
        // Ensure 'from' vertex is present in the adjacency list
        adj.putIfAbsent(from, new ArrayList<>());
        // Add 'to' vertex to the adjacency list of 'from'
        adj.get(from).add(to);
        // Ensure 'to' vertex is present in the adjacency list
        adj.putIfAbsent(to, new ArrayList<>());
    }

    // Method to get the list of adjacent vertices for a given vertex
    ArrayList<E> getAdjacents(E v) {
        return adj.get(v);
    }

    // Method to get all vertices in the graph
    Set<E> getVertices() {
        return adj.keySet();
    }
}

// Class to perform topological sorting on a directed graph
class TopologicalSort<E extends Comparable<E>> {
    // The graph represented as an adjacency list
    AdjacencyList<E> graph;
    // Map to store the in-degree of each vertex
    Map<E, Integer> inDegree;

    // Constructor to initialize the topological sort with a graph
    TopologicalSort(AdjacencyList<E> graph) {
        this.graph = graph;
    }

    // Method to calculate the in-degree of each vertex in the graph
    void calculateInDegree() {
        inDegree = new HashMap<>();
        // Initialize in-degree for each vertex
        for (E vertex : graph.getVertices()) {
            inDegree.putIfAbsent(vertex, 0);
            // Update in-degree for adjacent vertices
            for (E adjacent : graph.getAdjacents(vertex)) {
                inDegree.put(adjacent, inDegree.getOrDefault(adjacent, 0) + 1);
            }
        }
    }

    // Method to perform topological sorting and return the sorted order
    ArrayList<E> topSortOrder() {
        // Calculate in-degrees of all vertices
        calculateInDegree();
        // Queue to hold vertices with in-degree of 0
        Queue<E> q = new LinkedList<>();
        // Add all vertices with in-degree of 0 to the queue
        for (var entry : inDegree.entrySet()) {
            if (entry.getValue() == 0) {
                q.add(entry.getKey());
            }
        }
        // List to hold the topological order
        ArrayList<E> answer = new ArrayList<>();
        int processedVertices = 0;

        // Process vertices in the queue
        while (!q.isEmpty()) {
            E current = q.poll(); // Get the next vertex
            answer.add(current);   // Add it to the topological order
            processedVertices++;   // Increment the count of processed vertices

            // Decrease in-degree for adjacent vertices
            for (E adjacent : graph.getAdjacents(current)) {
                inDegree.put(adjacent, inDegree.get(adjacent) - 1);
                // If in-degree becomes 0, add it to the queue
                if (inDegree.get(adjacent) == 0) {
                    q.add(adjacent);
                }
            }
        }

        // Check for cycles in the graph
        if (processedVertices != graph.getVertices().size()) {
            throw new IllegalStateException("Graph contains a cycle, topological sort not possible");
        }
        return answer; // Return the topologically sorted order
    }
}

// Main class to execute the topological sort
public final class Main {
    // Private constructor to prevent instantiation
    private Main() {
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read number of vertices and edges from input
        int vertices = scanner.nextInt();
        int edges = scanner.nextInt();
        // Create a new adjacency list for the graph
        AdjacencyList<String> graph = new AdjacencyList<>();
        // Read edges and add them to the graph
        for (int i = 0; i < edges; i++) {
            String from = scanner.next();
            String to = scanner.next();
            graph.addEdge(from, to);
        }
        // Create a TopologicalSort object with the graph
        TopologicalSort<String> topSort = new TopologicalSort<>(graph);
        try {
            // Get the topological order of the graph
            ArrayList<String> sortedOrder = topSort.topSortOrder();
            System.out.println("Topological Order:");
            // Print the sorted order
            for (String s : sortedOrder) {
                System.out.print(s + " ");
            }
            System.out.println();
        } catch (IllegalStateException e) {
            // Handle the case where the graph has a cycle
            System.out.println(e.getMessage());
        }
        // Close the scanner
        scanner.close();
    }
}
