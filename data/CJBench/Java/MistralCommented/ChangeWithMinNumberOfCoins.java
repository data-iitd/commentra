
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    // Method to determine the minimum number of coins required to make a given amount using recursion
    public static int determineUsingRecursion(int[] coins, int amount) {
        // Sort the given coins array in ascending order
        Arrays.sort(coins);

        // Call the inner recursive method and store the result
        var result = innerRecursion(coins, amount);

        // If the inner recursive method returns -1, then it's not possible to make the given amount using the given coins
        if (result == -1) {
            return result;
        }

        // Return the result from the inner recursive method
        return result;
    }

    // Inner recursive method to determine the minimum number of coins required to make a given amount
    private static int innerRecursion(int[] coins, int amount) {
        // Base case: if the amount is 0, then no coins are required
        if (amount == 0) {
            return 0;
        }

        // Initialize the result variable with maximum integer value
        int result = Integer.MAX_VALUE;

        // Loop through each coin in the given coins array
        for (var coin : coins) {
            // If the given amount is greater than or equal to the current coin, then recursively call the innerRecursion method with the remaining amount and update the result variable if a smaller number of coins is found
            if (amount >= coin) {
                int subResult = innerRecursion(coins, amount - coin);
                if (subResult != Integer.MAX_VALUE && subResult + 1 < result) {
                    result = subResult + 1;
                }
            }
        }

        // Return the result variable
        return result;
    }

    // Method to determine the minimum number of coins required to make a given amount using memoization
    public static int determineUsingMemoization(int[] coins, int amount) {
        // Initialize a new integer array to store the minimum number of coins required for each amount
        int[] minCoins = new int[amount + 1];

        // Initialize all the elements of the minCoins array with maximum integer value
        Arrays.fill(minCoins, Integer.MAX_VALUE);

        // Set the minimum number of coins required for the amount 0 to 0
        minCoins[0] = 0;

        // Sort the given coins array in ascending order
        Arrays.sort(coins);

        // Loop through each amount from 1 to the given amount
        for (int i = 1; i <= amount; i++) {
            // Loop through each coin in the given coins array
            for (var coin : coins) {
                // If the current amount is greater than or equal to the current coin, then recursively call the innerRecursion method with the remaining amount and update the minCoins array if a smaller number of coins is found
                if (i - coin >= 0) {
                    int subResult = minCoins[i - coin];
                    if (subResult != Integer.MAX_VALUE && subResult + 1 < minCoins[i]) {
                        minCoins[i] = subResult + 1;
                    }
                }
            }
        }

        // If the minimum number of coins required for the given amount is maximum integer value, then it's not possible to make the given amount using the given coins
        if (minCoins[amount] == Integer.MAX_VALUE) {
            return -1;
        }

        // Return the minimum number of coins required for the given amount
        return minCoins[amount];
    }

    // Main method to read the input and call the appropriate method to determine the minimum number of coins required
    public static void main(String[] args) {
        // Create a new Scanner object to read the input
        Scanner sc = new Scanner(System.in);

        // Read the number of coins and store it in an array
        int n = sc.nextInt();
        int[] coins = new int[n];
        for (int i = 0; i < n; i++) {
            coins[i] = sc.nextInt();
        }

        // Read the amount and determine the minimum number of coins required using both recursion and memoization methods
        int amount = sc.nextInt();
        System.out.println("Minimum coins required (Recursion): " + determineUsingRecursion(coins, amount));
        System.out.println("Minimum coins required (Memoization): " + determineUsingMemoization(coins, amount));

        // Close the Scanner object
        sc.close();
    }
}

