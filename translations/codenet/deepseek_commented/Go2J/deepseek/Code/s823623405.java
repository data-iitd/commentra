public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of elements
        int[] as = new int[n];
        java.util.Map<Integer, Integer> ps = new java.util.HashMap<>();
        for (int i = 0; i < n; i++) {
            as[i] = scanner.nextInt(); // Read each element of the array

            java.util.Map<Integer, Integer> ns = primeFactorize(as[i]); // Prime factorize the current element
            for (int k : ns.keySet()) {
                ps.put(k, Math.max(ps.getOrDefault(k, 0), ns.get(k))); // Update the map with the prime factors and their powers
            }
        }

        long x = 1;
        for (int k : ps.keySet()) {
            for (int i = 1; i <= ps.get(k); i++) {
                x = mul(x, k); // Calculate the LCM by multiplying the prime factors with their powers
            }
        }

        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = add(ans, div(x, as[i])); // Calculate the sum of modular inverses
        }
        System.out.println(ans); // Print the final answer
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

    private static final int mod = 1000000007;

    public static long pow(long n, long k) {
        if (k == 0) {
            return 1;
        } else if (k % 2 == 1) {
            return pow(n, k - 1) * n % mod;
        } else {
            long t = pow(n, k / 2);
            return t * t % mod;
        }
    }

    public static long add(long a, long b) {
        return (a + b) % mod;
    }

    public static long sub(long a, long b) {
        return (a + mod - b) % mod;
    }

    public static long mul(long a, long b) {
        return a % mod * b % mod % mod;
    }

    public static long div(long a, long b) {
        return mul(a, pow(b, mod - 2));
    }
}
