
import sys

def determine_using_recursion(coins, amount):
    coins.sort()
    result = inner_recursion(coins, amount)

    if result == sys.maxsize:
        return -1
    return result

def inner_recursion(coins, amount):
    if amount == 0:
        return 0

    result = sys.maxsize
    for coin in coins:
        # Go through all coins smaller or equal to `amount`
        if amount >= coin:
            sub_result = inner_recursion(coins, amount - coin)

            # Check for INT_MAX to avoid overflow and see if a result can be minimized
            if sub_result!= sys.maxsize and sub_result + 1 < result:
                result = sub_result + 1
    return result

def determine_using_memoization(coins, amount):
    # The min_coins[i] will be storing the minimum number of coins required for `i` value.
    # So min_coins[amount] will have the result
    min_coins = [sys.maxsize] * (amount + 1)
    min_coins[0] = 0

    coins.sort()

    # Compute minimum coins required for all values from 1 to `amount`
    for i in range(1, amount + 1):
        for coin in coins:
            # Go through all coins smaller or equal to `i`
            if i - coin >= 0:
                sub_result = min_coins[i - coin]

                if sub_result!= sys.maxsize and sub_result + 1 < min_coins[i]:
                    min_coins[i] = sub_result + 1

    if min_coins[amount] == sys.maxsize:
        return -1

    return min_coins[amount]

if __name__ == "__main__":
    # Input number of coins
    n = int(input("Enter the number of coins: "))
    coins = [int(input(f"Enter the value of coin {i + 1}: ")) for i in range(n)]

    # Input the amount
    amount = int(input("Enter the amount: "))

    # Output results
    print(f"Minimum coins required (Recursion): {determine_using_recursion(coins, amount)}")
    print(f"Minimum coins required (Memoization): {determine_using_memoization(coins, amount)}")

