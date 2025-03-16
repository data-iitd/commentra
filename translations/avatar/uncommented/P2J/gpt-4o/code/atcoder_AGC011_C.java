import java.util.*;

public class Main {
    static int n, m;
    static int[] vis;
    static int ci, cb, cc;
    static List<List<Integer>> g;

    public static boolean dfs(int x) {
        Stack<Pair> stk = new Stack<>();
        boolean flag = true;
        stk.push(new Pair(x, 1));
        
        while (!stk.isEmpty()) {
            Pair p = stk.pop();
            int u = p.node;
            int col = p.color;

            if (vis[u] != 0) {
                flag &= (vis[u] == col);
                continue;
            }
            vis[u] = col;
            for (int i : g.get(u)) {
                stk.push(new Pair(i, 3 - col));
            }
        }
        return flag;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();
        vis = new int[n + 1];
        ci = 0;
        cb = 0;
        cc = 0;
        g = new ArrayList<>(n + 1);
        
        for (int i = 0; i <= n; i++) {
            g.add(new ArrayList<>());
        }

        for (int i = 0; i < m; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            g.get(u).add(v);
            g.get(v).add(u);
        }

        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0) {
                if (g.get(i).isEmpty()) {
                    ci++;
                } else {
                    if (dfs(i)) {
                        cb++;
                    } else {
                        cc++;
                    }
                }
            }
        }

        System.out.println(ci * ci + 2 * ci * (n - ci) + cc * cc + 2 * cb * cc + 2 * cb * cb);
        scanner.close();
    }

    static class Pair {
        int node;
        int color;

        Pair(int node, int color) {
            this.node = node;
            this.color = color;
        }
    }
}
//<END-OF-CODE>
