import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation of the class
    private Main() {
    }

    // Declare a static final Map to store the Fibonacci numbers for memoization
    static final Map<Integer, Integer> CACHE = new HashMap<>();

    // Memoization method to calculate the nth Fibonacci number
    public static int fibMemo(int n) {
        // Check if the input is valid
        if (n < 0) {
            throw new IllegalArgumentException("Input n must be non-negative");
        }

        // Check if the result for the given input is already present in the cache
        if (CACHE.containsKey(n)) {
            return CACHE.get(n);
        }

        int f;

        // Base cases: Fibonacci numbers for 0 and 1
        if (n <= 1) {
            f = n;
        } else {
            // Recursive calls to calculate the previous two Fibonacci numbers
            f = fibMemo(n - 1) + fibMemo(n - 2);

            // Store the result in the cache for future use
            CACHE.put(n, f);
        }

        // Return the calculated Fibonacci number
        return f;
    }

    // Bottom-Up method to calculate the nth Fibonacci number
    public static int fibBotUp(int n) {
        // Check if the input is valid
        if (n < 0) {
            throw new IllegalArgumentException("Input n must be non-negative");
        }

        // Initialize an empty HashMap to store the Fibonacci numbers
        Map<Integer, Integer> fib = new HashMap<>();

        // Iterate through the numbers from 0 to n and calculate the Fibonacci numbers
        for (int i = 0; i <= n; i++) {
            int f;

            // Base cases: Fibonacci numbers for 0 and 1
            if (i <= 1) {
                f = i;
            } else {
                // Calculate the previous two Fibonacci numbers
                f = fib.get(i - 1) + fib.get(i - 2);

                // Store the calculated Fibonacci number in the HashMap
                fib.put(i, f);
            }
        }

        // Return the calculated Fibonacci number for the given input
        return fib.get(n);
    }

    // Optimized method to calculate the nth Fibonacci number using O(1) space complexity
    public static int fibOptimized(int n) {
        // Check if the input is valid
        if (n < 0) {
            throw new IllegalArgumentException("Input n must be non-negative");
        }

        if (n == 0) {
            // Base case: Fibonacci number for 0 is 0
            return 0;
        }

        int prev = 0;
        int res = 1;
        int next;

        // Iterate through the numbers from 2 to n and calculate the Fibonacci numbers
        for (int i = 2; i <= n; i++) {
            next = prev + res;
            prev = res;
            res = next;
        }

        // Return the calculated Fibonacci number for the given input
        return res;
    }

    // Method to calculate the nth Fibonacci number using Binet's Formula
    public static int fibBinet(int n) {
        // Check if the input is valid
        if (n < 0) {
            throw new IllegalArgumentException("Input n must be non-negative");
        }

        double squareRootOf5 = Math.sqrt(5);
        double phi = (1 + squareRootOf5) / 2;

        // Calculate the nth Fibonacci number using Binet's Formula
        return (int) ((Math.pow(phi, n) - Math.pow(-phi, -n)) / squareRootOf5);
    }

    // Main method to read the input and print the results
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the input from the user
        int n = scanner.nextInt();

        // Print the results for the given input using Memoization, Bottom-Up, Optimized Approach, and Binet's Formula
        System.out.println("Main number using Memoization: " + fibMemo(n));
        System.out.println("Main number using Bottom-Up: " + fibBotUp(n));
        System.out.println("Main number using Optimized Approach: " + fibOptimized(n));
        System.out.println("Main number using Binet's Formula: " + fibBinet(n));

        // Close the scanner
        scanner.close();
    }
}
