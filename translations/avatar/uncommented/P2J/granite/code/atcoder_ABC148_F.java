
import java.util.*;
import java.io.*;

class atcoder_ABC148_F {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] in = br.readLine().split(" ");
        int n = Integer.parseInt(in[0]);
        int ta = Integer.parseInt(in[1]) - 1;
        int ao = Integer.parseInt(in[2]) - 1;
        ArrayList<Integer>[] g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < n - 1; i++) {
            in = br.readLine().split(" ");
            int a = Integer.parseInt(in[0]) - 1;
            int b = Integer.parseInt(in[1]) - 1;
            g[a].add(b);
            g[b].add(a);
        }
        int[] ta_dist = new int[n];
        int[] ao_dist = new int[n];
        Arrays.fill(ta_dist, -1);
        Arrays.fill(ao_dist, -1);
        dfs(ta, ta_dist, g);
        dfs(ao, ao_dist, g);
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (ta_dist[i] > ao_dist[i]) {
                continue;
            }
            res = Math.max(res, ao_dist[i]);
        }
        System.out.println(res - 1);
    }

    static void dfs(int node, int[] dist, ArrayList<Integer>[] g) {
        dist[node] = 0;
        for (int v : g[node]) {
            if (dist[v]!= -1) {
                continue;
            }
            dfs(v, dist, g);
            dist[node] = Math.max(dist[node], dist[v] + 1);
        }
    }
}

Translate the above Java code to C++ and end with comment "