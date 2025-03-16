import sys
import math

def determineUsingRecursion(coins, amount):
    if len(coins) == 0:
        return -1
    coins.sort()
    return innerRecursion(coins, amount)

def innerRecursion(coins, amount):
    if amount == 0:
        return 0
    result = sys.maxsize
    for coin in coins:
        if amount >= coin:
            subResult = innerRecursion(coins, amount - coin)
            if subResult!= sys.maxsize and subResult + 1 < result:
                result = subResult + 1
    return result

def determineUsingMemoization(coins, amount):
    minCoins = [sys.maxsize] * (amount + 1)
    minCoins[0] = 0
    coins.sort()
    for i in range(1, amount + 1):
        for coin in coins:
            if i - coin >= 0:
                subResult = minCoins[i - coin]
                if subResult!= sys.maxsize and subResult + 1 < minCoins[i]:
                    minCoins[i] = subResult + 1
    if minCoins[amount] == sys.maxsize:
        return -1
    return minCoins[amount]

def main():
    n = int(input())
    coins = [int(x) for x in input().split()]
    amount = int(input())
    print("Minimum coins required (Recursion): " + str(determineUsingRecursion(coins, amount)))
    print("Minimum coins required (Memoization): " + str(determineUsingMemoization(coins, amount)))

if __name__ == "__main__":
    main()

