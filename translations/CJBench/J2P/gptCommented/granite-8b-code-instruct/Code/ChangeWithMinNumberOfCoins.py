
import sys

def determine_using_recursion(coins, amount):
    # Sort the coins array to facilitate the recursive process
    coins.sort()
    # Call the inner recursive method to calculate the result
    result = inner_recursion(coins, amount)
    # If the result is still Integer.MAX_VALUE, it means it's not possible to form the amount
    if result == sys.maxsize:
        return -1 # Return -1 to indicate failure
    return result # Return the minimum number of coins needed

# Inner recursive method to find the minimum coins needed for a given amount
def inner_recursion(coins, amount):
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
            sub_result = inner_recursion(coins, amount - coin)
            # Check if the sub_result is valid and update the result if a better option is found
            if sub_result!= sys.maxsize and sub_result + 1 < result:
                result = sub_result + 1 # Update result with the new minimum
    return result # Return the minimum coins needed for the current amount

def determine_using_memoization(coins, amount):
    # Create an array to store the minimum coins needed for each amount up to the target amount
    min_coins = [sys.maxsize] * (amount + 1)
    # Initialize the array with a large value
    min_coins[0] = 0
    # Sort the coins array to facilitate the process
    coins.sort()
    # Iterate through each amount from 1 to the target amount
    for i in range(1, amount + 1):
        # Iterate through each coin
        for coin in coins:
            # Check if the coin can be used for the current amount
            if i - coin >= 0:
                # Get the minimum coins needed for the remaining amount
                sub_result = min_coins[i - coin]
                # Update the min_coins array if a better option is found
                if sub_result!= sys.maxsize and sub_result + 1 < min_coins[i]:
                    min_coins[i] = sub_result + 1 # Update with the new minimum
    # If the minimum coins for the target amount is still a large value, return -1
    if min_coins[amount] == sys.maxsize:
        return -1 # Indicate that it's not possible to form the amount
    return min_coins[amount] # Return the minimum coins needed for the target amount

# Main method to execute the program
if __name__ == "__main__":
    n = int(input("Enter the number of coins: "))
    coins = [int(x) for x in input("Enter the coin values: ").split()]
    amount = int(input("Enter the target amount: "))
    # Output the result for the recursive approach
    print("Minimum coins required (Recursion):", determine_using_recursion(coins, amount))
    # Output the result for the memoization approach
    print("Minimum coins required (Memoization):", determine_using_memoization(coins, amount))