# Import the sys module for user input
import sys

# Read two integers from the user: n and k
n, k = map(int, sys.stdin.readline().split())

# Increment n by 1
n += 1

# Initialize a variable z to store the adjustment needed to make n divisible by k
z = 0

# Check if n is not divisible by k
if n % k != 0:
    # Calculate the adjustment needed to make n divisible by k
    z = k - n % k

# Output the final result, which is n plus the adjustment z
print(n + z)

# <END-OF-CODE>
