
import java.util.*;
import java.util.LinkedList;
import java.util.ArrayList;
import java.util.HashMap;

// Define a generic AdjacencyList class for Comparable elements
class AdjacencyList<E extends Comparable<E>> {
    Map<E, ArrayList<E>> adj; // Store the adjacency list as a Map of vertices to their adjacent vertices

    // Constructor
    AdjacencyList() {
        adj = new LinkedHashMap<>(); // Use LinkedHashMap to maintain insertion order
    }

    // Add an edge between two vertices
    void addEdge(E from, E to) {
        adj.putIfAbsent(from, new ArrayList<>()); // Add a new empty list if from doesn't have one yet
        adj.get(from).add(to); // Add to the list of adjacents for from
        adj.putIfAbsent(to, new ArrayList<>()); // Add a new empty list if to doesn't have one yet
    }

    // Get the list of adjacent vertices for a given vertex
    ArrayList<E> getAdjacents(E v) {
        return adj.get(v);
    }

    // Get all the vertices in the graph
    Set<E> getVertices() {
        return adj.keySet();
    }
}

// Define a generic TopologicalSort class for Comparable elements
class TopologicalSort<E extends Comparable<E>> {
    AdjacencyList<E> graph; // Store the graph to be sorted
    Map<E, Integer> inDegree; // Store the in-degree for each vertex

    // Constructor
    TopologicalSort(AdjacencyList<E> graph) {
        this.graph = graph;
    }

    // Calculate the in-degree for each vertex
    void calculateInDegree() {
        inDegree = new HashMap<>();
        for (E vertex : graph.getVertices()) {
            inDegree.putIfAbsent(vertex, 0); // Initialize the in-degree for each vertex to 0
            for (E adjacent : graph.getAdjacents(vertex)) {
                inDegree.put(adjacent, inDegree.getOrDefault(adjacent, 0) + 1); // Increment the in-degree for each adjacent
            }
        }
    }

    // Perform the topological sort
    ArrayList<E> topSortOrder() {
        calculateInDegree(); // Calculate the in-degree for all vertices
        Queue<E> q = new LinkedList<>(); // Create a queue to store vertices with 0 in-degree
        ArrayList<E> answer = new ArrayList<>(); // Create an empty list to store the topological order

        // Add all vertices with 0 in-degree to the queue
        for (var entry : inDegree.entrySet()) {
            if (entry.getValue() == 0) {
                q.add(entry.getKey());
            }
        }

        // Process vertices in the order they are removed from the queue
        while (!q.isEmpty()) {
            E current = q.poll(); // Get the next vertex with 0 in-degree
            answer.add(current); // Add it to the answer
            for (E adjacent : graph.getAdjacents(current)) {
                inDegree.put(adjacent, inDegree.get(adjacent) - 1); // Decrease the in-degree for each adjacent
                if (inDegree.get(adjacent) == 0) {
                    q.add(adjacent); // Add it to the queue if its in-degree is now 0
                }
            }
        }

        // Throw an exception if there is a cycle in the graph
        if (answer.size() != graph.getVertices().size()) {
            throw new IllegalStateException("Graph contains a cycle, topological sort not possible");
        }

        return answer;
    }
}

// Main class to read input and call the topological sort algorithm
public final class Main {
    private Main() {
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Read input from the console

        int vertices = scanner.nextInt(); // Read the number of vertices
        int edges = scanner.nextInt(); // Read the number of edges

        AdjacencyList<String> graph = new AdjacencyList<>(); // Create an empty graph
        for (int i = 0; i < edges; i++) {
            String from = scanner.next(); // Read the source vertex
            String to = scanner.next(); // Read the destination vertex
            graph.addEdge(from, to); // Add an edge between the vertices
        }

        TopologicalSort<String> topSort = new TopologicalSort<>(graph); // Create a new topological sort object

        try {
            ArrayList<String> sortedOrder = topSort.topSortOrder(); // Perform the topological sort
            System.out.println("Topological Order:"); // Print the header for the output
            for (String s : sortedOrder) {
                System.out.print(s + " "); // Print each vertex in the topological order
            }
            System.out.println(); // Print a newline after all vertices have been printed
        } catch (IllegalStateException e) {
            System.out.println(e.getMessage()); // Print an error message if there is a cycle in the graph
        }

        scanner.close(); // Close the scanner after reading all input
    }
}