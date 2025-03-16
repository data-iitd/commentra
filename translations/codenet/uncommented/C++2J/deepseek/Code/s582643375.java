import java.util.*;

public class Main {
    static final int mod = 1000000007;
    static final int NMAX = 1000010;

    static long[] fac = new long[NMAX];
    static long[] finv = new long[NMAX];
    static long[] inv = new long[NMAX];

    static void init() {
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i < NMAX; i++) {
            fac[i] = fac[i - 1] * i % mod;
            inv[i] = mod - inv[mod % i] * (mod / i) % mod;
            finv[i] = finv[i - 1] * inv[i] % mod;
        }
    }

    static long C(int n, int k) {
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int X = scanner.nextInt();
        int Y = scanner.nextInt();
        if ((X + Y) % 3 != 0) {
            System.out.println(0);
            return;
        }
        int n = (X + Y) / 3 + 1;
        int k = 2 * (n - 1) - Y + 1; // y = 2xより最も上にくる点からどれだけ離れているか。
        init();
        System.out.println(C(n - 1, k - 1));
    }
}
