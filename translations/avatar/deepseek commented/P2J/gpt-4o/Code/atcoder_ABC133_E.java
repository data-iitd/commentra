import java.util.*;

public class GraphColoring {
    static List<List<Integer>> graph = new ArrayList<>();
    static final int MOD = 1000000007;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();  // Read the number of nodes
        int K = scanner.nextInt();  // Read the number of colors

        // Initialize the graph
        for (int i = 0; i < N; i++) {
            graph.add(new ArrayList<>());
        }

        // Construct the graph by reading edges
        for (int i = 0; i < N - 1; i++) {
            int a = scanner.nextInt() - 1;  // Read edge start node
            int b = scanner.nextInt() - 1;  // Read edge end node
            graph.get(a).add(b);  // Append the edge to the graph
            graph.get(b).add(a);  // Since the graph is undirected, append the reverse edge as well
        }

        long ans = dfs(0, -1, K);  // Call the dfs function starting from the root node with the initial number of colors
        System.out.println(ans);  // Print the final result
    }

    // Define the DFS function to calculate the number of valid colorings
    static long dfs(int fro, int to, int f) {
        long caseNum = f;  // Initialize the number of valid colorings with the initial number of colors
        int colorNum = (f == K) ? K - 1 : K - 2;  // Set the number of available colors for the current node

        for (int u : graph.get(fro)) {
            if (u == to) {
                continue;  // Skip if the neighbor is the parent node
            }
            long pat = dfs(u, fro, colorNum);  // Recursively call dfs for the neighbor
            if (pat == 0) {
                caseNum = 0;  // If no valid colorings, set the current number to 0
                break;  // Break out of the loop as further calculations are unnecessary
            }
            caseNum = (caseNum * pat) % MOD;  // Multiply the current number of valid colorings by the recursive result
            colorNum--;  // Decrease the number of available colors for the next node
        }
        return caseNum;  // Return the number of valid colorings for the current node
    }
}
// <END-OF-CODE>
