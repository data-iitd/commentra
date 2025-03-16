// ProblemB.java

import java.util.*;
import java.io.*;

// Define a constant for modulus operation
class Constants {
    static final int constMod = (int) 1e9 + 7;
}

// Main class
public class ProblemB {
    // Initialize scanner and writer for input and output
    static Scanner sc = new Scanner(System.in);
    static PrintWriter wr = new PrintWriter(System.out);

    // -----------------------------------------

    // getInt reads a single integer from input
    static int getInt() {
        return sc.nextInt();
    }

    // getIntArray reads n integers from input and returns them as an array
    static int[] getIntArray(int n) {
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = getInt();
        }
        return arr;
    }

    // -----------------------------------------

    // solve function implements the main logic of the problem
    static void solve() {
        // Read n and m from input
        int n = getInt();
        int m = getInt();
        // Read n integers into array a
        int[] a = getIntArray(n);

        // Calculate the sum of all elements in a
        int sum = 0;
        for (int v : a) {
            sum += v;
        }

        // Count how many elements in a meet the required rate
        int count = 0;
        double rate = (double) sum / (4 * m);
        for (int v : a) {
            if ((double) v >= rate) {
                count++;
            }
        }

        // Output "Yes" if count is greater than or equal to m, otherwise "No"
        if (count >= m) {
            wr.println("Yes");
        } else {
            wr.println("No");
        }
    }

    // -----------------------------------------

    // main function initializes the program and calls solve
    public static void main(String[] args) {
        // Call the solve function to execute the main logic
        solve();
        // Flush the writer to output results
        wr.flush();
    }
}

// <END-OF-CODE>
