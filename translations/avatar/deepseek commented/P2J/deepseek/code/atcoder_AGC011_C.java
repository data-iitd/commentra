import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Reading the number of nodes
        int m = scanner.nextInt();  // Reading the number of edges
        int[] vis = new int[n + 1];  // Initializing visited list
        int ci = 0, cb = 0, cc = 0;  // Counters for isolated, bipartite, and connected components
        List<List<Integer>> g = new ArrayList<>(n + 1);  // Creating an adjacency list to represent the graph

        // Initialize adjacency list
        for (int i = 0; i <= n; i++) {
            g.add(new ArrayList<>());
        }

        // Depth-First Search (DFS) function to determine if a graph is bipartite
        boolean dfs(int x, int color) {
            Stack<int[]> stack = new Stack<>();
            stack.push(new int[]{x, color});
            while (!stack.isEmpty()) {
                int[] nodeColor = stack.pop();
                int u = nodeColor[0];
                int col = nodeColor[1];
                if (vis[u] != 0) {
                    if (vis[u] != col) {
                        return false;
                    }
                    continue;
                }
                vis[u] = col;
                for (int v : g.get(u)) {
                    stack.push(new int[]{v, 3 - col});
                }
            }
            return true;
        }

        // Constructing the graph by reading edges
        for (int i = 0; i < m; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            g.get(u).add(v);  // Adding edge u-v
            g.get(v).add(u);  // Adding edge v-u (undirected graph)
        }

        // Traversing the graph to classify nodes
        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0) {
                if (g.get(i).isEmpty()) {
                    ci++;
                } else {
                    if (dfs(i, 1)) {
                        cb++;
                    } else {
                        cc++;
                    }
                }
            }
        }

        // Calculating and printing the result based on the counts of isolated, bipartite, and connected components
        System.out.println(ci * ci + 2 * ci * (n - ci) + cc * cc + 2 * cb * cc + 2 * cb * cb);
    }
}
