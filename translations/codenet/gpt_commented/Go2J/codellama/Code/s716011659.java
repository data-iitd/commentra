
package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Create a Scanner object for easy input
        Scanner input = new Scanner(System.in);

        // Read the number of elements in the array
        int n = input.nextInt();

        // Initialize an array to hold the input values
        int[] arrA = new int[n];
        // Read the input values into the array
        for (int i = 0; i < n; i++) {
            arrA[i] = input.nextInt();
        }

        // Create a cumulative sum array to store the cumulative sums of arrA
        int[] cumSumA = new int[n+1];
        cumSumA[0] = 0; // The first element is 0 (sum of zero elements)
        // Calculate the cumulative sums
        for (int i = 0; i < n; i++) {
            cumSumA[i+1] = cumSumA[i] + arrA[i];
        }

        // Initialize the answer variable to a large value
        double ans = Double.MAX_VALUE;
        // Iterate through the cumulative sums to find the minimum difference
        for (int i = 1; i < n; i++) {
            // Calculate the absolute difference between the total sum and twice the current cumulative sum
            if (Math.abs(cumSumA[n]-(cumSumA[i]*2)) < ans) {
                // Update the answer if the current difference is smaller
                ans = Math.abs(cumSumA[n] - cumSumA[i]*2);
            }
        }

        // Print the final answer as an integer
        System.out.println((int)ans);
    }
}

