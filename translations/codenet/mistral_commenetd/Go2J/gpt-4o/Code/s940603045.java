// Import necessary packages
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Random;

// Main class
public class Main {
    // Constants
    private static final int INF = Integer.MAX_VALUE; // Maximum signed integer value
    private static final Random rand = new Random(); // Random number generator

    // Directions for movement
    private static final int[] dx = {0, 1, 1, 1, 0, -1, -1, -1, 0};
    private static final int[] dy = {1, 1, 0, -1, -1, -1, 0, 1, 0};

    // Main method
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in)); // Buffered reader for input

        // Read input N as a string
        String N = reader.readLine();
        // Convert N to an integer
        int n = 0;
        // Iterate through each digit in the number N
        for (char c : N.toCharArray()) {
            n += c - '0'; // Convert each digit to an integer and add to the sum
        }
        // Convert N to an integer
        int m = Integer.parseInt(N);
        // Check if m is divisible by n
        if (m % n == 0) {
            System.out.println("Yes"); // Print "Yes" if m is divisible by n
        } else {
            System.out.println("No"); // Print "No" if m is not divisible by n
        }
    }

    // Pair class for storing two integers
    static class Pair {
        int a, b;

        Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }

    // Utility methods
    static boolean in(int c, int a, int z) {
        return c >= a && c < z; // Check if c is within the range [a, z)
    }

    static boolean out(int c, int a, int z) {
        return !in(c, a, z); // Check if c is outside the range [a, z)
    }

    static int btoi(boolean b) {
        return b ? 1 : 0; // Convert boolean to integer: 1 for true, 0 for false
    }

    static boolean itob(int a) {
        return a != 0; // Convert integer to boolean: true for non-zero, false for zero
    }

    static int max(int... a) {
        int r = a[0];
        for (int value : a) {
            if (r < value) {
                r = value; // Find the maximum integer among the given integers
            }
        }
        return r;
    }

    static int min(int... a) {
        int r = a[0];
        for (int value : a) {
            if (r > value) {
                r = value; // Find the minimum integer among the given integers
            }
        }
        return r;
    }

    static int sum(int[] a) {
        int r = 0;
        for (int value : a) {
            r += value; // Calculate the sum of all integers in the given array
        }
        return r;
    }

    static int pro(int[] a) {
        int r = a[0];
        for (int i = 1; i < a.length; i++) {
            r *= a[i]; // Calculate the product of all integers in the given array
        }
        return r;
    }

    static int[] fill(int[] a, int n) {
        for (int i = 0; i < a.length; i++) {
            a[i] = n; // Fill the given array with the given integer value
        }
        return a;
    }

    static int[] minmax(int a, int b) {
        return a > b ? new int[]{b, a} : new int[]{a, b}; // Return the minimum and maximum integers among the given integers
    }

    static int abs(int a) {
        return a < 0 ? -a : a; // Calculate the absolute value of an integer
    }
}
// <END-OF-CODE>
