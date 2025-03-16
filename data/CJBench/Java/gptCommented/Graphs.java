import java.util.ArrayList;
import java.util.Scanner;

// Class representing a graph using an adjacency list
class AdjacencyListGraph<E extends Comparable<E>> {
    // List to hold all vertices in the graph
    ArrayList<Vertex> vertices;

    // Constructor to initialize the graph
    AdjacencyListGraph() {
        vertices = new ArrayList<>();
    }

    // Inner class representing a vertex in the graph
    private class Vertex {
        E data; // Data contained in the vertex
        ArrayList<Vertex> adjacentVertices; // List of adjacent vertices

        // Constructor to initialize a vertex with given data
        Vertex(E data) {
            adjacentVertices = new ArrayList<>();
            this.data = data;
        }

        // Method to add an adjacent vertex; returns false if it already exists
        public boolean addAdjacentVertex(Vertex to) {
            for (Vertex v : adjacentVertices) {
                if (v.data.compareTo(to.data) == 0) {
                    return false; // Vertex already adjacent
                }
            }
            return adjacentVertices.add(to); // Add the vertex if not already adjacent
        }

        // Method to remove an adjacent vertex; returns true if successful
        public boolean removeAdjacentVertex(E to) {
            for (int i = 0; i < adjacentVertices.size(); i++) {
                if (adjacentVertices.get(i).data.compareTo(to) == 0) {
                    adjacentVertices.remove(i); // Remove the vertex
                    return true;
                }
            }
            return false; // Vertex not found
        }
    }

    // Method to remove an edge from the graph; returns true if successful
    public boolean removeEdge(E from, E to) {
        Vertex fromV = null; // Vertex from which the edge is to be removed
        // Find the vertex corresponding to 'from'
        for (Vertex v : vertices) {
            if (from.compareTo(v.data) == 0) {
                fromV = v;
                break;
            }
        }
        if (fromV == null) {
            return false; // 'From' vertex not found
        }
        return fromV.removeAdjacentVertex(to); // Remove the edge
    }

    // Method to add an edge to the graph; creates vertices if they don't exist
    public boolean addEdge(E from, E to) {
        Vertex fromV = null; // Vertex from which the edge starts
        Vertex toV = null; // Vertex to which the edge points
        // Find or create the vertices for 'from' and 'to'
        for (Vertex v : vertices) {
            if (from.compareTo(v.data) == 0) { 
                fromV = v;
            } else if (to.compareTo(v.data) == 0) { 
                toV = v;
            }
            if (fromV != null && toV != null) {
                break; // Both vertices found
            }
        }
        // Create 'from' vertex if it doesn't exist
        if (fromV == null) {
            fromV = new Vertex(from);
            vertices.add(fromV);
        }
        // Create 'to' vertex if it doesn't exist
        if (toV == null) {
            toV = new Vertex(to);
            vertices.add(toV);
        }
        return fromV.addAdjacentVertex(toV); // Add the edge
    }

    // Method to represent the graph as a string
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        // Iterate through each vertex to build the string representation
        for (Vertex v : vertices) {
            sb.append("Vertex: ");
            sb.append(v.data);
            sb.append("\n");
            sb.append("Adjacent vertices: ");
            // List all adjacent vertices
            for (Vertex v2 : v.adjacentVertices) {
                sb.append(v2.data);
                sb.append(" ");
            }
            sb.append("\n");
        }
        return sb.toString(); // Return the complete string representation
    }
}

// Main class to execute the program
public final class Main {
    // Private constructor to prevent instantiation
    private Main() {
    }

    // Main method to run the graph program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Scanner for user input
        AdjacencyListGraph<Integer> graph = new AdjacencyListGraph<>(); // Create a graph instance
        int edgeCount = scanner.nextInt(); // Read the number of edges
        // Loop to read edges and add them to the graph
        for (int i = 0; i < edgeCount; i++) {
            int from = scanner.nextInt(); // Read starting vertex
            int to = scanner.nextInt(); // Read ending vertex
            graph.addEdge(from, to); // Add edge to the graph
        }
        // Output the graph representation
        System.out.println("Graph Representation:");
        System.out.println(graph);
        scanner.close(); // Close the scanner
    }
}
