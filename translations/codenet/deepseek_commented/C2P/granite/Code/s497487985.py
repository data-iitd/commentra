
import sys

# Define a function to compare integers in descending order
def compare_int(a, b):
    return -1 if a < b else (1 if a > b else 0)

# Define a function to calculate the greatest common divisor (GCD)
def gcd(a, b):
    while b!= 0:
        a, b = b, a % b
    return a

# Define a function to calculate the least common multiple (LCM)
def lcm(a, b):
    return a * b // gcd(a, b)

# Read input values
n, k, q = map(int, input().split())
a = list(map(int, input().split()))
point = [0] * (n + 1)

# Process each query to update points
for i in range(q):
    point[a[i]] += 1

# Determine if each player can reach the required points
for i in range(1, n + 1):
    if k - (q - point[i]) > 0:
        print("Yes")  # Player can reach the required points
    else:
        print("No")  # Player cannot reach the required points

