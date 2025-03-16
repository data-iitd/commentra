
import java.util.*;

public class Main {
    // Define a custom Edge class to store edge information (from, to, weight)
    static class Edge {
        int from;
        int to;
        int weight;

        // Constructor for Edge class
        Edge(int from, int to, int weight) {
            this.from = from;
            this.to = to;
            this.weight = weight;
        }

        // Override toString method to print edge information in a readable format
        @Override
        public String toString() {
            return from + " - " + to + " : " + weight;
        }
    }

    // Define a custom UnionFind data structure for handling disjoint sets
    static class UnionFind {
        private final int[] parent;
        private final int[] rank;

        // Constructor for UnionFind data structure with given size
        UnionFind(int size) {
            parent = new int[size];
            rank = new int[size];

            // Initialize all elements as separate sets
            for (int i = 0; i < size; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        // Find the root of the set containing the given element
        int find(int x) {
            if (parent[x] != x) {
                // Path compression and union by rank to improve performance
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        // Union two sets containing the given elements
        boolean union(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);

            // If the given elements are already in the same set, return false
            if (rootX == rootY) {
                return false;
            }

            // Connect the smaller rank set to the larger rank set to maintain a forest
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }

            // Return true to indicate successful union
            return true;
        }
    }

    // Kruskal's algorithm implementation to find the minimum spanning tree (MST)
    public static List<Edge> kruskal(List<Edge> edges, int vertices) {
        // Sort the given edges in non-decreasing order of their weights
        Collections.sort(edges, Comparator.comparingInt(edge -> edge.weight));

        // Initialize UnionFind data structure with the given number of vertices
        UnionFind uf = new UnionFind(vertices);

        // Initialize an empty list to store the MST edges
        List<Edge> mst = new ArrayList<>();

        // Iterate through the sorted edges and add them to the MST if they don't form a cycle
        for (Edge edge : edges) {
            if (uf.union(edge.from, edge.to)) {
                mst.add(edge);
            }

            // Once the MST contains (V-1) edges, break the loop
            if (mst.size() == vertices - 1) {
                break;
            }
        }

        // Return the computed MST
        return mst;
    }

    // Main method to read input and call the kruskal algorithm
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the number of vertices and edges from the input
        int vertices = sc.nextInt();
        int edges = sc.nextInt();

        // Initialize an empty list to store the edges
        List<Edge> edgeList = new ArrayList<>();

        // Read the edges from the input and add them to the list
        for (int i = 0; i < edges; i++) {
            int from = sc.nextInt();
            int to = sc.nextInt();
            int weight = sc.nextInt();
            edgeList.add(new Edge(from, to, weight));
        }

        // Call the kruskal algorithm to find the minimum spanning tree (MST)
        List<Edge> mst = kruskal(edgeList, vertices);

        // Print the computed MST
        System.out.println("Minimum Spanning Tree (MST):");
        for (Edge edge : mst) {
            System.out.println(edge);
        }

        // Close the scanner
        sc.close();
    }
}