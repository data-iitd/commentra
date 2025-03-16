import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Main class to encapsulate the functionality
final class Main {
    // Private constructor to prevent instantiation
    private Main() {
    }

    // Edge class to represent edges in the graph
    static class Edge {
        final int src;       // Source vertex of the edge
        final int dest;      // Destination vertex of the edge
        final int weight;    // Weight of the edge

        // Constructor for Edge
        Edge(final int src, final int dest, final int weight) {
            this.src = src;
            this.dest = dest;
            this.weight = weight;
        }
    }

    // Graph class to represent the graph
    static class Graph {
        final int vertex;    // Number of vertices in the graph
        final List<Edge> edges; // List of edges in the graph

        // Constructor for Graph
        Graph(final int vertex) {
            this.vertex = vertex;
            this.edges = new ArrayList<>();
        }

        // Method to add an edge to the graph
        void addEdge(int src, int dest, int weight) {
            edges.add(new Edge(src, dest, weight));
        }
    }

    // Component class to manage disjoint sets
    private static class Component {
        int parent;       // Parent of the component
        int rank;         // Rank of the component

        // Constructor for Component
        Component(final int parent, final int rank) {
            this.parent = parent;
            this.rank = rank;
        }
    }

    // BoruvkaState class to manage the state of Boruvka's algorithm
    private static class BoruvkaState {
        List<Edge> result; // List to store the edges in the MST
        Component[] components; // Array to store components
        final Graph graph; // The graph for which we are finding the MST

        // Constructor for BoruvkaState
        BoruvkaState(final Graph graph) {
            this.result = new ArrayList<>();
            this.components = initializeComponents(graph);
            this.graph = graph;
        }

        // Method to merge components using the cheapest edge
        void merge(final Edge[] cheapest) {
            for (int i = 0; i < graph.vertex; ++i) {
                if (cheapest[i] != null) {
                    final var component1 = find(components, cheapest[i].src);
                    final var component2 = find(components, cheapest[i].dest);
                    if (component1 != component2) {
                        result.add(cheapest[i]);
                        union(components, component1, component2);
                    }
                }
            }
        }

        // Method to check if there are more edges to add to the MST
        boolean hasMoreEdgesToAdd() {
            return result.size() < graph.vertex - 1;
        }

        // Method to compute the cheapest edges for each component
        private Edge[] computeCheapestEdges() {
            Edge[] cheapest = new Edge[graph.vertex];
            for (final var edge : graph.edges) {
                final var set1 = find(components, edge.src);
                final var set2 = find(components, edge.dest);
                if (set1 != set2) {
                    if (cheapest[set1] == null || edge.weight < cheapest[set1].weight) {
                        cheapest[set1] = edge;
                    }
                    if (cheapest[set2] == null || edge.weight < cheapest[set2].weight) {
                        cheapest[set2] = edge;
                    }
                }
            }
            return cheapest;
        }

        // Method to initialize components for disjoint set
        private static Component[] initializeComponents(final Graph graph) {
            Component[] components = new Component[graph.vertex];
            for (int v = 0; v < graph.vertex; ++v) {
                components[v] = new Component(v, 0);
            }
            return components;
        }
    }

    // Method to find the parent of a component
    static int find(final Component[] components, final int i) {
        if (components[i].parent != i) {
            components[i].parent = find(components, components[i].parent);
        }
        return components[i].parent;
    }

    // Method to union two components
    static void union(Component[] components, final int x, final int y) {
        final int xroot = find(components, x);
        final int yroot = find(components, y);
        if (components[xroot].rank < components[yroot].rank) {
            components[xroot].parent = yroot;
        } else if (components[xroot].rank > components[yroot].rank) {
            components[yroot].parent = xroot;
        } else {
            components[yroot].parent = xroot;
            components[xroot].rank++;
        }
    }

    // Method to find the Minimum Spanning Tree using Boruvka's algorithm
    static List<Edge> boruvkaMST(final Graph graph) {
        var boruvkaState = new BoruvkaState(graph);
        while (boruvkaState.hasMoreEdgesToAdd()) {
            final var cheapest = boruvkaState.computeCheapestEdges();
            boruvkaState.merge(cheapest);
        }
        return boruvkaState.result;
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int vertices = scanner.nextInt();
        int edges = scanner.nextInt();
        Graph graph = new Graph(vertices);
        for (int i = 0; i < edges; i++) {
            int src = scanner.nextInt();
            int dest = scanner.nextInt();
            int weight = scanner.nextInt();
            graph.addEdge(src, dest, weight);
        }
        List<Edge> mst = boruvkaMST(graph);
        int totalWeight = 0;
        System.out.println("Edges in MST:");
        for (Edge edge : mst) {
            System.out.println(edge.src + " - " + edge.dest + " : " + edge.weight);
            totalWeight += edge.weight;
        }
        System.out.println("Total Weight: " + totalWeight);
    }
}
