import java.util.Arrays;
import java.util.Scanner;
public class Main {
    // Determines the minimum number of coins needed using recursion.
    public static int determineUsingRecursion(int[] coins, int amount) {
        // Sort the coins to ensure the recursion works efficiently.
        Arrays.sort(coins);
        // Call the inner recursion method to determine the result.
        var result = innerRecursion(coins, amount);
        // If the result is still MAX_VALUE, it means no combination was found.
        if (result == Integer.MAX_VALUE) {
            return -1;
        }
        return result;
    }
    
    // Helper method for determineUsingRecursion, implements the recursion logic.
    private static int innerRecursion(int[] coins, int amount) {
        // Base case: if the amount is 0, no coins are needed.
        if (amount == 0) {
            return 0;
        }
        // Initialize result to MAX_VALUE to track the minimum coins needed.
        int result = Integer.MAX_VALUE;
        // Iterate through each coin to find the minimum number of coins needed.
        for (var coin : coins) {
            if (amount >= coin) {
                // Recursively call innerRecursion with the remaining amount.
                int subResult = innerRecursion(coins, amount - coin);
                // Update the result if a new minimum is found.
                if (subResult != Integer.MAX_VALUE && subResult + 1 < result) {
                    result = subResult + 1;
                }
            }
        }
        return result;
    }
    
    // Determines the minimum number of coins needed using memoization.
    public static int determineUsingMemoization(int[] coins, int amount) {
        // Initialize an array to store the minimum number of coins needed for each amount.
        int[] minCoins = new int[amount + 1];
        // Fill the array with MAX_VALUE to indicate uncalculated amounts.
        Arrays.fill(minCoins, Integer.MAX_VALUE);
        // Base case: 0 coins are needed for an amount of 0.
        minCoins[0] = 0;
        // Sort the coins to ensure the memoization works efficiently.
        Arrays.sort(coins);
        // Iterate through each amount from 1 to the target amount.
        for (int i = 1; i <= amount; i++) {
            // Iterate through each coin to update the minCoins array.
            for (var coin : coins) {
                if (i - coin >= 0) {
                    // Get the result from the previous calculation.
                    int subResult = minCoins[i - coin];
                    // Update the minCoins array if a new minimum is found.
                    if (subResult != Integer.MAX_VALUE && subResult + 1 < minCoins[i]) {
                        minCoins[i] = subResult + 1;
                    }
                }
            }
        }
        // If the target amount's minimum coins is still MAX_VALUE, return -1.
        if (minCoins[amount] == Integer.MAX_VALUE) {
            return -1;
        }
        return minCoins[amount];
    }
    
    // Main method to read input, determine the minimum coins, and print the results.
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Read the number of coins.
        int n = sc.nextInt();
        // Initialize the coins array with the read number of coins.
        int[] coins = new int[n];
        // Read the coin denominations.
        for (int i = 0; i < n; i++) {
            coins[i] = sc.nextInt();
        }
        // Read the target amount.
        int amount = sc.nextInt();
        // Print the minimum coins required using recursion.
        System.out.println("Minimum coins required (Recursion): " + determineUsingRecursion(coins, amount));
        // Print the minimum coins required using memoization.
        System.out.println("Minimum coins required (Memoization): " + determineUsingMemoization(coins, amount));
        // Close the scanner.
        sc.close();
    }
}
