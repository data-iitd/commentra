import sys
import math

def determine_using_recursion(coins, amount):
    coins.sort()
    result = inner_recursion(coins, amount)
    if result == math.inf:
        return -1
    return result

def inner_recursion(coins, amount):
    if amount == 0:
        return 0
    result = math.inf
    for coin in coins:
        if amount >= coin:
            sub_result = inner_recursion(coins, amount - coin)
            if sub_result != math.inf and sub_result + 1 < result:
                result = sub_result + 1
    return result

def determine_using_memoization(coins, amount):
    min_coins = [math.inf] * (amount + 1)
    min_coins[0] = 0
    coins.sort()
    for i in range(1, amount + 1):
        for coin in coins:
            if i - coin >= 0:
                sub_result = min_coins[i - coin]
                if sub_result != math.inf and sub_result + 1 < min_coins[i]:
                    min_coins[i] = sub_result + 1
    if min_coins[amount] == math.inf:
        return -1
    return min_coins[amount]

if __name__ == "__main__":
    n = int(input())
    coins = list(map(int, input().split()))
    amount = int(input())
    print("Minimum coins required (Recursion): " + str(determine_using_recursion(coins, amount)))
    print("Minimum coins required (Memoization): " + str(determine_using_memoization(coins, amount)))
    # 