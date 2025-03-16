
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.PriorityQueue;
import java.util.Random;
import java.util.Scanner;
import java.util.Stack;
import java.util.TreeMap;
import java.util.TreeSet;

/**
 * Main class to run the program.
 */
public class Main {
    // Static variable to hold the value of N.
    static int N;
    // Constant MOD value.
    static int MOD = (int) (1e9 + 7);

    /**
     * Main method where the program execution starts.
     * @param args Command line arguments.
     */
    public static void main(String args[]) {
        // Scanner to read input from the standard input stream.
        Scanner in = new Scanner(System.in);
        // PrintWriter to write output to the standard output stream.
        PrintWriter out = new PrintWriter(System.out);
        // Read the number of test cases.
        int t = in.nextInt();
        // Process each test case.
        while (t-- > 0) {
            // Read the values of n, a, and b.
            long n = in.nextInt();
            long a = in.nextInt();
            long b = in.nextInt();
            // Check if n is less than a.
            if (n < a) {
                out.println("No");
                continue;
            }
            // Check if a is equal to b.
            if (a == b) {
                if (n % a == 0) {
                    out.println("Yes");
                } else {
                    out.println("No");
                }
                continue;
            }
            // Calculate x as b / (b - a).
            long x = b / (b - a);
            // Check if n is greater than x * a.
            if (n > x * a) {
                out.println("Yes");
                continue;
            }
            // Perform binary search to find the minimum ans.
            long low = 1;
            long high = x + 1;
            long ans = 1;
            while (low <= high) {
                long mid = (low + high) / 2;
                if (mid * a < n) {
                    low = mid + 1;
                } else {
                    ans = mid;
                    high = mid - 1;
                }
            }
            // Check if n lies between (ans - 1) * b and ans * a.
            if (n > (ans - 1) * b && n < ans * a) {
                out.println("No");
            } else {
                out.println("Yes");
            }
        }
        // Close the PrintWriter to flush the output.
        out.close();
    }
}

