
import java.util.*;

public class atcoder_AGC011_C{
    static int n, m, vis[], ci, cb, cc;
    static ArrayList<Integer> g[];

    // Depth-First Search (DFS) function to determine if a graph is bipartite
    static boolean dfs(int x) {
        Stack<Integer> stk = new Stack<>();
        boolean flag = true;
        stk.push(x);
        vis[x] = 1;
        while (!stk.isEmpty()) {
            int u = stk.pop(), col = 3 - vis[u];
            if (vis[u]!= 0) {
                flag &= (vis[u] == col);
                continue;
            }
            vis[u] = col;
            for (int i : g[u]) {
                stk.push(i);
            }
        }
        return flag;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        vis = new int[n + 1];
        ci = cb = cc = 0;
        g = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) {
            g[i] = new ArrayList<>();
        }

        // Constructing the graph by reading edges
        for (int i = 0; i < m; i++) {
            int u = sc.nextInt(), v = sc.nextInt();
            g[u].add(v);
            g[v].add(u);
        }

        // Traversing the graph to classify nodes
        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0) {
                if (g[i].size() == 0) {
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
    }
}

Translate the above Java code to C++ and end with comment "