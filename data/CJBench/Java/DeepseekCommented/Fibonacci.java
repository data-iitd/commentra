
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
public final class Main {
    private Main() {
    }
    // Cache for memoization
    static final Map<Integer, Integer> CACHE = new HashMap<>();
    // Computes the Fibonacci number using memoization
    public static int fibMemo(int n) {
        if (n < 0) {
            throw new IllegalArgumentException("Input n must be non-negative");
        }
        // Check if the result is already in the cache
        if (CACHE.containsKey(n)) {
            return CACHE.get(n);
        }
        int f;
        // Base cases for Fibonacci sequence
        if (n <= 1) {
            f = n;
        } else {
            // Recursive call to compute Fibonacci number
            f = fibMemo(n - 1) + fibMemo(n - 2);
            // Store the computed Fibonacci number in the cache
            CACHE.put(n, f);
        }
        return f;
    }
    // Computes the Fibonacci number using a bottom-up approach
    public static int fibBotUp(int n) {
        if (n < 0) {
            throw new IllegalArgumentException("Input n must be non-negative");
        }
        // Map to store computed Fibonacci numbers
        Map<Integer, Integer> fib = new HashMap<>();
        for (int i = 0; i <= n; i++) {
            int f;
            // Base cases for Fibonacci sequence
            if (i <= 1) {
                f = i;
            } else {
                // Compute Fibonacci number using previously computed values
                f = fib.get(i - 1) + fib.get(i - 2);
            }
            // Store the computed Fibonacci number in the map
            fib.put(i, f);
        }
        return fib.get(n);
    }
    // Computes the Fibonacci number using an optimized iterative approach
    public static int fibOptimized(int n) {
        if (n < 0) {
            throw new IllegalArgumentException("Input n must be non-negative");
        }
        // Handle the base case where n is 0
        if (n == 0) {
            return 0;
        }
        int prev = 0;
        int res = 1;
        int next;
        // Iterate to compute the Fibonacci number
        for (int i = 2; i <= n; i++) {
            next = prev + res;
            prev = res;
            res = next;
        }
        return res;
    }
    // Computes the Fibonacci number using Binet's formula
    public static int fibBinet(int n) {
        if (n < 0) {
            throw new IllegalArgumentException("Input n must be non-negative");
        }
        double squareRootOf5 = Math.sqrt(5);
        double phi = (1 + squareRootOf5) / 2;
        return (int) ((Math.pow(phi, n) - Math.pow(-phi, -n)) / squareRootOf5);
    }
    // Main method to read input and print Fibonacci numbers
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        System.out.println("Fibonacci number using Memoization: " + fibMemo(n));
        System.out.println("Fibonacci number using Bottom-Up: " + fibBotUp(n));
        System.out.println("Fibonacci number using Optimized Approach: " + fibOptimized(n));
        System.out.println("Fibonacci number using Binet's Formula: " + fibBinet(n));
        scanner.close();
    }
}

These comments provide a clear understanding of each part of the code, making it easier to understand and maintain.