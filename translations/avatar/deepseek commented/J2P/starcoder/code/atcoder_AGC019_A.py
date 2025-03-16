
import sys

# Reading input values
Q = int(input())
H = int(input())
S = int(input())
D = int(input())
N = int(input())

# Calculating the minimum price for one unit
onePrice = min(min(Q * 4, H * 2), S)

# Conditional logic to determine the total cost
if onePrice <= D / 2:
    print(N * onePrice)
else:
    print((N // 2) * D + (N % 2) * onePrice)

# 