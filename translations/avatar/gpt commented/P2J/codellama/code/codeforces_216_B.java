
import java.util.Scanner;
import java.util.ArrayList;
import java.util.HashSet;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            ArrayList<ArrayList<Integer>> g = new ArrayList<ArrayList<Integer>>();
            HashSet<Integer> seen = new HashSet<Integer>();
            for (int i = 0; i < n; i++) {
                g.add(new ArrayList<Integer>());
            }
            for (int i = 0; i < m; i++) {
                int a = sc.nextInt();
                int b = sc.nextInt();
                g.get(a - 1).add(b - 1);
                g.get(b - 1).add(a - 1);
            }
            int ans = 0;
            for (int i = 0; i < n; i++) {
                if (!seen.contains(i)) {
                    int nodes = 0;
                    int edges = 0;
                    dfs(g, seen, i, nodes, edges);
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

    public static void dfs(ArrayList<ArrayList<Integer>> g, HashSet<Integer> seen, int i, int nodes, int edges) {
        if (seen.contains(i)) {
            return;
        }
        seen.add(i);
        nodes++;
        edges += g.get(i).size();
        for (int j : g.get(i)) {
            dfs(g, seen, j, nodes, edges);
        }
    }
}

