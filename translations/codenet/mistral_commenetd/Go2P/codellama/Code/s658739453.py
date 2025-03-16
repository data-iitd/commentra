
# Import the required packages
import math

# Define a constant 'd' as a big integer
d = 1000000007

# Initialize variables
n, p = map(int, input().split())

# Initialize an empty dictionary 'mdans' for storing distinct numbers
mdans = {}

# Read 'p' distinct numbers from the standard input and store them in the dictionary 'mdans'
for _ in range(p):
    n1 = int(input())
    mdans[n1] = n1 # Store the number 'n1' in the dictionary 'mdans' with its own key

# Initialize an array 'dp' of size 'n+1' with a default value of '0'
dp = [0] * (n+1)

# Initialize the first element of the array 'dp' with a value of '1'
dp[0] = 1

# Initialize the second element of the array 'dp' with a value of '1'
dp[1] = 1

# Initialize the third element of the array 'dp' with a value of '0' if the number '1' is present in the dictionary 'mdans'
if 1 in mdans:
    dp[1] = 0

# Calculate the remaining elements of the array 'dp' using the previous elements
for i in range(2, n+1):
    if i in mdans:
        continue # Skip the current iteration if the number 'i' is present in the dictionary 'mdans'
    dp[i] = (dp[i-1] + dp[i-2]) % d # Calculate the current element of the array 'dp' as the sum of the previous two elements modulo 'd'

# Print the final result
print(dp[n]) # Print the value of the last element of the array 'dp'

