import java.util.*;

public class Main {
    static int n, m;
    static int[] vis, ci, cb, cc;
    static List<List<Integer>> g;

    // Define a depth-first search (DFS) function to check for bipartiteness
    static boolean dfs(int x) {
        Stack<int[]> stk = new Stack<>();  // Initialize stack for DFS
        stk.push(new int[]{x, 1});  // Start DFS from node x with color 1
        while (!stk.isEmpty()) {
            int[] top = stk.pop();  // Get the current node and its color
            int u = top[0], col = top[1];
            if (vis[u] != 0) {  // If the node has already been visited
                if (vis[u] != col) {  // Check if the color matches
                    return false;  // Not bipartite
                }
                continue;
            }
            vis[u] = col;  // Mark the node as visited with the current color
            for (int i : g.get(u)) {  // Iterate through all adjacent nodes
                stk.push(new int[]{i, 3 - col});  // Push the adjacent node with the alternate color
            }
        }
        return true;  // Bipartite
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of nodes (n) and edges (m) from input
        n = scanner.nextInt();
        m = scanner.nextInt();

        // Initialize visitation status and counters for isolated components, bipartite components, and non-bipartite components
        vis = new int[n + 1];
        ci = new int[1];
        cb = new int[1];
        cc = new int[1];

        // Create an adjacency list to represent the graph
        g = new ArrayList<>(n + 1);
        for (int i = 0; i <= n; i++) {
            g.add(new ArrayList<>());
        }

        // Read edges and build the graph
        for (int i = 0; i < m; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            g.get(u).add(v);  // Add edge from u to v
            g.get(v).add(u);  // Add edge from v to u (undirected graph)
        }

        // Iterate through all nodes to count isolated and bipartite components
        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0) {  // If the node has not been visited
                if (g.get(i).isEmpty()) {  // Check if the node is isolated
                    ci[0]++;  // Increment isolated component counter
                } else {
                    if (dfs(i)) {  // Perform DFS and check if the component is bipartite
                        cb[0]++;  // Increment bipartite component counter
                    } else {
                        cc[0]++;  // Increment non-bipartite component counter
                    }
                }
            }
        }

        // Calculate and print the final result based on the counts of components
        System.out.println(ci[0] * ci[0] + 2 * ci[0] * (n - ci[0]) + cc[0] * cc[0] + 2 * cb[0] * cc[0] + 2 * cb[0] * cb[0]);
    }
}
