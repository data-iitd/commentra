
import java.io.*;
import java.util.*;

public class atcoder_ARC102_C{
    static long mod = 998244353;
    static long[] g1 = new long[8001];
    static long[] g2 = new long[8001];
    static long[] inverse = new long[8001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        int K = Integer.parseInt(line[0]);
        int N = Integer.parseInt(line[1]);
        long[] ans = new long[2 * K];
        Arrays.fill(ans, -1);
        for (int i = 2; i <= 2 * K; i++) {
            if (i <= K + 1) {
                ans[i - 2] = solve(i, K, N);
                System.out.println(ans[i - 2]);
            } else {
                System.out.println(ans[i - 2 - K]);
            }
        }
    }

    static long cmb(int n, int r, long mod) {
        if (r < 0 || r > n) {
            return 0;
        }
        r = Math.min(r, n - r);
        return g1[n] * g2[r] % mod * g2[n - r] % mod;
    }

    static long kumiawase(int p, int q) {
        return cmb(p + q - 1, q - 1, mod);
    }

    static long solve(int n, int K, int N) {
        int kumi = (n - 1) / 2;
        long ans = 0;
        for (int p = 0; p <= kumi; p++) {
            if (p > N) {
                break;
            }
            ans += (1L << p) * cmb(kumi, p, mod) * kumiawase(N - p, p + (K - kumi * 2 - (n % 2 == 0? 1 : 0)));
            if (n % 2 == 0 && N - p - 1 >= 0) {
                ans += (1L << p) * cmb(kumi, p, mod) * kumiawase(N - p - 1, p + (K - kumi * 2 - (n % 2 == 0? 1 : 0)));
            }
        }
        return ans % mod;
    }
}

