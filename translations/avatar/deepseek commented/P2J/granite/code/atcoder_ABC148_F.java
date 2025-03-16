
import java.io.*;
import java.util.*;

public class atcoder_ABC148_F{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int ta = Integer.parseInt(input[1]) - 1;
        int ao = Integer.parseInt(input[2]) - 1;

        List<List<Integer>> g = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            g.add(new ArrayList<>());
        }

        for (int i = 0; i < n - 1; i++) {
            input = br.readLine().split(" ");
            int a = Integer.parseInt(input[0]) - 1;
            int b = Integer.parseInt(input[1]) - 1;
            g.get(a).add(b);
            g.get(b).add(a);
        }

        int[] taDist = new int[n];
        int[] aoDist = new int[n];
        Arrays.fill(taDist, -1);
        Arrays.fill(aoDist, -1);

        dfs(g, ta, taDist, 0);
        dfs(g, ao, aoDist, 0);

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (taDist[i] <= aoDist[i]) {
                res = Math.max(res, aoDist[i]);
            }
        }

        System.out.println(res - 1);
    }

    private static void dfs(List<List<Integer>> g, int node, int[] dist, int depth) {
        dist[node] = depth;
        for (int neighbor : g.get(node)) {
            if (dist[neighbor] == -1) {
                dfs(g, neighbor, dist, depth + 1);
            }
        }
    }
}

Translate the above Java code to C++ and end with comment "