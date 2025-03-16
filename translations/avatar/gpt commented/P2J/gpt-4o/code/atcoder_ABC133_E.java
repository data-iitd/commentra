import java.util.*;

public class GraphColoring {
    static List<List<Integer>> graph = new ArrayList<>();
    static final int MOD = 1000000007;
    static int K;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of nodes (N) and the number of colors (K)
        int N = scanner.nextInt();
        K = scanner.nextInt();
        
        // Initialize the graph
        for (int i = 0; i < N; i++) {
            graph.add(new ArrayList<>());
        }

        // Build the graph by reading N-1 edges
        for (int i = 0; i < N - 1; i++) {
            int a = scanner.nextInt() - 1; // Read each edge (0-indexed)
            int b = scanner.nextInt() - 1; // Read each edge (0-indexed)
            graph.get(a).add(b);
            graph.get(b).add(a);
        }

        // Start the DFS from the root node (0) with no parent (-1) and K colors
        long ans = dfs(0, -1, K);
        
        // Print the final answer which is the number of valid colorings
        System.out.println(ans);
    }

    // Define a recursive function to perform depth-first search (DFS) and count valid colorings
    static long dfs(int fro, int to, int f) {
        long caseNum = f; // Initialize case number with the current color
        int colorNum = (f == K) ? K - 1 : K - 2; // Determine the number of available colors for the next node
        
        // Iterate through all adjacent nodes in the graph
        for (int u : graph.get(fro)) {
            if (u == to) { // Skip the node we came from to avoid cycles
                continue;
            }
            long pat = dfs(u, fro, colorNum); // Recursively call DFS for the adjacent node
            if (pat == 0) { // If no valid coloring is found, break out
                caseNum = 0;
                break;
            }
            caseNum = (caseNum * pat) % MOD; // Update the case number with the valid patterns found
            colorNum--; // Decrease the available colors for the next node
        }
        
        return caseNum; // Return the total valid colorings found
    }
}

// <END-OF-CODE>
