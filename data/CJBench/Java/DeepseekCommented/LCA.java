import java.util.ArrayList;
import java.util.Scanner;
public final class Main {
    private Main() {
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int v = scanner.nextInt(); // Read the number of vertices
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < v; i++) {
            adj.add(new ArrayList<>()); // Initialize adjacency list for each vertex
        }
        for (int i = 0; i < v - 1; i++) {
            int from = scanner.nextInt(); // Read edge from
            int to = scanner.nextInt(); // Read edge to
            adj.get(from).add(to); // Add edge to adjacency list
            adj.get(to).add(from); // Add edge to adjacency list (undirected graph)
        }
        int[] parent = new int[v]; // Array to store parent of each vertex
        int[] depth = new int[v]; // Array to store depth of each vertex
        dfs(adj, 0, -1, parent, depth); // Perform DFS starting from vertex 0
        int v1 = scanner.nextInt(); // Read first vertex
        int v2 = scanner.nextInt(); // Read second vertex
        System.out.println(getMain(v1, v2, depth, parent)); // Print the LCA of v1 and v2
        scanner.close(); // Close the scanner
    }
    private static void dfs(ArrayList<ArrayList<Integer>> adj, int s, int p, int[] parent, int[] depth) {
        for (int adjacent : adj.get(s)) { // Iterate over adjacent vertices
            if (adjacent != p) { // Avoid revisiting the parent vertex
                parent[adjacent] = s; // Set parent of adjacent vertex
                depth[adjacent] = 1 + depth[s]; // Increment depth by 1
                dfs(adj, adjacent, s, parent, depth); // Recursively call dfs for adjacent vertex
            }
        }
    }
    private static int getMain(int v1, int v2, int[] depth, int[] parent) {
        if (depth[v1] < depth[v2]) { // Ensure v1 is at a deeper depth than v2
            int temp = v1;
            v1 = v2;
            v2 = temp;
        }
        while (depth[v1] != depth[v2]) { // Move v1 up the tree until depths are equal
            v1 = parent[v1];
        }
        if (v1 == v2) { // If v1 and v2 are the same, return v1 (LCA found)
            return v1;
        }
        while (v1 != v2) { // Move both v1 and v2 up the tree until they meet
            v1 = parent[v1];
            v2 = parent[v2];
        }
        return v1; // Return the LCA
    }
}
