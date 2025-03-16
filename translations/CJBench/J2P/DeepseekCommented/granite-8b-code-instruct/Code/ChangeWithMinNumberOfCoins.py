
import sys

def determine_using_recursion(coins, amount):
    # Sort the coins to ensure the recursion works efficiently.
    coins.sort()
    # Call the inner recursion method to determine the result.
    result = inner_recursion(coins, amount)
    # If the result is still MAX_VALUE, it means no combination was found.
    if result == sys.maxsize:
        return -1
    return result

# Helper method for determine_using_recursion, implements the recursion logic.
def inner_recursion(coins, amount):
    # Base case: if the amount is 0, no coins are needed.
    if amount == 0:
        return 0
    # Initialize result to MAX_VALUE to track the minimum coins needed.
    result = sys.maxsize
    # Iterate through each coin to find the minimum number of coins needed.
    for coin in coins:
        if amount >= coin:
            # Recursively call inner_recursion with the remaining amount.
            sub_result = inner_recursion(coins, amount - coin)
            # Update the result if a new minimum is found.
            if sub_result!= sys.maxsize and sub_result + 1 < result:
                result = sub_result + 1
    return result

def determine_using_memoization(coins, amount):
    # Initialize an array to store the minimum number of coins needed for each amount.
    min_coins = [sys.maxsize] * (amount + 1)
    # Base case: 0 coins are needed for an amount of 0.
    min_coins[0] = 0
    # Sort the coins to ensure the memoization works efficiently.
    coins.sort()
    # Iterate through each amount from 1 to the target amount.
    for i in range(1, amount + 1):
        # Iterate through each coin to update the min_coins array.
        for coin in coins:
            if i - coin >= 0:
                # Get the result from the previous calculation.
                sub_result = min_coins[i - coin]
                # Update the min_coins array if a new minimum is found.
                if sub_result!= sys.maxsize and sub_result + 1 < min_coins[i]:
                    min_coins[i] = sub_result + 1
    # If the target amount's minimum coins is still MAX_VALUE, return -1.
    if min_coins[amount] == sys.maxsize:
        return -1
    return min_coins[amount]

# Main method to read input, determine the minimum coins, and print the results.
def main():
    # Read the number of coins.
    n = int(input("Enter the number of coins: "))
    # Initialize the coins array with the read number of coins.
    coins = [int(input("Enter the denomination of coin " + str(i + 1) + ": ")) for i in range(n)]
    # Read the target amount.
    amount = int(input("Enter the target amount: "))
    # Print the minimum coins required using recursion.
    print("Minimum coins required (Recursion): " + str(determine_using_recursion(coins, amount)))
    # Print the minimum coins required using memoization.
    print("Minimum coins required (Memoization): " + str(determine_using_memoization(coins, amount)))

if __name__ == "__main__":
    main()

