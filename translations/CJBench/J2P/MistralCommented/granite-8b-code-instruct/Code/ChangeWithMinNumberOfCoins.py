

import sys

def determine_using_recursion(coins, amount):
    # Sort the given coins array in ascending order
    coins.sort()

    # Call the inner recursive method and store the result
    result = inner_recursion(coins, amount)

    # If the inner recursive method returns -1, then it's not possible to make the given amount using the given coins
    if result == -1:
        return result

    # Return the result from the inner recursive method
    return result

def inner_recursion(coins, amount):
    # Base case: if the amount is 0, then no coins are required
    if amount == 0:
        return 0

    # Initialize the result variable with maximum integer value
    result = sys.maxsize

    # Loop through each coin in the given coins array
    for coin in coins:
        # If the given amount is greater than or equal to the current coin, then recursively call the inner_recursion method with the remaining amount and update the result variable if a smaller number of coins is found
        if amount >= coin:
            sub_result = inner_recursion(coins, amount - coin)
            if sub_result!= sys.maxsize and sub_result + 1 < result:
                result = sub_result + 1

    # Return the result variable
    return result

def determine_using_memoization(coins, amount):
    # Initialize a new integer array to store the minimum number of coins required for each amount
    min_coins = [sys.maxsize] * (amount + 1)

    # Set the minimum number of coins required for the amount 0 to 0
    min_coins[0] = 0

    # Sort the given coins array in ascending order
    coins.sort()

    # Loop through each amount from 1 to the given amount
    for i in range(1, amount + 1):
        # Loop through each coin in the given coins array
        for coin in coins:
            # If the current amount is greater than or equal to the current coin, then recursively call the inner_recursion method with the remaining amount and update the min_coins array if a smaller number of coins is found
            if i - coin >= 0:
                sub_result = min_coins[i - coin]
                if sub_result!= sys.maxsize and sub_result + 1 < min_coins[i]:
                    min_coins[i] = sub_result + 1

    # If the minimum number of coins required for the given amount is maximum integer value, then it's not possible to make the given amount using the given coins
    if min_coins[amount] == sys.maxsize:
        return -1

    # Return the minimum number of coins required for the given amount
    return min_coins[amount]

# Main method to read the input and call the appropriate method to determine the minimum number of coins required
if __name__ == "__main__":
    # Read the number of coins and store it in an array
    n = int(input("Enter the number of coins: "))
    coins = [int(input("Enter the value of coin " + str(i + 1) + ": ")) for i in range(n)]

    # Read the amount and determine the minimum number of coins required using both recursion and memoization methods
    amount = int(input("Enter the amount: "))
    print("Minimum coins required (Recursion):", determine_using_recursion(coins, amount))
    print("Minimum coins required (Memoization):", determine_using_memoization(coins, amount))