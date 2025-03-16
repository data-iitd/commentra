// Package main contains the main function for solving the problem.
import java.util.Scanner;

// The main class is the entry point of the program.
public class Main {
    // The main function is the entry point of the program.
    public static void main(String[] args) {
        // Initialize a new Scanner object for reading input.
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
            total = total % (pow(10, 9) + 7);
        }

        // Print the result to the standard output.
        System.out.println(total);
    }

    // The combi function calculates the number of combinations of 'n' taken 'k' at a time using a simplified formula.
    public static long combi(int n, int k) {
        // Calculate the minimum and maximum number of combinations.
        long min = (long)(k - 1) * k / 2;
        long max = (long)(2 * n - k + 1) * k / 2;
        // Return the difference between the maximum and minimum number of combinations.
        return max - min + 1;
    }

    // Util functions for performing basic mathematical operations.

    // Pow returns the result of raising the base to the given exponent.
    public static int pow(int base, int exponent) {
        // Initialize the answer with 1.
        int answer = 1;
        // Multiply the answer with the base for each bit in the exponent.
        for (int i = 0; i < exponent; i++) {
            answer *= base;
        }
        // Return the answer.
        return answer;
    }
}

// <END-OF-CODE>
