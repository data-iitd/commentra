
import sys # Importing the sys module for using input function

# Reading the prices of different quantities of the item
Q, H, S, D, N = map(int, sys.stdin.readline().split()) # Reading the input as a list of integers

# Calculating the minimum price for a single item based on the given prices
onePrice = min(Q * 4, H * 2, S)

# Checking if the price of one item is less than or equal to half the price of buying in pairs
if (onePrice <= D / 2):
    # If true, calculate the total cost for N items at the price of one item
    print(N * onePrice)
else:
    # If false, calculate the total cost using the pair price and the remaining single item price if N is odd
    print((N // 2) * D + (N % 2) * onePrice)

