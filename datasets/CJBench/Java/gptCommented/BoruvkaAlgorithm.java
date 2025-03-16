import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Main class containing the implementation of Boruvka's algorithm
final class Main {
    // Private constructor to prevent instantiation
    private Main() {
    }

    // Class representing an edge in the graph
    static class Edge {
        final int src;    // Source vertex of the edge
        final int dest;   // Destination vertex of the edge
        final int weight; // Weight of the edge

        // Constructor to initialize an edge
        Edge(final int src, final int dest, final int weight) {
            this.src = src;
            this.dest = dest;
            this.weight = weight;
        }
    }

    // Class representing a graph
    static class Graph {
        final int vertex; // Number of vertices in the graph
        final List<Edge> edges; // List of edges in the graph

        // Constructor to initialize the graph with a given number of vertices
        Graph(final int vertex) {
            this.vertex = vertex;
            this.edges = new ArrayList<>();
        }

        // Method to add an edge to the graph
        void addEdge(int src, int dest, int weight) {
            edges.add(new Edge(src, dest, weight));
        }
    }

    // Class representing a component in the union-find structure
    private static class Component {
        int parent; // Parent of the component
        int rank;   // Rank of the component for union by rank

        // Constructor to initialize a component
        Component(final int parent, final int rank) {
            this.parent = parent;
            this.rank = rank;
        }
    }

    // Class to maintain the state of Boruvka's algorithm
    private static class BoruvkaState {
        List<Edge> result; // List to store the resulting edges of the MST
        Component[] components; // Array of components for union-find
        final Graph graph; // The graph being processed

        // Constructor to initialize Boruvka's state
        BoruvkaState(final Graph graph) {
            this.result = new ArrayList<>();
            this.components = initializeComponents(graph);
            this.graph = graph;
        }

        // Method to merge components based on the cheapest edges found
        void merge(final Edge[] cheapest) {
            for (int i = 0; i < graph.vertex; ++i) {
                if (cheapest[i] != null) {
                    final var component1 = find(components, cheapest[i].src);
                    final var component2 = find(components, cheapest[i].dest);
                    // If the components are different, merge them
                    if (component1 != component2) {
                        result.add(cheapest[i]); // Add edge to the result
                        union(components, component1, component2); // Union the components
                    }
                }
            }
        }

        // Method to check if more edges can be added to the MST
        boolean hasMoreEdgesToAdd() {
            return result.size() < graph.vertex - 1; // MST has (V-1) edges
        }

        // Method to compute the cheapest edges for each component
        private Edge[] computeCheapestEdges() {
            Edge[] cheapest = new Edge[graph.vertex]; // Array to store cheapest edges
            for (final var edge : graph.edges) {
                final var set1 = find(components, edge.src);
                final var set2 = find(components, edge.dest);
                // If the edge connects different components, check for the cheapest
                if (set1 != set2) {
                    if (cheapest[set1] == null || edge.weight < cheapest[set1].weight) {
                        cheapest[set1] = edge; // Update cheapest edge for component 1
                    }
                    if (cheapest[set2] == null || edge.weight < cheapest[set2].weight) {
                        cheapest[set2] = edge; // Update cheapest edge for component 2
                    }
                }
            }
            return cheapest; // Return the array of cheapest edges
        }

        // Method to initialize the components for each vertex
        private static Component[] initializeComponents(final Graph graph) {
            Component[] components = new Component[graph.vertex];
            for (int v = 0; v < graph.vertex; ++v) {
                components[v] = new Component(v, 0); // Each vertex is its own parent initially
            }
            return components; // Return the initialized components
        }
    }

    // Method to find the root of a component using path compression
    static int find(final Component[] components, final int i) {
        if (components[i].parent != i) {
            components[i].parent = find(components, components[i].parent); // Path compression
        }
        return components[i].parent; // Return the root of the component
    }

    // Method to union two components
    static void union(Component[] components, final int x, final int y) {
        final int xroot = find(components, x);
        final int yroot = find(components, y);
        // Union by rank
        if (components[xroot].rank < components[yroot].rank) {
            components[xroot].parent = yroot;
        } else if (components[xroot].rank > components[yroot].rank) {
            components[yroot].parent = xroot;
        } else {
            components[yroot].parent = xroot;
            components[xroot].rank++; // Increase rank if they are of the same rank
        }
    }

    // Method to execute Boruvka's algorithm and find the MST
    static List<Edge> boruvkaMST(final Graph graph) {
        var boruvkaState = new BoruvkaState(graph); // Initialize Boruvka's state
        while (boruvkaState.hasMoreEdgesToAdd()) {
            final var cheapest = boruvkaState.computeCheapestEdges(); // Compute cheapest edges
            boruvkaState.merge(cheapest); // Merge components based on cheapest edges
        }
        return boruvkaState.result; // Return the resulting edges of the MST
    }

    // Main method to read input and execute the algorithm
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int vertices = scanner.nextInt(); // Read number of vertices
        int edges = scanner.nextInt(); // Read number of edges
        Graph graph = new Graph(vertices); // Initialize the graph
        // Read edges and add them to the graph
        for (int i = 0; i < edges; i++) {
            int src = scanner.nextInt();
            int dest = scanner.nextInt();
            int weight = scanner.nextInt();
            graph.addEdge(src, dest, weight);
        }
        // Execute Boruvka's algorithm to find the MST
        List<Edge> mst = boruvkaMST(graph);
        int totalWeight = 0; // Variable to store total weight of the MST
        System.out.println("Edges in MST:");
        // Print the edges in the MST and calculate total weight
        for (Edge edge : mst) {
            System.out.println(edge.src + " - " + edge.dest + " : " + edge.weight);
            totalWeight += edge.weight;
        }
        // Print the total weight of the MST
        System.out.println("Total Weight: " + totalWeight);
    }
}
