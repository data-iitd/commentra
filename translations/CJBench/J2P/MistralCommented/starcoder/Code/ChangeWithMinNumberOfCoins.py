
import sys

# Method to determine the minimum number of coins required to make a given amount using recursion
def determineUsingRecursion(coins, amount):
    # Sort the given coins array in ascending order
    coins.sort()

    # Call the inner recursive method and store the result
    result = innerRecursion(coins, amount)

    # If the inner recursive method returns -1, then it's not possible to make the given amount using the given coins
    if result == -1:
        return result

    # Return the result from the inner recursive method
    return result

# Inner recursive method to determine the minimum number of coins required to make a given amount
def innerRecursion(coins, amount):
    # Base case: if the amount is 0, then no coins are required
    if amount == 0:
        return 0

    # Initialize the result variable with maximum integer value
    result = sys.maxsize

    # Loop through each coin in the given coins array
    for coin in coins:
        # If the given amount is greater than or equal to the current coin, then recursively call the innerRecursion method with the remaining amount and update the result variable if a smaller number of coins is found
        if amount >= coin:
            subResult = innerRecursion(coins, amount - coin)
            if subResult!= sys.maxsize and subResult + 1 < result:
                result = subResult + 1

    # Return the result variable
    return result

# Method to determine the minimum number of coins required to make a given amount using memoization
def determineUsingMemoization(coins, amount):
    # Initialize a new integer array to store the minimum number of coins required for each amount
    minCoins = [sys.maxsize] * (amount + 1)

    # Initialize all the elements of the minCoins array with maximum integer value
    minCoins[0] = 0

    # Sort the given coins array in ascending order
    coins.sort()

    # Loop through each amount from 1 to the given amount
    for i in range(1, amount + 1):
        # Loop through each coin in the given coins array
        for coin in coins:
            # If the current amount is greater than or equal to the current coin, then recursively call the innerRecursion method with the remaining amount and update the minCoins array if a smaller number of coins is found
            if i - coin >= 0:
                subResult = minCoins[i - coin]
                if subResult!= sys.maxsize and subResult + 1 < minCoins[i]:
                    minCoins[i] = subResult + 1

    # If the minimum number of coins required for the given amount is maximum integer value, then it's not possible to make the given amount using the given coins
    if minCoins[amount] == sys.maxsize:
        return -1

    # Return the minimum number of coins required for the given amount
    return minCoins[amount]

# Main method to read the input and call the appropriate method to determine the minimum number of coins required
def main():
    # Read the number of coins and store it in an array
    n = int(input())
    coins = [int(x) for x in input().split()]

    # Read the amount and determine the minimum number of coins required using both recursion and memoization methods
    amount = int(input())
    print("Minimum coins required (Recursion): " + str(determineUsingRecursion(coins, amount)))
    print("Minimum coins required (Memoization): " + str(determineUsingMemoization(coins, amount)))

# Entry point of the program
if __name__ == "__main__":
    main()

# 