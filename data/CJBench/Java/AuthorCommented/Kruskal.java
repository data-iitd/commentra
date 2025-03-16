import java.util.*;

/**
 * Implements Kruskal's Algorithm to find the Minimum Spanning Tree (MST)
 * of a connected, undirected graph.
 */
public class Kruskal {

    /**
     * Represents an edge in the graph with a source, destination, and weight.
     */
    static class Edge {
        int from;
        int to;
        int weight;

        Edge(int from, int to, int weight) {
            this.from = from;
            this.to = to;
            this.weight = weight;
        }

        @Override
        public String toString() {
            return from + " - " + to + " : " + weight;
        }
    }

    /**
     * Union-Find structure to track connected components.
     */
    static class UnionFind {
        private final int[] parent;
        private final int[] rank;

        UnionFind(int size) {
            parent = new int[size];
            rank = new int[size];
            for (int i = 0; i < size; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]); // Path compression
            }
            return parent[x];
        }

        boolean union(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);

            if (rootX == rootY) {
                return false;
            }

            // Union by rank
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }

            return true;
        }
    }

    /**
     * Kruskal's algorithm to find the Minimum Spanning Tree (MST).
     */
    public static List<Edge> kruskal(List<Edge> edges, int vertices) {
        edges.sort(Comparator.comparingInt(edge -> edge.weight)); // Sort edges by weight
        UnionFind uf = new UnionFind(vertices);
        List<Edge> mst = new ArrayList<>();

        for (Edge edge : edges) {
            if (uf.union(edge.from, edge.to)) { // Add edge if it connects two separate components
                mst.add(edge);
            }
            if (mst.size() == vertices - 1) { // Stop when MST is complete
                break;
            }
        }

        return mst;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int vertices = sc.nextInt();
        int edges = sc.nextInt();

        List<Edge> edgeList = new ArrayList<>();
        for (int i = 0; i < edges; i++) {
            int from = sc.nextInt();
            int to = sc.nextInt();
            int weight = sc.nextInt();
            edgeList.add(new Edge(from, to, weight));
        }

        List<Edge> mst = kruskal(edgeList, vertices);

        System.out.println("Minimum Spanning Tree (MST):");
        for (Edge edge : mst) {
            System.out.println(edge);
        }

        sc.close();
    }
}
