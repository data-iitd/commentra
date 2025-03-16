
import java.util.*;

public class codeforces_216_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (solve(scanner)) {
        }
    }

    public static boolean solve(Scanner scanner) {
        int[] line0 = readInts(scanner);  // Read the first line of input
        if (line0 == null) {
            return false;  // Return false if EOF is encountered
        }
        int n = line0[0], m = line0[1];  // Unpack the number of nodes and edges
        Map<Integer, Set<Integer>> g = new HashMap<>();  // Initialize an empty graph
        Set<Integer> seen = new HashSet<>();  // Initialize an empty set to keep track of visited nodes
        for (int i = 1; i <= n; i++) {  // Initialize the graph with empty sets for each node
            g.put(i, new HashSet<>());
        }
        for (int i = 0; i < m; i++) {  // Read each edge and add it to the graph
            int[] ab = readInts(scanner);
            g.get(ab[0]).add(ab[1]);
            g.get(ab[1]).add(ab[0]);
        }
        int ans = 0;  // Initialize the answer variable
        for (int i = 1; i <= n; i++) {  // Traverse each node in the graph
            if (!seen.contains(i)) {  // If the node is not seen, perform DFS
                int[] nodesEdges = dfs(g, seen, i);  // Get the count of nodes and edges
                if (nodesEdges[0] > 1 && nodesEdges[0] % 2 == 1 && 2 * nodesEdges[0] == nodesEdges[1]) {  // Check the conditions
                    ans++;  // Increment the answer if the conditions are met
                }
            }
        }
        if ((n - ans) % 2 == 1) {  // Check if the number of disconnected components is odd
            ans++;  // Increment the answer if necessary
        }
        System.out.println(ans);  // Print the final answer
        return true;  // Return true to continue the loop
    }

    public static int[] dfs(Map<Integer, Set<Integer>> g, Set<Integer> seen, int i) {  // Depth-First Search to count nodes and edges in a graph
        if (seen.contains(i)) {  // If node is already seen, return 0, 0
            return new int[]{0, 0};
        }
        seen.add(i);  // Mark the node as seen
        int nodes = 1, edges = g.get(i).size();  // Initialize node count and count edges from the current node
        for (int j : g.get(i)) {  // Traverse all adjacent nodes
            int[] x = dfs(g, seen, j);  // Recursively call dfs for each adjacent node
            nodes += x[0];  // Update node count
            edges += x[1];  // Update edge count
        }
        return new int[]{nodes, edges};  // Return the count of nodes and edges
    }

    public static int[] readInts(Scanner scanner) {  // Function to read integers from input
        String[] strings = scanner.nextLine().split(" ");
        int[] ints = new int[strings.length];
        for (int i = 0; i < strings.length; i++) {
            ints[i] = Integer.parseInt(strings[i]);
        }
        return ints;
    }
}

Translate the above Java code to C++ and end with comment "