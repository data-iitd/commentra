import java.util.Arrays;
import java.util.Scanner;

public class Main {
    // Method to determine the minimum number of coins needed using recursion
    public static int determineUsingRecursion(int[] coins, int amount) {
        // Sort the coins array to facilitate the recursive process
        Arrays.sort(coins);
        // Call the inner recursive method to calculate the result
        var result = innerRecursion(coins, amount);
        // If the result is still Integer.MAX_VALUE, it means it's not possible to form the amount
        if (result == Integer.MAX_VALUE) {
            return -1; // Return -1 to indicate failure
        }
        return result; // Return the minimum number of coins needed
    }

    // Inner recursive method to find the minimum coins needed for a given amount
    private static int innerRecursion(int[] coins, int amount) {
        // Base case: if the amount is 0, no coins are needed
        if (amount == 0) {
            return 0;
        }
        // Initialize result to a large value
        int result = Integer.MAX_VALUE;
        // Iterate through each coin
        for (var coin : coins) {
            // Only proceed if the coin value is less than or equal to the remaining amount
            if (amount >= coin) {
                // Recursively call the method with the reduced amount
                int subResult = innerRecursion(coins, amount - coin);
                // Check if the subResult is valid and update the result if a better option is found
                if (subResult != Integer.MAX_VALUE && subResult + 1 < result) {
                    result = subResult + 1; // Update result with the new minimum
                }
            }
        }
        return result; // Return the minimum coins needed for the current amount
    }

    // Method to determine the minimum number of coins needed using memoization
    public static int determineUsingMemoization(int[] coins, int amount) {
        // Create an array to store the minimum coins needed for each amount up to the target amount
        int[] minCoins = new int[amount + 1];
        // Initialize the array with a large value
        Arrays.fill(minCoins, Integer.MAX_VALUE);
        // Base case: 0 coins are needed to make the amount 0
        minCoins[0] = 0;
        // Sort the coins array to facilitate the process
        Arrays.sort(coins);
        // Iterate through each amount from 1 to the target amount
        for (int i = 1; i <= amount; i++) {
            // Iterate through each coin
            for (var coin : coins) {
                // Check if the coin can be used for the current amount
                if (i - coin >= 0) {
                    // Get the minimum coins needed for the remaining amount
                    int subResult = minCoins[i - coin];
                    // Update the minCoins array if a better option is found
                    if (subResult != Integer.MAX_VALUE && subResult + 1 < minCoins[i]) {
                        minCoins[i] = subResult + 1; // Update with the new minimum
                    }
                }
            }
        }
        // If the minimum coins for the target amount is still a large value, return -1
        if (minCoins[amount] == Integer.MAX_VALUE) {
            return -1; // Indicate that it's not possible to form the amount
        }
        return minCoins[amount]; // Return the minimum coins needed for the target amount
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Read the number of coins
        int n = sc.nextInt();
        int[] coins = new int[n];
        // Read the coin values into the array
        for (int i = 0; i < n; i++) {
            coins[i] = sc.nextInt();
        }
        // Read the target amount
        int amount = sc.nextInt();
        // Output the result for the recursive approach
        System.out.println("Minimum coins required (Recursion): " + determineUsingRecursion(coins, amount));
        // Output the result for the memoization approach
        System.out.println("Minimum coins required (Memoization): " + determineUsingMemoization(coins, amount));
        // Close the scanner to prevent resource leaks
        sc.close();
    }
}
