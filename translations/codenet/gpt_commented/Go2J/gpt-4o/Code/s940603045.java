import java.util.*;
import java.io.*;

public class Main {
    // Direction vectors for 8 possible movements (up, down, left, right, and diagonals)
    static final int[] dx = {0, 1, 1, 1, 0, -1, -1, -1, 0};
    static final int[] dy = {1, 1, 0, -1, -1, -1, 0, 1, 0};

    // Define an infinite value for comparison
    static final int inf = Integer.MAX_VALUE;

    // Initialize a new scanner for input
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        // Read input as a string
        String N = scanner.nextLine();
        int n = 0; // Initialize sum of digits

        // Calculate the sum of digits in the input number
        for (char c : N.toCharArray()) {
            n += c - '0'; // Convert char to int and accumulate
        }

        // Convert the string input to an integer
        int m = Integer.parseInt(N);
        // Check if the number is divisible by the sum of its digits
        if (m % n == 0) {
            System.out.println("Yes"); // Print "Yes" if divisible
        } else {
            System.out.println("No"); // Print "No" if not divisible
        }
    }

    // Pair class to hold a pair of integers
    static class Pair {
        int a, b;

        Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }

    // Utility functions for various operations

    // Check if a value is within a range
    static boolean in(int c, int a, int z) {
        return c >= a && c < z;
    }

    // Check if a value is outside a range
    static boolean out(int c, int a, int z) {
        return !in(c, a, z);
    }

    // Convert boolean to integer (1 for true, 0 for false)
    static int btoi(boolean b) {
        return b ? 1 : 0;
    }

    // Convert integer to boolean (non-zero to true, zero to false)
    static boolean itob(int a) {
        return a != 0;
    }

    // Return the maximum value from a list of integers
    static int max(int... a) {
        int r = a[0];
        for (int value : a) {
            if (r < value) {
                r = value;
            }
        }
        return r;
    }

    // Return the minimum value from a list of integers
    static int min(int... a) {
        int r = a[0];
        for (int value : a) {
            if (r > value) {
                r = value;
            }
        }
        return r;
    }

    // Calculate the sum of a list of integers
    static int sum(int[] a) {
        int r = 0;
        for (int value : a) {
            r += value;
        }
        return r;
    }

    // Calculate the product of a list of integers
    static int pro(int[] a) {
        int r = a[0];
        for (int i = 1; i < a.length; i++) {
            r *= a[i];
        }
        return r;
    }

    // Fill an array with a specified value
    static int[] fill(int[] a, int n) {
        Arrays.fill(a, n);
        return a;
    }

    // Return the minimum and maximum of two integers
    static int[] minmax(int a, int b) {
        return new int[]{Math.min(a, b), Math.max(a, b)};
    }

    // Return the absolute value of an integer
    static int abs(int a) {
        return a < 0 ? -a : a;
    }

    // Calculate the ceiling of a division of two integers
    static int ceil(int a, int b) {
        return (a % b != 0) ? 1 : 0;
    }

    // Print an array of strings with space separation
    static void printStrings(String[] out) {
        System.out.println(String.join(" ", out));
    }

    // Print an array of integers with space separation
    static void printInts(int[] out) {
        System.out.println(Arrays.toString(out).replaceAll("[\\[\\],]", "").replaceAll(",", ""));
    }
}
// <END-OF-CODE>
