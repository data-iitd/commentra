
import sys

# Function to reverse the digits of an integer n
def reverse(n):
    # If n is a single digit, return n multiplied by 10
    if n < 10:
        return n * 10
    # Initialize r as 0 and t as n
    r = 0
    t = n
    # Loop to reverse the digits of n
    while t > 0:
        r = (r * 10) + t % 10 # Add the last digit of t to r
        t = t // 10 # Remove the last digit from t
    # Return the reversed integer
    return r

# Read two integers n and m from input
n = int(input())
m = int(input())

# Reverse the integer m and store the result in t
t = reverse(m)

# Print the sum of t and n
print(t + n)

