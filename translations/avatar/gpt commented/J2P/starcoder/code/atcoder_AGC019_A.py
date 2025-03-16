import sys

# Reading the prices of different quantities of the item
Q = int(sys.stdin.readline()) # Price for 4 items
H = int(sys.stdin.readline()) # Price for 2 items
S = int(sys.stdin.readline()) # Price for 1 item
D = int(sys.stdin.readline()) # Price for 1 item when bought in pairs
N = int(sys.stdin.readline()) # Number of items to buy

# Calculating the minimum price for a single item based on the given prices
onePrice = min(min(Q * 4, H * 2), S)

# Checking if the price of one item is less than or equal to half the price of buying in pairs
if onePrice <= D / 2:
    # If true, calculate the total cost for N items at the price of one item
    print(N * onePrice)
else:
    # If false, calculate the total cost using the pair price and the remaining single item price if N is odd
    print((N / 2) * D + (N % 2) * onePrice)

# 