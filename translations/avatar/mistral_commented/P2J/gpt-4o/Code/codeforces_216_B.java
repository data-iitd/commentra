import java.util.*;

public class GraphTraversal {

    // Function to read an array of integers from standard input
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

    // Description: Depth First Search (DFS) function to traverse the graph and calculate nodes and edges for a given vertex
    public static int[] dfs(Map<Integer, Set<Integer>> g, Set<Integer> seen, int i) {
        // Base case: if the current vertex is already in the seen set, return 0 for nodes and 0 for edges
        if (seen.contains(i)) {
            return new int[]{0, 0};
        }

        // Mark the current vertex as visited by adding it to the seen set
        seen.add(i);

        // Initialize nodes and edges counters
        int nodes = 1;
        int edges = g.get(i).size();

        // Recursively traverse the graph for all neighbors of the current vertex
        for (int j : g.get(i)) {
            // Recursive call to DFS function for the neighbor vertex
            int[] result = dfs(g, seen, j);
            nodes += result[0];
            edges += result[1];
        }

        // Return the final count of nodes and edges for the current vertex
        return new int[]{nodes, edges};
    }

    // Main function to solve the problem
    public static boolean solve() {
        // Read the first line of input containing the number of vertices and edges in the graph
        int[] line0;
        try {
            line0 = readInts();
        } catch (NoSuchElementException e) {
            // If there is no more input, return false to indicate the end of the program
            return false;
        }

        int n = line0[0]; // Number of vertices
        int m = line0[1]; // Number of edges

        // Initialize the graph as a map with vertices as keys and empty sets as values
        Map<Integer, Set<Integer>> g = new HashMap<>();
        Set<Integer> seen = new HashSet<>();

        // Initialize an empty set to store the neighbors of each vertex
        for (int i = 1; i <= n; i++) {
            g.put(i, new HashSet<>());
        }

        // Read the remaining lines of input containing the edges of the graph and add them to the graph
        for (int _ = 0; _ < m; _++) {
            int[] edge = readInts();
            int a = edge[0];
            int b = edge[1];
            g.get(a).add(b);
            g.get(b).add(a);
        }

        // Initialize the answer counter to 0
        int ans = 0;

        // Traverse the graph using DFS function for each unvisited vertex and check if it satisfies the condition
        for (int i = 1; i <= n; i++) {
            if (!seen.contains(i)) {
                int[] result = dfs(g, seen, i);
                int nodes = result[0];
                int edges = result[1];
                if (nodes > 1 && nodes % 2 == 1 && 2 * nodes == edges) {
                    ans++;
                }
            }
        }

        // Update the answer counter based on the parity of the total number of vertices
        if ((n - ans) % 2 == 1) {
            ans++;
        }

        // Print the final answer and return true to indicate the success of the program
        System.out.println(ans);
        return true;
    }

    // Main loop to repeatedly call the solve function until there is no more input
    public static void main(String[] args) {
        while (solve()) {
            // Continue solving until no more input
        }
    }
}
// <END-OF-CODE>
