import java.util.ArrayList;
import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation
    private Main() {
    }

    public static void main(String[] args) {
        // Create a scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of vertices in the graph
        int v = scanner.nextInt();
        
        // Initialize an adjacency list to represent the graph
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < v; i++) {
            adj.add(new ArrayList<>());
        }
        
        // Read edges and populate the adjacency list
        for (int i = 0; i < v - 1; i++) {
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            // Add the edge in both directions (undirected graph)
            adj.get(from).add(to);
            adj.get(to).add(from);
        }
        
        // Arrays to store the parent and depth of each vertex
        int[] parent = new int[v];
        int[] depth = new int[v];
        
        // Perform DFS to populate parent and depth arrays
        dfs(adj, 0, -1, parent, depth);
        
        // Read the two vertices for which we want to find the lowest common ancestor (LCA)
        int v1 = scanner.nextInt();
        int v2 = scanner.nextInt();
        
        // Output the lowest common ancestor of the two vertices
        System.out.println(getMain(v1, v2, depth, parent));
        
        // Close the scanner to free resources
        scanner.close();
    }

    // Depth-First Search (DFS) to compute parent and depth of each vertex
    private static void dfs(ArrayList<ArrayList<Integer>> adj, int s, int p, int[] parent, int[] depth) {
        for (int adjacent : adj.get(s)) {
            // Avoid going back to the parent node
            if (adjacent != p) {
                // Set the parent of the adjacent node
                parent[adjacent] = s;
                // Set the depth of the adjacent node
                depth[adjacent] = 1 + depth[s];
                // Recursively call DFS for the adjacent node
                dfs(adj, adjacent, s, parent, depth);
            }
        }
    }

    // Function to find the lowest common ancestor (LCA) of two nodes
    private static int getMain(int v1, int v2, int[] depth, int[] parent) {
        // Ensure v1 is the deeper node
        if (depth[v1] < depth[v2]) {
            int temp = v1;
            v1 = v2;
            v2 = temp;
        }
        
        // Bring v1 and v2 to the same depth
        while (depth[v1] != depth[v2]) {
            v1 = parent[v1];
        }
        
        // If they are the same, return the ancestor
        if (v1 == v2) {
            return v1;
        }
        
        // Move both nodes up until we find the common ancestor
        while (v1 != v2) {
            v1 = parent[v1];
            v2 = parent[v2];
        }
        
        // Return the lowest common ancestor
        return v1;
    }
}
