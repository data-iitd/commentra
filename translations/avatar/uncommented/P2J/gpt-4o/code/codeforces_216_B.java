import java.util.*;

public class Main {
    public static void main(String[] args) {
        while (solve()) {}
    }

    public static boolean solve() {
        Scanner scanner = new Scanner(System.in);
        int n, m;
        try {
            String[] line0 = scanner.nextLine().split(" ");
            n = Integer.parseInt(line0[0]);
            m = Integer.parseInt(line0[1]);
        } catch (NoSuchElementException e) {
            return false; // EOF
        }

        Map<Integer, Set<Integer>> g = new HashMap<>();
        Set<Integer> seen = new HashSet<>();

        for (int i = 1; i <= n; i++) {
            g.put(i, new HashSet<>());
        }

        for (int i = 0; i < m; i++) {
            String[] edge = scanner.nextLine().split(" ");
            int a = Integer.parseInt(edge[0]);
            int b = Integer.parseInt(edge[1]);
            g.get(a).add(b);
            g.get(b).add(a);
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!seen.contains(i)) {
                int[] result = dfs(g, seen, i);
                int nodes = result[0];
                int edges = result[1];
                if (nodes > 1 && nodes % 2 == 1 && 2 * nodes == edges) {
                    ans++;
                }
            }
        }

        if ((n - ans) % 2 == 1) {
            ans++;
        }
        System.out.println(ans);
        return true;
    }

    public static int[] dfs(Map<Integer, Set<Integer>> g, Set<Integer> seen, int i) {
        if (seen.contains(i)) {
            return new int[]{0, 0};
        }
        seen.add(i);
        int nodes = 1;
        int edges = g.get(i).size();
        for (int j : g.get(i)) {
            int[] result = dfs(g, seen, j);
            nodes += result[0];
            edges += result[1];
        }
        return new int[]{nodes, edges};
    }
}
// <END-OF-CODE>
