import java.util.*;

public class Main {
    static final int MOD2 = 1000000007;
    static final int MOD = 998244353;
    static final int INF = (1 << 30) - 1;
    static final long LINF = (1L << 60);
    static final double EPS = 1e-10;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        int aall = 0, ball = 0;
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
            b[i] = scanner.nextInt();
            aall += a[i];
            ball += b[i];
        }

        long[][][] dp = new long[aall + 1][ball + 1][2];
        dp[0][0][0] = 1;
        for (int i = 1; i <= n; i++) {
            int id = i % 2;
            for (int asum = aall; asum >= 0; asum--) {
                for (int cnt = 0; cnt <= ball; cnt++) {
                    for (int p = 0; p < 2; p++) {
                        if (asum - a[i - 1] < 0) continue;
                        long pw = 1;
                        for (int use = 0; use < b[i - 1]; use++) {
                            if (cnt - use >= 0) {
                                long tmp =  comb(cnt, use) % MOD * pw % MOD;
                                dp[asum][cnt][p][0] += dp[asum - a[i - 1]][cnt - use][p ^ 1][0] * tmp % MOD;
                                dp[asum][cnt][p][1] += dp[asum - a[i - 1]][cnt - use][p ^ 1][1] * tmp % MOD;
                            } else break;
                            pw = pw * a[i - 1] % MOD;
                        }
                        if (cnt - b[i - 1] + 1 >= 0)
                            dp[asum][cnt][p][1] += dp[asum - a[i - 1]][cnt - b[i - 1] + 1][p ^ 1][0] * comb(cnt, b[i - 1] - 1) % MOD * pw % MOD;
                        dp[asum][cnt][p][0] %= MOD;
                        dp[asum][cnt][p][1] %= MOD;
                    }
                }
            }
        }

        long ans = 0;
        for (int asum = 0; asum <= aall; asum++) {
            long rev_asum_pow = 1;
            for (int cnt = 0; cnt <= ball; cnt++) {
                rev_asum_pow = rev_asum_pow * rev(asum) % MOD;
                for (int p = 0; p < 2; p++) {
                    long x = dp[asum][cnt][p][1] * rev_asum_pow % MOD * (cnt + 1) % MOD * aall % MOD * rev(asum) % MOD;
                    if (p == 1) ans += x;
                    else ans -= x;
                    ans %= MOD;
                }
            }
        }

        if (ans < 0) ans += MOD;
        System.out.println(ans);
    }

    static long comb(int n, int k) {
        if (n < k) return 0;
        long res = fact[n] * revfact[n - k] % MOD * revfact[k] % MOD;
        return res;
    }

    static long mod_pow(long x, long a, long m) {
        if (a == 0) return 1;
        long res = mod_pow(x, a / 2, m);
        res = res * res % m;
        if (a % 2 == 1) res = res * x % m;
        return res;
    }

    static long rev(long x) {
        return mod_pow(x, MOD - 2, MOD);
    }

    static long[] fact = new long[1100000];
    static long[] revfact = new long[1100000];

    static {
        fact[0] = 1;
        revfact[0] = 1;
        for (int i = 1; i < 1100000; i++) {
            fact[i] = fact[i - 1] * i % MOD;
            revfact[i] = rev(fact[i]);
        }
    }
}
