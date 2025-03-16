package main;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] as = new int[n];
        Map<Integer, Integer> ps = new HashMap<>();

        for (int i = 0; i < n; i++) {
            as[i] = scanner.nextInt();
            Map<Integer, Integer> ns = primeFactorize(as[i]);
            for (Map.Entry<Integer, Integer> entry : ns.entrySet()) {
                int k = entry.getKey();
                int v = entry.getValue();
                ps.put(k, Math.max(ps.getOrDefault(k, 0), v));
            }
        }

        long x = 1;
        for (Map.Entry<Integer, Integer> entry : ps.entrySet()) {
            int k = entry.getKey();
            int v = entry.getValue();
            for (int i = 1; i <= v; i++) {
                x = (x * k) % 1000000007;
            }
        }

        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = (ans + divide(x, as[i])) % 1000000007;
        }

        System.out.println(ans);
    }

    private static Map<Integer, Integer> primeFactorize(int n) {
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

    private static long pow(long n, long k) {
        if (k == 0) {
            return 1;
        } else if (k % 2 == 1) {
            return pow(n, k - 1) * n % 1000000007;
        } else {
            long t = pow(n, k / 2);
            return t * t % 1000000007;
        }
    }

    private static long divide(long a, long b) {
        return a * pow(b, 1000000005) % 1000000007;
    }
}
