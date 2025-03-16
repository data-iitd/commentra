
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

final class Main {
    private Main() {
        // Private constructor to prevent instantiation of the class from outside
    }

    static class Edge {
        final int src;
        final int dest;
        final int weight;

        Edge(final int src, final int dest, final int weight) {
            // Constructor for creating an edge with source, destination and weight
            this.src = src;
            this.dest = dest;
            this.weight = weight;
        }
    }

    static class Graph {
        final int vertex;
        final List<Edge> edges;

        Graph(final int vertex) {
            // Constructor for creating a graph with given number of vertices
            this.vertex = vertex;
            this.edges = new ArrayList<>();
        }

        void addEdge(int src, int dest, int weight) {
            // Method for adding an edge between two vertices with given weight
            edges.add(new Edge(src, dest, weight));
        }
    }

    private static class Component {
        int parent;
        int rank;

        Component(final int parent, final int rank) {
            // Constructor for creating a component with given parent and rank
            this.parent = parent;
            this.rank = rank;
        }
    }

    private static class BoruvkaState {
        List<Edge> result;
        Component[] components;
        final Graph graph;

        BoruvkaState(final Graph graph) {
            // Constructor for creating a Boruvka state with given graph
            this.result = new ArrayList<>();
            this.components = initializeComponents(graph);
            this.graph = graph;
        }

        void merge(final Edge[] cheapest) {
            // Method for merging two components with the cheapest edge between them
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

        boolean hasMoreEdgesToAdd() {
            // Method for checking if there are more edges to add to the MST
            return result.size() < graph.vertex - 1;
        }

        private Edge[] computeCheapestEdges() {
            // Method for finding the cheapest edges between different components
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

        private static Component[] initializeComponents(final Graph graph) {
            // Method for initializing the components with each vertex as a separate set
            Component[] components = new Component[graph.vertex];
            for (int v = 0; v < graph.vertex; ++v) {
                components[v] = new Component(v, 0);
            }
            return components;
        }
    }

    static int find(final Component[] components, final int i) {
        // Method for finding the root of the component containing the given vertex
        if (components[i].parent != i) {
            components[i].parent = find(components, components[i].parent);
        }
        return components[i].parent;
    }

    static void union(Component[] components, final int x, final int y) {
        // Method for merging two components into one
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

    static List<Edge> boruvkaMST(final Graph graph) {
        // Method for finding the minimum spanning tree using Boruvka's algorithm
        var boruvkaState = new BoruvkaState(graph);
        while (boruvkaState.hasMoreEdgesToAdd()) {
            final var cheapest = boruvkaState.computeCheapestEdges();
            boruvkaState.merge(cheapest);
        }
        return boruvkaState.result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Creating a Scanner object for reading input

        int vertices = scanner.nextInt(); // Reading the number of vertices from the input
        int edges = scanner.nextInt(); // Reading the number of edges from the input

        Graph graph = new Graph(vertices); // Creating a graph with the given number of vertices
        for (int i = 0; i < edges; i++) {
            int src = scanner.nextInt(); // Reading the source vertex from the input
            int dest = scanner.nextInt(); // Reading the destination vertex from the input
            int weight = scanner.nextInt(); // Reading the weight of the edge from the input
            graph.addEdge(src, dest, weight); // Adding the edge to the graph
        }

        List<Edge> mst = boruvkaMST(graph); // Finding the minimum spanning tree using Boruvka's algorithm

        int totalWeight = 0; // Initializing the total weight of the MST to zero
        System.out.println("Edges in MST:"); // Printing the header for the output
        for (Edge edge : mst) {
            System.out.println(edge.src + " - " + edge.dest + " : " + edge.weight); // Printing each edge and its weight
            totalWeight += edge.weight; // Adding the weight of each edge to the total weight
        }

        System.out.println("Total Weight: " + totalWeight); // Printing the total weight of the MST