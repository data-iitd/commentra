import sys

# Method to determine the minimum number of coins needed using recursion
def determineUsingRecursion(coins, amount):
    # Sort the coins array to facilitate the recursive process
    coins.sort()
    # Call the inner recursive method to calculate the result
    result = innerRecursion(coins, amount)
    # If the result is still sys.maxsize, it means it's not possible to form the amount
    if result == sys.maxsize:
        return -1 # Return -1 to indicate failure
    return result # Return the minimum number of coins needed

# Inner recursive method to find the minimum coins needed for a given amount
def innerRecursion(coins, amount):
    # Base case: if the amount is 0, no coins are needed
    if amount == 0:
        return 0
    # Initialize result to a large value
    result = sys.maxsize
    # Iterate through each coin
    for coin in coins:
        # Only proceed if the coin value is less than or equal to the remaining amount
        if amount >= coin:
            # Recursively call the method with the reduced amount
            subResult = innerRecursion(coins, amount - coin)
            # Check if the subResult is valid and update the result if a better option is found
            if subResult!= sys.maxsize and subResult + 1 < result:
                result = subResult + 1 # Update result with the new minimum
    return result # Return the minimum coins needed for the current amount

# Method to determine the minimum number of coins needed using memoization
def determineUsingMemoization(coins, amount):
    # Create an array to store the minimum coins needed for each amount up to the target amount
    minCoins = [sys.maxsize] * (amount + 1)
    # Initialize the array with a large value
    minCoins[0] = 0
    # Sort the coins array to facilitate the process
    coins.sort()
    # Iterate through each amount from 1 to the target amount
    for i in range(1, amount + 1):
        # Iterate through each coin
        for coin in coins:
            # Check if the coin can be used for the current amount
            if i - coin >= 0:
                # Get the minimum coins needed for the remaining amount
                subResult = minCoins[i - coin]
                # Update the minCoins array if a better option is found
                if subResult!= sys.maxsize and subResult + 1 < minCoins[i]:
                    minCoins[i] = subResult + 1 # Update with the new minimum
    # If the minimum coins for the target amount is still a large value, return -1
    if minCoins[amount] == sys.maxsize:
        return -1 # Indicate that it's not possible to form the amount
    return minCoins[amount] # Return the minimum coins needed for the target amount

# Main method to execute the program
def main():
    # Read the number of coins
    n = int(input())
    coins = [0] * n
    # Read the coin values into the array
    for i in range(n):
        coins[i] = int(input())
    # Read the target amount
    amount = int(input())
    # Output the result for the recursive approach
    print("Minimum coins required (Recursion): " + str(determineUsingRecursion(coins, amount)))
    # Output the result for the memoization approach
    print("Minimum coins required (Memoization): " + str(determineUsingMemoization(coins, amount)))

# Entry point of the program
if __name__ == "__main__":
    main()

# 