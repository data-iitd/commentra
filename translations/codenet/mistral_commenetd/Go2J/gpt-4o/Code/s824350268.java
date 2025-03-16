import java.util.*;
import java.io.*;

public class Main {
    // Constants definition
    private static final int INITIAL_BUF_SIZE = 10000;
    private static final int MAX_BUF_SIZE = 1000000;
    private static final int MOD = (int) (1e9 + 7);

    // Main function
    public static void main(String[] args) {
        // Read the first integer from the standard input
        Scanner sc = new Scanner(System.in);
        int N = getInt(sc);

        // Calculate the square root of N
        int sqrtN = (int) Math.sqrt(N);

        // Initialize the minimum number with N
        int min = N;

        // Iterate through all numbers from 1 to the square root of N
        for (int i = 1; i <= sqrtN; i++) {
            // Check if N is divisible by i
            if (N % i != 0) {
                continue;
            }

            // Calculate the number of divisors of i and N
            int num = i + (N / i) - 2;

            // Update the minimum number if the current number is smaller
            if (num < min) {
                min = num;
            }
        }

        // Print the minimum number
        System.out.println(min);
    }

    // Helper function for reading integers from the standard input
    private static int getInt(Scanner sc) {
        return sc.nextInt();
    }

    // Helper functions for basic arithmetic operations
    private static int abs(int a) {
        return Math.abs(a);
    }

    private static int pow(int p, int q) {
        return (int) Math.pow(p, q);
    }

    private static int powMod(int n, int p) {
        // Base case: if p is 0, return 1
        if (p == 0) {
            return 1;
        } else if (p % 2 == 0) {
            // Recursive case: if p is even, square the base and recursively call powMod
            int t = powMod(n, p / 2);
            return calcMod(t * t);
        } else {
            // Recursive case: if p is odd, multiply the base with the result of recursively calling powMod with p-1
            return calcMod(n * powMod(n, p - 1));
        }
    }

    // Helper function for calculating the modulo operation
    private static int calcMod(int x) {
        // Calculate the modulo of x with the modulus constant
        return x % MOD;
    }

    // Helper functions for finding the minimum and maximum values
    private static int min(int... nums) {
        // Base case: if there are no numbers, throw an exception
        if (nums.length == 0) {
            throw new IllegalArgumentException("Function min() requires at least one argument.");
        }

        // Initialize the minimum value with the first number
        int res = nums[0];

        // Iterate through all numbers and update the minimum value if necessary
        for (int num : nums) {
            res = Math.min(res, num);
        }

        // Return the minimum value
        return res;
    }

    private static int max(int... nums) {
        // Base case: if there are no numbers, throw an exception
        if (nums.length == 0) {
            throw new IllegalArgumentException("Function max() requires at least one argument.");
        }

        // Initialize the maximum value with the first number
        int res = nums[0];

        // Iterate through all numbers and update the maximum value if necessary
        for (int num : nums) {
            res = Math.max(res, num);
        }

        // Return the maximum value
        return res;
    }

    // Helper function for checking if a number is prime
    private static boolean isPrime(int n) {
        // Base case: if n is less than 2, it is not prime
        if (n < 2) {
            return false;
        }

        // Base case: if n is 2, it is prime
        if (n == 2) {
            return true;
        }

        // Base case: if n is even, it is not prime
        if (n % 2 == 0) {
            return false;
        }

        // Calculate the square root of n and iterate through all odd numbers from 3 to the square root of n
        int sqrtN = (int) Math.sqrt(n);
        for (int i = 3; i <= sqrtN; i += 2) {
            // If n is divisible by i, it is not prime
            if (n % i == 0) {
                return false;
            }
        }

        // If we have reached here, n is prime
        return true;
    }
}

// <END-OF-CODE>
