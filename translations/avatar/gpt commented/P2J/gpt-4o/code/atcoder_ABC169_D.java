import java.util.*;
import java.io.*;

public class Main {
    // Define a large constant for infinity
    static final long INF = 999999999999999999L;

    // Define a modulus constant for calculations
    static final long MOD = 1000000007;

    // Function to perform prime factorization of a number
    static List<Integer> primeFactorize(int n) {
        List<Integer> factors = new ArrayList<>();
        // Divide n by 2 until it is odd
        while (n % 2 == 0) {
            factors.add(2);
            n /= 2;
        }

        // Check for odd factors from 3 upwards
        for (int f = 3; f * f <= n; f += 2) {
            while (n % f == 0) {
                factors.add(f);
                n /= f;
            }
        }

        // If n is still greater than 1, it is a prime factor
        if (n > 1) {
            factors.add(n);
        }

        return factors;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());

        // If n is 1, print 0 and exit
        if (n == 1) {
            System.out.println(0);
            return;
        }

        // Perform prime factorization on n
        List<Integer> fac_ = primeFactorize(n);

        // Count the occurrences of each prime factor
        Map<Integer, Integer> fac = new HashMap<>();
        for (int factor : fac_) {
            fac.put(factor, fac.getOrDefault(factor, 0) + 1);
        }

        // Initialize the answer variable
        long ans = 0;

        // Calculate the number of ways to express the prime factors
        for (Map.Entry<Integer, Integer> entry : fac.entrySet()) {
            int x = entry.getValue();
            // For each prime factor's exponent, calculate how many times it can be used
            for (int i = 1; i < 99999999; i++) {
                if (x >= i) {
                    x -= i;
                    ans++;
                } else {
                    break;
                }
            }
        }

        // Print the final answer
        System.out.println(ans);
    }
}
// <END-OF-CODE>
