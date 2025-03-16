// Java:
// This line is a Java comment to download the problem statement from AtCoder.
// It is not necessary to understand its functionality for the given code.

package main;

import java.util.*;
import java.io.*;

// Define a custom scanner type for reading input efficiently.
class scanner {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public scanner(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = new StringTokenizer("");
    }

    public String next() {
        while (!tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public int[] nextIntArr(int n) {
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = nextInt();
        }
        return arr;
    }
}

// Define the main function to solve the problem.
public class Main {
    public static void main(String[] args) {
        // Initialize a scanner to read input from standard input.
        scanner sc = new scanner(System.in);
        // Read the number of test cases and iterate through each test case.
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            // Read the number of heights and initialize an array to store them.
            int[] heights = sc.nextIntArr(n);
            // Call the solve function and print the result.
            System.out.println(solve(n, heights));
        }
    }

    // Define a helper function for calculating absolute value.
    public static int iabs(int x) {
        if (x < 0) {
            return -x;
        }
        return x;
    }

    // Define the main function to solve the problem.
    public static int solve(int n, int[] heights) {
        // Initialize a table t to store the minimum cost to reach each index.
        int[] t = new int[n + 1];
        // Set the initial value of the table to maximum integer.
        Arrays.fill(t, Integer.MAX_VALUE);
        // Set the base case, the cost to reach index 0 is 0.
        t[0] = 0;

        // Iterate through the array from index 1 to n-1.
        for (int i = 1; i < n; i++) {
            // Calculate the cost to reach index i from the previous index.
            int prevIndexCost = t[i - 1];
            // Update the cost to reach index i if the difference between heights is beneficial.
            int heightsDiff = heights[i] - heights[i - 1];
            if (heightsDiff < 0) {
                prevIndexCost += heightsDiff;
            } else {
                prevIndexCost -= heightsDiff;
            }
            // Update the cost to reach index i if the difference between previous index is beneficial.
            int prevIndex = i - 2;
            if (prevIndex >= 0) {
                int prevPrevIndexCost = t[prevIndex];
                heightsDiff = heights[i] - heights[prevIndex];
                if (heightsDiff < 0) {
                    prevPrevIndexCost += heightsDiff;
                } else {
                    prevPrevIndexCost -= heightsDiff;
                }
                if (prevIndexCost < t[i]) {
                    t[i] = prevIndexCost;
                }
                if (prevPrevIndexCost < t[i]) {
                    t[i] = prevPrevIndexCost;
                }
            } else {
                // If the difference between previous index is not valid, only update the cost if the current difference is beneficial.
                if (prevIndexCost < t[i]) {
                    t[i] = prevIndexCost;
                }
            }
        }

        // Return the minimum cost to reach the last index.
        return t[n - 1];
    }
}

// The following comment can be added at the end of the code.

