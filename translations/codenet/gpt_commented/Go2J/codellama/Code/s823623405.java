
package main;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Read the number of elements
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        // Initialize a slice to store the input numbers and a map to store the maximum prime factors
        int[] as = new int[n];
        Map<Integer, Integer> ps = new HashMap<>();

        // Read each number and perform prime factorization
        for (int i = 0; i < n; i++) {
            as[i] = sc.nextInt();

            // Get the prime factors of the current number
            Map<Integer, Integer> ns = primeFactorize(as[i]);
            // Update the maximum count of each prime factor found
            for (Map.Entry<Integer, Integer> entry : ns.entrySet()) {
                ps.put(entry.getKey(), Math.max(ps.getOrDefault(entry.getKey(), 0), entry.getValue()));
            }
        }

        // Calculate the product of the maximum prime factors raised to their respective powers
        int x = 1;
        for (Map.Entry<Integer, Integer> entry : ps.entrySet()) {
            for (int i = 1; i <= entry.getValue(); i++) {
                x = mul(x, entry.getKey());
            }
        }

        // Calculate the final answer by summing the results of x divided by each input number
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = add(ans, div(x, as[i]));
        }

        // Print the final answer
        System.out.println(ans);
    }

    // Function to return the maximum of two integers
    public static int max(int a, int b) {
        return a > b ? a : b;
    }

    // Function to perform prime factorization of a number
    public static Map<Integer, Integer> primeFactorize(int n) {
        Map<Integer, Integer> res = new HashMap<>();
        // Check for factors from 2 up to the square root of n
        for (int i = 2; i*i <= n; i++) {
            // While i is a factor of n, divide n by i and count the occurrences
            while (n % i == 0) {
                n /= i;
                res.put(i, res.getOrDefault(i, 0) + 1);
            }
        }
        // If n is still greater than 1, it is a prime factor itself
        if (n != 1) {
            res.put(n, res.getOrDefault(n, 0) + 1);
        }
        return res;
    }

    // Define a constant for the modulo operation
    public static final int mod = 1000000007;

    // Function to compute n raised to the power of k under modulo
    public static int pow(int n, int k) {
        if (k == 0) {
            return 1;
        } else if (k % 2 == 1) {
            return pow(n, k - 1) * n % mod;
        } else {
            int t = pow(n, k / 2);
            return t * t % mod;
        }
    }

    // Function to add two integers under modulo
    public static int add(int a, int b) {
        return (a + b) % mod;
    }

    // Function to subtract two integers under modulo
    public static int sub(int a, int b) {
        return (a + mod - b) % mod;
    }

    // Function to multiply two integers under modulo
    public static int mul(int a, int b) {
        return a % mod * b % mod % mod;
    }

    // Function to divide two integers under modulo using modular multiplicative inverse
    public static int div(int a, int b) {
        return mul(a, pow(b, mod - 2));
    }
}

