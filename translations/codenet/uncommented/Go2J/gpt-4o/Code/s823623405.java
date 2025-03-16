import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    static final int MOD = 1000000007;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] as = new int[n];
        Map<Integer, Integer> ps = new HashMap<>();

        for (int i = 0; i < n; i++) {
            as[i] = scanner.nextInt();
            Map<Integer, Integer> ns = primeFactorize(as[i]);
            for (Map.Entry<Integer, Integer> entry : ns.entrySet()) {
                ps.put(entry.getKey(), Math.max(ps.getOrDefault(entry.getKey(), 0), entry.getValue()));
            }
        }

        long x = 1;
        for (Map.Entry<Integer, Integer> entry : ps.entrySet()) {
            int k = entry.getKey();
            int v = entry.getValue();
            for (int i = 1; i <= v; i++) {
                x = mul(x, k);
            }
        }

        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = add(ans, div(x, as[i]));
        }
        System.out.println(ans);
    }

    static int max(int a, int b) {
        return Math.max(a, b);
    }

    static Map<Integer, Integer> primeFactorize(int n) {
        Map<Integer, Integer> res = new HashMap<>();
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

    static long pow(long n, long k) {
        if (k == 0) {
            return 1;
        } else if (k % 2 == 1) {
            return mul(pow(n, k - 1), n);
        } else {
            long t = pow(n, k / 2);
            return mul(t, t);
        }
    }

    static long add(long a, long b) {
        return (a + b) % MOD;
    }

    static long sub(long a, long b) {
        return (a + MOD - b) % MOD;
    }

    static long mul(long a, long b) {
        return (a % MOD * b % MOD) % MOD;
    }

    static long div(long a, int b) {
        return mul(a, pow(b, MOD - 2));
    }
}
// <END-OF-CODE>
