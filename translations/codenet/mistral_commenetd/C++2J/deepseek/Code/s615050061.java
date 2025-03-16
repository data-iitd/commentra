import java.util.*;

public class Main {
    static class FastScanner {
        private Scanner scanner = new Scanner(System.in);
        public int nextInt() {
            return scanner.nextInt();
        }
        public String next() {
            return scanner.next();
        }
    }

    public static void main(String[] args) {
        FastScanner scanner = new FastScanner();
        int n = scanner.nextInt();
        char[] s = scanner.next().toCharArray();

        long[] f = new long[n + 1];
        int[] g = new int[n + 1];
        Map<Long, Long> map = new HashMap<>();
        long cnt = 0;

        f[0] = 0;
        g[0] = 0;

        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] == '+' || s[i - 1] == '-') {
                f[i] = f[i - 1] + (s[i - 1] == '+' ? 1 : -1) * pow(13131, g[i] = g[i - 1]);
            } else {
                f[i] = f[i - 1];
                g[i] = g[i - 1] + (s[i - 1] == '<' ? -1 : 1);
            }
        }

        for (int i = n; i > 0; --i) {
            map.put(f[i], map.getOrDefault(f[i], 0L) + 1);
            cnt += map.getOrDefault(f[n] * pow(13131, g[i - 1]) + f[i - 1], 0L);
        }

        System.out.println(cnt);
    }

    private static long pow(long a, int k) {
        if (k < 0) k += (1L << 63) - 1;
        long t = 1;
        for (; k > 0; a *= a, k >>= 1) {
            if ((k & 1) == 1) t *= a;
        }
        return t;
    }
}
