import java.util.Scanner;

public class Main {
    static final long MOD = 998244353;
    static long[] fact = new long[1100000];
    static long[] revfact = new long[1100000];
    static long[] rev = new long[1100000];
    static long[][] comb = new long[1100][1100];
    static long[][][][] dp = new long[440][440][2][2];
    static long aall, ball;
    static long n, ans;
    static long[] a = new long[440];
    static long[] b = new long[440];

    static void init() {
        long m = MOD;
        fact[0] = 1;
        revfact[0] = 1;
        rev[0] = 0;
        rev[1] = 1;
        for (int i = 1; i < 1100000; i++) {
            fact[i] = fact[i - 1] * i % m;
            if (i > 1) {
                rev[i] = MOD / i * (MOD - rev[(int) (MOD % i)]) % MOD;
            }
            revfact[i] = revfact[i - 1] * rev[i] % MOD;
        }
    }

    static long nCk(long n, long k) {
        if (n < k) return 0;
        if (comb[(int) n][(int) k] != 0) return comb[(int) n][(int) k];
        long res = fact[(int) n] * revfact[(int) (n - k)] % MOD * revfact[(int) k] % MOD;
        comb[(int) n][(int) k] = res;
        return res;
    }

    static long mod_pow(long x, long a, long m) {
        if (a == 0) return 1;
        long res = mod_pow(x, a / 2, m);
        res = res * res % m;
        if (a % 2 != 0) res = res * x % m;
        return res;
    }

    static long inv(long x, long m) {
        return mod_pow(x, m - 2, m);
    }

    public static void main(String[] args) {
        init();
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextLong();
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextLong();
            b[i] = scanner.nextLong();
            aall += a[i];
            ball += b[i];
        }

        dp[0][0][0][0] = 1;
        for (int i = 1; i <= n; i++) {
            int id = i % 2;
            for (int asum = (int) aall; asum >= 0; asum--) {
                for (int cnt = 0; cnt <= ball; cnt++) {
                    for (int p = 0; p < 2; p++) {
                        if (asum - a[i - 1] < 0) continue;
                        long pw = 1;
                        for (int use = 0; use < b[i - 1]; use++) {
                            if (cnt - use >= 0) {
                                long tmp = nCk(cnt, use) % MOD * pw % MOD;
                                dp[asum][cnt][p][0] += dp[asum - (int) a[i - 1]][cnt - use][p ^ 1][0] * tmp % MOD;
                                dp[asum][cnt][p][1] += dp[asum - (int) a[i - 1]][cnt - use][p ^ 1][1] * tmp % MOD;
                            } else break;
                            pw = pw * a[i - 1] % MOD;
                        }
                        if (cnt - b[i - 1] + 1 >= 0)
                            dp[asum][cnt][p][1] += dp[asum - (int) a[i - 1]][cnt - b[i - 1] + 1][p ^ 1][0] * nCk(cnt, b[i - 1] - 1) % MOD * pw % MOD;
                        dp[asum][cnt][p][0] %= MOD;
                        dp[asum][cnt][p][1] %= MOD;
                    }
                }
            }
        }

        for (int asum = 0; asum <= aall; asum++) {
            long rev_asum_pow = 1;
            for (int cnt = 0; cnt <= ball; cnt++) {
                rev_asum_pow = rev_asum_pow * rev[asum] % MOD;
                for (int p = 0; p < 2; p++) {
                    long x = dp[asum][cnt][p][1] * rev_asum_pow % MOD * (cnt + 1) % MOD * aall % MOD * rev[asum] % MOD;
                    if (p == 1) ans += x;
                    else ans -= x;
                    ans %= MOD;
                }
            }
        }
        if (ans < 0) ans += MOD;
        System.out.println(ans);
        scanner.close();
    }
}

// <END-OF-CODE>
