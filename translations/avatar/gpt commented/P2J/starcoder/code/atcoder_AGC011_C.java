import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] vis = new int[n + 1];
        int ci = 0, cb = 0, cc = 0;
        ArrayList<Integer>[] g = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            g[i] = new ArrayList<Integer>();
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
                    boolean flag = true;
                    Stack<Integer> stk = new Stack<Integer>();
                    stk.push(i);
                    while (!stk.empty()) {
                        int u = stk.pop();
                        if (vis[u]!= 0) {
                            flag &= (vis[u] == (stk.empty()? 1 : 3));
                            continue;
                        }
                        vis[u] = (stk.empty()? 1 : 3);
                        for (int j : g[u]) {
                            stk.push(j);
                        }
                    }
                    if (flag) {
                        cb++;
                    } else {
                        cc++;
                    }
                }
            }
        }
        System.out.println(ci * ci + 2 * ci * (n - ci) + cc * cc + 2 * cb * cc + 2 * cb * cb);
    }
}

