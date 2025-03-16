import java.util.*;

public class Main {
    static int n, m;
    static int[] vis;
    static int ci, cb, cc;
    static List<List<Integer>> g;

    static boolean dfs(int x, int col) {
        Stack<int[]> stk = new Stack<>();
        stk.push(new int[]{x, col});
        boolean flag = true;

        while (!stk.isEmpty()) {
            int[] top = stk.pop();
            int u = top[0];
            int currentCol = top[1];

            if (vis[u] != 0) {
                flag &= (vis[u] == currentCol);
                continue;
            }

            vis[u] = currentCol;
            for (int v : g.get(u)) {
                stk.push(new int[]{v, 3 - currentCol});
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
                    if (dfs(i, 1)) {
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
