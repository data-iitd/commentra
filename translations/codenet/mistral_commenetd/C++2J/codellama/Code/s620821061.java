
import java.util.Scanner;

/**
 * @author <A HREF="mailto:v.danylo06@gmail.com">V. Danylo</A>
 *
 * @version 1.0
 *
 * @since 1.0
 */
public class BitMatching {

    private static final int MN = 520;

    private static int[][] G = new int[2 * MN][];
    private static int[] match = new int[2 * MN];
    private static boolean[] used = new boolean[2 * MN];

    private static void init() {
        for (int i = 0; i < 2 * MN; i++) {
            G[i] = new int[0];
        }
    }

    private static void add(int a, int b) {
        G[a] = Arrays.copyOf(G[a], G[a].length + 1);
        G[a][G[a].length - 1] = b + MN;

        G[b + MN] = Arrays.copyOf(G[b + MN], G[b + MN].length + 1);
        G[b + MN][G[b + MN].length - 1] = a;
    }

    private static boolean dfs(int v) {
        used[v] = true;

        for (int i = 0; i < G[v].length; i++) {
            int u = G[v][i], w = match[u];

            if (w < 0 || (!used[w] && dfs(w))) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false;
    }

    private static int exec() {
        int res = 0;

        for (int i = 0; i < MN; i++) {
            match[i] = -1;
        }

        for (int v = 0; v < MN; v++) {
            if (match[v] < 0) {
                for (int i = 0; i < MN; i++) {
                    used[i] = false;
                }

                if (dfs(v)) {
                    res++;
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            int n = scanner.nextInt();
            int m = scanner.nextInt();

            if (n == 0) {
                break;
            }

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
    }

    private static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}

