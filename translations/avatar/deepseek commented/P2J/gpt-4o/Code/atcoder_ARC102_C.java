import java.util.Scanner;

public class Main {
    static final int MOD = 998244353;
    static final int __N = 8000;
    static long[] g1 = new long[__N + 1];
    static long[] g2 = new long[__N + 1];
    static long[] inverse = new long[__N + 1];

    static {
        g1[0] = g1[1] = 1;
        g2[0] = g2[1] = 1;
        inverse[0] = 0;
        inverse[1] = 1;

        for (int i = 2; i <= __N; i++) {
            g1[i] = (g1[i - 1] * i) % MOD;
            inverse[i] = (-inverse[MOD % i] * (MOD / i)) % MOD;
            if (inverse[i] < 0) inverse[i] += MOD; // Ensure positive
            g2[i] = (g2[i - 1] * inverse[i]) % MOD;
        }
    }

    public static long cmb(int n, int r) {
        if (r < 0 || r > n) return 0;
        r = Math.min(r, n - r);
        return g1[n] * g2[r] % MOD * g2[n - r] % MOD;
    }

    public static long kumiawase(int p, int q) {
        return cmb(p + q - 1, q - 1);
    }

    public static long solve(int n, int K, int N) {
        assert n <= K + 1;
        long ans = 0;
        int kumi = (n - 1) / 2;
        for (int p = 0; p <= kumi; p++) {
            if (p > N) break;
            ans += (long) (Math.pow(2, p) * cmb(kumi, p) % MOD * kumiawase(N - p, p + (K - kumi * 2 - (n % 2 == 0 ? 1 : 0)))) % MOD;
            if (n % 2 == 0 && N - p - 1 >= 0) {
                ans += (long) (Math.pow(2, p) * cmb(kumi, p) % MOD * kumiawase(N - p - 1, p + (K - kumi * 2 - (n % 2 == 0 ? 1 : 0)))) % MOD;
            }
            ans %= MOD;
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int K = scanner.nextInt();
        int N = scanner.nextInt();
        long[] ans = new long[2 * K + 1];

        for (int i = 2; i <= 2 * K; i++) {
            if (i <= K + 1) {
                long tmp = solve(i, K, N) % MOD;
                ans[i] = tmp;
                System.out.println(tmp);
            } else {
                System.out.println(ans[2 * K - i]);
            }
        }
        scanner.close();
    }
}

// <END-OF-CODE>
