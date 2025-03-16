
import java.io.*;
import java.util.*;

class s338629964 {
    static final int MOD = 998244353;
    static final int MAX = 1000000;
    static final PrintWriter out = new PrintWriter(System.out);
    static final long[] fact = new long[MAX];
    static final long[] revfact = new long[MAX];
    static final long[] inv = new long[MAX];

    static long mod_pow(long x, long a) {
        if (a == 0) return 1;
        long res = mod_pow(x, a / 2);
        res = res * res % MOD;
        if (a % 2!= 0) res = res * x % MOD;
        return res;
    }

    static void init() {
        fact[0] = 1;
        for (int i = 1; i < MAX; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        inv[1] = 1;
        for (int i = 2; i < MAX; i++) {
            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        }
        revfact[0] = 1;
        for (int i = 1; i < MAX; i++) {
            revfact[i] = revfact[i - 1] * inv[i] % MOD;
        }
    }

    static long comb(int n, int k) {
        if (n < k) return 0;
        return fact[n] * revfact[k] % MOD * revfact[n - k] % MOD;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] a = new int[N];
        int[] b = new int[N];
        int sumA = 0, sumB = 0;
        for (int i = 0; i < N; i++) {
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
            sumA += a[i];
            sumB += b[i];
        }
        init();
        long[][][][] dp = new long[N + 1][sumA + 1][sumB + 1][2][2];
        dp[0][0][0][0][0] = 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= sumA; j++) {
                for (int k = 0; k <= sumB; k++) {
                    for (int l = 0; l < 2; l++) {
                        for (int m = 0; m < 2; m++) {
                            if (dp[i][j][k][l][m] == 0) continue;
                            for (int n = 0; n < a[i]; n++) {
                                if (j + n > sumA) break;
                                for (int o = 0; o <= b[i]; o++) {
                                    if (k + o > sumB) break;
                                    int nextL = l ^ (n < a[i] - 1? 1 : 0);
                                    int nextM = m ^ (o < b[i] - 1? 1 : 0);
                                    dp[i + 1][j + n][k + o][nextL][nextM] += dp[i][j][k][l][m] * comb(k + o, o) % MOD * mod_pow(a[i], o) % MOD;
                                    dp[i + 1][j + n][k + o][nextL][nextM] %= MOD;
                                }
                            }
                        }
                    }
                }
            }
        }
        long ans = 0;
        for (int i = 0; i <= sumA; i++) {
            long tmp = 0;
            for (int j = 0; j <= sumB; j++) {
                for (int k = 0; k < 2; k++) {
                    for (int l = 0; l < 2; l++) {
                        tmp += dp[N][i][j][k][l];
                    }
                }
            }
            ans += tmp * mod_pow(sumA - i, MOD - 2) % MOD * (sumB + 1) % MOD * sumA % MOD;
            ans %= MOD;
        }
        out.println(ans);
        out.flush();
    }
}

