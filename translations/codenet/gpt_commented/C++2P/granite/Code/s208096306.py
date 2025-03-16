
import sys

# Function to compute the greatest common divisor (GCD) of two integers
def gcd(a, b):
    # Ensure 'a' is the larger number for the algorithm
    if a < b: a, b = b, a
    r = a % b
    while r > 0:
        a = b
        b = r
        r = a % b
    return b

# Read the number of integers from input
n = int(input())

# Read the first integer and initialize 'ans' with it
ans = int(input())

# Loop through the remaining integers to compute the GCD
for i in range(1, n):
    a = int(input())
    ans = gcd(ans, a)

# Output the final GCD result
print(ans)

