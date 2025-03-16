
import java.io.*;
import java.util.*;

public class atcoder_AGC028_B{
    static final int MOD = 100000007;
    static final int MAX = 1000000;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] split = br.readLine().split(" ");
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = Long.parseLong(split[i]);
        }
        long[] fact = new long[MAX];
        fact[0] = 1;
        for (int i = 1; i < MAX; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        long[] inv = new long[MAX];
        for (int i = 0; i < MAX; i++) {
            inv[i] = pow(i + 1, MOD - 2);
        }
        long[] sumInv = new long[MAX];
        sumInv[0] = inv[0];
        for (int i = 1; i < MAX; i++) {
            sumInv[i] = (sumInv[i - 1] + inv[i]) % MOD;
        }
        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += a[i] * (sumInv[i] + sumInv[n - 1 - i] - 1) % MOD;
            ans %= MOD;
        }
        ans = ans * fact[n] % MOD;
        System.out.println(ans);
    }

    static long pow(long a, long b) {
        long ret = 1;
        while (b > 0) {
            if (b % 2 == 1) {
                ret = ret * a % MOD;
            }
            a = a * a % MOD;
            b /= 2;
        }
        return ret;
    }
}

