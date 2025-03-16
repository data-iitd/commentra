import java.util.*;

public class GraphComponents {
    static int[] vis;
    static int ci = 0, cb = 0, cc = 0;
    static List<List<Integer>> g;

    // Define a depth-first search (DFS) function to check for bipartiteness
    static boolean dfs(int x) {
        Stack<Pair> stk = new Stack<>();
        boolean flag = true;  // Flag for bipartiteness
        stk.push(new Pair(x, 1));  // Start DFS from node x with color 1

        while (!stk.isEmpty()) {
            Pair current = stk.pop();
            int u = current.node;
            int col = current.color;

            if (vis[u] != 0) {  // If the node has already been visited
                flag &= (vis[u] == col);  // Check if the color matches
                continue;
            }
            vis[u] = col;  // Mark the node as visited with the current color
            for (int i : g.get(u)) {  // Iterate through all adjacent nodes
                stk.push(new Pair(i, 3 - col));  // Push the adjacent node with the alternate color
            }
        }
        return flag;  // Return whether the component is bipartite
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of nodes (n) and edges (m) from input
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Initialize visitation status and create an adjacency list to represent the graph
        vis = new int[n + 1];
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
                    ci++;  // Increment isolated component counter
                } else {
                    if (dfs(i)) {  // Perform DFS and check if the component is bipartite
                        cb++;  // Increment bipartite component counter
                    } else {
                        cc++;  // Increment non-bipartite component counter
                    }
                }
            }
        }

        // Calculate and print the final result based on the counts of components
        System.out.println(ci * ci + 2 * ci * (n - ci) + cc * cc + 2 * cb * cc + 2 * cb * cb);
        
        scanner.close();
    }

    // Helper class to store node and color pairs
    static class Pair {
        int node;
        int color;

        Pair(int node, int color) {
            this.node = node;
            this.color = color;
        }
    }
}
// <END-OF-CODE>
