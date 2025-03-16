
import java.io.*;
import java.util.*;

public class s338629964{
    static final int MOD = 998244353;
    static final int MAXN = 440;
    static final int MAXSUM = 1000000;
    static int[] fact = new int[MAXSUM + 1];
    static int[] invfact = new int[MAXSUM + 1];
    static int[] inv = new int[MAXSUM + 1];
    static int[][] comb = new int[MAXN][MAXN];
    static int[][][][] dp = new int[MAXN][MAXN][2][2];

    public static void main(String[] args) throws IOException {
        init();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] a = new int[n];
        int[] b = new int[n];
        int aall = 0, ball = 0;
        for (int i = 0; i < n; i++) {
            String[] split = br.readLine().split(" ");
            a[i] = Integer.parseInt(split[0]);
            b[i] = Integer.parseInt(split[1]);
            aall += a[i];
            ball += b[i];
        }
        dp[0][0][0][0] = 1;
        for (int i = 1; i <= n; i++) {
            int id = i % 2;
            for (int asum = aall; asum >= 0; asum--) {
                for (int cnt = 0; cnt <= ball; cnt++) {
                    for (int p = 0; p < 2; p++) {
                        if (asum - a[i - 1] < 0) continue;
                        int pw = 1;
                        for (int use = 0; use < b[i - 1]; use++) {
                            if (cnt - use >= 0) {
                                int tmp = comb[cnt][use] * pw % MOD;
                                dp[asum][cnt][p][0] += dp[asum - a[i - 1]][cnt - use][p ^ 1][0] * tmp % MOD;
                                dp[asum][cnt][p][1] += dp[asum - a[i - 1]][cnt - use][p ^ 1][1] * tmp % MOD;
                            } else break;
                            pw = pw * a[i - 1] % MOD;
                        }
                        if (cnt - b[i - 1] + 1 >= 0)
                            dp[asum][cnt][p][1] += dp[asum - a[i - 1]][cnt - b[i - 1] + 1][p ^ 1][0] * comb[cnt][b[i - 1] - 1] % MOD * pw % MOD;
                        dp[asum][cnt][p][0] %= MOD;
                        dp[asum][cnt][p][1] %= MOD;
                    }
                }
            }
        }
        int ans = 0;
        for (int asum = 0; asum <= aall; asum++) {
            int rev_asum_pow = 1;
            for (int cnt = 0; cnt <= ball; cnt++) {
                rev_asum_pow = rev_asum_pow * inv[asum] % MOD;
                for (int p = 0; p < 2; p++) {
                    int x = dp[asum][cnt][p][1] * rev_asum_pow % MOD * (cnt + 1) % MOD * aall % MOD * inv[asum] % MOD;
                    if (p == 1) ans += x;
                    else ans -= x;
                    ans %= MOD;
                }
            }
        }
        if (ans < 0) ans += MOD;
        System.out.println(ans);
    }

    static void init() {
        fact[0] = 1;
        invfact[0] = 1;
        inv[1] = 1;
        for (int i = 1; i <= MAXSUM; i++) {
            fact[i] = (int) ((long) fact[i - 1] * i % MOD);
            inv[i] = MOD - (int) ((long) inv[MOD % i] * (MOD / i) % MOD);
            invfact[i] = (int) ((long) invfact[i - 1] * inv[i] % MOD);
        }
        for (int i = 0; i < MAXN; i++) {
            comb[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }
    }
}

