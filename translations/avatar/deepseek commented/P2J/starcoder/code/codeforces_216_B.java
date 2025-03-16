import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            try {
                int[] line0 = new int[2];
                line0 = getLine(sc);
                int n = line0[0];
                int m = line0[1];
                if (n == 0 && m == 0) {
                    break;
                }
                Map<Integer, Set<Integer>> g = new HashMap<Integer, Set<Integer>>();
                for (int i = 1; i <= n; i++) {
                    g.put(i, new HashSet<Integer>());
                }
                for (int i = 0; i < m; i++) {
                    int[] line1 = new int[2];
                    line1 = getLine(sc);
                    int a = line1[0];
                    int b = line1[1];
                    g.get(a).add(b);
                    g.get(b).add(a);
                }
                int ans = 0;
                Set<Integer> seen = new HashSet<Integer>();
                for (int i = 1; i <= n; i++) {
                    if (seen.contains(i)) {
                        continue;
                    }
                    int[] nodesEdges = dfs(g, seen, i);
                    int nodes = nodesEdges[0];
                    int edges = nodesEdges[1];
                    if (nodes > 1 && nodes % 2 == 1 && 2 * nodes == edges) {
                        ans += 1;
                    }
                }
                if ((n - ans) % 2 == 1) {
                    ans += 1;
                }
                System.out.println(ans);
            } catch (Exception e) {
                break;
            }
        }
    }

    public static int[] getLine(Scanner sc) {
        int[] line = new int[2];
        line[0] = sc.nextInt();
        line[1] = sc.nextInt();
        return line;
    }

    public static int[] dfs(Map<Integer, Set<Integer>> g, Set<Integer> seen, int i) {
        if (seen.contains(i)) {
            return new int[]{0, 0};
        }
        seen.add(i);
        int nodes = 1;
        int edges = g.get(i).size();
        for (int j : g.get(i)) {
            int[] x = dfs(g, seen, j);
            nodes += x[0];
            edges += x[1];
        }
        return new int[]{nodes, edges};
    }
}

