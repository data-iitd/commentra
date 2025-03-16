import java.util.*;
import java.io.*;

public class Main {
    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(InputStream stream) {
            try {
                br = new BufferedReader(new InputStreamReader(stream));
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) {
        FastScanner scanner = new FastScanner(System.in);
        int n = scanner.nextInt();
        char[] s = scanner.next().toCharArray();
        long[] f = new long[n + 1];
        int[] g = new int[n + 1];
        Map<Long, Long> map = new HashMap<>();
        long cnt = 0;
        final long B = 13131;

        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] == '+' || s[i - 1] == '-') {
                f[i] = f[i - 1] + (s[i - 1] == '+' ? 1 : -1) * pow(B, g[i] = g[i - 1]);
            } else {
                f[i] = f[i - 1];
                g[i] = g[i - 1] + (s[i - 1] == '<' ? -1 : 1);
            }
        }

        for (int i = n; i > 0; --i) {
            ++map.put(f[i], map.getOrDefault(f[i], 0L) + 1);
            cnt += map.getOrDefault(f[n] * pow(B, g[i - 1]) + f[i - 1], 0L);
        }

        System.out.println(cnt);
    }

    static long pow(long a, long k) {
        if (k < 0) k += (1L << 63) - 1;
        long t = 1;
        for (; k > 0; a = a * a, k >>= 1) {
            if ((k & 1) > 0) t = t * a;
        }
        return t;
    }
}
