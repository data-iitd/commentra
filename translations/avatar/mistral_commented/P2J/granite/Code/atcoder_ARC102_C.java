
import java.io.*;
import java.util.*;

class atcoder_ARC102_C {
    static final int MOD = 998244353;
    static final int MAXN = 8000;

    static int[] g1 = new int[MAXN + 1];
    static int[] g2 = new int[MAXN + 1];
    static int[] inverse = new int[MAXN + 1];

    static int cmb(int n, int r, int mod) {
        if (r < 0 || r > n) {
            return 0;
        }
        r = Math.min(r, n - r);
        return (int) ((long) g1[n] * g2[r] % mod * g2[n - r] % mod);
    }

    static int kumiawase(int p, int q) {
        return cmb(p + q - 1, q - 1, MOD);
    }

    static int solve(int n) {
        assert n <= K + 1;
        int ans = 0;
        int kumi = (n - 1) / 2;
        for (int p = 0; p <= kumi; p++) {
            if (p > N) {
                break;
            }
            ans += (int) ((long) (1 << p) * cmb(kumi, p, MOD) * kumiawase(N - p, p + (K - kumi * 2 - (n % 2 == 0? 1 : 0))) % MOD;
            if (n % 2 == 0 && N - p - 1 >= 0) {
                ans += (int) ((long) (1 << p) * cmb(kumi, p, MOD) * kumiawase(N - p - 1, p + (K - kumi * 2 - (n % 2 == 0? 1 : 0))) % MOD;
            }
        }
        return ans;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        int K = Integer.parseInt(line[0]);
        int N = Integer.parseInt(line[1]);

        g1[0] = g2[0] = 1;
        inverse[1] = 1;
        for (int i = 2; i <= MAXN; i++) {
            g1[i] = (int) ((long) g1[i - 1] * i % MOD);
            inverse[i] = (int) ((long) (MOD - MOD / i) * inverse[MOD % i] % MOD);
            g2[i] = (int) ((long) g2[i - 1] * inverse[i] % MOD);
        }

        int[] ans = new int[2 * K + 1];
        for (int i = 2; i <= 2 * K; i++) {
            ans[i] = solve(i);
            System.out.println(ans[i]);
        }
        for (int i = 2; i <= 2 * K; i++) {
            if (i <= K + 1) {
                System.out.println(ans[i]);
            } else {
                System.out.println(ans[2 * K + 2 - i]);
            }
        }
    }
}

