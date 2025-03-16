import java.util.Scanner;

public class Main {
    static final int MOD = 1000000007;
    static final int NMAX = 1000010;
    static long[] fac = new long[NMAX];
    static long[] finv = new long[NMAX];
    static long[] inv = new long[NMAX];

    // Initialize factorial, inverse factorial, and inverse arrays
    static void init() {
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i < NMAX; i++) {
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    }

    // Calculate the binomial coefficient C(n, k)
    static long C(int n, int k) {
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
    }

    // Main function logic
    public static void main(String[] args) {
        init();
        Scanner scanner = new Scanner(System.in);
        int X = scanner.nextInt();
        int Y = scanner.nextInt();
        // Check if the sum of X and Y is divisible by 3
        if ((X + Y) % 3 != 0) {
            System.out.println(0);
            return;
        }
        // Calculate the number of steps needed to reach the target point
        int n = (X + Y) / 3 + 1;
        // Calculate the number of steps needed to reach the target point from the most upper point
        int k = 2 * (n - 1) - Y + 1; // y = 2xより最も上にくる点からどれだけ離れているか。
        // Output the number of ways to reach the target point
        System.out.println(C(n - 1, k - 1));
    }
}
// <END-OF-CODE>
