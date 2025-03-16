import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation
    private Main() {
    }

    // Cache to store previously computed Fibonacci numbers for memoization
    static final Map<Integer, Integer> CACHE = new HashMap<>();

    // Method to compute Fibonacci number using memoization
    public static int fibMemo(int n) {
        // Validate input to ensure it is non-negative
        if (n < 0) {
            throw new IllegalArgumentException("Input n must be non-negative");
        }
        // Check if the result is already cached
        if (CACHE.containsKey(n)) {
            return CACHE.get(n);
        }
        int f;
        // Base cases for Fibonacci sequence
        if (n <= 1) {
            f = n;
        } else {
            // Recursive calls to compute Fibonacci number
            f = fibMemo(n - 1) + fibMemo(n - 2);
            // Store the computed result in the cache
            CACHE.put(n, f);
        }
        return f;
    }

    // Method to compute Fibonacci number using Bottom-Up dynamic programming
    public static int fibBotUp(int n) {
        // Validate input to ensure it is non-negative
        if (n < 0) {
            throw new IllegalArgumentException("Input n must be non-negative");
        }
        // Map to store Fibonacci numbers computed in a bottom-up manner
        Map<Integer, Integer> fib = new HashMap<>();
        // Iteratively compute Fibonacci numbers from 0 to n
        for (int i = 0; i <= n; i++) {
            int f;
            // Base cases for Fibonacci sequence
            if (i <= 1) {
                f = i;
            } else {
                // Use previously computed values to calculate the current Fibonacci number
                f = fib.get(i - 1) + fib.get(i - 2);
            }
            // Store the computed Fibonacci number in the map
            fib.put(i, f);
        }
        // Return the Fibonacci number for n
        return fib.get(n);
    }

    // Method to compute Fibonacci number using an optimized iterative approach
    public static int fibOptimized(int n) {
        // Validate input to ensure it is non-negative
        if (n < 0) {
            throw new IllegalArgumentException("Input n must be non-negative");
        }
        // Handle the base case for Fibonacci sequence
        if (n == 0) {
            return 0;
        }
        // Variables to store the last two Fibonacci numbers
        int prev = 0;
        int res = 1;
        int next;
        // Iteratively compute Fibonacci numbers up to n
        for (int i = 2; i <= n; i++) {
            next = prev + res; // Calculate the next Fibonacci number
            prev = res;        // Update previous Fibonacci number
            res = next;       // Update current Fibonacci number
        }
        // Return the Fibonacci number for n
        return res;
    }

    // Method to compute Fibonacci number using Binet's formula
    public static int fibBinet(int n) {
        // Validate input to ensure it is non-negative
        if (n < 0) {
            throw new IllegalArgumentException("Input n must be non-negative");
        }
        // Calculate the golden ratio and its square root
        double squareRootOf5 = Math.sqrt(5);
        double phi = (1 + squareRootOf5) / 2;
        // Use Binet's formula to compute the Fibonacci number
        return (int) ((Math.pow(phi, n) - Math.pow(-phi, -n)) / squareRootOf5);
    }

    // Main method to execute the program
    public static void main(String[] args) {
        // Create a scanner to read input from the user
        Scanner scanner = new Scanner(System.in);
        // Read the integer input for which Fibonacci number is to be computed
        int n = scanner.nextInt();
        // Print the Fibonacci number computed using different methods
        System.out.println("Main number using Memoization: " + fibMemo(n));
        System.out.println("Main number using Bottom-Up: " + fibBotUp(n));
        System.out.println("Main number using Optimized Approach: " + fibOptimized(n));
        System.out.println("Main number using Binet's Formula: " + fibBinet(n));
        // Close the scanner to prevent resource leaks
        scanner.close();
    }
}
