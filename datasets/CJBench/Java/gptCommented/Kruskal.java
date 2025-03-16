import java.util.*;

public class Main {
    // Class representing an edge in the graph
    static class Edge {
        int from; // Starting vertex of the edge
        int to;   // Ending vertex of the edge
        int weight; // Weight of the edge

        // Constructor to initialize an edge
        Edge(int from, int to, int weight) {
            this.from = from;
            this.to = to;
            this.weight = weight;
        }

        // Override toString method for easy representation of the edge
        @Override
        public String toString() {
            return from + " - " + to + " : " + weight;
        }
    }

    // Class implementing the Union-Find (Disjoint Set Union) data structure
    static class UnionFind {
        private final int[] parent; // Array to track the parent of each node
        private final int[] rank;   // Array to track the rank (depth) of each tree

        // Constructor to initialize the Union-Find structure
        UnionFind(int size) {
            parent = new int[size];
            rank = new int[size];
            // Initialize each node to be its own parent and rank to 0
            for (int i = 0; i < size; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        // Find the root of the set containing 'x' with path compression
        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]); // Path compression
            }
            return parent[x];
        }

        // Union the sets containing 'x' and 'y'
        boolean union(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            // If they are already in the same set, return false
            if (rootX == rootY) {
                return false;
            }
            // Union by rank to keep the tree flat
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            return true; // Successfully unioned
        }
    }

    // Method to perform Kruskal's algorithm to find the Minimum Spanning Tree (MST)
    public static List<Edge> kruskal(List<Edge> edges, int vertices) {
        // Sort edges based on their weights in ascending order
        edges.sort(Comparator.comparingInt(edge -> edge.weight));
        UnionFind uf = new UnionFind(vertices); // Initialize Union-Find structure
        List<Edge> mst = new ArrayList<>(); // List to store the edges of the MST

        // Iterate through the sorted edges
        for (Edge edge : edges) {
            // If the edge connects two different components, add it to the MST
            if (uf.union(edge.from, edge.to)) {
                mst.add(edge);
            }
            // Stop if we have added enough edges to the MST
            if (mst.size() == vertices - 1) {
                break;
            }
        }
        return mst; // Return the resulting MST
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a scanner for input
        int vertices = sc.nextInt(); // Read the number of vertices
        int edges = sc.nextInt(); // Read the number of edges
        List<Edge> edgeList = new ArrayList<>(); // List to store all edges

        // Read edges from input
        for (int i = 0; i < edges; i++) {
            int from = sc.nextInt(); // Read starting vertex
            int to = sc.nextInt(); // Read ending vertex
            int weight = sc.nextInt(); // Read weight of the edge
            edgeList.add(new Edge(from, to, weight)); // Add edge to the list
        }

        // Compute the Minimum Spanning Tree using Kruskal's algorithm
        List<Edge> mst = kruskal(edgeList, vertices);
        System.out.println("Minimum Spanning Tree (MST):");
        // Print the edges in the MST
        for (Edge edge : mst) {
            System.out.println(edge);
        }
        sc.close(); // Close the scanner
    }
}
