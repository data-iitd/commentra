package main;

import java.io.*;
import java.util.*;

public class Main {

    // Function to get a new scanner from a file pointer
    public static Scanner getScanner(File fp) {
        Scanner scanner = new Scanner(fp);
        scanner.useDelimiter("[^0-9]+");
        return scanner;
    }

    // Function to read the next string from the scanner
    public static String getNextString(Scanner scanner) {
        return scanner.next();
    }

    // Function to read the next integer from the scanner
    public static int getNextInt(Scanner scanner) {
        return scanner.nextInt();
    }

    // Main function to read input and process it
    public static void main(String[] args) {
        // Open the standard input stream if no file is provided as an argument
        File fp = new File("input.txt");
        if (args.length > 0) {
            fp = new File(args[0]);
        }
        Scanner scanner = getScanner(fp);
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        // Read the number of test cases from the input
        int n = getNextInt(scanner);

        // Initialize a slice to store the prefix sum of squares of elements
        int[] mm = new int[n+1];

        // Initialize a 2D slice to store the dynamic programming table
        int[][] dp = new int[n+1][n+1];

        // Read the elements and their prefix sum of squares from the input
        for (int i = 0; i < n; i++) {
            // Read the next integer as the current element
            mm[i+1] = getNextInt(scanner);
            // Read the next integer as the next element's prefix sum of square
            mm[i+1] += mm[i] * mm[i];
        }

        // Process the dynamic programming table for all subarrays of given size
        for (int l = 2; l <= n; l++) {
            for (int i = 1; i <= n-l+1; i++) {
                int j = i + l - 1;
                // Iterate through all subarrays of the current subarray
                for (int k = i; k <= j-1; k++) {
                    // Calculate the sum of squares of elements in the current subarray
                    int d = dp[i][k] + dp[k+1][j] + mm[i-1]*mm[k]*mm[j];
                    // Update the dynamic programming table if a larger sum is found
                    if (dp[i][j] == 0 || dp[i][j] > d) {
                        dp[i][j] = d;
                    }
                }
            }
        }

        // Print the result for the given input
        System.out.println(dp[1][n]);

        // End of the code

    }

}

