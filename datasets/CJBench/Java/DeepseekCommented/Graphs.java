import java.util.ArrayList;
import java.util.Scanner;

// This class represents a graph using an adjacency list.
class AdjacencyListGraph<E extends Comparable<E>> {
    // List to store all vertices in the graph.
    ArrayList<Vertex> vertices;

    // Constructor to initialize the graph with an empty list of vertices.
    AdjacencyListGraph() {
        vertices = new ArrayList<>();
    }

    // Inner class representing a vertex in the graph.
    private class Vertex {
        // Data stored in the vertex.
        E data;
        // List of adjacent vertices.
        ArrayList<Vertex> adjacentVertices;

        // Constructor to initialize a vertex with given data.
        Vertex(E data) {
            adjacentVertices = new ArrayList<>();
            this.data = data;
        }

        // Method to add an adjacent vertex to this vertex.
        // Returns false if the vertex already exists in the adjacency list.
        public boolean addAdjacentVertex(Vertex to) {
            for (Vertex v : adjacentVertices) {
                if (v.data.compareTo(to.data) == 0) {
                    return false; 
                }
            }
            return adjacentVertices.add(to); 
        }

        // Method to remove an adjacent vertex from this vertex.
        // Returns true if the vertex was removed, false otherwise.
        public boolean removeAdjacentVertex(E to) {
            for (int i = 0; i < adjacentVertices.size(); i++) {
                if (adjacentVertices.get(i).data.compareTo(to) == 0) {
                    adjacentVertices.remove(i);
                    return true;
                }
            }
            return false;
        }
    }

    // Method to remove an edge between two vertices.
    // Returns true if the edge was removed, false if the edge did not exist.
    public boolean removeEdge(E from, E to) {
        Vertex fromV = null;
        for (Vertex v : vertices) {
            if (from.compareTo(v.data) == 0) {
                fromV = v;
                break;
            }
        }
        if (fromV == null) {
            return false;
        }
        return fromV.removeAdjacentVertex(to);
    }

    // Method to add an edge between two vertices.
    // Returns true if the edge was added, false if the edge already existed.
    public boolean addEdge(E from, E to) {
        Vertex fromV = null;
        Vertex toV = null;
        for (Vertex v : vertices) {
            if (from.compareTo(v.data) == 0) { 
                fromV = v;
            } else if (to.compareTo(v.data) == 0) { 
                toV = v;
            }
            if (fromV != null && toV != null) {
                break; 
            }
        }
        if (fromV == null) {
            fromV = new Vertex(from);
            vertices.add(fromV);
        }
        if (toV == null) {
            toV = new Vertex(to);
            vertices.add(toV);
        }
        return fromV.addAdjacentVertex(toV);
    }

    // Method to provide a string representation of the graph.
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Vertex v : vertices) {
            sb.append("Vertex: ");
            sb.append(v.data);
            sb.append("\n");
            sb.append("Adjacent vertices: ");
            for (Vertex v2 : v.adjacentVertices) {
                sb.append(v2.data);
                sb.append(" ");
            }
            sb.append("\n");
        }
        return sb.toString();
    }
}

// Main class to run the graph operations.
public final class Main {
    // Private constructor to prevent instantiation.
    private Main() {
    }

    // Main method to take input and print the graph representation.
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        AdjacencyListGraph<Integer> graph = new AdjacencyListGraph<>();
        int edgeCount = scanner.nextInt();
        for (int i = 0; i < edgeCount; i++) {
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            graph.addEdge(from, to);
        }
        System.out.println("Graph Representation:");
        System.out.println(graph);
        scanner.close();
    }
}
