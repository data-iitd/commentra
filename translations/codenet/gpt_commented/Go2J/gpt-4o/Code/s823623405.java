import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    private static final int MOD = 1000000007;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements
        int n = scanner.nextInt();
        
        // Initialize an array to store the input numbers and a map to store the maximum prime factors
        int[] as = new int[n];
        Map<Integer, Integer> ps = new HashMap<>();
        
        // Read each number and perform prime factorization
        for (int i = 0; i < n; i++) {
            as[i] = scanner.nextInt();
            
            // Get the prime factors of the current number
            Map<Integer, Integer> ns = primeFactorize(as[i]);
            // Update the maximum count of each prime factor found
            for (Map.Entry<Integer, Integer> entry : ns.entrySet()) {
                ps.put(entry.getKey(), Math.max(ps.getOrDefault(entry.getKey(), 0), entry.getValue()));
            }
        }
        
        // Calculate the product of the maximum prime factors raised to their respective powers
        long x = 1;
        for (Map.Entry<Integer, Integer> entry : ps.entrySet()) {
            int k = entry.getKey();
            int v = entry.getValue();
            for (int i = 1; i <= v; i++) {
                x = mul(x, k);
            }
        }
        
        // Calculate the final answer by summing the results of x divided by each input number
        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = add(ans, div(x, as[i]));
        }
        
        // Print the final answer
        System.out.println(ans);
    }

    // Function to compute n raised to the power of k under modulo
    private static long pow(long n, long k) {
        if (k == 0) {
            return 1;
        } else if (k % 2 == 1) {
            return mul(pow(n, k - 1), n);
        } else {
            long t = pow(n, k / 2);
            return mul(t, t);
        }
    }

    // Function to add two integers under modulo
    private static long add(long a, long b) {
        return (a + b) % MOD;
    }

    // Function to multiply two integers under modulo
    private static long mul(long a, long b) {
        return (a % MOD * b % MOD) % MOD;
    }

    // Function to divide two integers under modulo using modular multiplicative inverse
    private static long div(long a, long b) {
        return mul(a, pow(b, MOD - 2));
    }

    // Function to perform prime factorization of a number
    private static Map<Integer, Integer> primeFactorize(int n) {
        Map<Integer, Integer> res = new HashMap<>();
        // Check for factors from 2 up to the square root of n
        for (int i = 2; i * i <= n; i++) {
            // While i is a factor of n, divide n by i and count the occurrences
            while (n % i == 0) {
                n /= i;
                res.put(i, res.getOrDefault(i, 0) + 1);
            }
        }
        // If n is still greater than 1, it is a prime factor itself
        if (n > 1) {
            res.put(n, res.getOrDefault(n, 0) + 1);
        }
        return res;
    }
}
// <END-OF-CODE>
