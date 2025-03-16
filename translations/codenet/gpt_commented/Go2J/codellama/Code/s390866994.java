
package main;

import java.util.Scanner;

public class Main {

    // Function to print output to the console
    public static void out(Object... x) {
        System.out.println(String.valueOf(x));
    }

    // Scanner for reading input from standard input
    public static Scanner sc = new Scanner(System.in);

    // Function to read an integer from input
    public static int getInt() {
        sc.next(); // Read the next token
        int i = Integer.parseInt(sc.next()); // Convert the token to an integer
        return i; // Return the integer
    }

    // Function to read a string from input
    public static String getString() {
        sc.next(); // Read the next token
        return sc.next(); // Return the string
    }

    // Basic utility functions for mathematical operations
    public static int max(int a, int b) {
        if (a > b) {
            return a; // Return a if it is greater than b
        }
        return b; // Otherwise, return b
    }

    public static int min(int a, int b) {
        if (a < b) {
            return a; // Return a if it is less than b
        }
        return b; // Otherwise, return b
    }

    public static int asub(int a, int b) {
        if (a > b) {
            return a - b; // Return the absolute difference if a is greater than b
        }
        return b - a; // Otherwise, return the absolute difference
    }

    public static int abs(int a) {
        if (a >= 0) {
            return a; // Return a if it is non-negative
        }
        return -a; // Otherwise, return the negation of a
    }

    public static void main(String[] args) {
        sc.useDelimiter("\\s+"); // Set the scanner to split input by words

        // Read the number of elements (N), maximum count (C), and time limit (K)
        int N = getInt();
        int C = getInt();
        int K = getInt();
        int[] t = new int[N]; // Create an array to hold the time values

        // Read N time values from input
        for (int i = 0; i < N; i++) {
            t[i] = getInt(); // Store each time value in the array
        }

        sort(t); // Sort the time values in ascending order

        // Initialize variables for counting groups and tracking the end time
        int ans = 1; // Start with one group
        int cnt = 1; // Count of elements in the current group
        int end = t[0] + K; // Calculate the end time for the first group

        // Iterate through the sorted time values
        for (int i = 1; i < N; i++) {
            // Check if we can add the current time to the current group
            if (cnt < C && t[i] <= end) {
                cnt++; // Increment the count of the current group
            } else {
                // Start a new group since the current time exceeds the end time
                cnt = 1; // Reset the count for the new group
                end = t[i] + K; // Update the end time for the new group
                ans++; // Increment the group count
            }
        }
        out(ans); // Output the total number of groups formed
    }

    // Sort the time values in ascending order
    public static void sort(int[] t) {
        for (int i = 0; i < t.length - 1; i++) {
            for (int j = i + 1; j < t.length; j++) {
                if (t[i] > t[j]) {
                    int temp = t[i];
                    t[i] = t[j];
                    t[j] = temp;
                }
            }
        }
    }
}

