import java.util.Scanner;

public class Main {
    static final int MOD = 998244353;
    static final int FAC_NUM = 300001;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int sum = 0;
        for (int i = 1; i <= N; i++) {
            if (i % 3 == 0 || i % 5 == 0) {
                continue;
            }
            sum += i;
        }
        System.out.println(sum);
    }

    // Power function
    static int pow(int a, int n) {
        int ans = 1;
        while (n > 0) {
            if ((n & 1) == 1) {
                ans = (int) ((1L * ans * a) % MOD);
            }
            a = (int) ((1L * a * a) % MOD);
            n >>= 1;
        }
        return ans;
    }

    // GCD function
    static int gcd(int a, int b) {
        if (a < b) {
            return gcd(b, a);
        }
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Min function
    static int min(int a, int b) {
        return a < b ? a : b;
    }

    // Combination function
    static int combination(int n, int k, int[] fac, int[] ifac) {
        if (n < k || n < 0) {
            return 0;
        }
        if (k == 0) {
            return 1;
        }
        return (int) ((1L * ifac[k] * ifac[n - k] % MOD) * fac[n] % MOD);
    }

    // Factorial function
    static int[][] factorial() {
        int[] fac = new int[FAC_NUM];
        int[] ifac = new int[FAC_NUM];
        fac[0] = 1;
        ifac[0] = 1;
        for (int i = 1; i < FAC_NUM; i++) {
            fac[i] = (int) ((1L * fac[i - 1] * i) % MOD);
            ifac[i] = (int) ((1L * ifac[i - 1] * pow(i, MOD - 2)) % MOD);
        }
        return new int[][]{fac, ifac};
    }

    // Lower bound function
    static int lowerBound(int[] vs, int v) {
        int n = vs.length / 2;
        int m = vs.length;
        while (m != n) {
            if (vs[n] < v) {
                n = (m - n + 1) / 2 + n;
            } else {
                m = n;
                n = n / 2;
            }
        }
        return n;
    }

    // Initialize an integer array
    static int[] intSlice(int n, int init) {
        int[] r = new int[n];
        for (int i = 0; i < r.length; i++) {
            r[i] = init;
        }
        return r;
    }
}

// <END-OF-CODE>
