import java.util.*;

public class Main {
    static Scanner scanner = new Scanner(System.in);

    static List<Integer> readInts() {
        return Arrays.asList(scanner.nextLine().split(" ")).stream().map(Integer::parseInt).collect(Collectors.toList());
    }

    static int[] dfs(Map<Integer, Set<Integer>> g, Set<Integer> seen, int i) {
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

    public static void main(String[] args) {
        while (true) {
            List<Integer> line0 = readInts();
            if (line0 == null) {
                break;
            }
            int n = line0.get(0);
            int m = line0.get(1);
            Map<Integer, Set<Integer>> g = new HashMap<>();
            Set<Integer> seen = new HashSet<>();
            for (int i = 1; i <= n; i++) {
                g.put(i, new HashSet<>());
            }
            for (int i = 0; i < m; i++) {
                List<Integer> edge = readInts();
                int a = edge.get(0);
                int b = edge.get(1);
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
        }
    }
}
