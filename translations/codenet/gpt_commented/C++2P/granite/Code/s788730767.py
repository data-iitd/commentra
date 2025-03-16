
import math

# Function to calculate permutations nPr
def nPr(n, r):
    res = 1
    # Calculate nPr using the formula n! / (n - r)!
    for i in range(r):
        res *= (n - i) # Multiply by (n - i) for r times
    return res # Return the result

# Function to calculate combinations nCr
def nCr(n, r):
    # Using the formula nCr = nPr(n, r) / r!
    res = 1
    # Calculate nCr using an iterative approach to avoid large intermediate values
    for i in range(r):
        res *= (n - i) # Multiply by (n - i)
        res /= (i + 1) # Divide by (i + 1) to account for r!
    return int(res) # Return the result as integer

# Input the number of elements and the parity flag
n = int(input())
p = int(input())

# Read the array elements and count even and odd numbers
a = [int(input()) for _ in range(n)]
b = sum(1 for x in a if x % 2 == 0) # Count even numbers
c = sum(1 for x in a if x % 2 == 1) # Count odd numbers

# Initialize sums for combinations
bsum = 2**b # Calculate the total subsets of even numbers (2^b)
csum = 0 # Initialize csum

# Calculate combinations of odd numbers based on the parity flag
if p == 0:
    # If p is 0, count combinations of even counts of odd numbers
    for i in range(c + 1):
        if i % 2 == 0:
            csum += nCr(c, i) # Add combinations for even i
else:
    # If p is 1, count combinations of odd counts of odd numbers
    for i in range(c + 1):
        if i % 2 == 1:
            csum += nCr(c, i) # Add combinations for odd i

# Calculate the final answer as the product of bsum and csum
ans = bsum * csum
# Output the result
print(ans)

