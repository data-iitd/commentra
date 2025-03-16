import java.util.*;
import java.io.*;

public class Main {
    // Constants for modulo value
    private static final int MOD = 1000000007;

    // Main function
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Read an integer N from input
        int N = sc.nextInt();
        // Calculate the integer square root of N
        int sqrtN = (int) Math.sqrt(N);

        // Initialize min to N, which will hold the minimum value found
        int min = N;
        // Iterate through all possible divisors of N
        for (int i = 1; i <= sqrtN; i++) {
            // If i is not a divisor of N, skip to the next iteration
            if (N % i != 0) {
                continue;
            }

            // Calculate the value based on the divisor and its complement
            int num = i + (N / i) - 2;
            // Update min if the new value is smaller
            if (num < min) {
                min = num;
            }
        }

        // Print the minimum value found
        System.out.println(min);
    }

    // Function to calculate x % mod
    private static int calcMod(int x) {
        return x % MOD;
    }

    // Function to compute (n^p) % mod using exponentiation by squaring
    private static int powMod(int n, int p) {
        if (p == 0) {
            return 1;
        } else if (p % 2 == 0) {
            int t = powMod(n, p / 2);
            return calcMod(t * t);
        } else {
            return calcMod(n * powMod(n, p - 1));
        }
    }

    // Function to find the minimum value among a variable number of integers
    private static int min(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("function min() requires at least one argument.");
        }
        int res = nums[0];
        for (int num : nums) {
            res = Math.min(res, num);
        }
        return res;
    }

    // Function to find the maximum value among a variable number of integers
    private static int max(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("function max() requires at least one argument.");
        }
        int res = nums[0];
        for (int num : nums) {
            res = Math.max(res, num);
        }
        return res;
    }

    // Function to check if a number is prime
    private static boolean isPrime(int n) {
        if (n < 2) {
            return false;
        } else if (n == 2) {
            return true;
        } else if (n % 2 == 0) {
            return false;
        }

        // Check for factors from 3 to the square root of n
        int sqrtN = (int) Math.sqrt(n);
        for (int i = 3; i <= sqrtN; i += 2) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }

    // Function to reverse a string
    private static String reverse(String s) {
        return new StringBuilder(s).reverse().toString();
    }

    // Function to print an integer array in a formatted way
    private static void printIntArray(int[] array) {
        System.out.println(Arrays.toString(array).substring(1, Arrays.toString(array).length() - 1));
    }
}

// <END-OF-CODE>
