import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class BitMatching {
    static final int MN = 520;
    static ArrayList<Integer>[] G = new ArrayList[2 * MN];
    static int[] match = new int[2 * MN];
    static boolean[] used = new boolean[2 * MN];

    static {
        for (int i = 0; i < G.length; i++) {
            G[i] = new ArrayList<>();
        }
    }

    public static void init() {
        for (int i = 0; i < 2 * MN; i++) {
            G[i].clear();
        }
    }

    public static void add(int a, int b) {
        G[a].add(b + MN);
        G[b + MN].add(a);
    }

    public static boolean dfs(int v) {
        used[v] = true;
        for (int u : G[v]) {
            int w = match[u];
            if (w < 0 || (!used[w] && dfs(w))) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false;
    }

    public static int exec() {
        int res = 0;
        Arrays.fill(match, -1);
        for (int v = 0; v < MN; v++) {
            if (match[v] < 0) {
                Arrays.fill(used, false);
                if (dfs(v)) {
                    res++;
                }
            }
        }
        return res;
    }

    public static long gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            if (n == 0) break;
            init();
            int[] a = new int[n];
            int[] b = new int[m];
            for (int i = 0; i < n; i++) {
                a[i] = scanner.nextInt();
            }
            for (int i = 0; i < m; i++) {
                b[i] = scanner.nextInt();
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (gcd(a[i], b[j]) != 1) {
                        add(i, j);
                    }
                }
            }
            System.out.println(exec());
        }
        scanner.close();
    }
}
// <END-OF-CODE>
