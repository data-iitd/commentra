import java.util.*;

public class Main {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        while (solve()) {
            // Loop until solve returns false
        }
    }

    static boolean solve() {
        List<Integer> line0 = new ArrayList<>();
        try {
            line0 = readInts(); // Read the first line of input
        } catch (NoSuchElementException e) {
            return false; // Return false if EOF is encountered
        }
        int n = line0.get(0); // Number of nodes
        int m = line0.get(1); // Number of edges
        Map<Integer, Set<Integer>> g = new HashMap<>(); // Initialize an empty graph
        Set<Integer> seen = new HashSet<>(); // Initialize an empty set to keep track of visited nodes

        for (int i = 1; i <= n; i++) { // Initialize the graph with empty sets for each node
            g.put(i, new HashSet<>());
        }

        for (int i = 0; i < m; i++) { // Read each edge and add it to the graph
            List<Integer> edge = readInts();
            int a = edge.get(0);
            int b = edge.get(1);
            g.get(a).add(b);
            g.get(b).add(a);
        }

        int ans = 0; // Initialize the answer variable
        for (int i = 1; i <= n; i++) { // Traverse each node in the graph
            if (!seen.contains(i)) { // If the node is not seen, perform DFS
                int[] result = dfs(g, seen, i); // Get the count of nodes and edges
                int nodes = result[0];
                int edges = result[1];
                if (nodes > 1 && nodes % 2 == 1 && 2 * nodes == edges) { // Check the conditions
                    ans++; // Increment the answer if the conditions are met
                }
            }
        }

        if ((n - ans) % 2 == 1) { // Check if the number of disconnected components is odd
            ans++; // Increment the answer if necessary
        }
        System.out.println(ans); // Print the final answer
        return true; // Return true to continue the loop
    }

    static List<Integer> readInts() { // Function to read integers from input
        String line = scanner.nextLine();
        String[] parts = line.split(" ");
        List<Integer> integers = new ArrayList<>();
        for (String part : parts) {
            integers.add(Integer.parseInt(part));
        }
        return integers;
    }

    static int[] dfs(Map<Integer, Set<Integer>> g, Set<Integer> seen, int i) { // Depth-First Search
        if (seen.contains(i)) { // If node is already seen, return 0, 0
            return new int[]{0, 0};
        }
        seen.add(i); // Mark the node as seen
        int nodes = 1; // Initialize node count
        int edges = g.get(i).size(); // Count edges from the current node
        for (int j : g.get(i)) { // Traverse all adjacent nodes
            int[] result = dfs(g, seen, j); // Recursively call dfs for each adjacent node
            nodes += result[0]; // Update node count
            edges += result[1]; // Update edge count
        }
        return new int[]{nodes, edges}; // Return the count of nodes and edges
    }
}
// <END-OF-CODE>
