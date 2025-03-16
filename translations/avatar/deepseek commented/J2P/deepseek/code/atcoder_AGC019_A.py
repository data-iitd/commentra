import sys

# Reading input values
Q = int(input())
H = int(input())
S = int(input())
D = int(input())
N = int(input())

# Calculating the minimum price for one unit
one_price = min(Q * 4, H * 2, S)

# Conditional logic to determine the total cost
if one_price <= D / 2:
    print(N * one_price)
else:
    print((N // 2) * D + (N % 2) * one_price)
