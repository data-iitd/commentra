
import java.util.*;

public class codeforces_216_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (solve(scanner)) {
            // Do nothing
        }
    }

    public static boolean solve(Scanner scanner) {
        try {
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            Map<Integer, Set<Integer>> graph = new HashMap<>();
            for (int i = 1; i <= n; i++) {
                graph.put(i, new HashSet<>());
            }
            for (int i = 0; i < m; i++) {
                int a = scanner.nextInt();
                int b = scanner.nextInt();
                graph.get(a).add(b);
                graph.get(b).add(a);
            }
            int ans = 0;
            Set<Integer> seen = new HashSet<>();
            for (int i = 1; i <= n; i++) {
                if (!seen.contains(i)) {
                    int[] count = dfs(graph, seen, i);
                    if (count[0] > 1 && count[0] % 2 == 1 && count[0] * 2 == count[1]) {
                        ans++;
                    }
                }
            }
            if ((n - ans) % 2 == 1) {
                ans++;
            }
            System.out.println(ans);
            return true;
        } catch (Exception e) {
            return false;
        }
    }

    public static int[] dfs(Map<Integer, Set<Integer>> graph, Set<Integer> seen, int i) {
        if (seen.contains(i)) {
            return new int[]{0, 0};
        }
        seen.add(i);
        int nodes = 1;
        int edges = graph.get(i).size();
        for (int j : graph.get(i)) {
            int[] count = dfs(graph, seen, j);
            nodes += count[0];
            edges += count[1];
        }
        return new int[]{nodes, edges};
    }
}

Translate the above Java code to C++ and end with comment "