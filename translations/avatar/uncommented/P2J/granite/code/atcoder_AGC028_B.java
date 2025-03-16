
import java.io.*;
import java.util.*;

class atcoder_AGC028_B {
    static final long MOD = 100000007;
    static final int MAX = 1000000;
    static final int SQRT = 1000;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[] A = br.readLine().split(" ");
        long[] fact = new long[MAX];
        fact[0] = 1;
        for (int i = 1; i < SQRT; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        for (int i = SQRT; i < MAX; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        long[] inv = new long[N];
        inv[N - 1] = pow(fact[N - 1], MOD - 2);
        for (int i = N - 2; i >= 0; i--) {
            inv[i] = inv[i + 1] * (i + 1) % MOD;
        }
        long[] sum_inv = new long[N];
        sum_inv[0] = inv[0];
        for (int i = 1; i < N; i++) {
            sum_inv[i] = (sum_inv[i - 1] + inv[i]) % MOD;
        }
        long ans = 0;
        for (int i = 0; i < N; i++) {
            ans += Long.parseLong(A[i]) * (sum_inv[i] + sum_inv[N - 1 - i] - 1) % MOD;
            ans %= MOD;
        }
        ans *= fact[N];
        ans %= MOD;
        System.out.println(ans);
    }

    static long pow(long a, long n) {
        long res = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                res = res * a % MOD;
            }
            a = a * a % MOD;
            n /= 2;
        }
        return res;
    }
}
