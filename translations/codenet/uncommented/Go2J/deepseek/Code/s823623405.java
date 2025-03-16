public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int[] as = new int[n];
        java.util.Map<Integer, Integer> ps = new java.util.HashMap<>();
        for (int i = 0; i < n; i++) {
            as[i] = scanner.nextInt();
            java.util.Map<Integer, Integer> ns = primeFactorize(as[i]);
            for (int k : ns.keySet()) {
                ps.put(k, Math.max(ps.getOrDefault(k, 0), ns.get(k)));
            }
        }

        long x = 1;
        for (int k : ps.keySet()) {
            for (int i = 1; i <= ps.get(k); i++) {
                x = (x * k) % 1000000007;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = (ans + divide(x, as[i])) % 1000000007;
        }
        System.out.println(ans);
    }

    public static java.util.Map<Integer, Integer> primeFactorize(int n) {
        java.util.Map<Integer, Integer> res = new java.util.HashMap<>();
        for (int i = 2; i * i <= n; i++) {
            while (n % i == 0) {
                n /= i;
                res.put(i, res.getOrDefault(i, 0) + 1);
            }
        }
        if (n != 1) {
            res.put(n, res.getOrDefault(n, 0) + 1);
        }
        return res;
    }

    public static final int MOD = 1000000007;

    public static long pow(long n, int k) {
        if (k == 0) {
            return 1;
        } else if (k % 2 == 1) {
            return pow(n, k - 1) * n % MOD;
        } else {
            long t = pow(n, k / 2);
            return t * t % MOD;
        }
    }

    public static int add(int a, int b) {
        return (a + b) % MOD;
    }

    public static int subtract(int a, int b) {
        return (a + MOD - b) % MOD;
    }

    public static long multiply(long a, long b) {
        return a % MOD * b % MOD % MOD;
    }

    public static int divide(int a, int b) {
        return (int) (multiply(a, pow(b, MOD - 2)) % MOD);
    }
}
