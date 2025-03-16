# Import the sys and input function
import sys
input = sys.stdin.readline

# Read the number of test cases, n, from the standard input
n = int(input())

# Initialize a variable, ans, with a large value
ans = 10 ** 18

# Use a for loop to iterate through all possible factors of n
for i in range(1, int(n ** (1 / 2)) + 2):
    # If the current number, i, is not a factor of n, skip to the next iteration
    if n % i != 0:
        continue
    
    # Calculate the quotient, j, of n by i
    j = n // i
    
    # Check if the sum of i and j is smaller than the current value of ans
    if i + j < ans:
        # If it is, update the value of ans
        ans = i + j

# After the for loop, print the value of ans as the output
print(ans)
