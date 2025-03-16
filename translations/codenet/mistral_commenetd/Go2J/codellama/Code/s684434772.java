
// Package main contains the main function for solving the problem.
package main;

// The main function is the entry point of the program.
public class Main {
    // The main function is the entry point of the program.
    public static void main(String[] args) {
        // Initialize a new Scanner object named 'sc'.
        Scanner sc = new Scanner();

        // Read 'n' and 'k' from the standard input.
        int n = sc.readInt();
        int k = sc.readInt();

        // Initialize a variable 'total' to store the sum of combinations.
        long total = 0;

        // Calculate the sum of combinations of 'n' taken 'i' at a time, where 'i' ranges from 'k' to 'n+1'.
        for (int i = k; i <= n+1; i++) {
            // Calculate the number of combinations using the combi function.
            long comb = combi(n, i);
            // Add the number of combinations to the 'total' variable.
            total += comb;
            // Apply modulo operation to reduce the size of the number.
            total = total % (Pow64(10, 9) + 7);
        }

        // Print the result to the standard output.
        System.out.println(total);
    }

    // The combi function calculates the number of combinations of 'n' taken 'k' at a time using a simplified formula.
    public static long combi(int n, int k) {
        // Calculate the minimum and maximum number of combinations.
        long min = (long)k * (long)(k-1) / 2;
        long max = (long)(2*n-k+1) * (long)k / 2;
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
        // bufio.Scanner is used to read input from the standard input.
        private java.util.Scanner bufScanner;

        // NewScanner initializes a new Scanner object.
        public Scanner() {
            // Initialize a new bufio.Scanner object named 'bufSc'.
            bufScanner = new java.util.Scanner(System.in);
            // Set the splitting function of bufio.Scanner to scan words.
            bufScanner.useDelimiter("\\s+");
        }

        // ReadString reads a string from the standard input.
        public String readString() {
            // Read a word from the standard input using bufio.Scanner.
            java.util.Scanner bufSc = bufScanner;
            bufSc.next();
            // Return the read word as a string.
            return bufSc.next();
        }

        // ReadInt reads an integer from the standard input.
        public int readInt() {
            // Read a word from the standard input using bufio.Scanner.
            java.util.Scanner bufSc = bufScanner;
            bufSc.next();
            // Convert the read word to an integer using Integer.parseInt.
            int num = Integer.parseInt(bufSc.next());
            // Return the read integer.
            return num;
        }

        // ReadInt64 reads an integer64 from the standard input.
        public long readInt64() {
            // Read a word from the standard input using bufio.Scanner.
            java.util.Scanner bufSc = bufScanner;
            bufSc.next();
            // Convert the read word to an integer64 using Long.parseLong.
            long num = Long.parseLong(bufSc.next());
            // Return the read integer64.
            return num;
        }
    }
}

