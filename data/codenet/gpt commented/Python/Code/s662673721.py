import sys
input = sys.stdin.readline  # Use fast input for competitive programming

# Read the integer input n
n = int(input())

# Initialize the answer with a large number
ans = 10 ** 18

# Iterate through possible divisors from 1 to the square root of n
for i in range(1, int(n ** (1 / 2)) + 2):
    # Check if i is a divisor of n
    if n % i != 0:
        continue  # If not, skip to the next iteration
    
    # Calculate the corresponding divisor j
    j = n // i
    
    # Update the answer with the minimum value of (i + j - 2)
    ans = min(ans, i + j - 2)

# Print the final answer
print(ans)
