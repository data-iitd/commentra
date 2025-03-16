import java.util.*;

public class GraphColoring {
    // Initializing the variables
    static int n, m;
    static int[] vis;
    static int ci = 0, cb = 0, cc = 0;
    static List<List<Integer>> g;

    // Function to perform DFS traversal from a given vertex 'x'
    static boolean dfs(int x) {
        Stack<Pair> stk = new Stack<>();
        boolean flag = true;

        // Pushing the current vertex 'x' into the stack with color '1'
        stk.push(new Pair(x, 1));

        // Traversing the graph until the stack is empty
        while (!stk.isEmpty()) {
            Pair current = stk.pop();
            int u = current.vertex;
            int col = current.color;

            // If the current vertex 'u' is already visited, then check if it has the same color as the previous vertex
            if (vis[u] != 0) {
                flag &= (vis[u] == col);
                continue;
            }

            // Mark the current vertex 'u' as visited with the current color 'col'
            vis[u] = col;

            // Recursively traverse all the adjacent vertices of 'u'
            for (int i : g.get(u)) {
                stk.push(new Pair(i, 3 - col));
            }
        }

        // Return the flag indicating whether all vertices in the connected component have the same color or not
        return flag;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Taking the number of vertices (n) and edges (m) as input
        n = scanner.nextInt();
        m = scanner.nextInt();

        // Initializing the visited list and other variables
        vis = new int[n + 1];
        g = new ArrayList<>(n + 1);
        for (int i = 0; i <= n; i++) {
            g.add(new ArrayList<>());
        }

        // Adding edges to the graph
        for (int i = 0; i < m; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            // Adding an edge between vertices 'u' and 'v' in both the adjacency lists
            g.get(u).add(v);
            g.get(v).add(u);
        }

        // Finding the number of isolated vertices and connected components
        for (int i = 1; i <= n; i++) {
            // If the current vertex 'i' is not visited yet
            if (vis[i] == 0) {
                // If the current vertex 'i' has no edges, then it is an isolated vertex
                if (g.get(i).isEmpty()) {
                    ci++;
                } else {
                    // Else, perform DFS traversal from the current vertex 'i' and count the number of connected components
                    if (dfs(i)) {
                        cb++;
                    } else {
                        cc++;
                    }
                }
            }
        }

        // Calculating and printing the final answer
        System.out.println(ci * ci + 2 * ci * (n - ci) + cc * cc + 2 * cb * cc + 2 * cb * cb);
        scanner.close();
    }

    // Pair class to hold vertex and color
    static class Pair {
        int vertex;
        int color;

        Pair(int vertex, int color) {
            this.vertex = vertex;
            this.color = color;
        }
    }
}
// <END-OF-CODE>
