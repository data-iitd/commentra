import sys
import math

# Determines the minimum number of coins needed using recursion.
def determineUsingRecursion(coins, amount):
    # Sort the coins to ensure the recursion works efficiently.
    coins.sort()
    # Call the inner recursion method to determine the result.
    result = innerRecursion(coins, amount)
    # If the result is still MAX_VALUE, it means no combination was found.
    if result == sys.maxsize:
        return -1
    return result

# Helper method for determineUsingRecursion, implements the recursion logic.
def innerRecursion(coins, amount):
    # Base case: if the amount is 0, no coins are needed.
    if amount == 0:
        return 0
    # Initialize result to MAX_VALUE to track the minimum coins needed.
    result = sys.maxsize
    # Iterate through each coin to find the minimum number of coins needed.
    for coin in coins:
        if amount >= coin:
            # Recursively call innerRecursion with the remaining amount.
            subResult = innerRecursion(coins, amount - coin)
            # Update the result if a new minimum is found.
            if subResult!= sys.maxsize and subResult + 1 < result:
                result = subResult + 1
    return result

# Determines the minimum number of coins needed using memoization.
def determineUsingMemoization(coins, amount):
    # Initialize an array to store the minimum number of coins needed for each amount.
    minCoins = [sys.maxsize] * (amount + 1)
    # Fill the array with MAX_VALUE to indicate uncalculated amounts.
    minCoins[0] = 0
    # Sort the coins to ensure the memoization works efficiently.
    coins.sort()
    # Iterate through each amount from 1 to the target amount.
    for i in range(1, amount + 1):
        # Iterate through each coin to update the minCoins array.
        for coin in coins:
            if i - coin >= 0:
                # Get the result from the previous calculation.
                subResult = minCoins[i - coin]
                # Update the minCoins array if a new minimum is found.
                if subResult!= sys.maxsize and subResult + 1 < minCoins[i]:
                    minCoins[i] = subResult + 1
    # If the target amount's minimum coins is still MAX_VALUE, return -1.
    if minCoins[amount] == sys.maxsize:
        return -1
    return minCoins[amount]

# Main method to read input, determine the minimum coins, and print the results.
def main():
    # Read the number of coins.
    n = int(input())
    # Initialize the coins array with the read number of coins.
    coins = [0] * n
    # Read the coin denominations.
    for i in range(n):
        coins[i] = int(input())
    # Read the target amount.
    amount = int(input())
    # Print the minimum coins required using recursion.
    print("Minimum coins required (Recursion): " + str(determineUsingRecursion(coins, amount)))
    # Print the minimum coins required using memoization.
    print("Minimum coins required (Memoization): " + str(determineUsingMemoization(coins, amount)))

# Entry point of the program.
if __name__ == "__main__":
    main()

# 