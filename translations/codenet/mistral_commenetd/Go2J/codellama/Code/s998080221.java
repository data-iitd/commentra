
// Package main is the entry point of the program
package main

// Import the Scanner class to read input from the console
import java.util.Scanner;

// Function main is the entry point of the program
public class Main {
    // Function solve reads input from the console, processes it, and writes the output to the console
    public static void solve() {
        // Create a Scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);
        // Read two integers N and K from the console
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        // Initialize an array A of size N
        int[] A = new int[N];
        // Read N integers from the console and store them in the array A
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }
        // Initialize variables maxProfit, maxCnt, and maxA
        int maxProfit = 0;
        int maxCnt = 0;
        int maxA = A[N - 1];
        // Iterate through the array A from the last index to the first index
        for (int i = N - 2; i >= 0; i--) {
            // Calculate the profit of the current transaction
            int profit = Math.max(0, maxA - A[i]);
            // If the current profit is greater than the maximum profit found so far, update maxProfit and maxCnt
            if (maxProfit < profit) {
                maxProfit = profit;
                maxCnt = 1;
            } else if (maxProfit == profit) {
                maxCnt++;
            }
            // Update maxA with the maximum of the current element and maxA
            maxA = Math.max(maxA, A[i]);
        }
        // Write the output to the console
        System.out.println(maxCnt);
    }

    // Function main is the entry point of the program
    public static void main(String[] args) {
        // Call the solve function to solve the problem
        solve();
    }
}

