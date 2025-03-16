
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Taking the number of vertices (n) and edges (m) as input
        int n = sc.nextInt();
        int m = sc.nextInt();

        // Initializing the visited list and other variables
        boolean[] vis = new boolean[n + 1];
        int ci = 0, cb = 0, cc = 0;
        ArrayList<Integer>[] g = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) {
            g[i] = new ArrayList<Integer>();
        }

        // Adding edges to the graph
        for (int i = 0; i < m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            // Adding an edge between vertices 'u' and 'v' in both the adjacency lists
            g[u].add(v);
            g[v].add(u);
        }

        // Finding the number of isolated vertices and connected components
        for (int i = 1; i <= n; i++) {
            // If the current vertex 'i' is not visited yet
            if (!vis[i]) {
                // If the current vertex 'i' has no edges, then it is an isolated vertex
                if (g[i].size() == 0) {
                    ci++;
                }
                // Else, perform DFS traversal from the current vertex 'i' and count the number of connected components
                else {
                    if (dfs(i, g, vis)) {
                        cb++;
                    } else {
                        cc++;
                    }
                }
            }
        }

        // Calculating and printing the final answer
        System.out.println(ci * ci + 2 * ci * (n - ci) + cc * cc + 2 * cb * cc + 2 * cb * cb);
    }

    // Function to perform DFS traversal from a given vertex 'x'
    public static boolean dfs(int x, ArrayList<Integer>[] g, boolean[] vis) {
        // Creating an empty stack and initializing a flag
        Stack<Integer> stk = new Stack<Integer>();
        boolean flag = true;

        // Pushing the current vertex 'x' into the stack with color '1'
        stk.push(x);
        vis[x] = true;

        // Traversing the graph until the stack is empty
        while (!stk.empty()) {
            int u = stk.pop();

            // If the current vertex 'u' is already visited, then check if it has the same color as the previous vertex
            if (vis[u]) {
                flag &= (vis[u] == true);
                continue;
            }

            // Mark the current vertex 'u' as visited with the current color 'true'
            vis[u] = true;

            // Recursively traverse all the adjacent vertices of 'u'
            for (int i : g[u]) {
                stk.push(i);
            }
        }

        // Return the flag indicating whether all vertices in the connected component have the same color or not
        return flag;
    }
}

