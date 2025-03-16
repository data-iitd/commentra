import java.util.*;

public class Main {
    static final long MOD = 1000000007;

    // Function to calculate a^n
    static long pow(long a, long n) {
        long res = 1;
        while (n > 0) {
            if ((n & 1) == 1) res = res * a % MOD;
            a = a * a % MOD;
            n >>= 1;
        }
        return res;
    }

    // Function to calculate a^n % mod
    static long mod_pow(long a, long n, long mod) {
        long res = 1;
        while (n > 0) {
            if ((n & 1) == 1) res = res * a % mod;
            a = a * a % mod;
            n >>= 1;
        }
        return res;
    }

    // Function to calculate a^(-1) % mod (only if a % mod != 0)
    static long mod_inv(long a, long mod) {
        return mod_pow(a, mod - 2, mod);
    }

    // Function to calculate nCk % mod
    static long mod_nCk(int n, int k, long mod) {
        if (n == 0 || k == 0) return 1;
        long p = 1, q = 1;
        for (int i = n - k + 1; i <= n; i++)
            p = (p * i) % mod;
        for (int i = 2; i <= k; i++)
            q = (q * i) % mod;
        q = mod_inv(q, mod);
        return (p * q) % mod;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        System.out.println(mod_nCk(k, n, MOD));
    }
}
