import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    static int n;
    static List<ArrayList<Edge>> g; // Step 1: Declare the graph as an adjacency list
    static int[] ans; // Step 3: Declare the answer array to store edge colors

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = Integer.parseInt(sc.next()); // Read the number of nodes
        g = new ArrayList<>(); // Initialize the graph
        for (int i = 0; i < n; i++) {
            g.add(new ArrayList<>()); // Initialize each node's adjacency list
        }
        for (int i = 0; i < n - 1; i++) { // Step 2: Read and populate the graph
            int a = Integer.parseInt(sc.next()) - 1; // Read node a
            int b = Integer.parseInt(sc.next()) - 1; // Read node b
            g.get(a).add(new Edge(i, b)); // Add edge from a to b
            g.get(b).add(new Edge(i, a)); // Add edge from b to a
        }
        ans = new int[n - 1]; // Step 3: Initialize the answer array
        dfs(0, -1, -1); // Step 3: Call DFS with root node 0, initial color -1, and parent -1
        int max = 0; // Step 5: Initialize max to find the maximum color used
        for (int temp : ans) {
            max = Math.max(max, temp); // Step 5: Find the maximum color used
        }
        System.out.println(max); // Step 5: Print the maximum color used
        for (int c : ans) {
            System.out.println(c); // Step 5: Print the colors assigned to each edge
        }
    }

    static void dfs(int to, int color, int parent) { // Step 4: Define the DFS function
        int k = 1; // Initialize the color counter
        for (Edge e : g.get(to)) { // Iterate through the adjacency list of the current node
            if (e.to == parent) continue; // Skip if the neighbor is the parent
            if (k == color) k++; // Ensure the color is not the same as the parent's color
            ans[e.id] = k; // Assign the color to the edge
            dfs(e.to, k, to); // Recursively call DFS for the neighbor
            k++; // Increment the color counter for the next edge
        }
    }
}

class Edge { // Define the Edge class
    int id;
    int to;

    Edge(int id, int to) {
        this.id = id;
        this.to = to;
    }
}
