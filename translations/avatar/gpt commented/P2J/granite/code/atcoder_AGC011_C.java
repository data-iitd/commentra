
import java.util.*;

public class atcoder_AGC011_C{
    static int n, m, vis[], ci, cb, cc;
    static ArrayList<Integer> g[];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        vis = new int[n + 1];
        ci = 0;
        cb = 0;
        cc = 0;
        g = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            g[u].add(v);
            g[v].add(u);
        }
        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0) {
                if (g[i].size() == 0) {
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
    }

    static boolean dfs(int x) {
        Stack<Integer> stk = new Stack<>();
        boolean flag = true;
        stk.push(x);
        vis[x] = 1;
        while (!stk.isEmpty()) {
            int u = stk.pop();
            for (int i : g[u]) {
                if (vis[i] == 0) {
                    vis[i] = 3 - vis[u];
                    stk.push(i);
                } else {
                    flag &= (vis[i] == 3 - vis[u]);
                }
            }
        }
        return flag;
    }
}

Translate the above Java code to C++ and end with comment "