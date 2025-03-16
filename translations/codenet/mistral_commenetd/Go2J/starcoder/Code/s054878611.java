
package main;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Read the size of the array from the standard input
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        // Allocate memory for the array and read its elements from the standard input
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        // Call the solution function and print the result
        System.out.println(solution(n, a));
    }

    // Function to find the maximum number of occurrences of a number in the array
    public static int solution(int n, int[] a) {
        // Initialize a memo table to store the number of occurrences of each number
        int[] memo = new int[100002];

        // Iterate through the array and update the memo table
        for (int i = 0; i < n; i++) {
            // Increment the memo table for the current number and the next two numbers
            memo[a[i]]++;
            memo[a[i] + 1]++;
            memo[a[i] + 2]++;
        }

        // Initialize output variable to store the maximum number of occurrences found
        int out = 0;

        // Iterate through the memo table and update the output variable if a larger number is found
        for (int i = 0; i < memo.length; i++) {
            if (memo[i] > 0) {
                // Update the output variable with the maximum number found so far
                out = Math.max(out, memo[i]);
            }
        }

        // Return the maximum number of occurrences found
        return out;
    }
}

