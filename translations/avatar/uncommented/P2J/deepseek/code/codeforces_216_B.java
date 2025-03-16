import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (solve(scanner)) {}
    }

    public static List<Integer> readInts(Scanner scanner) {
        String[] tokens = scanner.nextLine().split(" ");
        List<Integer> ints = new ArrayList<>();
        for (String token : tokens) {
            ints.add(Integer.parseInt(token));
        }
        return ints;
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

    public static boolean solve(Scanner scanner) {
        List<Integer> line0 = readInts(scanner);
        if (line0.isEmpty()) {
            return false;
        }
        int n = line0.get(0);
        int m = line0.get(1);
        Map<Integer, Set<Integer>> g = new HashMap<>();
        Set<Integer> seen = new HashSet<>();
        for (int i = 1; i <= n; i++) {
            g.put(i, new HashSet<>());
        }
        for (int i = 0; i < m; i++) {
            List<Integer> ab = readInts(scanner);
            int a = ab.get(0);
            int b = ab.get(1);
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
                    ans += 1;
                }
            }
        }
        if ((n - ans) % 2 == 1) {
            ans += 1;
        }
        System.out.println(ans);
        return true;
    }
}
