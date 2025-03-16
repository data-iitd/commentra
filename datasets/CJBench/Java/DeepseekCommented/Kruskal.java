import java.util.*;
public class Main {
    // Represents an edge in the graph with 'from', 'to', and 'weight' attributes.
    static class Edge {
        int from;
        int to;
        int weight;
        // Constructor to initialize the edge with 'from', 'to', and 'weight'.
        Edge(int from, int to, int weight) {
            this.from = from;
            this.to = to;
            this.weight = weight;
        }
        // Returns a string representation of the edge in the format 'from - to : weight'.
        @Override
        public String toString() {
            return from + " - " + to + " : " + weight;
        }
    }
    // Implements the Union-Find (Disjoint Set Union) data structure for tracking connected components.
    static class UnionFind {
        private final int[] parent;
        private final int[] rank;
        // Constructor to initialize the Union-Find structure with a given size.
        UnionFind(int size) {
            parent = new int[size];
            rank = new int[size];
            for (int i = 0; i < size; i++) {
                parent[i] = i; // Each node is its own parent initially.
                rank[i] = 0;   // Rank is initialized to 0 for each node.
            }
        }
        // Finds the root of the node 'x' with path compression.
        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]); // Path compression.
            }
            return parent[x];
        }
        // Unites the sets containing nodes 'x' and 'y'. Returns true if they were in different sets.
        boolean union(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX == rootY) {
                return false; // They are already in the same set.
            }
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX; // Attach smaller rank tree under root of higher rank tree.
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++; // If ranks are same, then make one as root and increment its rank.
            }
            return true;
        }
    }
    // Implements Kruskal's algorithm to find the Minimum Spanning Tree (MST) of the graph.
    public static List<Edge> kruskal(List<Edge> edges, int vertices) {
        edges.sort(Comparator.comparingInt(edge -> edge.weight)); // Sort edges by weight.
        UnionFind uf = new UnionFind(vertices);
        List<Edge> mst = new ArrayList<>();
        for (Edge edge : edges) {
            if (uf.union(edge.from, edge.to)) { // Add edge to MST if it doesn't form a cycle.
                mst.add(edge);
            }
            if (mst.size() == vertices - 1) { // Stop if MST has 'vertices - 1' edges.
                break;
            }
        }
        return mst;
    }
    // Main method to read input, compute MST, and print the result.
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int vertices = sc.nextInt(); // Read number of vertices.
        int edges = sc.nextInt();    // Read number of edges.
        List<Edge> edgeList = new ArrayList<>();
        for (int i = 0; i < edges; i++) {
            int from = sc.nextInt(); // Read 'from' vertex of the edge.
            int to = sc.nextInt();   // Read 'to' vertex of the edge.
            int weight = sc.nextInt(); // Read weight of the edge.
            edgeList.add(new Edge(from, to, weight)); // Add edge to the list.
        }
        List<Edge> mst = kruskal(edgeList, vertices);
        System.out.println("Minimum Spanning Tree (MST):");
        for (Edge edge : mst) {
            System.out.println(edge); // Print each edge in the MST.
        }
        sc.close(); // Close the scanner.
    }
}
