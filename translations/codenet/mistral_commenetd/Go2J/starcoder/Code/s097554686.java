// Package declaration and importing required library
package main;

import java.util.*;

// Class declaration
public class Main {

    // Function definition for main function
    public static void main(String[] args) {
        // Creating object for Scanner class
        Scanner input = new Scanner(System.in);

        // Reading input values for number of queries and time interval
        int n = input.nextInt();
        int t = input.nextInt();

        // Creating object for array list
        ArrayList<Integer> mem = new ArrayList<Integer>();

        // Initializing memory slice with zero values
        for (int i = 0; i < size; i++) {
            mem.add(0);
        }

        // Iterating through each query in the input
        for (int i = 0; i < n; i++) {
            // Reading input values for start and end time intervals
            int l = input.nextInt();
            int r = input.nextInt();

            // Updating memory slice values for start and end time intervals
            mem.set(l, mem.get(l) + 1);
            mem.set(r, mem.get(r) - 1);
        }

        // Initializing variable for answer
        int ans = mem.get(0);

        // Iterating through each time interval in the memory slice
        for (int i = 1; i < t + 1; i++) {
            // Updating memory slice values by adding previous value
            mem.set(i, mem.get(i) + mem.get(i - 1));

            // Updating answer if current memory slice value is greater than previous answer
            if (ans < mem.get(i)) {
                ans = mem.get(i);
            }
        }

        // Printing the final answer
        System.out.println(ans);
    }

}

