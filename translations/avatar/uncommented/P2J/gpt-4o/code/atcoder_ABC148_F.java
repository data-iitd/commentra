import java.util.*;

public class Main {
    static int mod = 1000000007;
    static int INF = Integer.MAX_VALUE;
    static int[] ta_dist, ao_dist;
    static List<List<Integer>> g;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int ta = scanner.nextInt() - 1;
        int ao = scanner.nextInt() - 1;

        g = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            g.add(new ArrayList<>());
        }

        for (int i = 0; i < n - 1; i++) {
            int a = scanner.nextInt() - 1;
            int b = scanner.nextInt() - 1;
            g.get(a).add(b);
            g.get(b).add(a);
        }

        ta_dist = new int[n];
        Arrays.fill(ta_dist, -1);
        ta_dist[ta] = 0;

        ao_dist = new int[n];
        Arrays.fill(ao_dist, -1);
        ao_dist[ao] = 0;

        aoDfs(ao);
        taDfs(ta);

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (ta_dist[i] > ao_dist[i]) continue;
            res = Math.max(res, ao_dist[i]);
        }
        System.out.println(res - 1);
    }

    static void taDfs(int node) {
        for (int v : g.get(node)) {
            if (ta_dist[v] != -1) continue;
            ta_dist[v] = ta_dist[node] + 1;
            taDfs(v);
        }
    }

    static void aoDfs(int node) {
        for (int v : g.get(node)) {
            if (ao_dist[v] != -1) continue;
            ao_dist[v] = ao_dist[node] + 1;
            aoDfs(v);
        }
    }
}
//<END-OF-CODE>
