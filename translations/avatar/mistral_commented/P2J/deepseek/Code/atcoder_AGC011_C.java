import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[] vis = new int[n + 1];
        int ci = 0, cb = 0, cc = 0;
        List<List<Integer>> g = new ArrayList<>(n + 1);
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
                    if (dfs(i, vis, g)) {
                        cb++;
                    } else {
                        cc++;
                    }
                }
            }
        }

        System.out.println(ci * ci + 2 * ci * (n - ci) + cc * cc + 2 * cb * cc + 2 * cb * cb);
    }

    private static boolean dfs(int x, int[] vis, List<List<Integer>> g) {
        Stack<int[]> stack = new Stack<>();
        boolean flag = true;
        stack.push(new int[]{x, 1});

        while (!stack.isEmpty()) {
            int[] top = stack.pop();
            int u = top[0];
            int col = top[1];

            if (vis[u] != 0) {
                flag &= (vis[u] == col);
                continue;
            }

            vis[u] = col;

            for (int v : g.get(u)) {
                stack.push(new int[]{v, 3 - col});
            }
        }

        return flag;
    }
}
