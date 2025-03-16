
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public final class Main {
    private Main() {
        // Private constructor to prevent instantiation of the class
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize a Scanner object to read input from the console

        int v = scanner.nextInt(); // Read the number of vertices (nodes) from the input

        ArrayList<ArrayList<Integer>> adj = new ArrayList<>(); // Initialize an ArrayList to store the adjacency list

        for (int i = 0; i < v; i++) { // Iterate through each vertex and initialize an empty ArrayList for its neighbors
            adj.add(new ArrayList<>());
        }

        for (int i = 0; i < v - 1; i++) { // Iterate through each edge and add it to the adjacency list
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            adj.get(from).add(to); // Add the neighbor to the list of neighbors of the current vertex
            adj.get(to).add(from); // Add the current vertex to the list of neighbors of the neighbor
        }

        int[] parent = new int[v]; // Initialize an integer array to store the parent of each vertex
        int[] depth = new int[v]; // Initialize an integer array to store the depth of each vertex

        dfs(adj, 0, -1, parent, depth); // Call the depth-first search algorithm starting from vertex 0

        int v1 = scanner.nextInt(); // Read the first vertex from the input
        int v2 = scanner.nextInt(); // Read the second vertex from the input

        System.out.println(getMain(v1, v2, depth, parent)); // Call the function to find the LCA (Lowest Common Ancestor) of the two vertices and print the result

        scanner.close(); // Close the Scanner object to release the system resources
    }

    private static void dfs(ArrayList<ArrayList<Integer>> adj, int s, int p, int[] parent, int[] depth) {
        for (int adjacent : adj.get(s)) { // Iterate through each neighbor of the current vertex
            if (adjacent != p) { // Check if the neighbor is not the parent of the current vertex
                parent[adjacent] = s; // Set the parent of the neighbor to the current vertex
                depth[adjacent] = 1 + depth[s]; // Update the depth of the neighbor by adding 1 to the depth of the current vertex
                dfs(adj, adjacent, s, parent, depth); // Recursively call the DFS algorithm for the neighbor
            }
        }
    }

    private static int getMain(int v1, int v2, int[] depth, int[] parent) {
        if (depth[v1] < depth[v2]) { // Check if the depth of v1 is smaller than the depth of v2
            int temp = v1;
            v1 = v2;
            v2 = temp; // Swap the values of v1 and v2 if the depth of v1 is smaller
        }

        while (depth[v1] != depth[v2]) { // Traverse up the tree from v1 to find the LCA
            v1 = parent[v1];
        }

        if (v1 == v2) { // Check if v1 and v2 are the same vertex
            return v1; // Return the vertex if they are the same
        }

        while (v1 != v2) { // Traverse up the tree from v1 to find the LCA
            v1 = parent[v1];
            v2 = parent[v2];
        }

        return v1; // Return the LCA of v1 and v2
    }
}