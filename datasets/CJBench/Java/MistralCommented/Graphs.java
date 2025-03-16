
import java.util.ArrayList;
import java.util.Scanner;

// Define a generic AdjacencyListGraph class with a type parameter E that extends Comparable<E>
class AdjacencyListGraph<E extends Comparable<E>> {
    // Initialize an empty ArrayList to store vertices
    ArrayList<Vertex<E>> vertices;

    // Constructor initializes the ArrayList
    AdjacencyListGraph() {
        vertices = new ArrayList<>();
    }

    // Define an inner class Vertex with data and ArrayList to store adjacent vertices
    private class Vertex<E extends Comparable<E>> {
        E data;
        ArrayList<Vertex<E>> adjacentVertices;

        // Constructor initializes data and empty ArrayList for adjacent vertices
        Vertex(E data) {
            this.data = data;
            adjacentVertices = new ArrayList<>();
        }

        // Add an adjacent vertex to the ArrayList if it doesn't already exist
        public boolean addAdjacentVertex(Vertex<E> to) {
            for (Vertex<E> v : adjacentVertices) {
                if (v.data.compareTo(to.data) == 0) {
                    return false;
                }
            }
            return adjacentVertices.add(to);
        }

        // Remove an adjacent vertex from the ArrayList by its data
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

    // Add an edge by adding two vertices as adjacent to each other
    public boolean addEdge(E from, E to) {
        Vertex<E> fromV = null;
        Vertex<E> toV = null;

        // Find the vertices in the ArrayList based on their data
        for (Vertex<E> v : vertices) {
            if (from.compareTo(v.data) == 0) {
                fromV = v;
            } else if (to.compareTo(v.data) == 0) {
                toV = v;
            }
            if (fromV != null && toV != null) {
                break;
            }
        }

        // If the vertices are not found, create new ones and add them to the ArrayList
        if (fromV == null) {
            fromV = new Vertex<>(from);
            vertices.add(fromV);
        }
        if (toV == null) {
            toV = new Vertex<>(to);
            vertices.add(toV);
        }

        // Add the adjacent relationship between the vertices
        return fromV.addAdjacentVertex(toV);
    }

    // Remove an edge by removing the adjacent relationship between two vertices
    public boolean removeEdge(E from, E to) {
        Vertex<E> fromV = null;

        // Find the vertex based on its data
        for (Vertex<E> v : vertices) {
            if (from.compareTo(v.data) == 0) {
                fromV = v;
                break;
            }
        }

        // If the vertex is not found, return false
        if (fromV == null) {
            return false;
        }

        // Remove the adjacent relationship between the vertices
        return fromV.removeAdjacentVertex(to);
    }

    // Override the toString method to print the graph representation
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();

        // Iterate through each vertex and print its data and adjacent vertices
        for (Vertex<E> v : vertices) {
            sb.append("Vertex: ");
            sb.append(v.data);
            sb.append("\n");
            sb.append("Adjacent vertices: ");
            for (Vertex<E> v2 : v.adjacentVertices) {
                sb.append(v2.data);
                sb.append(" ");
            }
            sb.append("\n");
        }

        // Return the StringBuilder content as a String
        return sb.toString();
    }
}

// Main class to read edges from the user and print the graph representation
public final class Main {
    private Main() {
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Initialize an empty AdjacencyListGraph
        AdjacencyListGraph<Integer> graph = new AdjacencyListGraph<>();

        // Read the number of edges from the user
        int edgeCount = scanner.nextInt();

        // Add edges to the graph
        for (int i = 0; i < edgeCount; i++) {
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            graph.addEdge(from, to);
        }

        // Print the graph representation
        System.out.println("Graph Representation:");
        System.out.println(graph);

        // Close the Scanner
        scanner.close();
    }
}