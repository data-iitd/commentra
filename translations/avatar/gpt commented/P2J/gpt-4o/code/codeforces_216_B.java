import java.util.*;

public class Main {
    // Method to read integers from input
    public static int[] readInts() {
        Scanner scanner = new Scanner(System.in);
        String line = scanner.nextLine();
        String[] parts = line.split(" ");
        int[] result = new int[parts.length];
        for (int i = 0; i < parts.length; i++) {
            result[i] = Integer.parseInt(parts[i]);
        }
        return result;
    }

    // Depth-first search (DFS) method
    public static int[] dfs(Map<Integer, Set<Integer>> g, Set<Integer> seen, int i) {
        if (seen.contains(i)) {
            return new int[]{0, 0}; // Return 0 nodes and 0 edges if already seen
        }
        seen.add(i); // Mark the current node as seen
        int nodes = 1; // Count the current node
        int edges = g.get(i).size(); // Count the edges connected to the current node
        for (int j : g.get(i)) {
            int[] result = dfs(g, seen, j);
            nodes += result[0]; // Accumulate the number of nodes found
            edges += result[1]; // Accumulate the number of edges found
        }
        return new int[]{nodes, edges}; // Return the total count of nodes and edges
    }

    public static boolean solve() {
        int[] line0;
        try {
            line0 = readInts(); // Attempt to read the first line of input
        } catch (NoSuchElementException e) {
            return false; // If end of input is reached, return false
        }
        int n = line0[0]; // Number of nodes
        int m = line0[1]; // Number of edges
        Map<Integer, Set<Integer>> g = new HashMap<>(); // Initialize the graph
        Set<Integer> seen = new HashSet<>(); // Initialize a set to keep track of seen nodes
        for (int i = 1; i <= n; i++) {
            g.put(i, new HashSet<>()); // Initialize each node's adjacency list
        }
        for (int j = 0; j < m; j++) {
            int[] edge = readInts(); // Read each edge
            g.get(edge[0]).add(edge[1]); // Add the edge to the graph (undirected)
            g.get(edge[1]).add(edge[0]);
        }
        int ans = 0; // Initialize the answer counter
        for (int i = 1; i <= n; i++) {
            if (!seen.contains(i)) { // If the node has not been seen
                int[] result = dfs(g, seen, i); // Perform DFS
                int nodes = result[0];
                int edges = result[1];
                // Check the conditions for counting valid components
                if (nodes > 1 && nodes % 2 == 1 && 2 * nodes == edges) {
                    ans++; // Increment the answer if conditions are met
                }
            }
        }
        if ((n - ans) % 2 == 1) {
            ans++; // Adjust the answer if the remaining nodes are odd
        }
        System.out.println(ans); // Output the final answer
        return true; // Return true to indicate successful processing
    }

    public static void main(String[] args) {
        while (solve()) {
            // Continuously solve the problem until EOF is reached
        }
    }
}

// <END-OF-CODE>
