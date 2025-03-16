import java.util.*;

public class GraphComponents {
    static int n, m;
    static int[] vis;
    static int ci = 0, cb = 0, cc = 0;
    static List<List<Integer>> g;

    // Depth-First Search (DFS) function to determine if a graph is bipartite
    static boolean dfs(int x) {
        Stack<Pair> stk = new Stack<>();
        boolean flag = true; // Using a flag to check bipartiteness
        stk.push(new Pair(x, 1)); // Starting DFS from node x with color 1

        while (!stk.isEmpty()) {
            Pair current = stk.pop();
            int u = current.node;
            int col = current.color;

            if (vis[u] != 0) { // If the node has been visited, check if the color is consistent
                flag &= (vis[u] == col);
                continue;
            }
            vis[u] = col; // Marking the node as visited with the current color

            for (int i : g.get(u)) {
                stk.push(new Pair(i, 3 - col)); // Adding adjacent nodes to the stack with the opposite color
            }
        }
        return flag;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();
        vis = new int[n + 1];
        g = new ArrayList<>(n + 1);
        for (int i = 0; i <= n; i++) {
            g.add(new ArrayList<>());
        }

        // Constructing the graph by reading edges
        for (int i = 0; i < m; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            g.get(u).add(v); // Adding edge u-v
            g.get(v).add(u); // Adding edge v-u (undirected graph)
        }

        // Traversing the graph to classify nodes
        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0) { // If the node has not been visited
                if (g.get(i).isEmpty()) {
                    ci++; // Increment the count of isolated nodes
                } else {
                    if (dfs(i)) {
                        cb++; // Increment the count of bipartite graphs
                    } else {
                        cc++; // Increment the count of connected components that are not bipartite
                    }
                }
            }
        }

        // Calculating and printing the result based on the counts of isolated, bipartite, and connected components
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
