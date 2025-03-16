// This line is a Go generate command to download the problem statement from AtCoder.
// It is not necessary to understand its functionality for the given code.

import java.util.Scanner;

public class Main {
    // Define a helper function for calculating absolute value.
    private static int iabs(int x) {
        return x < 0 ? -x : x;
    }

    // Define the main function to solve the problem.
    private static int solve(int n, int[] heights) {
        // Initialize a table t to store the minimum cost to reach each index.
        int[] t = new int[n + 1];
        // Set the initial value of the table to maximum integer.
        for (int i = 0; i < t.length; i++) {
            t[i] = Integer.MAX_VALUE;
        }
        // Set the base case, the cost to reach index 0 is 0.
        t[0] = 0;

        // Iterate through the array from index 1 to n-1.
        for (int i = 1; i < n; i++) {
            // Calculate the cost to reach index i from the previous index.
            int prevIndexCost = t[i - 1];
            // Update the cost to reach index i if the difference between heights is beneficial.
            if (heights[i] - heights[i - 1] < 0) {
                prevIndexCost += heights[i] - heights[i - 1];
            } else {
                prevIndexCost -= heights[i] - heights[i - 1];
            }
            // Update the cost to reach index i if the difference between previous index is beneficial.
            if (i - 2 >= 0) {
                int prevPrevIndexCost = t[i - 2];
                if (heights[i] - heights[i - 2] < 0) {
                    prevPrevIndexCost += heights[i] - heights[i - 2];
                } else {
                    prevPrevIndexCost -= heights[i] - heights[i - 2];
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

    // Define the main function to read input and call the solve function.
    public static void main(String[] args) {
        // Initialize a scanner to read input from standard input.
        Scanner sc = new Scanner(System.in);
        // Read the number of test cases.
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            // Read the number of heights and initialize an array to store them.
            int m = sc.nextInt();
            int[] heights = new int[m];
            for (int j = 0; j < m; j++) {
                heights[j] = sc.nextInt();
            }
            // Call the solve function and print the result.
            int ans = solve(m, heights);
            System.out.println(ans);
        }
        sc.close();
    }
}

// <END-OF-CODE>
