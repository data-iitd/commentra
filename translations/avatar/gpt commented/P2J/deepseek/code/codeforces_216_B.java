import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (solve(scanner)) {
            // Continue looping until EOF
        }
    }

    public static List<Integer> readInts(Scanner scanner) {
        // Reads a line of input, splits it into components, and converts them to integers
        String[] parts = scanner.nextLine().split(" ");
        List<Integer> ints = new ArrayList<>();
        for (String part : parts) {
            ints.add(Integer.parseInt(part));
        }
        return ints;
    }

    public static int dfs(Map<Integer, Set<Integer>> g, Set<Integer> seen, int i) {
        // Performs a depth-first search (DFS) on the graph 'g' starting from node 'i'
        // 'seen' keeps track of visited nodes to avoid cycles
        if (seen.contains(i)) {
            // If the node has already been visited, return 0 nodes and 0 edges
            return 0;
        }
        seen.add(i);  // Mark the current node as seen
        int nodes = 1;  // Count the current node
        int edges = g.get(i).size();  // Count the edges connected to the current node
        for (int j : g.get(i)) {
            // Recursively visit all adjacent nodes
            nodes += dfs(g, seen, j);  // Accumulate the number of nodes found
        }
        return nodes;  // Return the total count of nodes
    }

    public static boolean solve(Scanner scanner) {
        // Main function to solve the problem
        List<Integer> line0 = readInts(scanner);
        if (line0 == null) {
            // If end of input is reached, return false to stop processing
            return false;
        }
        int n = line0.get(0);  // Unpack the number of nodes (n)
        int m = line0.get(1);  // Unpack the number of edges (m)
        Map<Integer, Set<Integer>> g = new HashMap<>();  // Initialize the graph as a dictionary
        Set<Integer> seen = new HashSet<>();  // Initialize a set to keep track of seen nodes
        for (int i = 1; i <= n; i++) {
            // Initialize each node's adjacency list as an empty set
            g.put(i, new HashSet<>());
        }
        for (int i = 0; i < m; i++) {
            // Read each edge and add it to the graph (undirected)
            List<Integer> edge = readInts(scanner);
            int a = edge.get(0);
            int b = edge.get(1);
            g.get(a).add(b);
            g.get(b).add(a);
        }
        int ans = 0;  // Initialize the answer counter
        for (int i = 1; i <= n; i++) {
            // Iterate through each node to find connected components
            if (!seen.contains(i)) {
                // If the node has not been seen, perform DFS
                int nodes = dfs(g, seen, i);
                // Check the conditions for counting valid components
                if (nodes > 1 && nodes % 2 == 1 && 2 * nodes == g.get(i).size()) {
                    ans += 1;  // Increment the answer if conditions are met
                }
            }
        }
        if ((n - ans) % 2 == 1) {
            // Adjust the answer if the remaining nodes are odd
            ans += 1;
        }
        System.out.println(ans);  // Output the final answer
        return true;  // Return true to indicate successful processing
    }
}
