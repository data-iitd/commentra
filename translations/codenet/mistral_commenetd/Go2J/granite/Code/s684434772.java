
// Package main contains the main function for solving the problem.
package main;

import java.util.*;
import java.io.*;

// The main function is the entry point of the program.
public class s684434772{
    public static void main(String[] args) {
        // Initialize a new Scanner object named'sc'.
        Scanner sc = new Scanner(System.in);

        // Read 'n' and 'k' from the standard input.
        int n = sc.nextInt();
        int k = sc.nextInt();

        // Initialize a variable 'total' to store the sum of combinations.
        long total = 0;

        // Calculate the sum of combinations of 'n' taken 'i' at a time, where 'i' ranges from 'k' to 'n+1'.
        for (int i = k; i <= n + 1; i++) {
            // Calculate the number of combinations using the combi function.
            long comb = combi(n, i);
            // Add the number of combinations to the 'total' variable.
            total += comb;
            // Apply modulo operation to reduce the size of the number.
            total = total % (long)Math.pow(10, 9) + 7;
        }

        // Print the result to the standard output.
        System.out.println(total);
    }

    // The combi function calculates the number of combinations of 'n' taken 'k' at a time using a simplified formula.
    public static long combi(int n, int k) {
        // Calculate the minimum and maximum number of combinations.
        long min = (long)k * (k - 1) / 2;
        long max = (long)(2 * n - k + 1) * k / 2;
        // Return the difference between the maximum and minimum number of combinations.
        return max - min + 1;
    }

    // Util functions for performing basic mathematical operations.

    // Abs returns the absolute value of a given integer.
    public static int Abs(int x) {
        // If the number is positive, return the number itself.
        // Otherwise, return the negative of the number.
        if (x >= 0) {
            return x;
        }
        return -x;
    }

    // Min returns the minimum value among the given integers.
    public static int Min(int... values) {
        // Initialize the minimum value with the first integer.
        int min = values[0];
        // Compare each integer with the minimum value and update the minimum value if necessary.
        for (int v : values) {
            if (v < min) {
                min = v;
            }
        }
        // Return the minimum value.
        return min;
    }

    // Max returns the maximum value among the given integers.
    public static int Max(int... values) {
        // Initialize the maximum value with the first integer.
        int max = values[0];
        // Compare each integer with the maximum value and update the maximum value if necessary.
        for (int v : values) {
            if (v > max) {
                max = v;
            }
        }
        // Return the maximum value.
        return max;
    }

    // Pow returns the result of raising the base to the given exponent.
    public static int Pow(int base, int exponent) {
        // Initialize the answer with 1.
        int answer = 1;
        // Multiply the answer with the base for each bit in the exponent.
        for (int i = 0; i < exponent; i++) {
            answer *= base;
        }
        // Return the answer.
        return answer;
    }

    // Abs64 returns the absolute value of a given integer64.
    public static long Abs64(long x) {
        // If the number is positive, return the number itself.
        // Otherwise, return the negative of the number.
        if (x >= 0) {
            return x;
        }
        return -x;
    }

    // Min64 returns the minimum value among the given integer64s.
    public static long Min64(long... values) {
        // Initialize the minimum value with the first integer.
        long min = values[0];
        // Compare each integer with the minimum value and update the minimum value if necessary.
        for (long v : values) {
            if (v < min) {
                min = v;
            }
        }
        // Return the minimum value.
        return min;
    }

    // Max64 returns the maximum value among the given integer64s.
    public static long Max64(long... values) {
        // Initialize the maximum value with the first integer.
        long max = values[0];
        // Compare each integer with the maximum value and update the maximum value if necessary.
        for (long v : values) {
            if (v > max) {
                max = v;
            }
        }
        // Return the maximum value.
        return max;
    }

    // Pow64 returns the result of raising the base to the given exponent.
    public static long Pow64(long base, int exponent) {
        // Initialize the answer with 1.
        long answer = 1;
        // Multiply the answer with the base for each bit in the exponent.
        for (int i = 0; i < exponent; i++) {
            answer *= base;
        }
        // Return the answer.
        return answer;
    }

    // Scanner struct is used to read input from the standard input.
    public static class Scanner {
        // BufferedReader is used to read input from the standard input.
        BufferedReader br;
        // StringTokenizer is used to tokenize the input.
        StringTokenizer st;

        // Initialize a new Scanner object with the standard input.
        public Scanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
            st = new StringTokenizer("");
        }

        // Read a string from the standard input.
        public String next() {
            // If there are no more tokens, read a new line of input.
            if (!st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            // Return the next token.
            return st.nextToken();
        }

        // Read an integer from the standard input.
        public int nextInt() {
            return Integer.parseInt(next());
        }

        // Read an integer64 from the standard input.
        public long nextLong() {
            return Long.parseLong(next());
        }
    }
}

// Translate the above Java code to C++ and end with comment "