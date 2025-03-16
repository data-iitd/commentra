
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
final class BoruvkaAlgorithm {
    private BoruvkaAlgorithm() {
    }
    static class Edge {
        final int src;
        final int dest;
        final int weight;
        Edge(final int src, final int dest, final int weight) {
            this.src = src;
            this.dest = dest;
            this.weight = weight;
        }
    }
    static class Graph {
        final int vertex;
        final List<Edge> edges;
        Graph(final int vertex) {
            this.vertex = vertex;
            this.edges = new ArrayList<>();
        }
        void addEdge(int src, int dest, int weight) {
            edges.add(new Edge(src, dest, weight));
        }
    }
    private static class Component {
        int parent;
        int rank;
        Component(final int parent, final int rank) {
            this.parent = parent;
            this.rank = rank;
        }
    }
    private static class BoruvkaState {
        List<Edge> result;
        Component[] components;
        final Graph graph;
        BoruvkaState(final Graph graph) {
            this.result = new ArrayList<>();
            this.components = initializeComponents(graph);
            this.graph = graph;
        }
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
        boolean hasMoreEdgesToAdd() {
            return result.size() < graph.vertex - 1;
        }
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
        private static Component[] initializeComponents(final Graph graph) {
            Component[] components = new Component[graph.vertex];
            for (int v = 0; v < graph.vertex; ++v) {
                components[v] = new Component(v, 0);
            }
            return components;
        }
    }
    static int find(final Component[] components, final int i) {
        if (components[i].parent != i) {
            components[i].parent = find(components, components[i].parent);
        }
        return components[i].parent;
    }
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
    static List<Edge> boruvkaMST(final Graph graph) {
        var boruvkaState = new BoruvkaState(graph);
        while (boruvkaState.hasMoreEdgesToAdd()) {
            final var cheapest = boruvkaState.computeCheapestEdges();
            boruvkaState.merge(cheapest);
        }
        return boruvkaState.result;
    }
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
