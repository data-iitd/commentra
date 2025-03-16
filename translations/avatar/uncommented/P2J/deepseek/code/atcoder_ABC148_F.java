import java.util.*;

public class Main {
    static int n, ta, ao;
    static List<List<Integer>> g = new ArrayList<>();
    static int[] taDist;
    static int[] aoDist;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        ta = scanner.nextInt();
        ao = scanner.nextInt();
        ta -= 1;
        ao -= 1;
        for (int i = 0; i < n; i++) {
            g.add(new ArrayList<>());
        }
        for (int i = 0; i < n - 1; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            g.get(a - 1).add(b - 1);
            g.get(b - 1).add(a - 1);
        }
        taDist = new int[n];
        Arrays.fill(taDist, -1);
        aoDist = new int[n];
        Arrays.fill(aoDist, -1);
        taDist[ta] = 0;
        aoDist[ao] = 0;
        taDFS(ta);
        aoDFS(ao);
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (taDist[i] <= aoDist[i]) {
                res = Math.max(res, aoDist[i]);
            }
        }
        System.out.println(res - 1);
    }

    static void taDFS(int node) {
        for (int v : g.get(node)) {
            if (taDist[v] != -1) continue;
            taDist[v] = taDist[node] + 1;
            taDFS(v);
        }
    }

    static void aoDFS(int node) {
        for (int v : g.get(node)) {
            if (aoDist[v] != -1) continue;
            aoDist[v] = aoDist[node] + 1;
            aoDFS(v);
        }
    }
}
