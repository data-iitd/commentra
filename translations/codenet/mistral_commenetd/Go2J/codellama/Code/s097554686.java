// Package declaration and importing required library
package main;

// Importing required library
import java.util.Scanner;

// Function definition for main function
public class Main {
    // Main function
    public static void main(String[] args) {
        // Variable declaration and initialization for number of queries and time interval
        int n, t;

        // Initializing memory slice with zero values
        int[] mem = new int[100001];

        // Reading input values for number of queries and time interval
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        t = sc.nextInt();

        // Iterating through each query in the input
        for (int i = 0; i < n; i++) {
            // Reading input values for start and end time intervals
            int l = sc.nextInt();
            int r = sc.nextInt();

            // Updating memory slice values for start and end time intervals
            mem[l] += 1;
            mem[r] -= 1;
        }

        // Initializing variable for answer
        int ans = mem[0];

        // Iterating through each time interval in the memory slice
        for (int i = 1; i < t + 1; i++) {
            // Updating memory slice values by adding previous value
            mem[i] += mem[i - 1];

            // Updating answer if current memory slice value is greater than previous answer
            if (ans < mem[i]) {
                ans = mem[i];
            }
        }

        // Printing the final answer
        System.out.println(ans);
    }
}

